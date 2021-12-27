// ans.cpp 18 Jan 18, 10:03:47 100 0.53 Judging completed in 4.379s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int n,s,r;
bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int>b){
    return(a.first.second<b.first.second);
}
vector<pair<int,int> > t;//iterator, distance travelled...
int getd(int a){//as of this time, how many things did you do?
    int lo,hi,mid;
    lo=0;
    hi=t.size()-1;
    while(lo<hi){//find the largest that is smaller or equal
    	mid=lo+hi;
        mid-=(lo+hi)/2;
        if(t[mid].second<=a)lo=mid;
        else hi=mid-1;//t[mid]>=a
    }
    return t[lo].first+((a-t[lo].second)*r);
}

bool flag=0;

char gec()
{
    char c=getchar_unlocked();
    if ((c<'0'||c>'9')&&(c!=' '&&c!='\n')) flag=1;
    return c;
}
inline int get()
{
    int ret=0;
    char c=gec();
    while (c<'0'||c>'9')
    {
        if (flag) return 0;
        c=gec();
    }
    while (c>='0'&&c<='9')
    {
        (ret*=10)+=c-'0';
        c=gec();
    }
    return ret;
}

int main(){
    n=get();s=get();r=get();
    pair<pair<int,int>,int> bs[s];//buses...
    for(int x=0;x<s;x++){
        //cin>>bs[x].first.first>>bs[x].first.second>>bs[x].second;
        bs[x].first.first=get();
        bs[x].first.second=get();
        bs[x].second=get();
        if(flag)break;
    }
    sort(bs,bs+s,cmp);
    t.push_back(make_pair(0,0));
    for(int x=0;x<s;x++){
        t.push_back(make_pair( min(getd(bs[x].first.second),getd(bs[x].first.first)+bs[x].second) ,bs[x].first.second));
    }
    cout<<getd(n);
    return 0;
}