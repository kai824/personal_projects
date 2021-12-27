// ans.cpp 8 Mar 18, 19:33:40 100 0.09 Judging completed in 5.139s on AWS Oregon.
#include<iostream>
#include<string>
#include<bitset>
using namespace std;
#pragma optimise

short int lps[5005];
int dp[100005];
bitset<100005>found;
string txt,pat;
bool first=true;
// create lps[] that will hold the longest prefix suffix values for pattern

// Fills lps[] for given patttern pat[0..M-1]
inline void computeLPSArray(int M){
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i=1;
    while (i < M){
        if (pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if (len != 0){
                len = lps[len-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Prints occurrences of txt[] in pat[]
inline void KMPSearch(){//find pat in txt
    int M = pat.length();
    int N = txt.length();

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(M);

    int i = 0;  // index for txt[]
    int j  = 0;  // index for pat[]
    while (i < N){
        if (pat[j] == txt[i]){
            j++;
            i++;
        }

        if (j == M){
            found[i-j]=1;
            j = lps[j-1];
        }

        // mismatch after j matches
        else if (i < N && pat[j] != txt[i]){
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                 j = lps[j-1];
            else
                 i = i+1;
        }
    }
    int current=0;
    for(int x=0;x<txt.length();x++){
    	current=dp[x];
    	if(x==0)dp[x]=0;
    	else dp[x]=dp[x-1];
    	if(found[x]==1){
    		if(first)dp[x]++;
    		else dp[x]+=current;
    	}
    	dp[x]%=1000000007;
    	found[x]=0;
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    //KMPSearch(pat, txt);
    int n,p;
    cin>>n>>p;
    cin>>txt;
    for(int x=0;x<p;x++){
    	cin>>pat;
    	KMPSearch();
    	first=false;
    }
    cout<<dp[txt.length()-1];
    return 0;
}