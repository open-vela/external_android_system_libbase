#
# Copyright (C) 2023 Xiaomi Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

include $(APPDIR)/Make.defs

CXXEXT = .cpp

CXXSRCS += abi_compatibility.cpp
CXXSRCS += chrono_utils.cpp
CXXSRCS += cmsg.cpp
CXXSRCS += errors_unix.cpp
CXXSRCS += file.cpp
CXXSRCS += hex.cpp
CXXSRCS += logging.cpp
CXXSRCS += mapped_file.cpp
CXXSRCS += parsebool.cpp
CXXSRCS += parsenetaddress.cpp
CXXSRCS += posix_strerror_r.cpp
CXXSRCS += process.cpp
CXXSRCS += properties.cpp
CXXSRCS += stringprintf.cpp
CXXSRCS += strings.cpp
CXXSRCS += test_utils.cpp
CXXSRCS += threads.cpp

include $(APPDIR)/Application.mk
