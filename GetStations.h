#pragma once

#include<list>
#include<cstring>

template<uint32_t Year>
	requires (Year < 1971U)
inline void GetStations(std::list<char const*>& stations_) {
	stations_.clear();
	stations_.assign(
		{
			"Tokyo",
			"Kanda",
			"Akihabara",
			"Okachimachi",
			"Ueno",
			"Uguisudani",
			"Nippori",
			"Tabata",
			"Komagome",
			"Sugamo",
			"Otsuka",
			"Ikebukuro",
			"Mejiro",
			"Takadanobaba",
			"Shin-Okubo",
			"Shinjuku",
			"Yoyogi",
			"Harajuku",
			"Shibuya",
			"Ebisu",
			"Meguro",
			"Gotanda",
			"Osaki",
			"Shinagawa",
			"Tamachi",
			"Hamamatsucho",
			"Shimbashi",
			"Yurakucho",
		}
	);
}

template<uint32_t Year>
	requires (Year >= 1971U && Year < 2020U)
inline void GetStations(std::list<char const*>& stations_) {
	GetStations<1970U>(stations_);
	for (auto&& it{ stations_.cbegin() }; it != stations_.cend(); ++it) {
		if (std::strcmp(*it, "Tabata") == 0) {
			stations_.emplace(it, "Nishi-Nippori");
			break;
		}
	}
}

template<uint32_t Year>
	requires (Year >= 2020U)
inline void GetStations(std::list<char const*>& stations_) {
	GetStations<2019U>(stations_);
	for (auto&& it{ stations_.cbegin() }; it != stations_.cend(); ++it) {
		if (std::strcmp(*it, "Tamachi") == 0) {
			stations_.emplace(it, "Takanawa Gateway");
			break;
		}
	}
}