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

    ll l = 0;
    ll r = n-1;

    while(l < r && v[l] == v[r]){

        l++;
        r--;
    }

    if(l >= r){

        cout << "YES\n";
        return;
    }

    ll opt1 = v[l];
    ll opt2 = v[r];

    ll l1 = l;
    ll r1 = r-1;

    ll l2 = l+1;
    ll r2 = r;


    while(l1 < r1){

        // cout << "l1: " << l1 << " r1: " << r1 << " op1: " << opt1 << nl ;

        while(l1 < r1 && v[l1] == v[r1]){

            l1++;
            r1--;
        }

        if(v[l1] != v[r1] && v[l1] == opt2) l1++;
        else if (v[l1] != v[r1] && v[r1] == opt2) r1--;
        else if(v[l1] != v[r1]) break;
    }


    if(l1 >= r1){

        cout << "YES\n";
        return;
    }

    while(l2 < r2){

        // cout << "l2: " << l2 << " r2: " << r2 << " op1: " << opt1 << nl ;
        
        while(l2 < r2 && v[l2] == v[r2]){
            
            l2++;
            r2--;
        }
        
        if(v[l2] != v[r2] && v[l2] == opt1) l2++;
        else if (v[l2] != v[r2] && v[r2] == opt1) r2--;
        else if(v[l2] != v[r2]) break;
    }
    
    if(l2 >= r2){

        cout << "YES\n";
        return;
    }

    cout << "NO\n";
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

