// ans.cpp 6 Nov 20, 21:25:38 100 0 Judging completed in 3.137s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    stack<int> integers;    //Stores the integers
    pair <string,int> command; //collects the commands
    vector<pair<string,int>> instructions; //stores the commands
    int N,Pos; cin >> N; // gets input, Pos: position (for commands)
    string func; // get instructions
    pair <int,int> int_op; // does PLUS and TIMES
    for (int i = 0; i < N; i++){
        //collects all the commands
        cin >> func;
        if (func == "PUSH" || func == "IFZERO"){
            cin >> Pos;
        }
        command.first = func;
        if (func == "PUSH" || func == "IFZERO"){
            command.second = Pos;
        }else{
            command.second = -1;
        }
        instructions.push_back(command);
    }
    int Register=0; // Storage for integers using the STORE
    pair <string,int> x;
    for (int i = 0; i < N; i++){
        x = instructions[i];
        //cout << x.first << ' ' << x.second << '\n';
        if (x.first == "PUSH"){
            integers.push(x.second);
        }else if (x.first == "STORE"){
            Register = integers.top();
            integers.pop();
        }else if (x.first == "LOAD"){
            integers.push(Register);
        }else if (x.first == "PLUS"){
            int_op.first = integers.top();
            integers.pop();
            int_op.second = integers.top();
            integers.pop();
            integers.push(int_op.first + int_op.second);
        }else if (x.first == "TIMES"){
            int_op.first = integers.top();
            integers.pop();
            int_op.second = integers.top();
            //cout << int_op.first << ' ' << int_op.second << '\n';
            integers.pop();
            integers.push(int_op.first * int_op.second);
        }else if (x.first == "DONE"){
            cout << integers.top();
            break;
        }else{
            if (integers.top() == 0){
               i = x.second -1; 
            }
            integers.pop();
        }
        //cout << integers.top() << '\n';
    }
    
}