// ans.cpp 18 Jun 19, 12:14:12 0 0.18 Judging completed in 4.845s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int a,b=0,c=0;
    FILE * f;
    ios::sync_with_stdio(false);
    f=fopen("tmp.txt","wb");
    while(cin>>a){
        fprintf(f,"%d\n",a);
        b+=floor(log10(a))+1;
        c++;
    }
    fclose(f);
    system("tac tmp.txt");
    return 0;
}