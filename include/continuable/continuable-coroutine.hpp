/*

                        /~` _  _ _|_. _     _ |_ | _
                        \_,(_)| | | || ||_|(_||_)|(/_

                    https://github.com/Naios/continuable
                                   v4.1.0

  Copyright(c) 2015 - 2020 Denis Blank <denis.blank at outlook dot com>

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files(the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions :

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
**/

#ifndef CONTINUABLE_COROUTINE_HPP_INCLUDED
#define CONTINUABLE_COROUTINE_HPP_INCLUDED

#include <continuable/continuable-base.hpp>
#include <continuable/continuable-types.hpp>
#include <continuable/detail/core/types.hpp>
#include <continuable/detail/features.hpp>

#if defined(CONTINUABLE_HAS_EXCEPTIONS)
#include <exception>
#endif // CONTINUABLE_HAS_EXCEPTIONS

#ifdef CONTINUABLE_HAS_EXPERIMENTAL_COROUTINE
#include <continuable/detail/other/coroutines.hpp>
#endif // CONTINUABLE_HAS_EXPERIMENTAL_COROUTINE

/// \cond false
#ifdef CONTINUABLE_HAS_EXPERIMENTAL_COROUTINE
// As far as I know there is no other way to implement this specialization...
// NOLINTNEXTLINE(cert-dcl58-cpp)
namespace std {
namespace experimental {
template <typename Data, typename... Args, typename... FunctionArgs>
struct coroutine_traits<
    cti::continuable_base<Data, cti::detail::identity<Args...>>,
    FunctionArgs...> {

  using promise_type =
      cti::detail::awaiting::promise_type<cti::continuable<Args...>,
                                          cti::promise<Args...>, Args...>;
};
} // namespace experimental
} // namespace std
#endif // CONTINUABLE_HAS_EXPERIMENTAL_COROUTINE
/// \endcond

#endif // CONTINUABLE_COROUTINE_HPP_INCLUDED
