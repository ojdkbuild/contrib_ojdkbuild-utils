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

#ifndef OJDKBUILD_UTILS_ASSERT_HPP
#define OJDKBUILD_UTILS_ASSERT_HPP

#include <stdexcept>
#include <string>

#include "ojdkbuild/utils/to_string.hpp"

#define ojbassert(_expr) if (!(_expr)) throw ojdkbuild::utils::assert_exception(std::string() + "ASSERTION ERROR: line: " + ojdkbuild::utils::to_string(__LINE__));

namespace ojdkbuild {
namespace utils {

class assert_exception : public std::runtime_error {
public:

    assert_exception(const std::string& msg) :
    std::runtime_error(msg) { }

};

} // namespace
}

// export namespace with shorter name, for use in tests
namespace ojb = ojdkbuild::utils;

#endif /* OJDKBUILD_UTILS_ASSERT_HPP */

