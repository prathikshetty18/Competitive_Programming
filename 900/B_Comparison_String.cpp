#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(string &s, int n){

    int curr = 1;

    int maxi = 1;

    for(int i = 1; i < n; i++){

        if(s[i] != s[i-1]) curr = 1;
        else{

            curr++;
            maxi = max(maxi, curr);
        }
    }

    cout << maxi + 1 << endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        int n;
        
        cin >> n;

        string s;

        cin >> s;

        solve(s, n);

        t--;
    }
}

