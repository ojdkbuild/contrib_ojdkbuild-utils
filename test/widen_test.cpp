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

#include <iostream>
#include "ojdkbuild/utils/assert.hpp"
#include "ojdkbuild/utils/narrow.hpp"

void test_widen() {
    // hello in russian in utf-8
    std::string src("\xd0\xbf\xd1\x80\xd0\xb8\xd0\xb2\xd0\xb5\xd1\x82");
    std::wstring wst = ojb::widen(src);
    ojbassert(6 == wst.length());
    std::string converted = ojb::narrow(wst);
    ojbassert(src == converted);
}

int main() {
    try {
        test_widen();
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