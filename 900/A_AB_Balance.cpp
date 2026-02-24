#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(string &s, int n){

    // only case when #ab != #ba is when b is located at only one end of the string

    if(s[0] == 'a' && s[n-1] == 'b'){

        s[n-1] = 'a';
    }
    else if(s[0] == 'b' && s[n-1] == 'a'){

        s[0] = 'a';
    }  

    cout << s << endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        string s;
        
        cin >> s;

        int n = s.size();

        solve(s, n);

        t--;
    }
}

