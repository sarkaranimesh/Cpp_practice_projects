#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

int main(int argc, char **argv){
    cout<<"Welcome to the greated calculator on Earth!"<<endl;


    bool end{false};

    while(!end){
        unsigned seed = time(0);
        srand(seed);
        int integer_1 = static_cast<int>((std::rand()%200));
        int integer_2 = static_cast<int>((std::rand()%200));
        int answer; char math_op;
        switch (rand()%3){
            case 0: math_op='+'; answer = integer_1 + integer_2; break;
            case 1: math_op='-'; answer = integer_1 - integer_2;break;
            default: math_op='*'; answer = integer_1*integer_2;break;
        }

        cout << "what is the result of "<<integer_1<<math_op<<integer_2<<" ? "<<endl;
        int user_answer;
        cin>>user_answer;
        cout<<"Your answer is "<<user_answer<<endl;

        if(user_answer == answer){
            cout<<"Congratulation! You got the result "<<answer<<" right!"<<endl;
        }
        else{
            cout<<"Naah! the correct answer is : "<<answer<<endl;
        }

        cout<<"do you want to try again? (Y|N) : ";
        char go_on;
        cin>>go_on;
        end=((go_on=='Y')|(go_on =='y'))? false : true;

    }
    cout << "That's all I have for you today dear. Best wishes "<< endl;

 return 0;
    
}
      