// SPDX-License-Identifier: BSL-1.0

//   Copyright Eddie Nolan and Jonathan Wakely 2023 - 2024.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include <std_archetypes/exposition_only.hpp>

namespace beman::utf_view::tests::std_archetypes {

#if defined(_GLIBCXX_VERSION_INCLUDED) || defined(_LIBCPP_VERSION)
static_assert(__boolean_testable<boolean_testable_archetype1>);
static_assert(__boolean_testable<boolean_testable_archetype2>);
#endif

} // namespace beman::utf_view::tests::std_archetypes
