// ans.cpp 7 Jan 18, 16:38:57 100 0.56 Judging completed in 5.297s on AWS Oregon.
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long add(long long x, long long y){
    long long a, b;
    do {
        a = x & y;
        b = x ^ y;
        x = a << 1;
        y = b;
    } while (a);
    return b;
}
long long _negate(long long x){
    return add(~x,1);
}
long long sub(long long x, long long y){
    return add(x, _negate(y));
}
vector<long long>v;
long long mul(long long a,long long b){
    v.push_back(a);
    transform(v.begin(),v.end(),v.begin(),bind1st(multiplies<long long>(),b));
    a=v[0];
    v.pop_back();
    return(a);
}
long long divide(long long a,long long b){
    v.push_back(b);
    transform(v.begin(),v.end(),v.begin(),bind1st(divides<long long>(),a));
    a=v[0];
    v.pop_back();
    return a;
}
long long modpow(long long base, long long expo) {
    long long result = 1;
    for (; expo; expo >>= 1) {
        if (expo & 1)
            result = mul(result, base);
        base = mul(base, base);
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long TC; cin >> TC;
    for (long long i = 0; i < TC; i = add(i, 1)){
        long long a, b, r; char c, e; cin >> a >> c >> b >> e >> r;
        if (c == 43){
            if (r == add(a, b)) cout << "YAS\n";
            else cout << "NOPE\n";
        }else if (c == 45){
            if (r == sub(a, b)) cout << "YAS\n";
            else cout << "NOPE\n";
        }else if (c == 42){
            if (r == mul(a, b)) cout << "YAS\n";
            else cout << "NOPE\n";
        }else if (c == 47){
            if (r == divide(a, b)) cout << "YAS\n";
            else cout << "NOPE\n";
        }else if (c == '^'){
            if (r == modpow(a, b)) cout << "YAS\n";
            else cout << "NOPE\n";
        }else if (c == 37){
            if (r == sub(a, (mul(divide(a, b), b)))) cout << "YAS\n";
            else cout << "NOPE\n";
        }
    }
}