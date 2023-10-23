/*

The MIT License (MIT)

Copyright (c) 2017-2022 Tim Warburton, Noel Chalmers, Jesse Chan, Ali Karakus

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

#ifndef BS6_HPP
#define BS6_HPP 1

#include "mesh.hpp"
#include "timer.hpp"

#ifndef DBS6
#define DBS6 STREAM_DIR"/BS/BS6/"
#endif

using namespace libp;

class bs6Settings_t: public settings_t {
public:
  bs6Settings_t(const int argc, char** argv, comm_t _comm);
  void report();
};

class bs6_t {
public:
  platform_t platform;
  settings_t settings;
  mesh_t mesh;

  bs6_t() = default;
  bs6_t(platform_t &_platform, settings_t& _settings,
        mesh_t& _mesh) {
    Setup(_platform, _settings, _mesh);
  }

  ~bs6_t() = default;

  //setup
  void Setup(platform_t &_platform, settings_t& _settings,
             mesh_t& _mesh);

  void Run();
};


#endif
