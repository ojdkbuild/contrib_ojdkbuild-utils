/*
 * Copyright 2019 akashche at redhat.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef OJDKBUILD_UTILS_CURRENT_EXECUTABLE_HPP
#define OJDKBUILD_UTILS_CURRENT_EXECUTABLE_HPP

#include <string>

namespace ojdkbuild {
namespace utils {

std::string current_executable_path();

std::string current_executable_dir();

} // namespace
}

#endif // OJDKBUILD_UTILS_CURRENT_EXECUTABLE_HPP
