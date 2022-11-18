#include <iostream>
#include <set>
#include <deque>
#include <vector>

#include "graph.h"

using namespace std;



// Проход графа в глубину
void DFS(const Graph_t& graph, vertex_t start, vector<bool>& used)
{
	used[start] = true;
	cout << start << ' '; 
	set<vertex_t> neighbour_set = graph.set_of_neightbours[start];
	for (auto& neighbour : neighbour_set) {
		if (!used[neighbour]) {
			DFS(graph, neighbour, used);
		}
	}
}

// Проход графа в ширину
void BFS(const Graph_t& graph, vertex_t start, vector<bool>& used)
{
	used[start] = true;
	deque<vertex_t> fired;
	fired.push_back(start);

	while (not fired.empty()) {
		vertex_t current = fired.front();
		fired.pop_front();
		auto neighbour_list = graph.set_of_neightbours[current];
		for (auto neighbour : neighbour_list) {
			if (not used[neighbour]) {
				used[neighbour] = true;
				fired.push_back(neighbour);
				cout << neighbour << ' ';
			}
		}
	}
}




// Проверка графа на ацикличность (вернет true - если нет цикла) для неориентированного графа 
bool check_DAG(const OrGraph_t& graph, vertex_t start, vector<bool>& used, vertex_t prev = 0)
{
	set<vertex_t> neighbour_set = graph.set_of_neightbours[start];
	for (auto& neighbour : neighbour_set) {
		if (neighbour == prev) {
			used[start] = true;
			continue;
		}

		if (used[neighbour]) return false;

		if (not check_DAG(graph, neighbour, used, start)) return false;
	}
	return true;
}





int main()
{


	OrGraph_t g1;
	g1.input();
	g1.print();

	vector<bool> used(g1.vertexes_number, false);
	bool is_DAG = true;
	for (vertex_t v = 0; v < g1.vertexes_number; v++) {
		if (used[v]) continue;
		if (not check_DAG(g1, v, used)) {
			is_DAG = false;
			break; 
		}
	}
	if (is_DAG) {
		cout << "Acyclic graph" << endl;
	}
	else {
		cout << "Cyclic graph" << endl;
	}
}

//class Timer {
//public:
//	Timer() {
//		start = chrono::high_resolution_clock::now();
//	}
//
//	~Timer()
//	{
//		end = chrono::high_resolution_clock::now();
//		cout << "DURATION " << chrono::duration<float>(end - start).count() << endl;
//	}
//	
//private:
//	chrono::steady_clock::time_point start;
//	chrono::steady_clock::time_point end;
//};



