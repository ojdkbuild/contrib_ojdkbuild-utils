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

#include "ojdkbuild/utils/to_string.hpp"

#include <iostream>
#include <stdexcept>
#include "ojdkbuild/utils/assert.hpp"

void test_to_string() {
    ojbassert("42" == ojb::to_string(42));
    ojbassert("42" == ojb::to_string(std::string("42")));
}

class BadExternalClass {
    bool will_throw;

public:
    BadExternalClass(bool will_throw) :
    will_throw(will_throw) { }

    friend std::ostream &operator<<(std::ostream& st, const BadExternalClass& cl) {
        if (cl.will_throw) {
            throw std::runtime_error("");
        }
        return st;
    }
};

void test_to_string_exception() {
    bool caught = false;
    try {
        BadExternalClass bc(true);
        ojb::to_string(bc);
    } catch (const std::runtime_error&) {
        caught = true;
    }
    ojbassert(caught);
}

int main() {
    try {
        test_to_string();
        test_to_string_exception();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
