/* breadthfirstsearch.cpp */

#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_set>

using list_type = std::unordered_set<std::string>;
using graph_type = std::map<std::string, list_type>;
using queue_type = std::queue<std::string>;

queue_type &list_to_queue(queue_type &q, list_type const &list) {
	for (auto &i : list) {
		q.emplace(i);
	}
	return q;
}

bool person_is_seller(std::string const &p) {
	return p.back() == 'm';
}

/**
 * @brief Do breadth-first search to find a mango seller in a graph of friends.
 * A mango seller has a name ending in the letter 'm'.
 * 
 * @param g Graph to search
 * @param root Root node to begin the search. Probably "you".
 * @return std::string name of the mango seller.
 */
std::string bfs(graph_type const &g, std::string &&root) {
	queue_type q;
	list_type visited;

	list_to_queue(q, g.at(root));
	visited.emplace(root);

	while (!q.empty()) {
		auto person = q.front();
		q.pop();

		if (visited.contains(person))
			continue;
		
		if (person_is_seller(person)) {
			return person;
		} else {
			list_to_queue(q, g.at(person));
			visited.emplace(person);
		}
	}

	return "";
}

int main(void) {
	graph_type graph;

	graph["you"] = {"alice", "bob", "claire"};
	graph["alice"] = {"peggy"};
	graph["bob"] = {"anuj", "peggy"};
	graph["claire"] = {"thom", "jonny"};
	graph["anuj"] = {};
	graph["peggy"] = {};
	graph["thom"] = {};
	graph["jonny"] = {};

	std::cout << "The seller is: " << bfs(graph, "you") << std::endl;

	return 0;
}