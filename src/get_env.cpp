/*
 * Copyright 2021 akashche at redhat.com
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

#include "ojdkbuild/utils/get_env.hpp"

#include "ojdkbuild/utils/windows.hpp"

#include "ojdkbuild/utils/addressof.hpp"
#include "ojdkbuild/utils/errcode_to_string.hpp"
#include "ojdkbuild/utils/exception.hpp"
#include "ojdkbuild/utils/narrow.hpp"
#include "ojdkbuild/utils/widen.hpp"

namespace ojdkbuild {
namespace utils {

std::string get_env(const std::string& name) {
    if (name.empty()) {
        throw exception("Specified environment variable name is empty");
    }
    auto wname = widen(name);
    auto wbuf = std::wstring();
    auto size_needed = ::GetEnvironmentVariableW(wname.c_str(), nullptr, 0);
    if (0 == size_needed) {
        auto err = ::GetLastError();
        if (ERROR_ENVVAR_NOT_FOUND == err) {
            return std::string();
        }
        throw exception(std::string("Error on environment variable required size calculation,") +
            " name: [" + name + "], error: [" + errcode_to_string(err) + "]");
    }
    wbuf.resize(size_needed);
    auto chars_copied = ::GetEnvironmentVariableW(wname.c_str(), addressof(wbuf.front()), wbuf.length());
    if (size_needed != (chars_copied + 1)) {
        throw exception(std::string("Error reading environment variable,") +
            " name: [" + name + "], error: [" + errcode_to_string(::GetLastError()) + "]");
    }
    wbuf.resize(chars_copied);
    return narrow(wbuf);
}

} // namespace
}

#endif // _WIN32
