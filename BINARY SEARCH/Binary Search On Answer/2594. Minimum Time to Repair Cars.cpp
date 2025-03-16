#include<bits/stdc++.h>
using namespace std;
int main(){}


class Solution {
public:
    typedef long long ll;
    // TC = O(n)
    bool isAllCarsRepairPossible(vector<int> &ranks, ll mid, int cars ) {
        ll carsCanRepair = 0;
        for(int i=0; i<ranks.size(); i++) {
            carsCanRepair += sqrt(mid/ranks[i]);
        }
        return carsCanRepair >= cars;
    }
    
    long long repairCars(vector<int>& ranks, int cars) {
        int maxi_rank = *max_element(begin(ranks), end(ranks));
        ll l = 0;
        ll h = 1LL * maxi_rank * cars * cars;
        
        ll ans = -1;
        // T.C = O(log(maxi_rank * cars * cars))
        while(l <= h) {
            ll mid = l + (h-l) / 2;
            if(isAllCarsRepairPossible(ranks, mid, cars)){
                ans = mid;
                // then try to more minimize the ans
                h = mid-1;
            }
            else {
                // All cars repair not possible in this max time..
                // maximize the time..
                l = mid + 1;
            }
        }
        return ans;
    }
};


/*
* There are so many case passible for cars distribution..
    The cars distribution can be like : 
        10 : 2  2  2  4 or
        10 : 3  3  3  1 or
        10 : 2  4  2  2 or
        10 : 1  2  3  4 ....


* In all of these we have to find the time in that any cars distribution case, all the cars must be repaired
* 1st CASE: 10 -> 2  2  2  4
    the time is as -> 4 * (2*2) = 16
                   -> 2 * (2*2) = 8
                   -> 3 * (2*2) = 12
                   -> 1 * (4*4) = 16

* So, in the 16th minute the whole cars done by the mechanics.

* 2nd CASE: 10 -> 3  3  3  1
    the time is as -> 4 * (3*3) = 36
                   -> 2 * (3*3) = 18
                   -> 3 * (3*3) = 27
                   -> 1 * (1*1) = 1

* So, in the 36th minute the whole cars done by the machanics.

Answer = min(16, 32 ....);

* NOTE: 
time = rank * (cars * cars)
cars = sqrt(time / rank);

* Out of all these case we have to find the minimum time required to repaired all the cars by mechanics. ***
* In simple word, Apply binary search in every case answers.

 Total TC = O(log(maxi_rank * cars * cars)) * O(n)

*/
