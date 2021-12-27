// ans.cpp 24 Mar 20, 13:50:51 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int k;
    f=fopen("tmp.txt","wb");
    while(cin>>k){
        fprintf(f,"%d\n",k);
    }
    fclose(f);
    system("tac tmp.txt");
    system("rm tmp.txt");
    return 0;
}