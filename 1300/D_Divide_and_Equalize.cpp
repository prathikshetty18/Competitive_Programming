#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl  "\n"
#define pb push_back
#define sz size
#define ff first
#define ss second
#define vll vector<ll>
#define vpll vector<pair<ll, ll>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007
ll mod_add(ll a, ll b, ll m = mod) { return ((a % m) + (b % m)) % m; }
ll mod_mul(ll a, ll b, ll m = mod) { return ((a % m) * (b % m)) % m; }
ll ceil_div(ll a, ll b){ return a/b + (a%b != 0); }

void solve(vll &v, ll &n, vector<bool> &prime, vll &hp){

    unordered_map<ll, ll> mp;

    for(ll i = 0; i < n; i++){

        while(v[i] != 1){

            ll div = hp[v[i]];

            while(v[i] % div == 0){

                mp[div]++;
                v[i] /= div;
            }
        }
    }

    for(auto [prime, count] : mp){

        if(count % n != 0){

            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    vll hp (1e6+1, -1);
    vector<bool> prime (1e6+1, true);

    prime[1] = false;
    prime[0] = false;

    for(ll i = 2; i <= 1e6; i++){

        if(prime[i] == true){

            hp[i] = i;

            for(ll j = i*i; j <= 1e6; j += i){

                prime[j] = false;
                hp[j] = i;
            }
        }
    }

    while(t--){

        ll n;
        
        cin >> n;

        vll v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n, prime, hp);
    }
}



// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define sp " "
// #define nl  "\n"
// #define pb push_back
// #define sz size
// #define ff first
// #define ss second
// #define vll vector<ll>
// #define vpll vector<pair<ll, ll>>
// #define all(v) v.begin(), v.end()
// #define rall(v) v.rbegin(), v.rend()
// #define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
// #define mod 1000000007
// ll mod_add(ll a, ll b, ll m = mod) { return ((a % m) + (b % m)) % m; }
// ll mod_mul(ll a, ll b, ll m = mod) { return ((a % m) * (b % m)) % m; }
// ll ceil_div(ll a, ll b){ return a/b + (a%b != 0); }

// void solve(vll &v, ll &n){

//     unordered_map<ll, ll> mp;

//     for(ll i = 0; i < n; i++){

//         while(v[i] % 2 == 0){

//             mp[2]++;
//             v[i] /= 2;
//         }

//         for(ll j = 3; j * j <= v[i]; j += 2){

//             while(v[i] % j == 0){

//                 mp[j]++;
//                 v[i] /= j;
//             }

//             if(v[i] == 1) break;
//         }

//         if(v[i] > 2){

//             mp[v[i]]++;
//         }
//     }

//     for(auto [prime, count] : mp){

//         // cout << "prime: " << prime << " count: " << count << nl;

//         if(count % n != 0){

//             cout << "NO\n";
//             return;
//         }
//     }

//     cout << "YES\n";
// }

// int main(){

//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     ll t;
//     cin >> t;

//     while(t--){

//         ll n;
        
//         cin >> n;

//         vll v (n);

//         for(ll i = 0; i < n; i++) cin >> v[i]; 

//         solve(v, n);
//     }
// }

