#include<iostream>
#include<cstdlib>
#include<string>
#include<format>
#include<chrono>
#include<thread>
#include<algorithm>
#include<Windows.h>

namespace {
	using JudgeFunc = int32_t(*)(int32_t);

	constexpr int32_t JudgeOdd(int32_t roll_) { return !!(roll_ & 1); }
	constexpr int32_t JudgeEven(int32_t roll_) { return !!!(roll_ & 1); }

	using RevealCallback = void(*)(int32_t, int32_t);

	void DelayReveal(RevealCallback callback_, int32_t roll_, int32_t isMatched_, uint32_t delayInMs_) {
		static auto wait = [](uint32_t timeInMs_) { ::Sleep(timeInMs_); };
		while (delayInMs_ > 0) {
			std::thread waitTh{ wait, std::min<uint32_t>(delayInMs_, 250U) };
			waitTh.join();
			std::cout << ".";
			delayInMs_ -= std::min<uint32_t>(delayInMs_, 250U);
		}
		std::cout << "\n";

		callback_(roll_, isMatched_);
	}

	void ShowResult(int32_t roll_, int32_t isMatched_) {
		std::cout << std::format("出目：{}\n{}\n", roll_, isMatched_ ? "正解" : "不正解");
	}
}

int main() {
	std::srand(static_cast<uint32_t>(std::chrono::system_clock::now().time_since_epoch().count()));

	std::string input{};
	while (true) {
		std::cout << "Odd (o/O) or even (e/E)? > ";
		std::cin >> input;
		if (input.size() == 1 && (input[0] == 'o' || input[0] == 'O' || input[0] == 'e' || input[0] == 'E')) {
			break;
		}
	}

	JudgeFunc judgeFuncs[2]{ JudgeEven, JudgeOdd };
	int32_t roll = (rand() % 6) + 1;
	int32_t isMatched = judgeFuncs[(input[0] == 'o' || input[0] == 'O')](roll);

	DelayReveal(ShowResult, roll, isMatched, 1000U);

	return 0;
}