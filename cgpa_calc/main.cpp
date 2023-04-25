/*
source chat gpt
Create a program that allows a user to input their grades for each course taken in a semester, calculates their CGPA, and stores the data in a file.

Here are some additional features you could add to make the project more challenging:

Allow the user to input the number of courses they took in the semester.
Implement input validation to ensure that the user enters valid grades (e.g. only A, B, C, D, or F).
Create a data structure (such as an array or vector) to store the user's grades for each course.
Use loops to iterate over the data structure to calculate the CGPA.
Store the user's CGPA and course grades in a file, and allow the user to retrieve their data from the file in a later session.
Add a feature to allow the user to view their past CGPAs and course grades
*/


#include <iostream>
#include <string>
#include <cctype>
using namespace std;

const int MAX_SUBJECTS = 5; // maximum number of subjects
const int MAX_GRADES = 4; // max number of grades A , B, C,D

void print_score_card(float grades[][MAX_GRADES], string subjects[], int numSubjects){
    // print header
    cout<<"Subjects"<<" ";
    for (int i{}; i< MAX_GRADES;i++){
        cout << "Test" <<i+1<<" ";
    }
    cout << endl;

    for(int i{};i<numSubjects;i++){
        cout<< subjects[i] <<" ";
        for(int j{};j<MAX_GRADES;j++){
            cout<<grades[i][j]<<" ";
        }
        cout<<endl;
    }
}



float calculate_cgpa(){
    float cummalative = 0.0;
    
    string subjects [MAX_SUBJECTS];
    float grades[MAX_SUBJECTS][MAX_GRADES];
    int numSubjects;
    cout <<"Enter the number of subjects : "<< endl;
    cin>>numSubjects;

    for (int i{}; i< numSubjects;i++){
        cout << " Enter the subject name : "<< endl;
        cin>> subjects[i];
        string grade;
        float subjectTotal = 0.0;
        for(int j{}; j<MAX_GRADES;j++){
            
            cout << "Enter grade "<<j+1 <<"for subject "<<subjects[i]<<" : "<< endl;
            cin>> grade;
            float numGrade;
            // check if entered grade is valid
            if (grade == "A"){
                numGrade = 4.0;
            }
            else if(grade == "B"){
                numGrade = 3.0;
            }
            else if(grade == "C"){
                numGrade = 2.0;

            }
            else if( grade == "D"){
                numGrade = 1.0;
            }
            else{
                cout << "The grade you have entered is invali , please enter a valid grade (A,B,C,D)"<<endl;
                --j; // goeas back on iteration
                continue;;
            }

            grades[i][j] = numGrade;
        }

        // calculating cgpa
        
        for (int j{}; j<MAX_GRADES;++j){
                        subjectTotal += grades[i][j];
        }
        
        cummalative += subjectTotal/MAX_GRADES;
        cout << "your "<<subjects[i]<<"cummalative score is " <<cummalative<< endl; 

    }
    cout<< "Do you want to print the scorecard (Y/N)?"<< endl;
    string choice ; 
    cin>>choice;
    if(choice == "y" or choice == "Y"){
        print_score_card(grades,subjects, numSubjects);
    }
    float CGPA = cummalative / numSubjects;
    return CGPA;

}

int main(){

    int class_year;
    string semester;
    cout <<"What is the class year? "<<endl;
    cin>>class_year;
    cout <<"What semester is this Fall ; Spring ; Summer ; Winter"<<endl;
    cin >> semester;

    float CGPA = calculate_cgpa();
    cout<< "For Class year "<< class_year <<"semester "<<semester <<" your CGPA is "<<CGPA<<endl;


    
    return 0;

}