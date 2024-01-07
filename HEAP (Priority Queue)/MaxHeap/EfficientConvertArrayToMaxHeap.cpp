#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class MaxHeap{
    vector<int> hp;
    void upHeapify(int ChlidIdx){
        while(ChlidIdx > 0){
            int ParentIdx = (ChlidIdx-1)/2;
            if(hp[ParentIdx] < hp[ChlidIdx]) { 
            swap(hp[ParentIdx] , hp[ChlidIdx]);
            ChlidIdx = ParentIdx;
            }
            else break;
        }
    }

    void downHeapify(int idx){
        while(idx < hp.size()){
            int lc = 2*idx+1;       // for leftChild Index = 2+parentIndex +1 
            int rc = 2*idx+2;       // for rightChild Index = 2+parentIndex +2

            if(lc >= hp.size()) break;
            int maxEleIdx = idx;
            if(hp[maxEleIdx] < hp[lc]){
                maxEleIdx = lc;
            }
            if(rc < hp.size() && hp[maxEleIdx] < hp[rc]){
                maxEleIdx = rc;
            }
            if(maxEleIdx != idx){
                swap(hp[maxEleIdx], hp[idx]);
                idx = maxEleIdx;
            }
            else break;
        }
    }

    public:
            void display(){
                cout<<"{";
                    for(int i=0; i<hp.size(); i++){
                        cout<<hp[i]<<" ";
                    }
                cout<<"}\n";
            } 

            void push(int element){
                hp.push_back(element);
                upHeapify(hp.size()-1);
            }

        MaxHeap(vector<int> v){
            /**
             Time Comlexity : O(n)   most optimized
            */
                hp = v;
                int n = hp.size();
                for(int i=n/2; i>=0; i--){  // because The Leaf Nodes Are Already a heap(Every Subheap is a Heap)
                    downHeapify(i);
                }
        }
};

int main(){ 
    vector<int> vec = { 9, 6, 1, 19, 3, 2, 8, 12, 5 };  // { 19 12 8 9 3 1 2 6 5  }
    MaxHeap hp(vec);        
    hp.display();
    hp.push(100);
    hp.display();
}