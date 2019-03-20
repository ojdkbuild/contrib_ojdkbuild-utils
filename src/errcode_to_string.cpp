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

#include "ojdkbuild/utils/errcode_to_string.hpp"

#include "ojdkbuild/utils/windows.hpp"

#include "ojdkbuild/utils/defer.hpp"
#include "ojdkbuild/utils/lambda.hpp"
#include "ojdkbuild/utils/narrow.hpp"
#include "ojdkbuild/utils/to_string.hpp"

namespace ojdkbuild {
namespace utils {

std::string errcode_to_string(unsigned long code) OJDKBUILD_NOEXCEPT {
    if (0 == code) {
        return std::string();
    }
    wchar_t* buf = nullptr;
    size_t size = ::FormatMessageW(
            FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
            nullptr,
            code,
            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
            reinterpret_cast<wchar_t*>(&buf),
            0,
            nullptr);
    if (0 == size) {
        return "Cannot format code: [" + to_string(code) + "]" +
            " into message, error code: [" + to_string(::GetLastError()) + "]";
    }
    auto deferred = defer(make_lambda(::LocalFree, buf));
    if (size <= 2) {
        return "code: [" + to_string(code) + "], message: []";
    }
    try {
        std::string msg = narrow(buf, size - 2);
        return "code: [" + to_string(code) + "], message: [" + msg + "]";
    } catch(const std::exception& e) {
        return "Cannot format code: [" + to_string(code) + "]" +
            " into message, narrow error: [" + e.what() + "]";
    }
}

} // namespace
}

#endif // _WIN32
