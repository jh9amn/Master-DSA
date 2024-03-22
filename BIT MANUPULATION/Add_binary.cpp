#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string ans = "";
        
        for(int i= 0; i <= max(a.size(), b.size()) - 1; i++){
            int digit1 = (i < a.size()) ? a[i] - '0' : 0;
            int digit2 = (i < b.size()) ? b[i] - '0' : 0;
            
            int total = digit1 + digit2 + carry;
            ans += to_string(total % 2);
            carry = total /2 ;
        }
        
        // if all digit over and carry remain 1 then add it ..
        if(carry == 1){
            ans = ans + "1";
        }
        
        // after that revesre  it again 
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};


int main(){


}