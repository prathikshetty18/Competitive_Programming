#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

void solve(string &s, ll &n){

    ll maxi = 0;
    ll temp = 0;

    ll ind = -1;

    for(ll i = 0; i < n; i++){

        if(s[i] == '0'){

            ind = i;
            break;
        }
    }

    if(ind == -1){

        cout << n * n << nl;
        return;
    }


    reverse(s.begin(), s.begin() + ind);
    reverse(s.begin()+ind, s.end());
    reverse(s.begin(), s.end());


    // cout << s << nl;

    for(ll i = 0; i < n; i++){

        if(s[i] == '1'){

            temp++;
            maxi = max(maxi, temp);
        }
        else{

            temp = 0;
        }
    }

    ll ans = 0;

    for(ll i = 1; i <= (maxi/2 + ((maxi % 2) != 0)); i++){

        ans = max(ans, i * (maxi-i+1));
    }

    cout << ans << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        string s;

        cin >> s;

        ll n = s.size();

        solve(s, n);

        t--;
    }
}

