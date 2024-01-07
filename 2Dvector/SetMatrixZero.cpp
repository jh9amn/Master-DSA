 #include<iostream>
 #include<vector>
 using namespace std;
 
 void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool flageZerothRow = false;
        bool flageZerothCol = false;

        for(int j=0; j<n; j++){
            if(matrix[0][j]==0)  flageZerothRow = true;
        }

        for(int i=0; i<m; i++){
            if(matrix[i][0] == 0)  flageZerothCol = true;
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j]==0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int j=1; j<n; j++){
            if(matrix[0][j] == 0) {
            for(int i=1; i<m; i++){
                matrix[i][j] = 0;
            }
          }
        }

        for(int i=1; i<m; i++){
            if(matrix[i][0] == 0){
                for(int j=1; j<n; j++){
                    matrix[i][j] = 0;            
                }
            }
        }

        if(flageZerothRow == true){
            for(int j=0; j<n; j++){
                matrix[0][j] = 0;
            }
        }

        if(flageZerothCol == true){
            for(int i=0; i<m; i++){
                matrix[i][0] = 0;
            }
        }

        return;
  }



    int main(){

    vector<int> v1;
    v1.push_back(0);
    v1.push_back(11);
    v1.push_back(1);
  

    vector<int> v2;
    v2.push_back(15);
    v2.push_back(16);
    v2.push_back(17);


    vector<int> v3;
    v3.push_back(0);
    v3.push_back(16);
    v3.push_back(17);

    vector<vector<int> >v;

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
  
    int n = v.size();
    int m = v[0].size();
    
       for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
               cout<<v[i][j]<<" ";
            }cout<<endl;
        }cout<<endl;

    setZeroes(v);


    cout<<"The Set Zero matrix is as"<<endl;
     for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
               cout<<v[i][j]<<" ";
            }cout<<endl;
        }
    
        }
    