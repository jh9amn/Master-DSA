#include<iostream>
using namespace std;
class Book{
  public:
    string name;
    int price;
    int noOfPages;

    int countBooks(int p){
        if(price < p) return 1;
        else return 0;
    }

    bool isBookPresent(string book){
        if(name == book) return true;
        else return false;
    }  
};

int main(){
  Book harryPotter ;
  harryPotter.name = "MAtrix";
  harryPotter.price = 1000;
  harryPotter.noOfPages = 500;

  cout<<harryPotter.isBookPresent("Angle");
  return 0;
}