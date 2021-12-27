// ans.cpp 7 Nov 16, 21:25:29 0 0.41 Judging completed in 8.993s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int current_sum=0,max_sum=0,a,b,c;
    priority_queue<int> can_eat;
    queue<int> out_of_reach;
    cin>>a>>b;
    for(int d=0;d<a;d++){
        cin>>c;
        if(d<b) can_eat.push(c);
        else out_of_reach.push(c);
    }
    while((can_eat.size()>0)||(out_of_reach.size()>0)){
        current_sum=current_sum+can_eat.top();
        can_eat.pop();
        if(current_sum>max_sum) max_sum=current_sum;
        if(out_of_reach.size()>0){
            can_eat.push(out_of_reach.front());
            out_of_reach.pop();
        }
    }
    cout<<max_sum;
    return 0;
}