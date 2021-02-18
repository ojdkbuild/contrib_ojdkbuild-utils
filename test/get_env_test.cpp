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

#include <iostream>
#include "ojdkbuild/utils/assert.hpp"
#include "ojdkbuild/utils/exception.hpp"

void test_empty() {
    auto thrown = false;
    try {
        ojb::get_env("");
    } catch(const ojb::exception& e) {
        thrown = true;
    }
    ojbassert(thrown);
}

void test_windir() {
    auto windir = ojb::get_env("WINDIR");
    ojbassert("C:\\Windows" == windir);
}

void test_absent() {
    auto res = ojb::get_env("SOME_VARIABLE_NAME_THAT_IS_NOT_DEFINED");
    ojbassert(res.empty());
}

int main() {
    try {
        test_empty();
        test_windir();
        test_absent();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}

#else // !_WIN32
int main() {
    return 0;
}
#endif // _WIN32
