// ans.cpp 9 Sep 17, 21:43:11 25.18 0 Judging completed in 2.832s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main(){
    char q=(char)34;
    string s[]={
        "    ",
        "#include <bits/stdc++.h>",
        "using namespace std;",
        "int main(){",
        "    char q=(char)34;",
        "    string s[]={",
        "    };",
        "    for(int x=1;x<=5;x++){",
        "        cout<<s[x]<<endl;",
        "    }",
        "    for(int x=0;x<18;x++){",
        "        cout<<s[0]<<s[0]<<q<<s[x]<<q<<','<<endl;",
        "    }",
        "    for(int x=6;x<18;x++){",
        "        cout<<s[x]<<endl;",
        "    }",
        "    return 0;",
        "}",
    };
    for(int x=1;x<=5;x++){
        cout<<s[x]<<endl;
    }
    for(int x=0;x<18;x++){
        cout<<s[0]<<s[0]<<q<<s[x]<<q<<','<<endl;
    }
    for(int x=6;x<18;x++){
        cout<<s[x]<<endl;
    }
    return 0;
}