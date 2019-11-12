# Copyright 2019, akashche at redhat.com
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required ( VERSION 2.8.12 )

# project
include ( ${CMAKE_CURRENT_LIST_DIR}/../../../resources/cmake/ojdkbuild_common.cmake )
project ( ojdkbuild_utils_test C CXX )

# dependencies
ojdkbuild_add_subdirectory ( ${CMAKE_CURRENT_LIST_DIR}/../../ojdkbuild-utils ojdkbuild_utils )

set ( ${PROJECT_NAME}_DEPS ojdkbuild_utils )
ojdkbuild_pkg_check_modules ( ${PROJECT_NAME}_DEPS_PC REQUIRED ${PROJECT_NAME}_DEPS )

# tests
set ( ${PROJECT_NAME}_TEST_INCLUDES ${${PROJECT_NAME}_DEPS_PC_INCLUDE_DIRS} )
set ( ${PROJECT_NAME}_TEST_LIBS ${${PROJECT_NAME}_DEPS_PC_LIBRARIES} )
set ( ${PROJECT_NAME}_TEST_OPTS ${${PROJECT_NAME}_DEPS_PC_CFLAGS_OTHER} )
ojdkbuild_enable_testing ( ${PROJECT_NAME}_TEST_INCLUDES ${PROJECT_NAME}_TEST_LIBS ${PROJECT_NAME}_TEST_OPTS )