#include<bits/stdc++.h>
using namespace std;
int main() {
    int test, a, b, x, y;
    cin>>test;
    
    while(test--)  {
        cin>>a>>b>>x>>y;
        // a much greater then b 
        if (b <= a-2) {
            cout<<-1<<endl;
        }
         
        else {
            if(b == a-1) {
                if((a^1) == b) cout<<y<<endl;
                else cout<<-1<<endl;
            }
            else if(a == b) {
                cout<<0<<endl;
            }
            
            else {
                // b-1 > a
                int t = b - a;
                int evenCnt = 0, oddCnt = 0;
                if(t % 2 == 1) {
                    // a == odd
                    // odd ->>> even start and so even count is more
                    if(a % 2 == 1){
                         evenCnt = (t+1) / 2;
                         oddCnt = t / 2;
                    }
                    // a == even
                    // even ->>> odd start and so odd count is more
                    else {
                        oddCnt = (t+1) / 2;
                        evenCnt = t / 2;
                    }
                    
                }
                // evenCnt == oddCnt == (b-a) / 2;
                else {
                    oddCnt = t / 2;
                    evenCnt = t / 2;
                }
                cout<<(evenCnt * x) + (oddCnt * min(x,y))<<endl;
            }
        }
    }
    return 0;
}