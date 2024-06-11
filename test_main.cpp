/*
 * Copyright (C) 2015 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <gtest/gtest.h>

#include "android-base/logging.h"
#include "chrono_utils_test.cpp"
#include "cmsg_test.cpp"
#include "endian_test.cpp"
#include "errors_test.cpp"
#include "function_ref_test.cpp"
#include "hex_test.cpp"
#include "macros_test.cpp"
#include "mapped_file_test.cpp"
#include "parsebool_test.cpp"
#include "parsedouble_test.cpp"
#include "parseint_test.cpp"
#include "parsenetaddress_test.cpp"
#include "process_test.cpp"
#include "scopeguard_test.cpp"
#include "strings_test.cpp"
#include "stringprintf_test.cpp"
#include "tidy/unique_fd_test.cpp"

extern "C"
{
int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  android::base::InitLogging(argv, android::base::StderrLogger);
  return RUN_ALL_TESTS();
}
}
