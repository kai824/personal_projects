// ans.cpp 7 Jan 18, 16:09:50 0 0.48 Judging completed in 4.676s on AWS Oregon.
#include <iostream>
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
long long mul(long long x, long long y){
    return x*y;
    long long m = 1, z = 0;
    if (x < 0){
        x = _negate(x);
        y = _negate(y);
    }
    while (x >= m && y) {
        if (x & m) z = add(y,z);
        y <<= 1; m <<= 1;
    }
    return z;
}
long long divide(long long x,long long y){
    return x/y;
    long long c = 0,sign = 0;
    if (x < 0){
        x = _negate(x);
        sign ^= 1;
    }
    if (y < 0){
        y = _negate(y);
        sign ^= 1;
    }
    if (y != 0){
        while (x >= y){
            x = sub(x,y);
            c = add(c, 1);
        }
    }
    if (sign){
        c = _negate(c);
    }
    return c;
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