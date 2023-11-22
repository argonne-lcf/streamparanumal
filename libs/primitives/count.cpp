/*

The MIT License (MIT)

Copyright (c) 2017-2023 Tim Warburton, Noel Chalmers, Jesse Chan, Ali Karakus

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

#include "primitives.hpp"

namespace libp {

namespace prim {


template<typename T>
dlong count(const dlong N, const memory<T> v, const T& value) {

  if (N<=0) return 0;

  dlong cnt = 0;
  #pragma omp parallel for reduction(+:cnt)
  for (dlong n=0; n<N; ++n) {
    cnt += (v[n] == value) ? 1 : 0;
  }

  return cnt;
}

template dlong count(const dlong N, const memory<int> v, const int& value);
template dlong count(const dlong N, const memory<long long int> v, const long long int& value);
template dlong count(const dlong N, const memory<float> v, const float& value);
template dlong count(const dlong N, const memory<double> v, const double& value);

} //namespace prim

} //namespace libp
