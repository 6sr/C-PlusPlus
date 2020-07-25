
//Directed Acyclic Graph
//topological sort
#include<iostream>
#include<unordered_map>
#include<list>
#include<string>
#include<set>
#include<queue>
using namespace std;

class Graph {
    int V;
    unordered_map<string,list<string>> m;
public :
    Graph(int v) {
        V = v;
    }
    void addEdge(string ind,string dep) {
        m[ind].push_back(dep);
    }
}