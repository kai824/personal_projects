// ans.cpp 9 Feb 18, 17:57:42 100 0 Judging completed in 4.415s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
bool isPalindrome(ull n) {
  const auto s = to_string(n);
  return s == std::string(s.rbegin(), s.rend()); }
  
ull specNearestPalindrome(ull n) {
  assert(0 <= n);

  ull less = n, more = n;
  while (true) {
    if (isPalindrome(less)) { return less; }
    if (isPalindrome(more)) { return more; }
    --less; ++more; } }

std::string reflect(std::string& str, ull n) {
  std::string s(str);
  s.resize(s.size() + n);
  std::reverse_copy(std::begin(str),
      std::next(std::begin(str), n),
      std::next(std::begin(s), str.size()));
  return s; }

bool isPow10(ull n) {
  return n < 10 ? n == 1 : (n % 10 == 0) && isPow10(n / 10); }

ull nearestPalindrome(ull n) {
  assert(0 <= n);
  if (n != 1 && isPow10(n)) { return n - 1; }  // special case

  auto nstr = to_string(n);
  // first half, rounding up
  auto f1 = nstr.substr(0, (nstr.size() + 1) / 2);
  auto p1 = stoi(reflect(f1, nstr.size() / 2));

  const auto twiddle = p1 <= n ? 1 : -1;
  auto f2 = to_string((stoi(f1) + twiddle));
  auto p2 = stoi(reflect(f2, nstr.size() / 2));

  if (p2 < p1) { std::swap(p1, p2); }
  return n - p1 <= p2 - n ? p1 : p2; }

int main(){
  string s, s1, s2, s3;
  cin >> s;
  if (s.size() == 1){cout << 0; return 0;}
  if (s.size() <= 6){\
  ull t = stoull(s);
    if (t > nearestPalindrome(t)) cout << t-nearestPalindrome(t);
  else cout << nearestPalindrome(t)-t;
  return 0;
  }
  s1 = s; s2 = s; s3=s;
  string firsthalf = s.substr(0, s.size()/2), firsthalf2, firsthalf3;
  firsthalf2 = firsthalf;
  firsthalf3 = firsthalf;
  reverse(firsthalf.begin(), firsthalf.end());
  //cout << firsthalf << endl;
  //cout << s1;
  if (s.size()%2==1) for (int i=s.size()/2+1,j=0;i<=s.size()-1;i++,j++) s1[i] = firsthalf[j];
  else for (int i=s.size()/2,j=0;i<=s.size()-1;i++,j++) s1[i] = firsthalf[j];
  ull u1, u2, d1=0, d2=0, original;
  u1 = stoull(s1);
  original = stoull(s);
  //cout << u1 << endl;
  if (u1 > original) d1 = u1-original;
  else d1 = original-u1;
  // SECOND METHOD
  u2 = stoull(firsthalf2);
  if (s.size()%2==1) s2[s.size()/2]++;
  else u2++;
  firsthalf2 = to_string(u2);
  //cout << firsthalf2 << endl;
  for (int i=0;i<firsthalf2.size();i++) s2[i] = firsthalf2[i];
  reverse(firsthalf2.begin(), firsthalf2.end());
  if (s.size()%2==1) for (int i=s.size()/2+1,j=0;i<=s.size()-1;i++,j++) s2[i] = firsthalf2[j];
  else for (int i=s.size()/2,j=0;i<=s.size()-1;i++,j++) s2[i] = firsthalf2[j];
  u2 = stoull(s2);
  if (u2 > original) d2 = u2-original;
  else d2 = original-u2;
  //cout << u2 << endl;
  //PART TWO
  u2 = stoull(firsthalf3);
  if (s.size()%2==1){
    if(s3[s.size()/2]=='0') s3[s.size()/2] = '9';
    else s3[s.size()/2]--;
    u2--;
  }
  else u2--;
  //cout << s3 << endl;
  firsthalf2 = to_string(u2);
  for (int i=0;i<firsthalf2.size();i++) s3[i] = firsthalf2[i];
  reverse(firsthalf2.begin(), firsthalf2.end());
  if (s.size()%2==1) for (int i=s.size()/2+1,j=0;i<=s.size()-1;i++,j++) s3[i] = firsthalf2[j];
  else for (int i=s.size()/2,j=0;i<=s.size()-1;i++,j++) s3[i] = firsthalf2[j];
  u2 = stoull(s3);
  if (u2 > original) d2 = min(d2, u2-original);
  else d2 = min(d2, original-u2);
  //cout << u2 << endl;
  //cout << u1 << " " << d1 << endl << u2 << " " << d2;
  
  cout << min(d1, d2);
}