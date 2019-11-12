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

#include "ojdkbuild/utils/localappdata.hpp"

#include <algorithm>
#include <vector>

#include "ojdkbuild/utils/windows.hpp"
#include <shlobj.h>

#include "ojdkbuild/utils/addressof.hpp"
#include "ojdkbuild/utils/defer.hpp"
#include "ojdkbuild/utils/exception.hpp"
#include "ojdkbuild/utils/lambda.hpp"
#include "ojdkbuild/utils/narrow.hpp"

namespace ojdkbuild {
namespace utils {

std::string localappdata_dir() {
    wchar_t* wbuf = nullptr;
    auto err = ::SHGetKnownFolderPath(
            FOLDERID_LocalAppData,
            KF_FLAG_CREATE,
            nullptr,
            addressof(wbuf));
    if (S_OK != err || nullptr == wbuf) {
        throw exception("Error getting 'LocalAppData' dir");
    }
    auto deferred = defer(make_lambda(::CoTaskMemFree, wbuf));
    auto path = narrow(wbuf, ::wcslen(wbuf));
    std::replace(path.begin(), path.end(), '\\', '/');
    path.push_back('/');
    return path;
}

} // namespace
}

#endif // _WIN32
