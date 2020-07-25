// Input graph taken from here - 
// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
// Given a graph and a source vertex in the graph, find shortest paths from source to all vertices in the given graph.

#include<iostream>
using namespace std;
const int V = 9;

int getMinKey(int key[], bool isPresent[]) {
    int min = INT16_MAX, minIdx = -1;
    for(int i =0;i < V;i++) {
        if(isPresent[i] == false && key[i] <= min) {
            min = key[i];
            minIdx = i;
        }
    }
    return minIdx;
} 

void printDijkstras(int key[]) {
    for(int i = 0;i < V;i++) {
        cout<<i<<" "<<key[i]<<endl;
    }
}

void dijkstras(int graph[][V]) {
    int key[V];
    bool visited[V];
    for(int i = 0;i < V;i++) {
        visited[i] = false;
        key[i] = INT16_MAX;
    }
    key[0] = 0;
    for(int i = 0;i < V - 1;i++) {
        int u = getMinKey(key, visited);
        visited[u] = true;
        for(int j = 0;j < V;j++) {
            if(graph[u][j] && visited[j] == false && key[u] < INT16_MAX && graph[u][j] + key[u] < key[j]) {
                key[j] = graph[u][j] + key[u];
            }
        }
    }
    printDijkstras(key);
}



int main() {
    cout<<"LOL"<<endl;
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0}, 
        {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
        {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
        {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
        {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
        {0, 0, 4, 14, 10, 0, 2, 0, 0}, 
        {0, 0, 0, 0, 0, 2, 0, 1, 6}, 
        {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
        {0, 0, 2, 0, 0, 0, 6, 7, 0} 
    }; 
    dijkstras(graph);
    return 0;
}
