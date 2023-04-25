#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;
// int addNumbers(int firstnum, int secondnum){
//     int sum = firstnum + secondnum;
//     return sum;
// }

// print the names of the days row
void print_days(){
    vector <string> week_days{"Mon","Tue","Wed","Thur","Fri","Sat","Sun"};

    for (string day : week_days){
        cout<<setw(4)<<day;
    }  
    cout<<endl;    
}

void print_dates(int day_index, int month,bool leap_year){
    int days_in_month;
    if (month == 1) {
        // Check for leap year
        if (leap_year==true) {
            days_in_month = 29;
        } else {
            days_in_month = 28;
        }
    } else if (month == 3 || month == 5 || month == 8 || month == 10) {
        days_in_month = 30;
    } else {
        days_in_month = 31;
    }
    
    int day_count = 1;
    for(int i=0;i<6;++i){
        for(int j=0;j<7;++j){
            if(i==0&j<day_index){
                cout<<setw(4)<<" ";
            }
            else if(day_count>days_in_month){
                break;
            }
            else{
                cout<<setw(4)<<day_count;
                day_count+=1;
            }

            if(j==6){
                cout<<endl;
            }
 
        }

    }
    cout<<endl;
        
    }

int get_last_day_of_month(bool leap_year, int month,int first_day_of_month) {
    int days_in_month;
    if (month == 2) {
        // Check for leap year
        if (leap_year==true) {
            days_in_month = 29;
        } else {
            days_in_month = 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        days_in_month = 30;
    } else {
        days_in_month = 31;
    }
    int last_day_of_month = (first_day_of_month + days_in_month - 1) % 7;
    return last_day_of_month;
}

// print calendar prints the days row and starts populating the dates
void print_calendar(int first_index, int year){
    cout<<"Calendar year for "<<year<<endl;
    vector <string> months{"January","February","March","April","May","June","July","August","September","October","November","December"};
    vector <int> days_in_month{31,28,31,30,31,30,31,31,30,31,30,31};
    vector <int> days_in_month_leap{31,29,31,30,31,30,31,31,30,31,30,31};

    bool leap_year{false};
    // check for leap year
    if(year%4 == 0){
        leap_year=true;
    }
    int last_day{};
    int first_day{first_index};
    
    for(int i=0;i<12;++i){
        last_day = get_last_day_of_month(leap_year,i,first_day);

        cout<<"--"<<months[i]<<"--"<<endl;
        if(i==0){
            first_day = first_index;
        }
        else if(last_day ==6){
            first_day = 0;
        }
        else{
            first_day = last_day+1;
        }

        print_days();
        print_dates(first_day,i,leap_year);

    }
}


int main(int argc, char **argv){
    int year{};
 cout << "Enter a year : "<<endl;
 cin>>year;
 int first_index{};
 cout<<"Enter the first day of the year [0:Mon,1:Tues,2:Wed,3:Thur,4:fri, 5:sat,6:sun] = "<<endl;
 cin>>first_index;

 print_calendar(first_index,year);
 return 0;
    
}
      