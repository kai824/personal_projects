// ans.cpp 22 Oct 17, 23:15:22 0 0 Judging completed in 3.658s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int arr[1000005],j,ans;
int b8[1000005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a;
    cin>>a;
    if(a.length()<3){
        cout<<-1;
        return 0;
    }
    arr[0]=0;
    for(int i=1;i<a.length();i++){
        if(a[i]==a[j]){
            j++;
            arr[i]=j;
        }else{
            while(true){
                if(j==0){
                    //arr[i]=0;
                    break;
                }
                j=arr[j-1];
                if(a[i]==a[j]){
                    arr[i]=arr[j]+1;
                    break;
                }
            }
        }
        b8[arr[i]]++;
    }
    if(arr[a.length()-1]==0){
        cout<<-1;
        return 0;
    }
    if(b8[arr[a.length()-1]]==1){
        if(arr[ arr[a.length()-1]-1 ]==0){
            cout<<-1;
            return 0;
        }else{
            ans=arr[ arr[a.length()-1]-1 ];
        }
    }else{
        ans=arr[a.length()-1];
    }
    for(int x=0;x<ans;x++){
    	cout<<a[x];
    }
    return 0;
}