#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
    vector<int> hp;

    void upHeapify(int ci){  //  ci = child Index
        while(ci>0){
            int pi = (ci-1)/2;  // for parent Index pi = (ci-1)/2
            if(hp[pi] < hp[ci]){
                swap(hp[pi], hp[ci]);
                ci = pi;
            }
            else break;
        }
    }

    void downHeapify(int idx){

        while(idx < hp.size()){
            int lc = 2*idx+1;       // for leftChild Index = 2+parentIndex +1 
            int rc = 2*idx+2;       // for rightChild Index = 2+parentIndex +2

            if(lc >= hp.size()) break;
            int maxEl = idx;
            if(hp[maxEl] < hp[lc]){
                maxEl = lc;
            }
            if(rc < hp.size() && hp[maxEl] < hp[rc]){
                maxEl = rc;
            }
            if(maxEl != idx){
                swap(hp[maxEl], hp[idx]);
                idx = maxEl;
            }
            else break;
        }
    }

    public:

    void display(){
        if(hp.size() < 0) return;
        cout<<"[";
       for(int i=0; i<hp.size(); i++){
        cout<<hp[i]<<" ";
       }
       cout<<"]\n";
    }

    int peak(){
        if(empty() == 0) return INT_MIN;
            return hp[0];
    }

    bool empty(){
        return hp.size()==0;
    }

    void push(int element){
        hp.push_back(element);
        upHeapify(hp.size()-1);
    }

    // need to check this functions
    void delOtherIdx(int RemoveIndx){
        if(RemoveIndx >= hp.size()) return;
        hp[RemoveIndx] = INT_MAX;
        upHeapify(hp.size()-1);
        swap(hp[0],hp[hp.size()-1]);
        hp.pop_back();
        if(!empty()) downHeapify(0);
    }

    void pop(){
        if(empty()) return;
        swap(hp[0],hp[hp.size()-1]);
        hp.pop_back();
        if(!empty()) downHeapify(0);
    }

};

int main(){
    MaxHeap v;
    v.push(3);
    v.push(4);
    v.push(11);
    v.push(9);
    v.push(14);
    v.push(-1);
    v.push(30);
    v.push(44);
    v.push(50);
    v.display();
    v.pop();
    v.display();
    v.pop();
    v.display();
    // v.delOtherIdx(4);
    // v.display();
}