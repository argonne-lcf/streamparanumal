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
#include "mesh2D.hpp"

void meshTri2D::ReferenceNodes(int N_){

  // char fname[BUFSIZ];
  // sprintf(fname, CEED_DIR "/nodes/triangleN%02d.dat", N_);

  // FILE *fp = fopen(fname, "r");

  // if (!fp) {
  //   stringstream ss;
  //   ss << "Cannot open file: " << fname;
  //   CEED_ABORT(ss.str())
  // }

  N = N_;
  Nfp = N+1;
  Np = (N+1)*(N+2)/2;

  CEED_ABORT(string("Tri node setup not complete."))

  // int Nrows, Ncols;

  // /* Nodal Data */
  // readDfloatArray(comm, fp, "Nodal r-coordinates", &(r),&Nrows,&Ncols);
  // readDfloatArray(comm, fp, "Nodal s-coordinates", &(s),&Nrows,&Ncols);
  // readDfloatArray(comm, fp, "Nodal Dr differentiation matrix", &(Dr), &Nrows, &Ncols);
  // readDfloatArray(comm, fp, "Nodal Ds differentiation matrix", &(Ds), &Nrows, &Ncols);
  // readDfloatArray(comm, fp, "Nodal Mass Matrix", &(MM), &Nrows, &Ncols);
  // readIntArray   (comm, fp, "Nodal Face nodes", &(faceNodes), &Nrows, &Ncols);
  // readDfloatArray(comm, fp, "Nodal Lift Matrix", &(LIFT), &Nrows, &Ncols);

  // /* Plotting data */
  // readDfloatArray(comm, fp, "Plotting r-coordinates", &(plotR),&Nrows,&Ncols);
  // readDfloatArray(comm, fp, "Plotting s-coordinates", &(plotS),&Nrows,&Ncols);
  // plotNp = Nrows;

  // readDfloatArray(comm, fp, "Plotting Interpolation Matrix", &(plotInterp),&Nrows,&Ncols);
  // readIntArray   (comm, fp, "Plotting triangulation", &(plotEToV), &Nrows, &Ncols);
  // plotNelements = Nrows;
  // plotNverts = Ncols;

  // /* Cubature data */
  // readDfloatArray(comm, fp, "Cubature r-coordinates", &(cubr),&Nrows,&Ncols);
  // readDfloatArray(comm, fp, "Cubature s-coordinates", &(cubs),&Nrows,&Ncols);
  // readDfloatArray(comm, fp, "Cubature weights", &(cubw),&Nrows,&Ncols);
  // cubNp = Nrows;

  // //zero out some unused values
  // cubNq = 0;
  // cubNfp = 0;

  // readDfloatArray(comm, fp, "Cubature Interpolation Matrix", &(cubInterp),&Nrows,&Ncols);
  // readDfloatArray(comm, fp, "Cubature Weak Dr Differentiation Matrix", &(cubDrW),&Nrows,&Ncols);
  // readDfloatArray(comm, fp, "Cubature Weak Ds Differentiation Matrix", &(cubDsW),&Nrows,&Ncols);
  // readDfloatArray(comm, fp, "Cubature Projection Matrix", &(cubProject),&Nrows,&Ncols);
  // readDfloatArray(comm, fp, "Cubature Surface Interpolation Matrix", &(intInterp),&Nrows,&Ncols);
  // intNfp = Nrows/Nfaces; //number of interpolation points per face

  // readDfloatArray(comm, fp, "Cubature Surface Lift Matrix", &(intLIFT),&Nrows,&Ncols);

  // fclose(fp);

  // // find node indices of vertex nodes
  // dfloat NODETOL = 1e-6;
  // vertexNodes = (int*) calloc(Nverts, sizeof(int));
  // for(int n=0;n<Np;++n){
  //   if( (r[n]+1)*(r[n]+1)+(s[n]+1)*(s[n]+1)<NODETOL)
  //     vertexNodes[0] = n;
  //   if( (r[n]-1)*(r[n]-1)+(s[n]+1)*(s[n]+1)<NODETOL)
  //     vertexNodes[1] = n;
  //   if( (r[n]+1)*(r[n]+1)+(s[n]-1)*(s[n]-1)<NODETOL)
  //     vertexNodes[2] = n;
  // }
}
