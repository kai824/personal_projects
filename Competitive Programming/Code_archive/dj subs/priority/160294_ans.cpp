// ans.cpp 7 Nov 16, 18:01:06 0 1.18 Judging completed in 8.744s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int fa(int x){
    return (x%13371337);
}
int fb(int x){
    int ans=0;
    while(x!=0){
        ans=ans+x%10;
        x=x/10;
    }
    return ans;
}
int fc(int x){
    uint64_t ans;
    uint64_t r;
    while(x!=0){
        r=x%10;
        ans=ans*10+r;
        r=r/10;
    }
    return ans;
}
bool cmp(pair<uint64_t,uint64_t> a,pair<uint64_t,uint64_t> b){
    return(a.first>b.first);
}
bool cmp2(pair<uint64_t,uint64_t> a,pair<uint64_t,uint64_t> b){
    return(a.second>b.second);
}
int main() {
    uint64_t a,c;
    deque<pair<uint64_t,uint64_t> >q; //<queue number, modified>
    cin>>a;
    pair<uint64_t,uint64_t> d;
    for(int b=0;b<a;b=b+1){
        cin>>c;
        d.first=c;
        q.push_back(d);
    }
    sort(q.begin(),q.end(),cmp);
    cin>>a;
    cout<<a;
    uint64_t e[a];
    for(int b=0;b<a;b=b+1){
        cin>>c;
        if(c==1){
            for(int bb=0;bb<q.size();b=b+1){
                q[bb].second=fa(q[bb].first);
            }
            stable_sort(q.begin(),q.end(),cmp2);
            e[b]=q[0].first;
            q.pop_front();
        }else if(c==2){
            for(int bb=0;bb<q.size();b=b+1){
                q[bb].second=fb(q[bb].first);
            }
            stable_sort(q.begin(),q.end(),cmp2);
            e[b]=q[0].first;
            q.pop_front();
        }else if(c==3){
            for(int bb=0;bb<q.size();b=b+1){
                q[bb].second=fc(q[bb].first);
            }
            stable_sort(q.begin(),q.end(),cmp2);
            e[b]=q[0].first;
            q.pop_front();
        }
        cout<<sizeof(e);
    }
    for(int b=0;b<sizeof(e);b=b+1){
        cout<<e[b]<<"\n";
    }
    return 0;
}