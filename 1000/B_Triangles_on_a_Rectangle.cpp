#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll l, b;

        cin >> l >> b;

        ll ans = LLONG_MIN;

        for(int i = 0; i < 4; i++){

            ll k;

            cin >> k;

            ll mini = LLONG_MAX;
            ll maxi = LLONG_MIN;

            for(ll j = 0; j < k; j++){

                ll temp;

                cin >> temp;

                mini = min(mini, temp);
                maxi = max(maxi, temp);
            }

            // cout << "mini: " << mini << " maxi: " << maxi << nl;

            if(i < 2){

                ans = max(ans, (maxi - mini) * b);
            }
            else{
                ans = max(ans, (maxi - mini) * l);
            }
        } 

        cout << ans << nl;

        t--;
    }
}

