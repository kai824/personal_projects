// ans.cpp 28 Oct 17, 14:47:19 100 0 Judging completed in 4.359s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

bool hasEnding (string fullString,string ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}
void m2(string a) {
    string b,c="",ans="-1";
    b=a;
    b.erase(0,1);
    b.erase(b.length()-1,1);
    for(int x=0;x<a.length()-1;x++){
        c=c+" ";
        c[c.length()-1]=a[x];
        if(hasEnding(a,c)&&b.find(c)!=string::npos){
            ans=c;
        }
    }
    cout<<ans;
}

int arr[1000005]={0},j=0,ans;
int b8[1000005]={0};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a;
    cin>>a;
    if(a.length()!=1 && a.length()<1000){
        m2(a);
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