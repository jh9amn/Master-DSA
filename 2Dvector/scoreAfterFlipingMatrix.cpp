    // leetCode 861
    #include<iostream>
    #include<vector>
    using namespace std;
    
    int matrixScore(vector<vector<int>>& grid) {

        // finding the size of vector row and column
        int rows = grid.size();
        int colm = grid[0].size();

        for(int i=0; i<rows; i++){
             // flip the rows whose first element is 0
            if(grid[i][0] == 0){
                for(int j=0; j<colm; j++){
                   // flips columns 0 into 1 and 1 into 0...
                   if(grid[i][j] == 0)  grid[i][j] = 1;
                   else grid[i][j] = 0;
                }
            }
        }


        // counting column wise 0 and 1
        for(int j=0; j<colm; j++){
            int noz = 0;
            int noo = 0;

            for(int i=0; i<rows; i++){
                if(grid[i][j] == 0)  noz++;
                else noo++;
            }

       
            for(int i=0; i<rows; i++){
                if(noz > noo){  // if noz > noo then flip column 0 into 1 and 1 into 0
                     // fliping column wise 0 into 1 and 1 into 0
                    if(grid[i][j] == 0)  grid[i][j] = 1;
                   else grid[i][j] = 0;
                }
            }
        }


        //Now Converting Binary into decimal
        int sum = 0;
        for(int i=0; i<rows; i++){
            int x = 1;
            for(int j = colm-1; j>=0; j--){
                sum += grid[i][j] * x;  // and these are highest possible sum 
                x *= 2;
            }
        }
         return sum;
    }