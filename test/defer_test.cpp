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

#include "ojdkbuild/utils/defer.hpp"

#include <iostream>
#include "ojdkbuild/utils/assert.hpp"

#include "ojdkbuild/utils/addressof.hpp"
#include "ojdkbuild/utils/lambda.hpp"
#include "ojdkbuild/utils/noexcept.hpp"

void flipper(bool* flag_ptr) OJDKBUILD_NOEXCEPT {
    bool val = *flag_ptr;
    *flag_ptr = !val;
}

void test_defer() {
    bool flag = false;
    {
        auto fun = ojb::make_lambda(flipper, ojb::addressof(flag));
        auto deferred = ojb::defer(fun);
        (void) deferred;
    }
    ojbassert(flag);
}

void test_defer_moved_out() {
    bool flag = false;
    {
        auto fun = ojb::make_lambda(flipper, ojb::addressof(flag));
        auto deferred = ojb::defer(fun);
        ojbassert(!flag);
        auto deferred_copy = deferred;
        ojbassert(!flag);
        (void) deferred_copy;
    }
    ojbassert(flag);
}

int main() {
    try {
        test_defer();
        test_defer_moved_out();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
