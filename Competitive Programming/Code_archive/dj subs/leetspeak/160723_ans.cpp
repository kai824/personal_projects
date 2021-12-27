// ans.cpp 9 Nov 16, 18:56:25 0 0 Compilation failed on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    string a,c="English";
    cin>>a;
    transform(a.begin(), a.end(), a.begin(), tolower);
    for(int b=0;b<a.size();b=b+1){
        if((a[b]!="a")||(a[b]!="b")||(a[b]!="c")||(a[b]!="d")||(a[b]!="e")||(a[b]!="f")||(a[b]!="g")||(a[b]!="h")||(a[b]!="i")||(a[b]!="j")||(a[b]!="k")||(a[b]!="l")||(a[b]!="m")||(a[b]!="n")||(a[b]!="o")||(a[b]!="p")||(a[b]!="q")||(a[b]!="r")||(a[b]!="s")||(a[b]!="t")||(a[b]!="u")||(a[b]!="v")||(a[b]!="w")||(a[b]!="x")||(a[b]!="y")||(a[b]!="z")){
            c="l33t";
        }
    }
    cout<<c;
    return 0;
}