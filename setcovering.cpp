/* setcovering.cpp */

#include <iostream>
#include <map>
#include <unordered_set>
#include <string>

using states_type = std::unordered_set<std::string>;
using stations_type = std::map<std::string, states_type>;

states_type states_intersection(states_type const &set1, states_type const &set2) {
	states_type out;

	for (auto &state : set1) {
		if (set2.contains(state))
			out.insert(state);
	}
	return out;
}

void states_sub(states_type &set1, states_type const &set2) {
	for (auto &state : set2) {
		if (set1.contains(state))
			set1.erase(state);
	}
}

int main(void) {
	states_type needed_states
		= {"mt", "wa", "or", "id", "nv", "ut", "ca", "az"};
	stations_type stations = {
		{"kone", {"id", "nv", "ut"}},
		{"ktwo", {"wa", "id", "mt"}},
		{"kthree", {"or", "nv", "ca"}},
		{"kfour", {"nv", "ut"}},
		{"kfive", {"ca", "az"}},
	};
	std::unordered_set<std::string> chosen_stations;

	while (!needed_states.empty()) {
		std::string best_station;
		states_type states_covered;

		for (auto &s : stations) {
			auto covered = states_intersection(needed_states, s.second);
			if (covered.size() > states_covered.size()) {
				best_station = s.first;
				states_covered = covered;
			}
		}
		states_sub(needed_states, states_covered);
		chosen_stations.insert(best_station);
	}

	std::cout << "The following stations are chosen:";
	for (auto &station : chosen_stations)
	{
		std::cout << " " << station;
	}
	std::cout << std::endl;
	return 0;
}
