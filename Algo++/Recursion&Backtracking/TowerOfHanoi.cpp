//Using a helper stick (peg), shift all rings from peg A to peg B using peg C.
//All rings are initally placed in ascending order, smallest being on top.
//No bigger ring can be placed over a smaller ring.

#include<iostream>
using namespace std;

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
  if (n == 1) {
    cout<<"Moving ring "<<n<<" from "<<from_rod<<" to "<<to_rod<<endl;
    return;
  }
  towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
  cout<<"Moving ring "<<n<<" from "<<from_rod<<" to "<<to_rod<<endl;
  towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}

int main() {
    int n;
    cin>>n;
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}
