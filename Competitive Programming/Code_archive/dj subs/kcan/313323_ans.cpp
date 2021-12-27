// ans.cpp 3 Jan 18, 17:02:58 100 0.42 Judging completed in 4.397s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int arr[10][8];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a;
    int n,k,b;
    cin>>n>>k;
    for(int x=0;x<n;x++){
        cin>>a;
        for(int y=0;y<a.length();y++){
            b=(int)a[y];
            for(int z=0;z<8;z++){
                if( (1<<z)&b)arr[y][z]++;
            }
        }
    }
    for(int x=0;x<10;x++){
        b=0;
        for(int y=0;y<8;y++){
            if((arr[x][y]%k)!=0)b=b|(1<<y);
        }
        if(b==0)break;
        cout<<(char)b;
    }
    return 0;
}