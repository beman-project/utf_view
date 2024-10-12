// SPDX-License-Identifier: BSL-1.0

//   Copyright Eddie Nolan and Jonathan Wakely 2023 - 2024.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#ifndef UTFVIEW_DETAIL_ERRONEOUS_BEHAVIOR_GLOBAL_HPP
#define UTFVIEW_DETAIL_ERRONEOUS_BEHAVIOR_GLOBAL_HPP

namespace utf_view::detail {

inline bool& erroneous_behavior_global() {
  static bool global{};
  return global;
}

} // namespace utf_view::detail

#endif // UTFVIEW_DETAIL_ERRONEOUS_BEHAVIOR_GLOBAL_HPP
