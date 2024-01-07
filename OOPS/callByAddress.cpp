 #include<iostream>
using namespace std;
class Student{
  public:
    int rno;
    string name;
    float marks;

    Student(int rno,string name,float marks){
        (*this). rno = rno;                // (*abc).x = abc->x
        this -> name = name;
        this -> marks = marks;
    }
};

// Here This is Work as Call By Value ....
// void change(Student s){


// There Are TWo way to use acll by address one is using & other is Using Pointer
// Here This is Work as Call By Address ....
void change(Student& s){
    s.name = "Harsh";
}

void change(Student* abc){
    (*abc).name = "Mohan";
}

 int main(){
    Student s(12,"Aman",84.90);
   change(s);           // this is using passing value to student type address container
   cout<<s.name<<endl;

   change(&s);          // this is using paasing address of object s to pointer 
   cout<<s.name<<endl;


 }