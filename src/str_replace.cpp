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

#include "ojdkbuild/utils/str_replace.hpp"

namespace ojdkbuild {
namespace utils {

std::string& str_replace(std::string& str, const std::string& snippet, const std::string& replacement) {
    if (snippet.empty()) {
        return str;
    }
    auto pos = std::string::npos;
    while (std::string::npos != (pos = str.find(snippet))) {
        str.replace(pos, snippet.length(), replacement);
    }
    return str;
}

} // namespace
}
