// ans.cpp 14 Nov 18, 09:57:21 100 0.16 Judging completed in 4.659s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ft1[1000005];
ll ft2[1000005];
void update(ll *ftx, ll pos, ll delta) {
	for (; pos <= 100000; pos += pos & (-pos)) {
	    ftx[pos] += delta;
	}
}
ll query(ll *ftx, ll pos) {
	ll sum = 0;
	for (; pos; pos -= pos & (-pos)) {
	    sum += ftx[pos];
	}
	return sum;
}

void rupdate(ll a, ll b, ll v) {
    update(ft1, a, v);
    update(ft1, b, -v);
    update(ft2, a, -(a-1) * v);
    update(ft2, b, b*v);
}

ll pquery(ll pos){
	return pos * query(ft1, pos) + query(ft2, pos);
}

ll rquery(ll a, ll b) {
    return pquery(b) - pquery(a-1);
}



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int K; cin >> K;
    for (int i = 1, a; i <= K; i++){
    	cin >> a; rupdate(i,i,a);
    }
    int Q; cin >> Q;
    while (Q--){
    	int T; cin >> T;
    	if (T == 0){
    		int A, B; cin >> A >> B;
    		cout << rquery(A+1, B+1) << '\n';
    	}else{
    		int A, B, C; cin >> A >> B >> C;
    		rupdate(A+1, B+1, C);
    	}
    }
}