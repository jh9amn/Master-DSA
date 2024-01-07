/*
Input a string and concatenate with its reverse string and print it.
Input : str = "PWSkills"
Output : "PWSkillssllikSWP"
Input : str = "pw"
Output : "pwwp"
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    string temp = s;

    reverse(s.begin(),s.end());

    temp = temp+s;

    cout<<"The concatenate string is as " <<temp;
}