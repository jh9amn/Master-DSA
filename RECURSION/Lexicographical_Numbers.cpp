class Solution {
public:
    void f(int i,int n, vector<int> &v){
        if(i > n) return ;
        if( i <= n && i != 0 ) v.push_back(i);

        if(i!=0){
            for(int j=0; j<=9; j++){
                f(10*i+j,n,v);
            }
        }
        else {
            for(int j=1; j<=9; j++){
                f(10*i+j,n,v);
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> v;
        f(0,n,v);
        return v;
    }
};

int main(){
    Solution s;
    cout<<s.f(0,5);
}