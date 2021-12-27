// ans.cpp 25 Dec 17, 22:59:24 1 1.24 Judging completed in 7.012s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
//set stores iterator and then the value
//the value will be changed to prefix...
map<int,set<pair<int,int> > >r;//r,c
map<int,set<pair<int,int> > >c;//c,r
set<pair<int,int> >sss;//to push in some way

int rd[4]={-1,1,0,0};//r directions
int cd[4]={0,0,-1,1};//c directions

int rquery(int rr,int cc){
    set<pair<int,int> > *ii;
    ii=&r[rr];
    if(ii==NULL)return 0;
    auto it=ii->upper_bound(make_pair(cc,INT_MAX));
    if(it==ii->begin())return 0;
    it--;
    return(it->second);
}
int cquery(int rr,int cc){
    set<pair<int,int> > *ii;
    ii=&c[cc];
    if(ii==NULL)return 0;
    auto it=ii->upper_bound(make_pair(rr,INT_MAX));
    if(it==ii->begin())return 0;
    it--;
    return(it->second);
}
int query(int rr,int cc){
    return(rquery(rr,cc)+cquery(rr,cc));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r_,c_,n,k,q,it,currentr=1,currentc=1,nr,nc,s,e,o;
    cin>>r_>>c_>>n>>k>>q;
    string a;
    cin>>a;
    for(int x=0;x<a.length();x++){
        if(a[x]=='U')it=0;
        else if(a[x]=='D')it=1;
        else if(a[x]=='L')it=2;
        else if(a[x]=='R')it=3;
        nr=currentr+(rd[it]*k);
        nc=currentc+(cd[it]*k);
        if(currentr+rd[it]<1)continue;
        if(currentc+cd[it]<1)continue;
        if(currentr+rd[it]>r_)continue;
        if(currentc+cd[it]>c_)continue;
        //^skip the rest of the code cause you can't even move one step
        if(nr<1)nr=1;
        if(nc<1)nc=1;
        if(nr>r_)nr=r_;
        if(nc>c_)nc=c_;
        //^ensuring that you stay within the limits...
        if(cd[it]==0){//directions which only affect r
        	if(&c[nc]==NULL){
        		c[nc]=sss;
        	}
        	s=min(currentr+rd[it],nr);
        	e=max(currentr+rd[it],nr);
        	e++;
        	auto i=&c[nc];
        	auto i2=i->upper_bound(make_pair(s-1,INT_MAX));
        	if(i2==i->end()||(i2->first)>s){//element doesn't exist yet...
        		i->insert(make_pair(s,1));
        	}else{//element exists already
        		o=i2->second;//current value of the element
        		i->erase(i2);//remove the old
        		i->insert(make_pair(e,o+1));//change it to the new
        	}
        	i2=i->upper_bound(make_pair(e-1,INT_MAX));
        	if(i2==i->end()||(i2->first)>e){
        		i->insert(make_pair(e,-1));
        	}else{
        		o=i2->second;
        		i->erase(i2);
        		i->insert(make_pair(e,o-1));
        	}
        }else{//directions which only affect c
        	/*r[nr].insert(make_pair(min(nc,currentc+cd[it]) , max(nc,currentc+cd[it])) );*/
        	if(&r[nr]==NULL){
        		r[nr]=sss;
        	}
        	s=min(nc,currentc+cd[it]);e=max(nc,currentc+cd[it]);e++;
        	auto i=&r[nr];
        	auto i2=i->upper_bound(make_pair(s-1,INT_MAX));
        	if(i2==i->end()||(i2->first)>s){//element doesn't exist yet...
        		i->insert(make_pair(s,1));
        	}else{//element exists already
        		o=i2->second;//current value of the element
        		i->erase(i2);//remove the old
        		i->insert(make_pair(e,o+1));//change it to the new
        	}
        	i2=i->upper_bound(make_pair(e-1,INT_MAX));
        	if(i2==i->end()||(i2->first)>e){
        		i->insert(make_pair(e,-1));
        	}else{
        		o=i2->second;
        		i->erase(i2);
        		i->insert(make_pair(e,o-1));
        	}
        }
        currentr=nr;
        currentc=nc;
    }
    bool aaa;int oooo;
    for(auto i=r.begin();i!=r.end();i++){
    	auto i2=i->second.end();
    	i2--;
    	int current=0,ooo;
    	aaa=false;
    	while(1){
    		//current-=i2->second;
    		oooo=i2->second;
    		ooo=i2->first;
    		auto i3=i2;
    		if(i2==i->second.begin())aaa=true;
    		else i3--;
    		i->second.erase(i2);
    		i->second.insert(make_pair(ooo,current));
    		current-=oooo;
    		if(aaa)break;
    		i2=i3;
    	}
    }
    for(auto i=c.begin();i!=c.end();i++){
    	auto i2=i->second.end();
    	i2--;
    	int current=0,ooo;
    	aaa=false;
    	while(1){
    		//current-=i2->second;
    		oooo=i2->second;
    		ooo=i2->first;
    		auto i3=i2;
    		if(i2==i->second.begin())aaa=true;
    		else i3--;
    		i->second.erase(i2);
    		i->second.insert(make_pair(ooo,current));
    		current-=oooo;
    		if(aaa)break;
    		i2=i3;
    	}
    }
    int coord1,coord2;
    for(int x=0;x<q;x++){
        cin>>coord1>>coord2;//with respect to r,c...
        cout<<query(coord1,coord2)<<'\n';
    }
    return 0;
}