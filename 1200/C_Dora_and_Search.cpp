#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl  "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007

void solve(vector<ll> &v, ll &n){

    vector<ll> track (n);

    iota(all(track), 1);

    ll l1 = 0, l2 = 0, r1 = n-1, r2 = n-1;

    while((v[l1] == track[l2]) || (v[l1] == track[r2]) || (v[r1] == track[l2]) || (v[r1] == track[r2])){

        while((l1 < r1) && (l2 < r2) && (v[l1] == track[l2])){

            l1++;
            l2++;
        }

        while((l1 < r1) && (l2 < r2) && (v[l1] == track[r2])){

            l1++;
            r2--;
        }

        while((l1 < r1) && (l2 < r2) && (v[r1] == track[l2])){

            r1--;
            l2++;
        }

        while((l1 < r1) && (l2 < r2) && (v[r1] == track[r2])){

            r1--;
            r2--;
        }

        //cout << "l1: " << v[l1] << " r1: " << v[r1] << " l2: " << track[l2] << " r2: " << track[r2] << nl;

        if(l1 >= r1 || l2 >= r2){

            cout << -1 << nl;
            return;
        }
    }

    //cout << "l1: " << v[l1] << " r1: " << v[r1] << " l2: " << track[l2] << " r2: " << track[r2] << nl;


    cout << l1+1 << sp << r1+1 << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        vector<ll> v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n);
    }
}

