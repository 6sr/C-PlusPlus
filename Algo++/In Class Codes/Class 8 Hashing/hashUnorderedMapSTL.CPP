#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main(int argc, char const *argv[])
{
    unordered_map<string,int> mp;
    mp.insert({"Coding",1});
    mp.insert({"Blocks",2});
    mp.insert({"Algo",3});
    mp.insert({"C++",4});
    for(unordered_map<string,int>::iterator it = mp.begin();it != mp.end();it++) {
        cout<<(*it).first<<"-->"<<(*it).second<<endl;
    }
    return 0;
}
