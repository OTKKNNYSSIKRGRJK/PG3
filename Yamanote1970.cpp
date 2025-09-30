#include<iostream>

#include"GetStations.h"

int main() {
	std::printf("List of Stations of Yamanote Line in 1970\n");

	std::list<char const*> stations;
	GetStations<1970U>(stations);
	uint32_t no{ 0U };
	for (auto const& station : stations) {
		std::printf("%2u | %s\n", ++no, station);
	}
	std::system("pause");
	return 0;
}