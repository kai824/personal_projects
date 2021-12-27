// ans.cpp 4 Mar 20, 23:16:56 0 0.84 Judging completed in 5.193s on AWS Oregon.
#include "bits/stdc++.h"
using namespace std;
#define int uint16_t
#define bigbig int32_t
bigbig bit_cnt[65540],n;
bigbig cnt1[65540],cnt2[65540],cnt3[65540],ccc;
//count no. of occurences in array, count the answer
//count3: count subsets of a

bigbig bf2(int num,int cur=0,int nex_bit=0){//return number of numbers that have subsets of num
	if(nex_bit==16){
		if(cur==0)return 0;
		return cnt3[cur];
	}
	if(((1<<nex_bit)&num)==0)return bf2(num,cur,nex_bit+1);//cannot set this bit to 1
	if(cur>0){
		for(;nex_bit<16;nex_bit++)cur+=(1<<nex_bit)&num;
		return cnt3[cur];//anything else that we add will include cnt3[cur]
	}

	return bf2(num,cur,nex_bit+1)+cnt3[1<<nex_bit]-bf2(num,cur+(1<<nex_bit),nex_bit+1);
}

vector<bigbig> ans;//ans[0] shouldn't count, since it's 0
void brute_force(int num){//subsets of num...
	ans.clear();
	ans.push_back(0);
	for(int x=0;x<16;x++){
		if((1<<x)&num){//given a choice...
			ccc=ans.size();
			for(int i=0;i<ccc;i++)ans.push_back(ans[i]+(1<<x));
		}
	}
}

inline void update1(int num,int32_t inc=1){
    n+=inc;//track no. of stuff in the first group...
	cnt1[num]+=inc;
	brute_force(num);
	for(bigbig i=0;i<ans.size()-1;i++)cnt3[ans[i]]+=inc;//for smaller subsets...
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

string inputs[100];
int32_t inps[100];
vector<int> output;

string binn(int num){
	string anss="";
	for(bigbig i=15;i>=0;i--){
		if((1<<i)&num)anss+='1';
		else anss+='0';
	}
	return anss;
}

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int32_t op,xx,c,a,mid=8;
	for(bigbig i=0;i<65540;i++)bit_cnt[i]=cnt(i);
    cin>>op;
    string ss;
    for(int32_t y=0;y<op;y++){
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
							a=bf2(int(~xx));
							/*a=0;
							brute_force(int(~xx));
							for(bigbig i=1;i<ans.size();i++){
								a+=cnt3[ans[i]];
								if(cnt3[ans[i]]>0){
									cout<<cnt3[ans[i]]<<' '<<binn(ans[i])<<' '<<bit_cnt[ans[i]]<<'\n';
								}
								if(bit_cnt[ans[i]]>1)a-=cnt3[ans[i]]*bit_cnt[ans[i]];
			          //if(cnt3[ans[i]]>0)cout<<ans[i]<<' '<<bit_cnt[ans[i]]<<' '<<cnt3[ans[i]]<<'\n';
							}*/
							if(a<0)assert(false);
							cout<<(n-a)+cnt2[xx]<<'\n';
						}
        }else{//delete...
            if(c<=mid){
                update1(xx,-1);
            }else update2(xx,-1);
        }
    }
}