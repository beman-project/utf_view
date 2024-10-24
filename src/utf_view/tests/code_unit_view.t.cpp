// SPDX-License-Identifier: BSL-1.0

//   Copyright Eddie Nolan and Jonathan Wakely 2023 - 2024.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include <utf_view/code_unit_view.hpp>
#include <utf_view/detail/constexpr_unless_msvc.hpp>
#include <ranges>
#include <string_view>
#include <tests/framework.hpp>

namespace utf_view::tests {

// TODO: Comprehensive testing for `code_unit_view`

constexpr bool smoke_test() {
  std::string_view foo{"foo"};
  auto bar{foo | as_char8_t};
  static_assert(std::ranges::borrowed_range<decltype(foo)>);
  auto baz{bar | std::ranges::to<std::u8string>()};
  if (baz != std::u8string_view{u8"foo"}) {
    return false;
  }
  return true;
}

template <typename View>
constexpr bool every_operator_test_impl(View v) {
  auto char8_t_view{v | as_char8_t};
  auto it{char8_t_view.begin()};
  auto sent{char8_t_view.end()};
  if (it == sent) {
    return false;
  }
  for (auto const i : std::views::iota(std::size_t{0}, v.size())) {
    ++it;
  }
  if (it != sent) {
    return false;
  }
  for (auto const i : std::views::iota(std::size_t{0}, v.size())) {
    --it;
  }
  if (it == sent) {
    return false;
  }
  return true;
}

constexpr bool every_operator_test() {
  if (!every_operator_test_impl(std::string_view{"012345789"})) {
    return false;
  }
  return true;
}

CONSTEXPR_UNLESS_MSVC bool code_unit_view_test() {
  if (!smoke_test()) {
    return false;
  }
  if (!every_operator_test()) {
    return false;
  }
  return true;
}

#ifndef _MSC_VER
static_assert(code_unit_view_test());
#endif

static auto const init{[] {
  framework::tests().insert({"code_unit_view_test", &code_unit_view_test});
  struct {
  } result{};
  return result;
}()};

} // namespace utf_view::tests
