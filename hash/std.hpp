// Copyright (c) 2016 Andrew Sutton
// All rights reserved

#ifndef HASH_STD_HPP
#define HASH_STD_HPP

#include <utility>
#include <tuple>
#include <vector>
#include <list>
#include <string>

namespace origin {

// Hash append for pairs.
template<typename H, typename T, typename U>
void
hash_append(H& h, std::pair<T, U> const& p)
{
  hash_append(p.first);
  hash_append(p.second);
}

namespace hash_detail {

template<int N, typename H, typename... Ts>
  typename std::enable_if<N == sizeof...(Ts), void>::type
hash_append_impl(H& h, std::tuple<Ts...> const& t)
{ 
  // Do nothing.
}

template<int N, typename H, typename... Ts>
  typename std::enable_if<N != sizeof...(Ts), void>::type
hash_append_impl(H& h, std::tuple<Ts...> const& t)
{
  hash_append(h, std::get<N>(t));
  hash_append_impl<N + 1>(h, t);
}

} // namespace hash_detail

// Hash append for tuples.
template<typename H, typename... Ts>
void
hash_append(H& h, std::tuple<Ts...> const& t)
{
  hash_detail::hash_append_impl<0>(h, t);
}

namespace hash_detail {

template<typename T> 
struct is_iterable : std::false_type { };

template<typename T, typename A> 
struct is_iterable<std::vector<T, A>> : std::true_type { };

template<typename T, typename A> 
struct is_iterable<std::list<T, A>> : std::true_type { };

template<typename C, typename T, typename A> 
struct is_iterable<std::basic_string<C, T, A>> : std::true_type { };

} // namespace hash_detail

// Hash append for any container for which is_iterable is true.
template<typename H, typename T>
  typename std::enable_if<hash_detail::is_iterable<T>::value, void>::type
hash_append(H& h, T const& v)
{
  hash_append(h, v.begin(), v.end());
  // hash_append(h, v.size());
}

} // namespace origin


#endif
