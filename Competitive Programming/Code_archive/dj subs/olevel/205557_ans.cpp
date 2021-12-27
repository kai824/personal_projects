// ans.cpp 30 Apr 17, 20:40:05 60 0.1 Judging completed in 5.174s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
struct student{
    int choices[5],score,score2;
    //the choices with choices[0] being the first choice...
    //score being aggregate score...
    //score 2 for sorting purposes when 2 peeps have same score1...
};
bool cmp(student a,student b){
    if(a.score==b.score){
        return(a.score2<b.score2);
    }else{
        return(a.score<b.score);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,c;
    cin>>n>>c;
    student students[n];
    int results[n];
    int schools[c+5];//the number of vacancies left in each school
    for(int x=1;x<=c;x++){
        cin>>schools[x];
    }
    for(int x=0;x<n;x++){
        cin>>students[x].score>>students[x].choices[0];
        cin>>students[x].choices[1]>>students[x].choices[2];
        cin>>students[x].choices[3]>>students[x].choices[4];
        students[x].score2=x;
    }
    sort(students,students+n,cmp);
    for(int x=0;x<n;x++){
        for(int y=0;y<6;y++){
            if(schools[students[x].choices[y]]>0){
                schools[students[x].choices[y]]--;
                results[students[x].score2]=students[x].choices[y];
                break;
            }
            if(y==6){
                results[students[x].score2]=-1;
            }
        }
    }
    for(int x=0;x<n;x++){
        cout<<results[x]<<'\n';
    }
    return 0;
}