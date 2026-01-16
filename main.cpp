#include<iostream>
#include<format>
#include<vector>
#include<thread>
#include<semaphore>

int main() {
	int idx{ 0 };
	std::binary_semaphore binSem{ 1LL };

	auto print{
		[&] () {
			binSem.acquire();
			++idx;
			std::cout << std::format("thread {}\n", idx);
			binSem.release();
		}
	};

	std::vector<std::thread> ths{};

	for (int i{ 0 }; i < 3; ++i) {
		ths.emplace_back(print);
	}
	
	for (auto& th : ths) {
		th.join();
	}

	return 0;
}