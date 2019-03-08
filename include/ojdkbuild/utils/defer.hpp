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

#ifndef OJDKBUILD_UTILS_DEFER_HPP
#define OJDKBUILD_UTILS_DEFER_HPP

#include "ojdkbuild/utils/noexcept.hpp"

namespace ojdkbuild {
namespace utils {

// http://stackoverflow.com/a/17356259/314015

template<typename T>
class defer_guard {
    T func;
    mutable bool moved_out;

    defer_guard& operator=(const defer_guard&);
public:

    explicit defer_guard(T functor) :
    func(functor),
    moved_out(false) { }

    defer_guard(const defer_guard& other) :
    func(other.func) {
        other.moved_out = true;
    }

    ~defer_guard() OJDKBUILD_NOEXCEPT {
#ifdef OJDKBUILD_NOEXCEPT_SUPPORTED
        static_assert(noexcept(func()),
                "Please check that the defer block cannot throw, "
                "and mark the lambda as 'noexcept'.");
#endif
        if (!moved_out) {
            func();
        }
    }
};

template<typename T>
defer_guard<T> defer(T func) {
    return defer_guard<T>(func);
}

} // namespace
}

#endif // OJDKBUILD_UTILS_DEFER_HPP
