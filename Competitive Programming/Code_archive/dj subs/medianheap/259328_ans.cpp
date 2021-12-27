// ans.cpp 17 Nov 17, 14:23:49 100 0.62 Judging completed in 4.495s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
priority_queue<int> pq1;
priority_queue<int,vector<int>,greater<int> > pq2;
int size1=0,size2=0,n;
//we must ensure that size1<=size2
//ensure that size1+1>=2
int b;
int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    cin>>n;
    string a;
    for(int x=0;x<n;x++){
        cin>>a;
        if(a=="PUSH"){
            cin>>b;
            if(size1==size2){
                //push it into pq2
                
                if(size1==0){
                	size2++;
                	pq2.push(b);
                	continue;
                }
                
                size2++;
                if(b<pq2.top()){
                    pq1.push(b);
                    pq2.push(pq1.top());
                    pq1.pop();
                }else{//b>=pq2.top()
                    pq2.push(b);
                }
            }else{//size1<size2
                //push it into pq1
                
                if(size1==0){
                	if(b<=pq2.top()){
                		pq1.push(b);
                	}else{
                		//b>pq2.top()
                		pq1.push(pq2.top());
                		pq2.pop();
                		pq2.push(b);
                	}
                	size1++;
                	continue;
                }
            	
                size1++;
                if(pq1.top()<b){
                    pq2.push(b);
                    pq1.push(pq2.top());
                    pq2.pop();
                }else{//b<=pq1.top();
                    pq1.push(b);
                }
            }
        }else{//a=="POP"
            if(size1<size2){
                //odd number of elements...
                size2--;
                pq2.pop();
            }else{
                //even number of elements...
                size1--;
                pq1.pop();
            }
        }
    }
    vector<int> v;
    while(!pq1.empty()){
        v.push_back(pq1.top());
        pq1.pop();
    }
    while(v.size()>0){
        cout<<v.back()<<' ';
        v.pop_back();
    }
    while(size2>0){
        cout<<pq2.top();
        size2--;
        pq2.pop();
        if(size2>0)cout<<' ';
    }
    return 0;
}