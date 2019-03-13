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

#include "ojdkbuild/utils/widen.hpp"

#include <windows.h>
#include "ojdkbuild/utils/addressof.hpp"
#include "ojdkbuild/utils/errcode_to_string.hpp"
#include "ojdkbuild/utils/exception.hpp"

namespace ojdkbuild {
namespace utils {

std::wstring widen(const std::string& st) {
    if (st.empty()) return std::wstring();
    int size_needed = ::MultiByteToWideChar(
            CP_UTF8,
            0,
            st.c_str(),
            static_cast<int>(st.length()),
            nullptr,
            0);
    if (0 == size_needed) {
        throw exception(std::string("Error on string widen calculation,") +
            " string: [" + st + "], error: [" + errcode_to_string(::GetLastError()) + "]");
    }
    auto res = std::wstring();
    res.resize(size_needed);
    int chars_copied = ::MultiByteToWideChar(
            CP_UTF8,
            0,
            st.c_str(),
            static_cast<int>(st.size()),
            addressof(res.front()),
            size_needed);
    if (chars_copied != size_needed) {
        throw exception(std::string("Error on string widen execution,") +
            " string: [" + st + "], error: [" + errcode_to_string(::GetLastError()) + "]");
    }
    return res;
}

} // namespace
}

#endif // _WIN32
