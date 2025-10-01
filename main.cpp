#include<iostream>
#include<string>
#include<format>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

int main() {
	std::ifstream file{};
	std::string_view fileName{ "PG3_2025_01_02.txt" };
	std::vector<std::string> accountList{};
	
	try {
		file.open(fileName.data());
		if (!file) {
			throw std::runtime_error{ std::format("Cannot open \"{}\"!\n", fileName) };
		}
	}
	catch (std::runtime_error const& err) {
		std::cout << err.what();
		std::exit(1);
	}

	std::string str_Account{};
	while (std::getline(file, str_Account, ',')) {
		accountList.emplace_back(str_Account);
	}
	file.close();

	std::sort(
		accountList.begin(),
		accountList.end(),
		[](std::string const& lhs_, std::string const& rhs_) -> bool {
			return (std::strcmp(lhs_.data(), rhs_.data()) < 0);
		}
	);

	for (auto const& account : accountList) {
		std::cout << account << "\n";
	}

	return 0;
}