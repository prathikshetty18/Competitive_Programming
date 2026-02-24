#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl endl

void solve(string &s, ll &n, ll &k){

    ll l = 0;
    ll r = 0;

    ll white = 0;
    ll black = 0;

    while(r < k){

        white += s[r] == 'W';
        black += s[r] == 'B';
        r++;
    }

    ll ans = INT_MAX;

    ans = min(ans, white);


    while(r < n){

        // update state

        if(s[l] == 'W') white--;
        if(s[l] == 'B') black--;
        if(s[r] == 'W') white++;
        if(s[r] == 'B') black++;

        l++;
        
        // handle invald

        // update global if valid

        ans = min(ans, white);

        r++;
    }

    cout << ans << endl;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n, k;
        
        cin >> n >> k;

        string s;

        cin >> s;

        solve(s, n, k);

        t--;
    }
}
