// ans.cpp 9 Nov 20, 14:48:15 100 0.01 Judging completed in 5.782s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
unsigned long long arr[26];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a;
    getline(cin,a);
    for(int x=0;x<a.length();x++){
        if(isalpha(a[x])){
            if(tolower(a[x])-'a'==0){
                arr[0]++;
            }else{
                arr[tolower(a[x])-'a']+=arr[tolower(a[x])-'a'-1];
            }
        }
    }
    cout<<arr[25];
    return 0;
}