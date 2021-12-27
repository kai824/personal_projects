#include"bits/stdc++.h"
using namespace std;

#define int long long
typedef pair<int,int> pii;
#define mp make_pair
#define f first
#define s second

vector<pii>lv,rv;//negative, positive...
vector<pair<pii,pii> > rr;//ranges of (inclusive range, ceil(dist), last bus)
pii arr[1000005],ans[1000005];
int n,m,a,d,dist,lo,hi,mid,l1,l2;

int gcd(int aa,int b){
	if(b==0)return aa;
	else return gcd(b,aa%b);
}
void funi(){
	for(int i=0;i<n;i++){
		if(arr[i].f<=0)continue;
		if(arr[i].f<arr[i].s)continue;//moving backwards...

		lo=0;hi=rr.size()-1;
		if(rr.back().f.s<arr[i].s)continue;//starting point not processed yet
		while(lo<hi){
			mid=lo+(hi-lo)/2;
			if(rr[mid].f.f<=arr[i].s && arr[i].s<=rr[mid].f.s){
				lo=hi=mid;break;
			}
			if(arr[i].s>rr[mid].f.s){
				lo=mid+1;
			}else hi=mid-1;
		}
		dist=rr[lo].s.f;//cout<<lo<<' ';
		while(rr.back().s.f>=dist+1){
			if(rr.back().s.f==dist+1){
				//check condition if need break or wtv
				l1=arr[i].f-arr[i].s;
				l2=arr[rr.back().s.s].f-arr[rr.back().s.s].s;
				if(l1<=l2){
					if(rr.back().f.f>arr[i].s-1){
						rr.pop_back();
						continue;
					}
					rr.back().f.s=arr[i].s-1;
					break;
				}
				a=(arr[rr.back().s.s].s*l1 - arr[i].s*l2 -1)/(l1-l2);a++;
				if(a<=rr.back().f.f && l1>l2){
					//cout<<a<<' '<<l1<<' '<<l2<<"a\n";
					rr.pop_back();
				}else{
					if(a<=rr.back().f.s){
						rr.back().f.s=a-1;
					}else break;
				}
			}else{
				if(arr[i].s>rr.back().f.f){
					rr.back().f.s=arr[i].s-1;
					break;
				}else{
					//cout<<"b\n";
					rr.pop_back();
				}
			}
		}
		rr.push_back(mp(mp(rr.back().f.s+1,arr[i].f),mp(dist+1,i)));
		/*for(int i=0;i<rr.size();i++){
			cout<<rr[i].f.f<<' '<<rr[i].f.s<<' '<<rr[i].s.f<<' '<<rr[i].s.s<<'\n';
		}cout<<"\n\n";*/
	}
}

int32_t main(){
	//freopen ("departure_9.in","r",stdin);
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;//buses, no. of ppl...


	for(int i=0;i<n;i++){
		cin>>arr[i].s>>arr[i].f;//to sort by end time...
	}
	for(int i=0;i<m;i++){
		cin>>a;//nonzero
		if(a<0){
			lv.push_back(mp(-a,i));
		}else{
			rv.push_back(mp(a,i));
		}
	}
	sort(lv.begin(),lv.end());
	sort(rv.begin(),rv.end());
	//process right side first

	sort(arr,arr+n);//pair of end, start
	rr.clear();rr.push_back(mp(mp(0,0),mp(0,-1) ) );
	funi();
	a=0;
	//compute answers for rv... NOT DONE HERE
	/*for(int i=0;i<rr.size();i++){
		cout<<rr[i].f.f<<' '<<rr[i].f.s<<' '<<rr[i].s.f<<' '<<rr[i].s.s<<'\n';
	}cout<<"\n\n";*/
	for(int i=0;i<rv.size();i++){
		while(rr[a].f.s<rv[i].f){
			a++;
		}
		ans[rv[i].s]=mp(rv[i].f-arr[rr[a].s.s].s,arr[rr[a].s.s].f-arr[rr[a].s.s].s);
		d=gcd(ans[rv[i].s].f,ans[rv[i].s].s);
		ans[rv[i].s].f/=d;ans[rv[i].s].s/=d;
		ans[rv[i].s].f+=ans[rv[i].s].s*(-1+rr[a].s.f);
	}

	for(int i=0;i<n;i++){
		arr[i]=mp(-arr[i].f,-arr[i].s);//negate everything...
	}
	sort(arr,arr+n);//just reverse but im lazy
	rr.clear();rr.push_back(mp(mp(0,0),mp(0,-1) ) );
	funi();
	a=0;
	for(int i=0;i<lv.size();i++){
		while(rr[a].f.s<lv[i].f){
			a++;
		}
		ans[lv[i].s]=mp(lv[i].f-arr[rr[a].s.s].s,arr[rr[a].s.s].f-arr[rr[a].s.s].s);
		d=gcd(ans[lv[i].s].f,ans[lv[i].s].s);
		ans[lv[i].s].f/=d;ans[lv[i].s].s/=d;
		ans[lv[i].s].f+=ans[lv[i].s].s*(-1+rr[a].s.f);
	}

	for(int i=0;i<m;i++){
		cout<<ans[i].f<<' '<<ans[i].s<<'\n';
	}
	return 0;
}
/*
5 8
0 5
3 11
1 -8
4 10
1 -3
1 2 5 6 8 -3 -7 11
*/
