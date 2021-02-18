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

#ifndef OJDKBUILD_UTILS_HPP
#define OJDKBUILD_UTILS_HPP

#include "ojdkbuild/utils/addressof.hpp"
#include "ojdkbuild/utils/defer.hpp"
#include "ojdkbuild/utils/exception.hpp"
#include "ojdkbuild/utils/lambda.hpp"
#include "ojdkbuild/utils/noexcept.hpp"
#include "ojdkbuild/utils/str_replace.hpp"
#include "ojdkbuild/utils/str_trim.hpp"
#include "ojdkbuild/utils/to_string.hpp"

#ifdef _WIN32
#include "ojdkbuild/utils/errcode_to_string.hpp"
#include "ojdkbuild/utils/current_executable.hpp"
#include "ojdkbuild/utils/get_env.hpp"
#include "ojdkbuild/utils/localappdata.hpp"
#include "ojdkbuild/utils/narrow.hpp"
#include "ojdkbuild/utils/widen.hpp"
#endif // _WIN32

namespace ojb = ojdkbuild::utils;

#endif // OJDKBUILD_UTILS_HPP
