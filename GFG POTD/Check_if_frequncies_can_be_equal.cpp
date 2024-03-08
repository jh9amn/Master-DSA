//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    bool isEqual(vector<int> &a){
        int curr = -1;
        for(auto it : a){
            if(it == 0 ) continue;
            else if(curr == -1) curr = it;
            else if (curr != it) return false;
        }
        return true;
    }
    
    
    
	bool sameFreq(string s)
	{
	    vector<int> a(26,0);
	    for(int i=0; i<s.size(); i++){
	        a[s[i] - 'a']++;
	    }
	    
	    
	    // Firstly checking if there is no need of any charactor removable if they are in equal freq already
	    int temp = 0;
	    for(int i=0; i<26; i++){
	      if(a[i] > 0){
	          temp = a[i];
	          break;
	      }
	    }
	    
	    for(int i=0; i<26; i++){
	        if(a[i] > 0 && temp == a[i]){
	            continue;
	        }
	        if(a[i] > 0 && temp != a[i]) break;
	        
	        if(i==25) return true;
	        
	    }
	    
	    // then here checking by removing one by one charactor from the string
	    for(int i=0; i<26; i++){
            if(a[i] != 0){
                a[i]--;
                if(isEqual(a)) return true;
                a[i]++;
            }
	    }
	    return false;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends