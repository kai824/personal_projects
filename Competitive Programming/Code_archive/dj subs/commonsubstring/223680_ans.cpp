// ans.cpp 18 Oct 17, 21:32:39 10 0.01 Judging completed in 3.445s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
void lcs( char *X, char *Y, int m, int n ){
   int L[m+1][n+1];
   for (int i=0; i<=m; i++){
     for (int j=0; j<=n; j++){
       if (i == 0 || j == 0)
         L[i][j] = 0;
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
       else
       L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
   int index = L[m][n];
   char lcs[index+1];
   lcs[index] = '\0';
   int i = m, j = n;
   while (i > 0 && j > 0){
      if (X[i-1] == Y[j-1]){
          lcs[index-1] = X[i-1];
          i--; j--; index--;     
      }
      else if (L[i-1][j] > L[i][j-1])
         i--;
      else
         j--;
   }
   cout << strlen(lcs);
}
int main()
{
  char X[1005];
  char Y[1005];
  cin>>X;
  cin>>Y;
  int m = strlen(X);
  int n = strlen(Y);
  lcs(X, Y, 1000, 1000);
  return 0;
}