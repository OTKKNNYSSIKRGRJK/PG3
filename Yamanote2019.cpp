#include<iostream>

#include"GetStations.h"

int main() {
	std::printf("List of Stations of Yamanote Line in 2019\n");

	std::list<char const*> stations;
	GetStations<2019U>(stations);
	uint32_t no{ 0U };
	for (auto const& station : stations) {
		std::printf("%2u | %s\n", ++no, station);
	}
	std::system("pause");
	return 0;
}