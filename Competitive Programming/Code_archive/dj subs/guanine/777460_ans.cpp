// ans.cpp 7 Nov 20, 14:31:00 24 0.21 Judging completed in 5.068s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int N; cin >>N;
    deque<char> DNA;// Stores the sequence of nucleotides
    string command; // gets the command
    char input; // gets input
    long long query_input; // also gets input
    bool num_req; // to avoid confusing myself
    vector<char> output;
    for (int i = 0; i < N; i++){
// CArries out all the commands
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
            for (long long l = 0; l < query_input; l++){
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
// Outputs all the queries
        cout << o << '\n';
    }
}