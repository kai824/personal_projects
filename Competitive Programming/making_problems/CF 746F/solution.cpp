#include"bits/stdc++.h"
using namespace std;
#define mp make_pair
typedef pair<int,int> pii;

int arr[200005],t[200005];

set<pii> ss;//t[i],i...
priority_queue<pii,vector<pii>,greater<pii> >pq;//songs we're skipping, shortest song first...

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n,w,k,end=-1,cur=0,cur_p=0,max_p=0,siz=0;
  cin>>n>>w>>k;
  for(int i=0;i<n;i++)cin>>arr[i];
  for(int i=0;i<n;i++)cin>>t[i];

  for(int i=0;i<n;i++){
    if(siz<w){
      if(cur+(1+t[i])/2>k){
        end=i;break;
      }
      pq.emplace(t[i],i);
      siz++;
      cur+=(1+t[i])/2;
    }else{
      if(t[i]>pq.top().first){
        if(cur+(pq.top().first/2)+(t[i]+1)/2>k){
          end=i;break;
        }
        ss.insert(pq.top());
        cur+=(pq.top().first/2)+(t[i]+1)/2;//listen to pq.top fully, listen to t[i] partly
        pq.pop();
        pq.emplace(t[i],i);
      }else{
        if(cur+t[i]>k){
          end=i;break;
        }
        cur+=t[i];
        ss.insert(mp(t[i],i));
      }
    }
    cur_p+=arr[i];//cur pleasure...
    ////cerr<<cur<<'\n';
  }
  ////cerr<<"0 "<<' '<<end<<' '<<cur<<' '<<cur_p<<'\n';
  max_p=cur_p;
  if(end==-1){
    cout<<max_p;//take everything...
    return 0;
  }
  for(int i=1;i<n;i++){
    //set left endpoint to i, see what happens...
    if(ss.find(mp(t[i-1],i-1))==ss.end()){//was on skip set...
      cur-=(1+t[i-1])/2;
      cur_p-=arr[i-1];
      if(ss.begin()==ss.end()){
        siz--;//nothing from set to insert...
      }else{
        cur-=(ss.rbegin()->first/2);//since moving this to skip set...
        pq.emplace(*ss.rbegin());//most time-consuming thing...
        ss.erase(--ss.end());
      }
    }else{
      cur-=t[i-1];
      cur_p-=arr[i-1];
      ss.erase(mp(t[i-1],i-1));
    }
    while(end<n){
      //shift end...
      if(siz<w){
        if(cur+(1+t[end])/2>k)break;
        pq.emplace(t[end],end);
        siz++;
        cur+=(1+t[end])/2;
      }else{
        while(pq.top().second<i)pq.pop();//irrelevant things
        if(t[end]>pq.top().first){
          if(cur+pq.top().first/2+(1+t[end])/2>k)break;
          ss.insert(pq.top());
          cur+=pq.top().first/2+(1+t[end])/2;//listen to pq.top fully, listen to t[i] partly
          pq.pop();
          pq.emplace(t[end],end);
        }else{
          if(cur+t[end]>k)break;
          cur+=t[end];
          ss.insert(mp(t[end],end));
        }
      }
      cur_p+=arr[end];//taking this item...
      end++;
    }
    //cerr<<i<<" "<<' '<<end<<' '<<cur<<' '<<cur_p<<'\n';
    max_p=max(max_p,cur_p);
  }
  cout<<max_p;

  return 0;
}
