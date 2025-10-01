#include<iostream>
#include<type_traits>
#include<string>
#include<sstream>

template<typename T, typename U>
	requires (std::is_arithmetic_v<T> && std::is_arithmetic_v<U>)
constexpr auto Min(T lhs_, U rhs_) -> decltype(lhs_ + rhs_) {
	return (lhs_ < rhs_) ? (lhs_) : (rhs_);
}

template<typename T>
	requires (std::is_enum_v<T>)
constexpr T Min(T lhs_, T rhs_) {
	using ValType = std::underlying_type_t<T>;
	return (static_cast<ValType>(lhs_) < static_cast<ValType>(rhs_)) ? (lhs_) : (rhs_);
}

int main() {
	std::cout << Min(-4, 3) << "\n";
	std::cout << Min(3.14159f, 2.71828f) << "\n";
	std::cout << Min(-273.15, 451.0) << "\n";

	return 0;
}