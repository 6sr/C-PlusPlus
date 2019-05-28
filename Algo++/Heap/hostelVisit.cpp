//Manal
//Dean of MAIT is going to visit Hostels of MAIT. As you know that he is a very busy person so he decided to visit only 
//first "K" nearest Hostels. Hostels are situated in 2D plane. You are given the coordinates of hostels and you have to answer
//the Rocket distance of Kth nearest hostel from origin ( Dean's place ) .

#include <bits/stdc++.h>
#define lli long long int
using namespace std;

lli rocketDistance(lli x,lli y){
    return x*x+y*y;
}

int main(){
    lli x,y,q,k,type;
    priority_queue<lli> pq;
    cin>>q>>k;
    for(lli i=0;i<q;i++){
        cin>>type;
        if (type == 1){
            cin>>x>>y;
            if (pq.size() == k){
                if (rocketDistance(x,y) < pq.top() ){
                    pq.pop();
                    pq.push(rocketDistance(x,y));
                }
            }
            else{
                pq.push(rocketDistance(x,y));
            }
        }
        else{
            cout<<pq.top()<<endl;
        }
    }
    return 0;
}
