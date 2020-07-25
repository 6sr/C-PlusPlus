#include<iostream>
#include<string>
using namespace std;
class Node {
public : 
    string key;
    int value;
    Node* next;
    Node(string k,int v) {
        key = k;
        value = v;
        next = NULL;
    }
    ~Node() {
        if(next != NULL) {      //Checking base case
            delete next;        //Rec Case
            //Recursive destructor to avoid memory leak
        }
    }
};

class Hashtable {
    int cs;     //No of nodes
    int ts;     //table size
    Node**table;

    int hashFn(string key) {
        int idx = 0;
        int p = 1;
        for(int i = 0;i < key.length();i++) {
            idx = (idx + (p * key[i]) % ts) % ts;
            p = (p * 37) % ts;
        }
        return idx % ts;
    }

    void resize() {
        Node**oldTable = table;
        table = new Node*[2 * ts];
        //Initialize new table
        for(int i = 0;i < 2 * ts;i++) {
            table[i] = NULL;
        }
        int oldTs = ts;
        ts = 2 * ts;
        cout<<"ts : "<<ts;
        //Iterate over old table and insert elements in new table
        for(int i = 0;i < oldTs;i++) {
            Node*temp = oldTable[i];
            int idx = hashFn(temp->key);
            while(temp != NULL) {
                insert(temp->key,temp->value);
                temp = temp->next;
            }
            delete oldTable[i];
            /*
            Node*temp = oldTable[i];
            int idx = hashFn(temp->key);
            temp->next = table[idx];
            table[idx] = temp;
            cs++;
            */
        }
        delete[] oldTable;
    }
public : 
    Hashtable(int ds = 7) {
        ts = ds;
        table = new Node*[ts];
        //Create and initialize table
        for(int i = 0;i < ts;i++) {
            table[i] = NULL;
        }
        cs = 0;
    }

    void insert(string key,int value) {
        int idx = hashFn(key);
        Node * n = new Node(key,value);
        n->next = table[idx];
        table[idx] = n;
        cs++;
        float loadFactor = float(cs) / float(ts);
        if(loadFactor > 0.7) {
            resize();
        }
    }

    int search(string key) {
        int idx = hashFn(key);
        Node*temp = table[idx];
        while(temp!=NULL) {
            if(temp->key == key) {
                return temp->value;
            }
            temp = temp->next;
        }
        return -1;
    }

    int& operator[](string key) {
        int f = search(key);
        if(f == - 1) {
            int v;
            insert(key,v);
        }
        int idx = hashFn(key);
        Node*temp = table[idx];
        while(temp!=NULL) {
            if(temp->key == key) {
                return temp->value;
            }
        }
    }

    void remove(string key) {
        //HW......


    }

    void print() {
        for(int i = 0;i < ts;i++) {
            cout<<"Bucket "<<i<<"-->";
            Node *temp = table[i];
            while(temp != NULL) {
                cout<<temp->key<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }
};