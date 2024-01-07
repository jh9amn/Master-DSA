#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void flood(vector<vector<int>>& image,int sr, int sc,int initialColor,int color){
        int n = image.size();
        int m = image[0].size();
        if(sr < 0 || sc < 0 || sr >= n || sc >= m) return;
        // not the initialColor means it is visisted
        if(image[sr][sc] != initialColor) return;
        image[sr][sc] = color;  // coloring the image

        flood(image,sr+1,sc,initialColor,color); // Right
        flood(image,sr-1,sc,initialColor,color); // Left
        flood(image,sr,sc+1,initialColor,color); // Up
        flood(image,sr,sc-1,initialColor,color); // Down
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        int initialColor = image[sr][sc] ;
        flood(image,sr,sc,initialColor,color);
        return image;
    }
};
int main(){

}