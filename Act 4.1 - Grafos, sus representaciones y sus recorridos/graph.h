/*
*  autor: Benjamin Valdes Aguirre
*  fecha: Diciembre 2020
*  programa: act 4.1 Implementacion Grafos
*  desc: estos programas son solciones parciales a algunos de
*  las actividades planteadas en el curso TC1031
*
*
*  Extiende este archivo para completar tu soución.
*/

#ifndef Graph_H_
#define Graph_H_

#include <string>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <set>

using namespace std;

class Graph {
    private:
		int edgesList;
		int edgesMat;
		int nodes;

		int* adjMatrix;

        vector<int>* adjList;

        // >>> student methods
        void dfs_helper(const vector<int>&, const int&, set<int>&,
                        stack<int>&, bool&);
        void bfs_helper(const vector<int>&, const int&, set<int>&,
                        queue<int>&, queue<stack<int>>&, stack<int>&,
                        bool&);
        // <<< student methods
    public:
		Graph(int);
		Graph();

		void loadGraphMat(string, int, int);
		void addEdgeAdjMatrix(int, int);
		void sortAdjList();

        // >>> student methods
        void loadGraphList(string, int, int);

        string DFS(int, int);
        string BFS(int, int);
        // <<< student methods

		string printAdjMat();
		string printAdjMat_clean();
        string printAdjList();

		bool contains(list<int>, int);
};

void Graph::bfs_helper(const vector<int>& neighboors, const int& goal,
                       set<int>& visited, queue<int>& ledger,
                       queue<stack<int>>& paths, stack<int>& path,
                       bool& found_path) {
    for (int neighboor : neighboors) {
        if (visited.find(neighboor) != visited.end()) {
            continue;
        }

        visited.insert(neighboor);
        ledger.push(neighboor);

        path.push(neighboor);
        paths.push(path);

        if (neighboor == goal) {
            found_path = true;
            return;
        }

        path.pop();
    }
}

string Graph::BFS(int start, int goal) {
    stringstream visited_and_path("");
    bool found_path = false;

    set<int> visited;
    queue<int> ledger;

    stack<int> path;
    queue<stack<int>> paths;

    visited.insert(start);
    ledger.push(start);

    path.push(start);
    paths.push(path);

    while (!ledger.empty()) {
        int node = ledger.front();
        path = paths.front();

        ledger.pop();
        paths.pop();

        bfs_helper(adjList[node], goal, visited, ledger,
                   paths, path, found_path);
        
        if (found_path) {
            break;
        }
    }

    visited_and_path << "visited:";

    for (auto it = visited.begin(); it != visited.end(); it++) {
        visited_and_path << " " << *it;
    }

    visited_and_path << " path:";

    if (found_path) {
        stringstream path_str("");

        while (!path.empty()) {
            path_str << path.top() << " ";
            path.pop();
        }

        string path_rstr = path_str.str();

        visited_and_path << string(path_rstr.rbegin(), path_rstr.rend());
    }

    return visited_and_path.str();
}

void Graph::dfs_helper(const vector<int>& neighboors, const int& goal,
                       set<int>& visited, stack<int>& path,
                       bool& found_path) {
    for (int neighboor : neighboors) {
        if (visited.find(neighboor) != visited.end()) {
            continue;
        }

        visited.insert(neighboor);
        path.push(neighboor);

        if (neighboor == goal) {
            found_path = true;
            return;
        }

        dfs_helper(adjList[neighboor], goal, visited, path, found_path);

        if (found_path) {
            return;
        }

        path.pop();
    }
}

string Graph::DFS(int from, int goal) {
    bool found_path = false;

    stringstream visited_and_path("");   
    set<int> visited;
    stack<int> path;

    visited.insert(from);
    path.push(from);

    dfs_helper(adjList[from], goal, visited, path, found_path);

    visited_and_path << "visited:";

    for (auto it = visited.begin(); it != visited.end(); it++) {
        visited_and_path << " " << *it;
    }

    visited_and_path << " path:";

    if (found_path) {
        stringstream path_str("");

        while (!path.empty()) {
            path_str << path.top() << " ";
            path.pop();
        }

        string path_rstr = path_str.str();

        visited_and_path << string(path_rstr.rbegin(), path_rstr.rend());
    }

    return visited_and_path.str();
}

void Graph::loadGraphList(string file, int nodes_, int edges) {
    edgesList = edges;
    nodes = nodes_;
    adjList = new vector<int>[nodes];

    ifstream file_stream(file);
    string file_line;

    pair<int, int> edge;

    if (file_stream.is_open()) {
        while (getline(file_stream, file_line)) {
            edge.first = stoi(file_line.substr(1,1));
            edge.second = stoi(file_line.substr(4,1));

            adjList[edge.first].push_back(edge.second);
            adjList[edge.second].push_back(edge.first);
        }
        file_stream.close();
    }
}

void Graph::loadGraphMat(string name, int a, int b){
	adjMatrix = new int [a*b];
	nodes = a;
	for (int i = 0; i < a*b; i++) {
		adjMatrix[i] = 0;
		string line;
		ifstream lee (name);
		int u, v;
		if (lee.is_open()){
			while (getline(lee, line)){
				u = stoi(line.substr(1,1));
				v = stoi(line.substr(4,1));
				addEdgeAdjMatrix(u,v);
			}
			lee.close(); // Closes the file
		} else {
			cout << "Unable to open file";
		}
    }
}

Graph::Graph() {
	edgesList = edgesMat = 0;
}

Graph::Graph(int n) {
	nodes = n;
	adjList = new vector<int>[nodes];
	adjMatrix = new int [nodes*nodes];
	for (int i = 0; i < nodes*nodes; i++)
		adjMatrix[i] = 0;
	edgesList = edgesMat = 0;
}

void Graph::addEdgeAdjMatrix(int u, int v){
	adjMatrix[u*nodes+v] = 1;
	adjMatrix[v*nodes+u] = 1;
	edgesMat++;
}

string Graph::printAdjList() {
    stringstream aux;
    for (int i = 0; i < nodes; i++) {
        aux << "vertex "
             << i << " :";

        for (int j = 0; j < adjList[i].size(); j ++){
             aux << " " << adjList[i][j];
        }

        aux << " ";
    }

    return aux.str();
}

string Graph::printAdjMat(){
	stringstream aux;
	for (int i = 0; i < nodes; i++){
	   for (int j = 0; j < nodes; j++){
			 aux << adjMatrix[i*nodes+j] << " ";
		 }
  }
	return aux.str();
}

string Graph::printAdjMat_clean(){
	stringstream aux;
	aux << "\n nodes \t|";

	for (int i = 0; i < nodes; i++) {
        aux << "\t" << i ;
	}

	aux << "\n";

	for (int i = 0; i < nodes; i++) {
        aux << "__________";
	}

	aux << "\n";

	for (int i = 0; i < nodes; i++) {
		aux << i << "\t|";

	    for (int j = 0; j < nodes; j++) {
            aux << "\t" << adjMatrix[i*nodes+j];
		}

	    aux << "\n";
    }
	return aux.str();
}

#endif /* Graph_H_ */
