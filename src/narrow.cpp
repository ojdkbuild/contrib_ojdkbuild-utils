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

#include "ojdkbuild/utils/narrow.hpp"

#include <vector>

#include "ojdkbuild/utils/windows.hpp"

#include "ojdkbuild/utils/exception.hpp"
#include "ojdkbuild/utils/to_string.hpp"

namespace ojdkbuild {
namespace utils {

std::string narrow(const wchar_t* wstring, size_t length) {
    if (0 == length) return std::string();
    int size_needed = ::WideCharToMultiByte(
            CP_UTF8,
            0,
            wstring,
            static_cast<int>(length),
            nullptr,
            0,
            nullptr,
            nullptr);
    if (0 == size_needed) {
        throw exception(std::string("Error on string narrow calculation,") +
            " string length: [" + to_string(length) + "], error code: [" + to_string(::GetLastError()) + "]");
    }
    auto vec = std::vector<char>();
    vec.resize(size_needed);
    int bytes_copied = ::WideCharToMultiByte(
            CP_UTF8,
            0,
            wstring,
            static_cast<int>(length),
            vec.data(),
            size_needed,
            nullptr,
            nullptr);
    if (bytes_copied != size_needed) {
        throw exception(std::string("Error on string narrow execution,") +
            " string length: [" + to_string(vec.size()) + "], error code: [" + to_string(::GetLastError()) + "]");
    }
    return std::string(vec.begin(), vec.end());
}

std::string narrow(const std::wstring& wstring) {
    return narrow(wstring.c_str(), wstring.length());
}

} // namespace
}

#endif // _WIN32
