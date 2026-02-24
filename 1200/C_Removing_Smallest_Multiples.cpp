#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl  "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007


void solve(string &s, ll &n){

    vector<bool> sieve(n+1, true);
    sieve[0] = false;
    // sieve[1] = true;

    ll cost = 0;

    for(ll i = 0; i < n; i++){

        ll start = i;
        ll curr = i + 1;

        // cout << "i: " << i << " curr: " << curr << nl;

        while(i < n && (s[i] == '0')){

            // cout << "i+1: " << i+1 << " curr: " << curr << " sieve[i+1]: " << sieve[i+1]<< nl;

            // s[i] = 1;
            
            if(sieve[i+1] == true){
                
                // cout << " INSIDE\n";
                
                cost += curr;
                sieve[i+1] = false;
            }

            i += curr;
        }

        i = start;
    }

    cout << cost << nl;
    

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        string s;

        cin >> s;

        solve(s, n);
    }
}

