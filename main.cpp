#include<iostream>
#include<array>
#include<format>
#include<cmath>

namespace {
	std::array<int64_t, 25LLU> TableRSP{};
	std::array<int64_t, 25LLU> TableRSA{};

	void InitTable() {
		TableRSP.fill(-1);
		TableRSP[0] = 0;
		TableRSP[1] = 100;
		TableRSA.fill(-1);
		TableRSA[0] = 0;
	}

	int64_t RecursiveSalaryPerHour(uint32_t hour_) {
		if (TableRSP[hour_] == -1) {
			TableRSP[hour_] = RecursiveSalaryPerHour(hour_ - 1U) * 2U - 50U;
		}
		return TableRSP[hour_];
	}

	int64_t RecursiveSalaryCumulative(uint32_t hour_) {
		if (TableRSA[hour_] == -1) {
			TableRSA[hour_] = RecursiveSalaryCumulative(hour_ - 1U) + RecursiveSalaryPerHour(hour_);
		}
		return TableRSA[hour_];
	}

	int64_t FixedSalaryCumulative(uint32_t hour_) {
		return 1226LL * hour_;
	}
}

int main() {
	InitTable();
	std::cout << std::format("| {: ^4s} | {: ^12s} | {: ^12s} | {: ^12s} |\n", "時間", "時給", "累積", "累積（固定）");
	for (int32_t i{ 1U }; i <= 24U; ++i) {
		std::cout <<
			std::format(
				"| {:4d} | {:12d} | {:12d} | {:12d} |\n",
				i,
				RecursiveSalaryPerHour(i),
				RecursiveSalaryCumulative(i),
				FixedSalaryCumulative(i)
			);
	}
	return 0;
}