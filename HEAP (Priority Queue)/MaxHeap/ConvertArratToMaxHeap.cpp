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

    void downHeapify(int i){
        while(i<hp.size()){
            int LeftchildIdx = 2*i+1;
            int RightChildIdx = 2*i*+2; 
            int maxEl = i;
            if(hp[maxEl] < hp[LeftchildIdx]) i = LeftchildIdx;
            if(hp[maxEl] < hp[RightChildIdx]) {
                maxEl = RightChildIdx;
            }
            if(maxEl != i){
                swap(hp[maxEl] , hp[RightChildIdx]);
                i = maxEl;
            }
            else break;
        }
    }


    public:
            void display(){
                cout<<"{ ";
                    for(int i=0; i<hp.size(); i++){
                        cout<<hp[i]<<" ";
                    }
                cout<<" }\n";
            } 

            bool empty(){
                return hp.size()==0 ;
            }


            void push(int element){
                hp.push_back(element);
                upHeapify(hp.size()-1);
            }

        MaxHeap(vector<int> v){
            /*
            T.C = O(nlogn)
            */
                hp = v;
                for(int i=0; i<hp.size(); i++){
                    upHeapify(i);
                }
        }
};

int main(){
    vector<int> vec = {  9, 6, 1, 19, 3, 2, 8, 12, 5 };   
    MaxHeap hp(vec);
    hp.display();
    hp.push(100);
    hp.display();
}