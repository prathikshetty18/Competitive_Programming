#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(ll &l, ll &r){

    ll ans = 0;

    if(l == 1 && r == 1){

        cout << 1 << endl;
        return;
    }

    if(l == 1){


        ans++;
        l = 2;
    }

    ans += (r-l+1)-1;

    cout << ans << endl;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll l, r;
        
        cin >> l >> r;

        solve(l, r);

        t--;
    }
}

