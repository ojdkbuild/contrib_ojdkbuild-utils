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

#include "ojdkbuild/utils/str_trim.hpp"

#include <cctype>
#include <algorithm>

namespace ojdkbuild {
namespace utils {

std::string str_trim(const std::string& str) {
    auto front = std::find_if_not(str.begin(), str.end(), std::isspace);
    auto back = std::find_if_not(str.rbegin(), std::string::const_reverse_iterator(front), std::isspace);
    return std::string(front, back.base());
}

} // namespace
}
