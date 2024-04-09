#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // T.C = O(n)  S.C= O(1)
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int count = 0;
        int i = 0;
        int n = tickets.size();
        while(tickets[k] != 0 && i < n){
            if(tickets[i] > 0) {
                tickets[i]--;
                count++;
            }
            else if(tickets[i] == 0){
                continue;
            }
            
            i++;
            if(i == n && tickets[k] != 0) i = 0;
        }
        return count;
    }
};



int main(){

}