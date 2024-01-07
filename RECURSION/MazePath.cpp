/* 
here, Maze like The matrix 
And We heve To find The Different Way to reach the Destination*/

#include<iostream> 
#include<string>
using namespace std;

// Total Number Of Ways 
int maze(int sr, int sc, int er, int ec){  //sc = staring Row,  Ec = Ending Column
if(sr > er || sc > ec) return 0;
if(sr == er && sc == ec) return 1;
int rightWays = maze(sr,sc+1,er,ec);    // right move in maze
int downWays = maze(sr+1,sc,er,ec);     // down move in maze
int totalWays = rightWays + downWays;
return totalWays;
}

// Fnding Ways Using Only two Parameter
int maze2(int row,int col){  //sc = staring Row,  Ec = Ending Column
if(row < 1 || col < 1) return 0;
if(row == 1 && col == 1) return 1;
int rightWays = maze2(row,col-1);   // right move
int downWays = maze2(row -1,col);   // down move
int totalWays = rightWays + downWays;
return totalWays;
}



// Printing The Maze Path
void printPath(int sr, int sc, int er, int ec, string s){  //sc = staring Row,  Ec = Ending Column
if(sr > er || sc > ec) return;
if(sr == er && sc == ec){    // Destination Reached
    cout<<s<<endl;
    return;
}
 printPath(sr,sc+1,er,ec,s+'R');  // R =  Right Move 
 printPath(sr+1,sc,er,ec,s+'D');  // D = Down Move
}
 
 // Printing the Maze Path Using Only Two Parameters
 void printpath2(int row, int col, string s){
    if(row < 1 || col < 1)  return ;
    if(row == 1 && col == 1){
        cout<<s<<endl;
        return;
    }
    printpath2(row,col-1,s+'R');  // right Move
    printpath2(row-1,col,s+'D');  // Down Move

 }

int main(){
    // cout<<"Total Ways Are "<<maze(1,1,3,3)<<endl;
    // cout<<"Total Ways Are "<<maze2(3,3)<<endl;
    // printPath(1,1,3,3,"");
    printpath2(3,3,"");

}