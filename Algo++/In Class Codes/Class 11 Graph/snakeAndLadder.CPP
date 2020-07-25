
//Adjacency list
#include<iostream>
#include<unordered_map>
#include<list>
#include<string>
#include<set>
#include<queue>
using namespace std;

class Graph {
    int V;
    list<int> *l;
public :
    Graph(int v) {
        V = v;
        l = new list<int>[v + 1];
    }
    void addEdge(int curr,int jumpTo) {
        l[curr].push_back(jumpTo);
    }
    void BFS(int s) {
        bool *visited = new bool[V]{0};
        q.push(s);
        visited[s] = true;
        for(auto nbr_cell : l[f]) {

        }

    }
};