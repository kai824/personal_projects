// ans.cpp 20 Nov 20, 18:25:27 0 0.1 Judging completed in 4.667s on AWS Oregon.
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

long long n, e, r;
long long fw[1005][1005];

long long query(){
    long long sum=0;
    for(int i=0; i<n; i++){
        for(int a=0; a<i; a++){
            sum += fw[i][a];
        }
    }
    return sum;
}

//initialisation
void init(){
    for(int i=0; i<n+5; i++){
        for(int a=0; a<n+5; a++){
            fw[i][a] = 1e9;
			if(i==a)fw[i][a]=0;
        }
    }
}

void update(long long ai, long long bi, long long li){
    
    fw[ai][bi] = fw[bi][ai] = min(fw[ai][bi], li);
    
    for(int j=0;j<n;j++){
		for(int a=0;a<n;a++){
			fw[j][a]=min(fw[j][a],fw[ai][bi]+min(fw[j][bi]+fw[ai][a],fw[j][ai]+fw[bi][a]) );
		}
	}
}

int main(){
    //ifstream cin("data.txt");
    long long ai, bi, li;
    cin >> n >> e >> r;
    
    init();
    
    for(int i=0; i<e; i++){
        cin >> ai >> bi >> li;
        if(li>fw[ai][bi])continue;
        fw[ai][bi] = li;
        fw[bi][ai] = li;
    }
    
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                fw[i][j] = min(fw[i][j], fw[i][k]+fw[k][j]);
            }
        }
    }
    
    for(int i=0; i<r; i++){
        cin >> ai >> bi >> li;
        update(ai, bi, li);
        cout << query() << '\n';
    }
}