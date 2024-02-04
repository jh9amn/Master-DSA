// #include<bits/stdc++.h>
// using namespace std;

// // https://www.codingninjas.com/studio/problems/ninja-s-training_3621003?leftPanelTabValue=PROBLEM

// // Memoization Tc = O(n*4*3)  Sc = O(n)+ O(n*4)
// int fm(int days, vector<vector<int>> &v, int prevTask, vector<vector<int>> &dp){
//     // if u reach idx = 0 which is equal to days = 1 then u have return 
//     // the max (v[index]) where index != prevtask index..
//     if(days == 0) {
//         int maxi = 0;  // there is only three task
//         for(int task=0; task<3; task++){
//             if( task != prevTask) {
//                 maxi = max(maxi,v[0][task]);
//             }
//         }
//         return maxi;
//     }

//     if(dp[days][prevTask] != -1) return dp[days][prevTask];

//     int maxi = 0;
//     for (int task = 0; task < 3; task++) {
//         if( task != prevTask) {
//             int totalPoint = v[days][task] + fm(days-1, v, task, dp);
//             maxi = max(maxi,totalPoint);
//         }
//     }
//     return  dp[days][prevTask] = maxi;
// }



// // Tabulation       Tc = O(n*4*3)  Sc = O(n*4)
// int ft(int n, vector<vector<int>> &v){
//     vector<vector<int>> dp(n+1,vector<int> (4,0));
//     // base case
//     dp[0][0] = max(v[0][1], v[0][2]);
//     dp[0][1] = max(v[0][0], v[0][2]) ;
//     dp[0][2] = max(v[0][0], v[0][1]);
//     dp[0][3] = max(v[0][0], max(v[0][1], v[0][2]));

//     for(int day = 1; day<=n; day++){
//         for(int prevTask = 0; prevTask < 4; prevTask++){
//             dp[day][prevTask] = 0;
//             for(int task = 0; task < 3; task++){
//                 if(task != prevTask){
//                     int point = v[day][task] + dp[day-1][task];
//                     dp[day][prevTask] = max(dp[day][prevTask], point);
//                 } 
//             }
//         }
//     }
//     return dp[n][3];
// }



// // Tabulation Space Optimization  Tc = O(n*4*3)  Sc = O(4);
// int fto(int n, vector<vector<int>> &v){
//     vector<int> prev(4,0);
//     // base case
//     prev[0] = max(v[0][1], v[0][2]);
//     prev[1] = max(v[0][0], v[0][2]) ;
//     prev[2] = max(v[0][0], v[0][1]);
//     prev[3] = max(v[0][0], max(v[0][1], v[0][2]));

//     for(int day = 1; day<=n; day++){
//         vector<int> temp (4,0);
//         for(int prevTask = 0; prevTask < 4; prevTask++){
//             temp[prevTask] = 0;
//             for(int task = 0; task < 3; task++){
//                 if(task != prevTask){
//                     int point = v[day][task] + prev[task];
//                     temp[prevTask] = max(temp[prevTask], point);
//                 } 
//             }
//         }
//         prev = temp;
//     }
//     return prev[3]; 
// }

// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     /* there is total 3 task to do 
//     .. 0 -> task 1
//     .. 1 -> task 2
//     .. 2 -> task 3
//     .. 3 -> you can able to pick any task..(use in starting picking)

//     */
//     int task = points[0].size();
//     int days = points.size();

//     vector<vector<int>> dp(days,vector<int> (task+1,-1));
//     // return fm(days-1, points, task, dp);
//     return fto(days-1,  points);
// }


// int main(){

// }