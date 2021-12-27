// ans.cpp 7 Nov 20, 14:34:40 100 0.22 Judging completed in 4.926s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int N; cin >>N;
    deque<char> DNA;
    string command;
    char input;
    long long query_input;
    bool num_req;
    vector<char> output;
    for (int i = 0; i < N; i++){
        cin >> command;
        num_req = command == "ADD_BACK" || command == "ADD_FRONT" ? true:false ;
        if (num_req){
            cin >> input;
        }else{
            cin >> query_input;
        }
        if (command == "ADD_BACK"){
            DNA.push_back(input);
        }else if (command == "ADD_FRONT"){
            DNA.push_front(input);
        }else if (command == "SNIP_FRONT"){
            for (long long l = 0; l < query_input + 1; l++){
                DNA.pop_front();
            }
        }else if (command == "SNIP_BACK"){
            for (long long k = DNA.size()-1; k > query_input; k--){
                DNA.pop_back();
            }
        }else{
            output.push_back(DNA[query_input]);
        }
    }
    for (char o : output){
        cout << o << '\n';
    }
}