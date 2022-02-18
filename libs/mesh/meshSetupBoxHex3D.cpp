/*

The MIT License (MIT)

Copyright (c) 2020 Tim Warburton, Noel Chalmers, Jesse Chan, Ali Karakus

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#include "mesh.hpp"

namespace libp {

void mesh_t::SetupBoxHex3D(){

  //local grid physical sizes
  //Hard code to 2x2x2
  dfloat DIMX=2.0, DIMY=2.0, DIMZ=2.0;

  //number of local elements in each dimension
  dlong nx, ny, nz;
  settings.getSetting("BOX NX", nx);
  settings.getSetting("BOX NY", ny);
  settings.getSetting("BOX NZ", nz);

  // find a factorization size = size_x*size_y*size_z such that
  //  size_x>=size_y>=size_z are all 'close' to one another
  int size_x, size_y, size_z;
  Factor3(size, size_x, size_y, size_z);

  //determine (x,y,z) rank coordinates for this processes
  int rank_x=-1, rank_y=-1, rank_z=-1;
  RankDecomp3(size_x, size_y, size_z,
              rank_x, rank_y, rank_z,
              rank);

  //local grid physical sizes
  dfloat dimx = DIMX/size_x;
  dfloat dimy = DIMY/size_y;
  dfloat dimz = DIMZ/size_z;

  //bottom corner of physical domain
  dfloat X0 = -DIMX/2.0 + rank_x*dimx;
  dfloat Y0 = -DIMY/2.0 + rank_y*dimy;
  dfloat Z0 = -DIMZ/2.0 + rank_z*dimz;

  //global number of elements in each dimension
  hlong NX = size_x*nx;
  hlong NY = size_y*ny;
  hlong NZ = size_z*nz;

  //global number of nodes in each dimension
  hlong NnX = NX+1;
  hlong NnY = NY+1;
  hlong NnZ = NZ+1;

  // build an nx x ny x nz box grid
  Nnodes = NnX*NnY*NnZ; //global node count
  Nelements = nx*ny*nz; //local

  EToV.malloc(Nelements*Nverts);
  EX.malloc(Nelements*Nverts);
  EY.malloc(Nelements*Nverts);
  EZ.malloc(Nelements*Nverts);

  const dfloat dx = dimx/nx;
  const dfloat dy = dimy/ny;
  const dfloat dz = dimz/nz;

  #pragma omp parallel for collapse(3)
  for(int k=0;k<nz;++k){
    for(int j=0;j<ny;++j){
      for(int i=0;i<nx;++i){

        const dlong e = i + j*nx + k*nx*ny;

        const hlong i0 = i+rank_x*nx;
        const hlong i1 = (i+1+rank_x*nx)%NnX;
        const hlong j0 = j+rank_y*ny;
        const hlong j1 = (j+1+rank_y*ny)%NnY;
        const hlong k0 = k+rank_z*nz;
        const hlong k1 = (k+1+rank_z*nz)%NnZ;

        EToV[e*Nverts+0] = i0 + j0*NnX + k0*NnX*NnY;
        EToV[e*Nverts+1] = i1 + j0*NnX + k0*NnX*NnY;
        EToV[e*Nverts+2] = i1 + j1*NnX + k0*NnX*NnY;
        EToV[e*Nverts+3] = i0 + j1*NnX + k0*NnX*NnY;

        EToV[e*Nverts+4] = i0 + j0*NnX + k1*NnX*NnY;
        EToV[e*Nverts+5] = i1 + j0*NnX + k1*NnX*NnY;
        EToV[e*Nverts+6] = i1 + j1*NnX + k1*NnX*NnY;
        EToV[e*Nverts+7] = i0 + j1*NnX + k1*NnX*NnY;

        dfloat x0 = X0 + dx*i;
        dfloat y0 = Y0 + dy*j;
        dfloat z0 = Z0 + dz*k;

        dfloat *ex = EX.ptr()+e*Nverts;
        dfloat *ey = EY.ptr()+e*Nverts;
        dfloat *ez = EZ.ptr()+e*Nverts;

        ex[0] = x0;    ey[0] = y0;    ez[0] = z0;
        ex[1] = x0+dx; ey[1] = y0;    ez[1] = z0;
        ex[2] = x0+dx; ey[2] = y0+dy; ez[2] = z0;
        ex[3] = x0;    ey[3] = y0+dy; ez[3] = z0;

        ex[4] = x0;    ey[4] = y0;    ez[4] = z0+dz;
        ex[5] = x0+dx; ey[5] = y0;    ez[5] = z0+dz;
        ex[6] = x0+dx; ey[6] = y0+dy; ez[6] = z0+dz;
        ex[7] = x0;    ey[7] = y0+dy; ez[7] = z0+dz;
      }
    }
  }
}

} //namespace libp
