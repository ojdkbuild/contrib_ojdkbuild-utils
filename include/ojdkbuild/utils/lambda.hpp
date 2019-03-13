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

#ifndef OJDKBUILD_UTILS_LAMBDA_HPP
#define OJDKBUILD_UTILS_LAMBDA_HPP

#include "ojdkbuild/utils/noexcept.hpp"

namespace ojdkbuild {
namespace utils {

template<typename Func, typename Arg>
class lambda {
    Func func;
    Arg arg;
public:

    lambda(Func func, Arg arg) :
    func(func),
    arg(arg) { }

    void operator()() OJDKBUILD_NOEXCEPT {
        func(arg);
    }
};

template<typename Func, typename Arg>
lambda<Func, Arg> make_lambda(Func func, Arg arg) {
    return lambda<Func, Arg>(func, arg);
}

} // namespace
}

#endif // OJDKBUILD_UTILS_LAMBDA_HPP
