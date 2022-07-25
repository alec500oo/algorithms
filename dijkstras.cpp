/* dijkstras.cpp */

#include <iostream>
#include <map>
#include <unordered_set>
#include <stack>

constexpr auto NO_NODE = "";

using node_type = std::map<std::string, int>;
using graph_type = std::map<std::string, node_type>;

// use 9999 for "inf"
constexpr auto INF = 9999;
using cost_type = std::map<std::string, int>;

using parent_type = std::map<std::string, std::string>;

using visited_type = std::unordered_set<std::string>;

std::string find_lowest_cost_node(cost_type const &costs,
	visited_type const &visited) {
	auto lowest_cost = INF;
	std::string lowest_cost_node = NO_NODE;

	for (auto c : costs) {
		if (c.second < lowest_cost && !visited.contains(c.first)) {
			lowest_cost = c.second;
			lowest_cost_node = c.first;
		}
	}

	return lowest_cost_node;
}

int do_dijkstras(graph_type const &graph, cost_type &costs,
	parent_type &parents) {
	visited_type visited;

	auto node = find_lowest_cost_node(costs, visited);
	while (node.compare(NO_NODE) != 0) {
		auto cost = costs[node];
		auto neighbors = graph.at(node);
		for (auto &n : neighbors) {
			auto new_cost = n.second + cost;
			if (costs[n.first] > new_cost) {
				costs[n.first] = new_cost;
				parents[n.first] = node;
			}
		}
		visited.insert(node);
		node = find_lowest_cost_node(costs, visited);
	}
	return costs["fin"];
}

std::string path(parent_type const &parents) {
	std::string out;
	std::stack<std::string> s;

	std::string node = "fin";
	s.push(node);
	while (node.compare("start") != 0) {
		node = parents.at(node);
		s.push(node);
	}

	out += s.top();
	s.pop();
	do
	{
		out += " -> " + s.top();
		s.pop();
	} while (!s.empty());

	return out;
}

int main(void) {
	graph_type graph;
	cost_type costs;
	parent_type parents;


	graph["start"] = {{"A", 6}, {"B", 2}};
	graph["A"] = {{"fin", 1}};
	graph["B"] = {{"A", 3}, {"fin", 5}};
	graph["fin"] = {};

	costs["A"] = 6;
	costs["B"] = 2;
	costs["fin"] = INF;

	parents["A"] = "start";
	parents["B"] = "start";
	parents["fin"] = "";

	auto cost = do_dijkstras(graph, costs, parents);

	std::cout
		<< "The path is: " << path(parents) << std::endl
		<< "With a cost of: " << cost << std::endl;
	return 0;
}