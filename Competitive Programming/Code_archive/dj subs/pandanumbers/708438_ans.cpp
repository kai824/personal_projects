// ans.cpp 3 Mar 20, 22:13:26 0 0.84 Judging completed in 5.266s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
#define int uint16_t
#define bigbig int32_t
bigbig bit_cnt[65540],n;
bigbig cnt1[65540],cnt2[65540],cnt3[65540],ccc;
//count no. of occurences in array, count the answer
//count3: count subsets of a

vector<bigbig> ans;//ans[0] shouldn't count, since it's 0
void brute_force(int num){//subsets of num...
	ans.clear();
	ans.push_back(0);
	for(int x=0;x<16;x++){
		if((1<<x)&num){//ooh, tea...
			ccc=ans.size();
			for(int i=0;i<ccc;i++)ans.push_back(ans[i]+(1<<x));
		}
	}
}

inline void update1(int num,int32_t inc=1){
    n+=inc;//track no. of stuff in the first group...
	cnt1[num]+=inc;
	brute_force(num);
	for(bigbig i=0;i<ans.size();i++)cnt3[ans[i]]+=inc;
}

void update2(int num,int32_t inc=1){
	brute_force(int(~num));
	for(int32_t i=0;i<ans.size();i++){
		//ans[i]+num
		cnt2[ans[i]+num]+=inc;
	}
}

inline bigbig cnt(bigbig num){
    bigbig ans=0;
    for(;num;num-=(num&(-num)))ans++;
    return ans;
}
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int32_t op,xx,c,a,mid=8;
	for(bigbig i=0;i<65540;i++)bit_cnt[i]=cnt(i);
    cin>>op;
    string ss;
    while(op--){
        cin>>ss>>xx;
        c=bit_cnt[xx];
        if(ss=="add"){
            if(c<=mid){
                update1(xx);
            }else update2(xx);
        }else if(ss=="cnt"){
            if(c<=mid){
				a=0;
				brute_force(xx);
				for(int32_t i=0;i<ans.size();i++)a+=cnt1[ans[i]];
				cout<<a<<'\n';
			}else{//ad, or bd...
				a=0;
				brute_force(int(~xx));
				for(bigbig i=0;i<ans.size();i++){
					a+=cnt3[ans[i]];
					a-=cnt3[ans[i]]*((1<<bit_cnt[ans[i]])-1);
				}
				cout<<(a)+cnt2[xx]<<'\n';
			}
        }else{//delete...
            if(c<=mid){
                update1(xx,-1);
            }else update2(xx,-1);
        }
    }
    return 0;
}