// ans.cpp 5 Nov 16, 21:09:24 0 0 Compilation failed on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
stack process(c,register,a,d){
    int d,b=c[d];
    switch(b){
        case "PUSH":
            cin>>d;
            a.push(d);
            c.push_back("PUSH");
        case "STORE":
            register=a.top();
            a.pop();
            c.push_back("STORE");
        case "LOAD":
            a.push(register);
            c.push_back("LOAD");
        case "PLUS":
            d=a.top();
            a.pop();
            d=d+a.top();
            a.pop();
            a.push(d);
            c.push_back("PLUS");
        case "TIMES":
            d=a.top();
            a.pop();
            d=d*a.top();
            a.pop();
            a.push(d);
            c.push_back("TIMES");
        case "IFZERO":
            cin>>d;
            a=process(c,register,a,d);
        case "DONE":
            break;
        return a;
    }
}
int main() {
    stack<int> a;
    vector<int> c;
    string b;
    int register=0,d,e;
    cin>>e;
    for(int f=0;f<e;f=f+1){
        cin>>b;
        c.push_back(b);
        switch(b) {
            case "PUSH":
                cin>>d;
                a.push(d);
                c.push_back("PUSH");
            case "STORE":
                register=a.top();
                a.pop();
                c.push_back("STORE");
            case "LOAD":
                a.push(register);
                c.push_back("LOAD");
            case "PLUS":
                d=a.top();
                a.pop();
                d=d+a.top();
                a.pop();
                a.push(d);
                c.push_back("PLUS");
            case "TIMES":
                d=a.top();
                a.pop();
                d=d*a.top();
                a.pop();
                a.push(d);
                c.push_back("TIMES");
            case "IFZERO":
                cin>>d;
                a=process(c,register,a,d);
            case "DONE":
                break;
        }
    }
    cout<<a.top();
    return 0;
}