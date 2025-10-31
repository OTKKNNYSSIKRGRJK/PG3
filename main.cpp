#include<iostream>
#include<format>
#include<random>
#include<cmath>

namespace {
	template<typename T, typename U>
	class MyClass {
	private:
		T Val0_;
		U Val1_;

		using RetType = decltype(Val0_ + Val1_);

	public:
		constexpr auto Min() const noexcept -> RetType {
			return
				static_cast<RetType>(Val0_) < static_cast<RetType>(Val1_) ?
				static_cast<RetType>(Val0_) :
				static_cast<RetType>(Val1_);
		}

	public:
		MyClass(T val0_, U val1_) : Val0_{ val0_ }, Val1_{ val1_ } {
			std::cout << std::format(
				"Min({} {}, {} {}) = ",
				typeid(T).name(), Val0_,
				typeid(U).name(), Val1_
			);
		}
	};

	std::mt19937 RndEngine{ std::random_device{}() };
}

int main() {
	unsigned int rndNums[18]{};
	for (auto& num : rndNums) {
		num = RndEngine();
	}

	std::cout
		<< MyClass{ static_cast<int>(rndNums[0]), static_cast<int>(rndNums[1]) }.Min() << "\n"
		<< MyClass{ std::cos(rndNums[2] * 0.125f), std::cos(rndNums[3] * 0.125f) }.Min() << "\n"
		<< MyClass{ std::cos(rndNums[4] * 0.125), std::cos(rndNums[5] * 0.125) }.Min() << "\n"
		<< MyClass{ static_cast<int>(rndNums[6]), static_cast<float>(rndNums[7]) }.Min() << "\n"
		<< MyClass{ static_cast<float>(rndNums[8]), static_cast<int>(rndNums[9]) }.Min() << "\n"
		<< MyClass{ static_cast<int>(rndNums[10]), static_cast<double>(rndNums[11]) }.Min() << "\n"
		<< MyClass{ static_cast<double>(rndNums[12]), static_cast<int>(rndNums[13]) }.Min() << "\n"
		<< MyClass{ std::cos(rndNums[14] * 0.125f), std::cos(rndNums[15] * 0.125) }.Min() << "\n"
		<< MyClass{ std::cos(rndNums[16] * 0.125), std::cos(rndNums[17] * 0.125f) }.Min() << "\n";

	return 0;
}