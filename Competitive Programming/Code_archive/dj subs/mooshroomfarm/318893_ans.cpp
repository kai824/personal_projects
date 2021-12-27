// ans.cpp 25 Jan 18, 17:58:10 11 1.26 Judging completed in 7.163s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
#define DEFAULT_VALUE 0LL//IMPT
#define ONE 0LL//IMPT
//if you are using this for another problem, please take not of all the comments marked as IMPT using command f

typedef long long ll;
ll process(ll a,ll b){
    return(a+b);//IMPT
}
struct node{
	long long v=DEFAULT_VALUE;
	//x is the one telling top or bottom
	//y is the one telling left or right
	node *tl=NULL,*tr=NULL,*bl=NULL,*br=NULL;//quad tree...
	node(){}
	void update(ll sx,ll sy,ll ex, ll ey,   ll x,ll y,ll add){
		if(sx==ex && sy==ey){
			v+=add;
			return;
		}
		
		if(x<=((sx+ex)/2)){//top
			if(y<=((sy+ey)/2)){//left
				if(tl==NULL)tl=new node();
				tl->update(sx,sy,((sx+ex)/2),((sy+ey)/2),x,y,add);
			}else{//right
				if(tr==NULL)tr=new node();
				tr->update(sx,((sy+ey)/2)+1,((sx+ex)/2),ey,x,y,add);
			}
		}else{//bottom
			if(y<=((sy+ey)/2)){//left
				if(bl==NULL)bl=new node();
				bl->update(((sx+ex)/2)+1,sy,ex,((sy+ey)/2),x,y,add);
			}else{//right
				if(br==NULL)br=new node();
				br->update(((sx+ex)/2)+1,((sy+ey)/2)+1,ex,ey,x,y,add);
			}
		}
		//update the value...
		v+=add;
	}
	ll query(ll sx,ll sy,ll ex,ll ey,     ll tx,ll ty,ll bx,ll by){
		if(tx<=sx && ex<=bx && ty<=sy && ey<=by)return v;
		ll ans=ONE;
		//tl
		if(tx<=((sx+ex)/2) && ty<=((sy+ey)/2)){
			if(tl==NULL)ans=DEFAULT_VALUE;
			else ans=tl->query(sx,sy,((sx+ex)/2),((sy+ey)/2),tx,ty,bx,by);
		}
		//tr
		if(tx<=((sx+ex)/2) && ((sy+ey)/2)<by){
			if(tr==NULL)ans=process(ans,DEFAULT_VALUE);//IMPT:in some cases of DEFAULT_VALUE, you might need like exponentiation(range multiplication) or multiplication(range sum)
			else ans=process(ans,tr->query(sx,((sy+ey)/2)+1,((sx+ex)/2),ey,tx,ty,bx,by));
		}
		//bl
		if(((sx+ex)/2)<bx && ty<=((sy+ey)/2)){
			if(bl==NULL)ans=process(ans,DEFAULT_VALUE);
			else ans=process(ans,bl->query(((sx+ex)/2)+1,sy,ex,((sy+ey)/2),tx,ty,bx,by));
		}
		//br
		if(((sx+ex)/2)<bx && ((sy+ey)/2)<by){
			if(br==NULL)ans=process(ans,DEFAULT_VALUE);
			else ans=process(ans,br->query(((sx+ex)/2)+1,((sy+ey)/2)+1,ex,ey,tx,ty,bx,by));
		}
		return ans;
	}
} *stodd,*steven;
map<pair<ll,ll>,ll>mp;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll R,C,k,q,b,c,d,e,f,g,xxxxx;string a;
	cin>>R>>C>>k>>q;
	//https://dunjudge.me/analysis/problems/1187/mooshroomfarm.pdf
	stodd=new node();steven=new node();
	for(ll x=0;x<q;x++){
		cin>>a;
		if(a=="feed"){
			cin>>b>>c>>d;d%=k;
			auto it=mp.find(make_pair(b,c));
			if(it==mp.end()){
				mp[make_pair(b,c)]=d;
				if((d%2)==1){//change in colour
					if(((b+c)%2)==1){
						stodd->update(1,1,R,C,b,c,1);
					}else{
						steven->update(1,1,R,C,b,c,1);
					}
				}
			}else{
				e=it->second;
				it->second+=d;
				it->second%=k;
				if((it->second%2)!=(e%2)){
					if(e%2){
						//odd, so the delta is negative
						if(((b+c)%2)==1){
							stodd->update(1,1,R,C,b,c,-1);
						}else{
							steven->update(1,1,R,C,b,c,-1);
						}
					}else{
						//positive delta...
						if(((b+c)%2)==1){
							stodd->update(1,1,R,C,b,c,1);
						}else{
							steven->update(1,1,R,C,b,c,1);
						}
					}
				}
			}
		}else{//gaze
			cin>>b>>c>>d>>e;
			f=stodd->query(1,1,R,C,b,c,d,e);
			g=steven->query(1,1,R,C,b,c,d,e);
			if((((d-b+1)*(e-c+1))%2)==0){
				b=((d-b+1)*(e-c+1))/2;//max of stodd
				c=b;//max of steven
			}else{
				if(((b+c)%2)==1){
					xxxxx=1;
				}else{
					xxxxx=0;
				}
				b=((d-b+1)*(e-c+1))/2;//max of stodd
				c=b;//max of steven
				if(xxxxx==1)b++;
				else c++;
			}
			cout<<min(f+(c-g),(b-f)+g)<<'\n';
		}
	}
	return 0;
}