// ans.cpp 7 Nov 20, 14:50:44 0 0.24 Judging completed in 4.351s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N; long long K; long long receiver; long long totalSatisfaction=0; long long answer=0;
    cin >> N >> K;
    priority_queue<long long> pq;
    for(long long i=0; i<K; i++){
        cin >> receiver;
        pq.push(receiver);
    }
    for(long long i=0; i<(N-K); i++){
        totalSatisfaction+=pq.top();
        pq.pop();
        cin >> receiver;
        pq.push(receiver);
        if(answer<totalSatisfaction){
            answer=totalSatisfaction;
        }
    }
    cout << answer;
}