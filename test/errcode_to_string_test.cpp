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

#include "ojdkbuild/utils/errcode_to_string.hpp"

#include <iostream>
#include "ojdkbuild/utils/assert.hpp"

void test_code() {
    std::string st = ojb::errcode_to_string(1);
    ojbassert(st.length() > 0);
    std::string invalid = ojb::errcode_to_string(-1);
    ojbassert(st.length() > 0);
}

int main() {
    try {
        test_code();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
