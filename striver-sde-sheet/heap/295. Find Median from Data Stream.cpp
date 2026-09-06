#include<bits/stdc++.h>
using namespace std;

int main(){}


class MedianFinder {
public:
/*
even - (n/2-1 + n/2)/2
odd -  n/2

ex:  0     1    4      3     5     6     9
    --------------     ----------------------
    left max heap        rigth min heap 

** we can define two heap 
    1) left max heap 
    2) right min heap 

    - and store the vaule 
    - if the newVal is greater than leftMaxHeap.top so put it into rightMinHeap
    - and check size of rightMinHeap > leftMaxHeap, then pop and put top into leftMaxHeap
    - else newVal is less than leftMaxHeap.top then put in leftMaxHeap and check
        - if size(leftMaxHeap) + 1 > size(rightMinHeap) then
            - then insert into rightMinHeap.push(leftMaxHeap().top())  
            - leftMaxHeap.pop()
    - always keep equal or +1 elements in leftMaxHeap with rigthMinHeap
    - if both heap has same size mean even case return avg(leftMaxHeap + rightMinHeap) 
    - if odd case: return top of leftMaxHeap becasue it has more element always
    - 

*/
    priority_queue<int> lpq;    // max heaap
    priority_queue<int, vector<int>, greater<int>> rpq;     // min heap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(!lpq.empty() and num > lpq.top()) {
            rpq.push(num);
        }
        else {
            lpq.push(num);
        }

        // rightMin heap has more ele then remove it and push into left maxHeap
        if(rpq.size() > lpq.size()) {
            lpq.push(rpq.top());
            rpq.pop();
        }

        // keep always lpq.size() == rpq.size()  or  lpq.size() + 1 than rpq.size()
        else if(lpq.size() - rpq.size() > 1) {
            rpq.push(lpq.top());
            lpq.pop();
        }

    }
    
    double findMedian() {
        if(!lpq.empty() and !rpq.empty()){
            if(lpq.size() == rpq.size())
                return double(lpq.top() + rpq.top())/2;
            else return lpq.top();
        }
        return lpq.top();
    }
};
