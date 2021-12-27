// ans.cpp 1 Jan 19, 21:17:32 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int x,i=0;
    FILE * f;
    while(cin>>x){
        f.open(to_string(i)+".txt");
        f=fopen(to_string(i)+".txt","wb");
        fprintf(f,"%d",x);
        fclose(f);
        i++;
    }
    ifstream f1;
    while(i--){
        f1.open(to_string(i)+".txt");
        f1.tie(0);
        f1>>x;
        cout<<x<<'\n';
        f1.close();
    }
    return 0;
}