
//Adjacency list
#include<iostream>
#include<unordered_map>
#include<list>
#include<string>
#include<set>
#include<queue>
using namespace std;

//Singly linked list --> forward_list
//Doubly Linked List --> list

class GraphMe {
    int V;
    unordered_map<string,list<string>> m;
public :
    GraphMe(int v) {
        V = v;
    }
    void addEdge(string src,string dest,bool bidir = true) {
        m[src].push_back(dest);
        if(bidir) {
            m[dest].push_back(src);
        }
    }
    void print() {
        for(auto p : m) {
            string src = p.first;
            auto cities = p.second;

            cout<<src<<" --> ";
            for(auto city : cities) {
                cout<<city<<",  ";
            }
            cout<<endl;
        }
    }
    void printLevel(set<string> &s,string src) {
        if(m[src].empty()) {
            return;
        }
                if(s.find(src) == s.end()) {
                cout<<src<<" ";
                    s.insert(src);
                }
        for(auto city : m[src]) {
            
            //for(auto city : p) {
                if(s.find(city) == s.end()) {
                cout<<city<<" ";
                    s.insert(city);
                    printLevel(s,city);
                }
            }
    }
};

class GraphSir {
    int V;
    unordered_map<string,list<string>> m;
public :
    GraphSir(int v) {
        V = v;
    }
    void dfsHelper(string node,unordered_map<string,bool> &visited) {
        cout<<node<<" ";
        visited[node] = true;
        for(auto child : m[node]) {
            if(!visited[child]) {
                dfsHelper(child,visited);
            }
        }
    }

    void dfsTraversal(string src) {
        unordered_map<string,bool> visited;
        dfsHelper(src,visited);
    }

    void bfsTraversal(string src) {
        queue<string> q;
        unordered_map<string,bool> visited;
        q.push(src);
        visited[src] = true;
        while(!q.empty()) {
            string city = q.front();

            //children of curr node
            for(auto child : m[city]) {
                if(!visited[child]) {
                    q.push(child);
                    visited[child] = true;

                }
            }
        }
    }

    void bfsShortest(string src,string dest) {
        queue<string> q;
        string ans[100];
        unordered_map<string,bool> visited;
        unordered_map<string,string> parent;
        q.push(src);
        visited[src] = true;
        int pathLen[100] = {0};
        int min = 0;
        ans[0] = src;
        int i = -1;
        while(!q.empty()) {
            string city = q.front();
            if(city == src) {
                cout<<"\n0 Distance away";
                cout<<"\n"<<src<<endl;
                break;
            }

            if(pathLen[i] < min) {
                min = pathLen[i];
            }
            //children of curr node
            for(auto child : m[city]) {
                i++;
                if(!visited[child]) {
                    ans[++pathLen[i]] = child;
                    q.push(child);
                    visited[child] = true;
                }
            }
        }
    }

};

int main() {
    GraphMe g(5);
    set<string> s;

    g.addEdge("Delhi","Amritsar");
    g.addEdge("Delhi","Jaipur");
    g.addEdge("Delhi","Bhopal");
    g.addEdge("Delhi","Lucknow");
    g.addEdge("Jaipur","Amritsar");
    g.addEdge("Jaipur","Bhopal");
    g.addEdge("Mumbai","Bhopal");
    g.addEdge("Mumbai","Pune");
    g.print();
    g.printLevel(s,"Delhi");
    return 0;
}