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

#include <iostream>
#include "ojdkbuild/utils/assert.hpp"

void test_replace() {
    std::string str1 = "foobarfoobaz";
    ojbassert("42bar42baz" == ojb::str_replace(str1, "foo", "42"));
    std::string str2 = "foo";
    ojbassert("foo" == ojb::str_replace(str2, "bar", ""));
    std::string str3 = "foo";
    ojbassert("foo" == ojb::str_replace(str3, "", "42"));
}

int main() {
    try {
        test_replace();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
