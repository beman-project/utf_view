// SPDX-License-Identifier: BSL-1.0

//   Copyright Eddie Nolan and Jonathan Wakely 2023 - 2024.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#ifndef UTF_VIEW_TESTS_FRAMEWORK_HPP
#define UTF_VIEW_TESTS_FRAMEWORK_HPP

#include <functional>
#include <map>
#include <string>

namespace utf_view::tests {

namespace framework {

  std::map<std::string, std::function<bool()>>& tests();

} // namespace framework

} // namespace utf_view::tests

#endif // UTF_VIEW_TESTS_FRAMEWORK_HPP
