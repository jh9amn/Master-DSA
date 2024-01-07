 #include<bits/stdc++.h>
 using namespace std;
 int f(string &s,int i, int n){
      if(i == n) return 1;
    //   if(s.size() >= 0) return 0;
      
    //   int maxi = INT_MIN;
    //   for(int j=0; j<s.size(); j++) {
    //       if(max < s[j]) maxi = s[j];
    //   }
    //   unordered_map<int,int> mp;
    //   for(int j=0; j<s.size(); j++){
    //       mp[s[j]]++;
    //   }
    //   for(int j=0; j<s.size(); j++){
    //       if(maxi < mp[j] ) return 0;
    //   }
      
      int res = 0;
      for(int k=0; k<n; k++){
          res = f(s,i,k) + f(s,k+1,n);
      }
      return res;
  }
  
int c(string &s)
{
      int n = s.size();
      return f(s,0,n);
}

int main(){
    string s = "122321";
    cout<<c(s);
}