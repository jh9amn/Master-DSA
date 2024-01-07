/*   Write a program in C++, take details of students like roll, name, fie, and 
marks of five subject and evaluate grade of each student , where number of 
student are five;   */



#include <iostream>
#include <string>

using namespace std;

struct Student {
    int rollNumber;
    string name;
    string field;
    int marks[5];
    char grade;
};

void calculateGrade(Student& student) {
    int totalMarks = 0;
    for (int i = 0; i < 5; i++) {
        totalMarks += student.marks[i];
    }

    int averageMarks = totalMarks / 5;

    if (averageMarks >= 90) {
        student.grade = 'A';
    } else if (averageMarks >= 80) {
        student.grade = 'B';
    } else if (averageMarks >= 70) {
        student.grade = 'C';
    } else if (averageMarks >= 60) {
        student.grade = 'D';
    } else {
        student.grade = 'F';
    }
}

int main() {
    Student students[5];

    // Taking input for each student
    for (int i = 0; i < 5; i++) {
        cout << "Enter details for student " << (i + 1) << ":" << endl;
        cout << "Roll Number: ";
        cin >> students[i].rollNumber;
        cout << "Name: ";
        cin.ignore();
        getline(cin, students[i].name);
        cout << "Field: ";
        getline(cin, students[i].field);

        cout << "Enter marks for 5 subjects: ";
        for (int j = 0; j < 5; j++) {
            cin >> students[i].marks[j];
        }
        cout << endl;

        // Calculate grade for the student
        calculateGrade(students[i]);
    }

    // Displaying grades for each student
    cout << "Grades for each student:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Student " << (i + 1) << ": " << students[i].grade << endl;
    }

    return 0;
}