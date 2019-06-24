/*
 Algorithm
 We rotate the array of initial board - 1,2,4,8,16,......,2^(n-1) => See bit form to visualise the board where 1 shows presence of queen
 1 => 2,4,8,16,.......,2^(n-1),1	-> initial helper
 2 => insert 2 in board	then rotate again => 8,16,......1,4
 3 => insert 8 in board	then rotate again => 32,64,....1,4,16

 Do this for i = 0 to i < (n+1)/2	-> by inspection
 In below code we iterate till (n-1)/2 as 1st case is done separately
 lol
*/

#include<iostream>
#include<queue>
#include<stack>
#include<cmath>

#include<bitset>	//cout<<bitset<8>(n).to_string();

using namespace std;

void printBitForm(int n,int numBits) {
	if(n >= pow(2,numBits)) {
		cout<<"Not possible";
		return;
	}
	stack<int> curr;
	for(int i = 0;i < numBits;i++) {
		curr.push(n % 2);
		n /= 2;
	}
	for(int i = 0;i < numBits;i++) {
		cout<<curr.top()<<" ";
		curr.pop();
	}
}

int main() {
	queue<int> board,helper;
	int n;
	char ans = 'y';
	while (ans == 'y' || ans == 'Y') {
		while (true) {
			cout<<"Enter n for N-Queen (n > 3) : ";
			cin>>n;
			if(n > 3)
				break;
			cout<<"n should be greater than 3";
		}

		for(int i = 1;i < n;i++) {
			helper.push(pow(2,i));
		}
		helper.push(1);
		for(int i = 0 ; i < (n - 1) / 2 ; i++) {
			board.push(helper.front());
			helper.pop();
			int curr = helper.front();
			helper.pop();
			helper.push(curr);
		}
		while (!helper.empty()) {
			board.push(helper.front());
			helper.pop();
		}
		
		while (!board.empty()) {
			int curr = board.front();
			board.pop();
			printBitForm(curr,n);	//cout<<bitset<8>(n).to_string();
			cout<<endl;
		}
		cout<<"Do you want to continue (y/n) : ";
		cin>>ans;
	}
	return 0;
}
