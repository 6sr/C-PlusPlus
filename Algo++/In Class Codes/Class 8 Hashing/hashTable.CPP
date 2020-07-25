#include<iostream>
#include"hashtable.h"
using namespace std;

int main() {
    Hashtable h;
    h.insert("Apple",100);
    h.insert("Mango",90);
    h.insert("Banana",80);
    h.insert("Cherry",70);
    h.insert("Orange",60);
    h.insert("Kiwi",50);
    
    cout<<"Value of Kiwi by search : "<<h.search("Kiwi");
    cout<<endl<<"Value of Papaya by search : "<<h.search("Papaya");
    h["Papaya"] = 40;
    cout<<"\nValue of papaya by [] : "<<h["Papaya"]<<endl;
    h.print();
    
    return 0;
}