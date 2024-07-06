#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        int i = 1;
        int flag = true;
        while (time--) {
            if (flag == false) {
                i--;
                if(i == 1) flag = true;
            }
            else {
                i++;
                if(i == n) flag = false;
            }
        }
        return i;
    }
};

int main(){

}
