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

#ifndef OJDKBUILD_UTILS_TO_STRING_HPP
#define OJDKBUILD_UTILS_TO_STRING_HPP

#include <sstream>

namespace ojdkbuild {
namespace utils {

template<typename T>
std::string to_string(const T& obj) {
    std::stringstream ss;
    ss << obj;
    return ss.str();
}

} // namespace
}

#endif // OJDKBUILD_UTILS_TO_STRING_HPP
