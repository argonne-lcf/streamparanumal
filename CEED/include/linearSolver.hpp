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

#ifndef LINEARSOLVER_HPP
#define LINEARSOLVER_HPP

#include <occa.hpp>
#include "types.h"
#include "utils.hpp"
#include "core.hpp"
#include "settings.hpp"
#include "solver.hpp"
#include "linAlg.hpp"

//virtual base linear solver class
class linearSolver_t {
public:
  MPI_Comm& comm;
  occa::device& device;
  settings_t& settings;
  occa::properties& props;
  mesh_t& mesh;
  linAlg_t& linAlg;

  dlong N;

  linearSolver_t(solver_t& solver):
    comm(solver.comm),
    device(solver.device),
    settings(solver.settings),
    props(solver.props),
    mesh(solver.mesh),
    linAlg(solver.linAlg) {}

  static linearSolver_t* Setup(solver_t& solver);

  virtual void Init(int _weighted, occa::memory& o_weight,
                    dlong _N, dlong Nhalo)=0;
  virtual int Solve(solver_t& solver,
                    occa::memory& o_x, occa::memory& o_rhs,
                    const dfloat tol, const int MAXIT, const int verbose)=0;

  virtual ~linearSolver_t(){}
};

//Conjugate Gradient
class cg: public linearSolver_t {
private:
  occa::memory o_p, o_Ap, o_Ax, o_w;

  dfloat* tmprdotr;
  occa::memory h_tmprdotr;
  occa::memory o_tmprdotr;

  int weighted;

  occa::kernel updateCGKernel;

  dfloat UpdateCG(const dfloat alpha, occa::memory &o_x, occa::memory &o_r);

public:
  cg(solver_t& solver);
  ~cg();

  void Init(int _weighted, occa::memory& o_weight,
                    dlong _N, dlong Nhalo);
  int Solve(solver_t& solver,
            occa::memory& o_x, occa::memory& o_rhs,
            const dfloat tol, const int MAXIT, const int verbose);
};

#endif
