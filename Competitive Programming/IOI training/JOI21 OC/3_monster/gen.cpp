#include<bits/stdc++.h>
using namespace std;

int main(){
  int sd;cin>>sd;srand(sd);
  int n=5;
  int arr[n];for(int i=0;i<n;i++)arr[i]=i;

  for(int i=1;i<n;i++){
    swap(arr[i],arr[rand()%i]);
  }
  cout<<n<<'\n';
  for(int i=0;i<n;i++){
    cout<<arr[i];
    if(i+1<n)cout<<' ';
  }
}
