#include<bits/stdc++.h>
using namespace std;
int main(){}


class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {

        unordered_set<string> st;
        for(auto it : folder){
            st.insert(it);
        }

        vector<string> ans;


        for(auto it : folder){
            for(int i=it.size()-1; i>=1; i--){
                // break into substr when '/' and check that is there any folder in it
                if(it[i] == '/'){
                    string ss = it.substr(0,i);
                    if(st.count(ss)){
                        st.erase(it);       // if found then remove that sub-folder
                        break;
                    }
                }
            }
        }

        for(auto it : st){
            ans.push_back(it);
        }
        return ans;
    }
};