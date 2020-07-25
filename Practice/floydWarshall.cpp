// Input graph taken from here - 
// https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/

// The Floyd Warshall Algorithm is for solving the All Pairs Shortest Path problem.
// The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph.

#include<iostream>
using namespace std;

const int V = 4; 

#define INF INT16_MAX

void printFloydWarshall(int graph[][V]) {
    for(int i = 0;i < V;i++) {
        for(int j = 0;j < V;j++) {
            if(graph[i][j] == INF) {
                cout<<"INF ";
                continue;
            }
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

void floydWarshall(int graph[][V]) {
    int tempGraph[V][V];
    for(int i = 0;i < V;i++) {
        for(int j = 0;j < V;j++) {
            tempGraph[i][j] = graph[i][j];
        }
    }

    for(int k = 0;k < V;k++) {
        for(int i = 0;i < V;i++) {
            for(int j = 0;j < V;j++) {
                if(tempGraph[i][k] + tempGraph[k][j] < tempGraph[i][j]) {
                    tempGraph[i][j] = tempGraph[i][k] + tempGraph[k][j];
                }
            }
        }
    }
    printFloydWarshall(tempGraph);
}

int main() {

    int graph[V][V] = { 
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };
    floydWarshall(graph);
    return 0;
}
