#pragma once
#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef int vertex_t;



typedef int32_t vertex_t;

class AbstactGraph {
public:
	virtual void input() = 0;
	virtual void print() const = 0;

public:
	int vertexes_number = 0;
	int edges_number = 0;
};



class Graph_type1 : public AbstactGraph {
public:

	void input() override
	{
		cout << "Number of Vertexes: ";
		cin >> vertexes_number;
		cout << "Number of Edges: ";
		cin >> edges_number;

		set_of_edges.clear();
		for (int i = 0; i < edges_number; i++) {
			cout << i << " edge: ";
			vertex_t a, b;
			cin >> a >> b;
			set_of_edges.insert(make_pair(a, b));
		}
	}

	void print() const override
	{
		cout << '\n';
		cout << "Vertexes: " << vertexes_number << endl;
		cout << "Edges: " << edges_number << endl;
		for (auto& edge : set_of_edges) {
			cout << '(' << edge.first << "," << edge.second << ") ";
		}
		cout << '\n';
	}

private:
	set<pair<vertex_t, vertex_t>> set_of_edges;
};





class Graph_type2 : public AbstactGraph {
public:

	void input() override
	{
		cout << "Number of Vertexes: ";
		cin >> vertexes_number;

		matrix.resize(vertexes_number);
		for (auto& line : matrix) {
			line.resize(vertexes_number, false);
		}

		cout << "Number of Edges: ";
		cin >> edges_number;

		for (int i = 0; i < edges_number; i++) {
			cout << i << " edge: ";
			vertex_t a, b;
			cin >> a >> b;
			matrix[a][b] = 1;
			matrix[b][a] = 1;
		}
	}

	void print() const override
	{
		cout << '\n';
		cout << "Vertexes: " << vertexes_number << endl;
		cout << "Edges: " << edges_number << endl;
		for (auto vec : matrix) {
			for (auto vertex : vec) {
				cout << vertex << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}

private:
	vector<vector<bool>> matrix;
};




class Graph_t {
public:
	void input()
	{
		cout << "vertexes: ";
		cin >> vertexes_number;
		cout << "edges: ";
		cin >> edges_number;
		set_of_neightbours.clear();
		set_of_neightbours.resize(vertexes_number);
		for (int i = 0; i < edges_number; i++) {
			vertex_t a, b;
			cout << "edge: ";
			cin >> a >> b;
			set_of_neightbours[a].insert(b); // у вершины а - сосед b
			set_of_neightbours[b].insert(a); // у вершины b - сосед a
		}
	}
	void print()
	{
		cout << "\nVertexes - " << vertexes_number << endl;
		cout << "Edges - " << edges_number << '\n' << endl;

		for (int vertex = 0; vertex < vertexes_number; vertex++) {
			cout << vertex << ": [";
			for (auto& neightbor : set_of_neightbours[vertex]) {
				cout << neightbor << ", ";
			}
			cout << "\b\b]\n";
		}
	}


	int vertexes_number = 0; // вершины
	int edges_number = 0; // рёбра
	vector<set<vertex_t>> set_of_neightbours; // списки смежности для каждой вершины графа
};



class OrGraph_t { // Ориентированный
public:
	void input()
	{
		cout << "vertexes: ";
		cin >> vertexes_number;
		cout << "edges: ";
		cin >> edges_number;
		set_of_neightbours.clear();
		set_of_neightbours.resize(vertexes_number);
		for (int i = 0; i < edges_number; i++) {
			vertex_t a, b;
			cout << "edge: ";
			cin >> a >> b;
			set_of_neightbours[a].insert(b); // у вершины а - сосед b
		}
	}
	void print()
	{
		cout << "\nVertexes - " << vertexes_number << endl;
		cout << "Edges - " << edges_number << '\n' << endl;

		for (int vertex = 0; vertex < vertexes_number; vertex++) {
			cout << vertex << ": [";
			for (auto& neightbor : set_of_neightbours[vertex]) {
				cout << neightbor << ", ";
			}
			cout << "\b\b]\n";
		}
	}


	int vertexes_number = 0; // вершины
	int edges_number = 0; // рёбра
	vector<set<vertex_t>> set_of_neightbours; // списки смежности для каждой вершины графа
};

