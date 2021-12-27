#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define int long long
typedef pair<int,int> pii;
#define mp make_pair
#define eb emplace_back

int n,k;
int arr[20];
int used=0;
int cnt_1=0,cnt_k=0,s1=0,s2=0;

bool ans=false;
void brute(int i){
  if(i==n+k){
    if(cnt_k!=k || cnt_1!=(n/2))return;
    if(s1==s2)ans=true;
    return;
  }

  if(true || cnt_1<(n/2)){
    cnt_1++;s1+=arr[i];
    brute(i+1);
    //if(ans)cerr<<1;
    if(ans)return;
    cnt_1--;s1-=arr[i];
  }

  s2+=arr[i];brute(i+1);s2-=arr[i];
  if(ans)return;
  //if(ans)cerr<<2;

  if(true || cnt_k<k){
    cnt_k++;
    used|=(1<<i);
    brute(i+1);
    //if(ans)cerr<<0;
    if(ans)return;
    used^=(1<<i);
    cnt_k--;
  }
}

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  cin>>n>>k;
  for(int i=0;i<n+k;i++){
    cin>>arr[i];
  }
  brute(0);
  vector<int> v;
  for(int i=0;i<n+k;i++){
    if(used&(1<<i));
    else v.push_back(arr[i]);
  }

  for(int i=0;i<v.size();i++){
    cout<<v[i];
    if(i+1<v.size())cout<<' ';
  }
  return 0;
}
