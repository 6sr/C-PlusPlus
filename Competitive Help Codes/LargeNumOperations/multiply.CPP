#include<iostream>
#include<string>
#include<vector>
using namespace std;

string multiply(string a, string b) {
    int flag1 = 0,flag2 = 0;
    if(a[0] == '-') {
        flag1 = 1;
        a = a.substr(1);
    }
    if(b[0] == '-') {
        flag2 = 1;
        b = b.substr(1);
    }

    int n1 = a.size(),n2 = b.size(); 
    if (!n1 || !n2) {
        return "0";
    }
   
    // will keep the result number in vector in reverse order 
    vector<int> result(n1 + n2, 0);
   
    // Below two indexes are used to find positions in result
    int i1 = 0;
    int i2 = 0;

    // Go from right to left in a 
    for (int i = n1 - 1; i >= 0; i--) {
        int carry = 0;
        int n1 = a[i] - '0';

        // To shift position to left after every multiplication of a digit in b 
        i2 = 0;

        // Go from right to left in b              
        for (int j = n2 - 1;j >= 0;j--) { 
            // Take current digit of second number 
            int n2 = b[j] - '0';

            // Multiply with current digit of first number 
            // and add result to previously stored result 
            // at current position.  
            int sum = n1 * n2 + result[i1 + i2] + carry;

            // Carry for next iteration 
            carry = sum / 10; 

            // Store result 
            result[i1 + i2] = sum % 10;   
            i2++;
        }

        // store carry in next cell 
        if (carry > 0) {
            result[i1 + i2] += carry; 
        }

        // To shift position to left after every 
        // multiplication of a digit in a. 
        i1++; 
    } 
   
    // ignore '0's from the right 
    int i = result.size() - 1; 
    while (i>=0 && result[i] == 0) {
        i--;
    }

    // If all were '0's - means either both or 
    // one of a or b were '0' 
    if (i == -1) {
        return "0";
    }

    // generate the result string 
    string s = ""; 
    while (i >= 0) {
        s += to_string(result[i--]);
    }
    if(flag1 ^ flag2) {
        s = "-" + s;
    }
    return s;
}

int main() {
    string a,b;
    cin>>a>>b;
    cout<<multiply(a,b);
    return 0;
}