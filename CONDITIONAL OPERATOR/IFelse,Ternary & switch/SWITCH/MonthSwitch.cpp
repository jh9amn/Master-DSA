#include<iostream>
using namespace std;
int main(){
int x;
cout<<"Enter the month Number";
cin>>x;

// switch(x){
//     case 1:
//         cout<<"january"<<30<<endl;
//         break;
//     case 2:
//         cout<<"February"<<28<<endl;
//         break;
//     case 3:
//         cout<<"March"<<31<<endl;
//         break;
//     case 4:
//         cout<<"April"<<30<<endl;
//         break;
//     case 5:
//         cout<<"May"<<31<<endl;
//         break;
//     case 6:
//         cout<<"Jun"<<30<<endl;
//         break;
//     case 7:
//         cout<<"July"<<31<<endl;
//         break;
//     case 8:
//         cout<<"August"<<31<<endl;
//         break;
//     case 9:
//         cout<<"Sptember"<<30<<endl;
//         break;
//     case 10:
//         cout<<"October"<<31<<endl;
//         break;
//      case 11:
//         cout<<"November"<<30<<endl;
//         break;
//      case 12:
//         cout<<"December"<<31<<endl;
//         break;   
//     default :
//         cout<<"Invalid Day Number";
// }


// Month Number 1,3,5,7,8,10,12 --> 31 days
// Month Number 4,6,9,11 -->  30 days
// Month Number 2 --> 28 days

switch((x<=7 && x%2!=0)  || x>=8 && x%2==0){
    case 1:
    cout<<"Having 31 days ";
    break;
    default : 
    cout<<"Invalid Day number";
}
  switch(x==4 || x==6 || x==9 || x==11 ){
    case 1:
    cout<<"Having 30 Days";
    
  }

  switch(x){
    case 2:
    cout<<"Having 28 Days";
  }






}