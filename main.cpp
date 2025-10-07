#include<iostream>

#include"GetStations.h"

template<uint32_t Year>
void PrintStations() {
	std::cout << Year << "年\n--------------------\n";
	std::list<char const*> stations;
	GetStations<Year>(stations);
	uint32_t no{ 0U };
	for (auto const& station : stations) {
		std::printf("%2u | %s\n", ++no, station);
	}
}

int main() {
	PrintStations<1970U>();
	std::cout << "\n";
	PrintStations<2019U>();
	std::cout << "\n";
	PrintStations<2022U>();
	return 0;
}