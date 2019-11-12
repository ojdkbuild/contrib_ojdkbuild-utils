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

#ifdef _WIN32

#include "ojdkbuild/utils/current_executable.hpp"

#include <algorithm>
#include <vector>

#include "ojdkbuild/utils/windows.hpp"

#include "ojdkbuild/utils/errcode_to_string.hpp"
#include "ojdkbuild/utils/exception.hpp"
#include "ojdkbuild/utils/narrow.hpp"
#include "ojdkbuild/utils/to_string.hpp"

namespace ojdkbuild {
namespace utils {

std::string current_executable_path() {
    auto vec = std::vector<wchar_t>();
    vec.resize(MAX_PATH);
    auto success = ::GetModuleFileNameW(
            nullptr,
            vec.data(),
            static_cast<DWORD>(vec.size()));
    if (0 == success) {
        throw exception(std::string("Error getting current executable dir,") +
            " error: [" + errcode_to_string(::GetLastError()) + "]");
    }
    auto path = narrow(vec.data(), vec.size());
    std::replace(path.begin(), path.end(), '\\', '/');
    return path;
}

std::string current_executable_dir() {
    auto path = current_executable_path();
    auto sid = path.rfind('/');
    return std::string::npos != sid ? path.substr(0, sid + 1) : path;
}

} // namespace
}

#endif // _WIN32
