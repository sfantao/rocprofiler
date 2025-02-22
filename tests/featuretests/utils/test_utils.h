/*
Copyright (c) 2015-2016 Advanced Micro Devices, Inc. All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
#ifndef TESTS_FEATURETESTS_PROFILER_UTILS_TEST_UTILS_H_
#define TESTS_FEATURETESTS_PROFILER_UTILS_TEST_UTILS_H_

#include <cxxabi.h>    // for __cxa_demangle
#include <dlfcn.h>     // for dladdr
#include <execinfo.h>  // for backtrace

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

namespace rocmtools {
namespace tests {
namespace utility {

// Get current running path
std::string GetRunningPath(std::string string_to_erase);

// Get Number of cores in the system
int GetNumberOfCores();

bool is_installed_path();

}  // namespace utility
}  // namespace tests
}  // namespace rocmtools

// used for dl_addr to locate the running
// path for executable
int main(int argc, char** argv);

using rocmtools::tests::utility::GetNumberOfCores;
using rocmtools::tests::utility::GetRunningPath;
using rocmtools::tests::utility::is_installed_path;

#endif  // TESTS_FEATURETESTS_PROFILER_UTILS_TEST_UTILS_H_
