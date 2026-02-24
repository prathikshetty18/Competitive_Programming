#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(ll n){

    // ll l = 1;
    // ll r = n;

    // ll mid;

    // // ll ans = LLONG_MAX;

    // while(l <= r){

    //     cout << "l: " << l << " r: " << r << endl;

    //     mid = l + (r-l)/2;

    //     if(n % mid != 0){
    //         // ans = min(ans, mid);
    //         r = mid-1;
    //     }
    //     else{
    //         l = mid+1;
    //     }
    // }

    int ans = 1;

    while(n % ans == 0){

        ans++;
    }

    cout << ans-1 << "\n";

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n;
        
        cin >> n;

        solve(n);

        t--;
    }
}

