#pragma once

#include <cstddef>

template <typename... Types>
class tuple {
public:
  constexpr tuple();

  constexpr tuple(const Types&... args);

  template <typename... UTypes>
  constexpr tuple(UTypes&&... args);

  template <typename... UTypes>
  constexpr tuple(const tuple<UTypes...>& other);

  template <typename... UTypes>
  constexpr tuple(tuple<UTypes...>&& other);
};

// deduction guide to aid CTAD
template <typename... Types>
tuple(Types...) -> tuple<Types...>;

template <typename... Types>
constexpr tuple<VTypes...> make_tuple(Types&&... args);

template <typename T>
struct tuple_size;

template <typename T>
inline constexpr std::size_t tuple_size_v = 0;

template <std::size_t N, typename T>
struct tuple_element;

template <std::size_t N, typename T>
using tuple_element_t = void;

template <std::size_t N, typename... Types>
constexpr Type& get(tuple<Types...>& t) noexcept;

template <std::size_t N, typename... Types>
constexpr Type&& get(tuple<Types...>&& t) noexcept;

template <std::size_t N, typename... Types>
constexpr const Type& get(const tuple<Types...>& t) noexcept;

template <std::size_t N, typename... Types>
constexpr const Type&& get(const tuple<Types...>&& t) noexcept;

template <typename T, typename... Types>
constexpr T& get(tuple<Types...>& t) noexcept;

template <typename T, typename... Types>
constexpr T&& get(tuple<Types...>&& t) noexcept;

template <typename T, typename... Types>
constexpr const T& get(const tuple<Types...>& t) noexcept;

template <typename T, typename... Types>
constexpr const T&& get(const tuple<Types...>&& t) noexcept;

template <typename... TTypes, typename... UTypes>
constexpr bool operator==(const tuple<TTypes...>& lhs, const tuple<UTypes...>& rhs);

template <typename... TTypes, typename... UTypes>
constexpr void operator<=>(const tuple<TTypes...>& lhs, const tuple<UTypes...>& rhs);

template <typename... Tuples>
constexpr tuple<CTypes...> tuple_cat(Tuples&&... args);
