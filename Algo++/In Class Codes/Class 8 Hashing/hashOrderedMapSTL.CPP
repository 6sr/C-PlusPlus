#include<iostream>
#include<map>
#include<string>
using namespace std;

int main() {
    map<string,int> mp;
    mp.insert({"Coding",1});
    mp.insert({"Blocks",2});
    mp.insert({"Algo",3});
    mp.insert({"C++",4});
    for(map<string,int>::iterator it = mp.begin();it != mp.end();it++) {
        cout<<(*it).first<<"-->"<<(*it).second<<endl;
    }
    return 0;
}
