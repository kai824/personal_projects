// ans.cpp 27 Nov 19, 11:21:25 0 0 Compilation failed on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

bool emerged[1000005];
int parent[1000005],cur;

int get_root(int x){
    if(parent[x]==-1)return x;
    parent[x]=get_root(parent[x]);
    return parent[x];
}

inline void merge(int a,int b){
    a=get_root(a);b=get_root(b);
    if(a==b)return;
    parent[a]=b;
}

inline bool exis(int x){
    if(x<0)return false;
    return emerged[x];
}

int GW(int n, int *h){
    pair<int,int> arr[n];
    int islands=0,ans=0;
    for(int x=0;x<n;x++){
        arr[x].first=h[x];
        arr[x].second=x;
        parent[x]=-1;
    }
    sort(arr,arr+n);
    for(int x=0;x<n;x++){
        cur=arr[x].second;
        emerged[cur]=true;
        if(exis(cur-1) && exis(cur+1)){
            islands--;
        }else if((exis(cur-1) || exis(cur+1))==false){
            islands++;
        }
        if(exis(cur-1))merge(cur-1,cur);
        if(exis(cur+1))merge(cur+1,cur);
        ans=max(ans,islands);
    }
    return ans;
}

int main()
{
   int  size;
   int  *H;
   int  i;
   int  NumberOfIslands;

   /*------------------------*/
   /* R e a d    i n p u t   */
   /*------------------------*/
   scanf ("%d",  &size );
   H = malloc ( size* sizeof(int) );

   for (i=0; i<size; i++)
     {  scanf ("%d",  &H[i] );  }

   NumberOfIslands =   GW ( size, H );

   printf ( "%d\n", NumberOfIslands );

}