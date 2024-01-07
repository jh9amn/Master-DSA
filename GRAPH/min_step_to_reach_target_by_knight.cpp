// https://www.codingninjas.com/studio/problems/minimum-steps-to-reach-target-by-a-knight_893050

// INCOMPLETE
#include<bits/stdc++.h>
using namespace std;
int minSteps(pair<int, int> k, pair<int, int> t, int n) {
    if(k.first == t.first && k.second == t.second) return 0;
    vector<vector<int>> grid(n+1,vector<int>(n+1,0));
    vector<vector<bool>> vis(n+1,vector<bool>(n+1,false));
    int knightrow = k.first;
    int knightcol = k.second;
    int targetrow = t.first;
    int targetcol = t.second;
   
    
    vis[knightrow][knightcol] = true;
    queue<pair<pair<int,int>,int>> q;
    int step = 0;
    q.push({{knightrow,knightcol},0});
   
    vector<pair<int,int>> direction{{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int s = q.front().second;
        
        q.pop();
        // for traversing into eight direction 
        for(auto it : direction){   
            int newr = r + it.first;
            int newc = c + it.second;
            
            if(newr == targetrow && newc == targetcol)  return s+1;


            if((newr >= 0 && newr < n && newc >= 0 && newc < n) &&
            vis[newr][newc] == false && (newr != targetrow && newc != targetcol)){
                vis[newr][newc] = true;
                q.push({{newr,newc},s+1});
                grid[newr][newc] = q.front().second;
            }
        }  
    } 
}


int main(){
    int n;
    cin>>n;
    int size;
    pair<int , int> k;
    pair<int, int> t;
    while(n--){
        cin>>size;
        int x,y,a,b;
        cin>>x>>y;
        k.first = x;
        k.second = y;
        cin>>a>>b;
        t.first = a;
        t.second = b;
    }

    cout<<minSteps(k,t,size);

}

/*
2
8
2 1
8 5
6
4 5
1 1


74 19
18 1

output
4
3



not workin testcase
50
100
9 84
52 8
100
15 24
83 15
100
19 67
27 97
100
25 6
58 3
100
29 49
45 85
100
32 47
89 66
100
35 90
32 48
100
42 29
64 54
100
45 72
51 36
100
48 13
95 61
100
51 12
82 42
100
58 97
13 5
100
61 95
57 30
100
64 36
44 12
100
68 79
88 94
100
74 19
18 1
100
78 61
63 82
100
81 59
50 63
100
84 1
94 44
100
87 43
81 70
100
94 84
11 32
100
97 25
56 58
100
100 24
43 39
100
3 66
87 20
100
9 6
17 27
100
12 48
62 8
100
16 91
49 91
100
19 89
93 72
100
26 73
23 79
100
29 71
10 60
100
35 55
42 67
100
39 54
86 48
100
42 96
29 29
100
48 36
60 36
100
52 78
48 17
100
55 20
92 99
100
61 61
22 5
100
65 2
9 87
100
68 1
53 69
100
71 43
41 94
100
75 85
85 75
100
81 25
15 38
100
84 67
59 63
100
88 66
46 45
100
94 50
78 7
100
97 48
21 32
100
1 90
8 14
100
3 32
52 96
100
9 73
84 2
100
13 14
27 84

*/