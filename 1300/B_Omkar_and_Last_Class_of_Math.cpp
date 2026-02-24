#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"
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

void solve(ll &n){

    if(n % 2 == 0){

        cout << n/2 << sp << n/2 << nl;
        return;
    }

    ll mini = LLONG_MAX;
    ll num1 = -1, num2 = -1;

    for(ll i = 1; i*i <= n; i++){

        if(n % i == 0){

            ll a = i, b = n - a;
            ll newLCM = lcm(a, b);

            //cout << "a: " << a << " b: " << b << " newLCM: " << newLCM << nl;

            if(a <= b && newLCM < mini){

                mini = newLCM;
                num1 = a;
                num2 = b;
            }

            a = n/i, b = n - a;
            newLCM = lcm(a, b);

            if(a <= b && newLCM < mini){

                mini = newLCM;
                num1 = a;
                num2 = b;
            }
        }
    }

    cout << num1 << sp << num2 << nl;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        solve(n);
    }
}

