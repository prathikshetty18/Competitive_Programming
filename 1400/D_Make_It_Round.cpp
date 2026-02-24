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
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007
ll mod_add(ll a, ll b, ll m = mod) { return ((a % m) + (b % m)) % m; }
ll mod_mul(ll a, ll b, ll m = mod) { return ((a % m) * (b % m)) % m; }
ll ceil_div(ll a, ll b){ return a/b + (a%b != 0); }

void callWhenEqual(ll &n, ll &m, ll &newMul){

    ll rem = m % newMul;

    newMul = m - rem;

    cout << n * newMul << nl;
    return;
}

void solve(ll &n, ll &m){

    ll n2 = 0, n5 = 0;

    ll nn = n;

    while(nn % 2 == 0){

        n2++;
        nn /= 2;
    }

    nn = n;

    while(nn % 5 == 0){

        n5++;
        nn /= 5;
    }

    if(n2 == n5){

        ll newMul = 1;

        while(newMul * 10 <= m){

            newMul *= 10;
        }

        callWhenEqual(n, m, newMul);
        return;
    }
    else if(n2 > n5){

        ll diff = n2 - n5;

        ll newMul = 1, count = 0;

        while((count < diff + 1) && newMul <= m){

            newMul *= 5;
            count++;
        }

        newMul /= 5;
        count--;

        // cout << "n2: " << n2 << " n5: " << n5 << nl;
        // cout << "count: " << count << " newMul: " << newMul << nl;

        if(count < diff){

            callWhenEqual(n, m, newMul);
            return;
        }
        else{

            while(newMul * 10 <= m){

                newMul *= 10;
            }

            callWhenEqual(n, m, newMul);
        }
    }
    else{

        ll diff = n5 - n2;

        ll newMul = 1, count = 0;

        while((count < diff + 1) && newMul <= m){

            newMul *= 2;
            count++;
        }

        newMul /= 2;
        count--;

        // cout << "n2: " << n2 << " n5: " << n5 << nl;
        // cout << "count: " << count << " newMul: " << newMul << nl;

        if(count < diff){

            callWhenEqual(n, m, newMul);
            return;
        }
        else{

            while(newMul * 10 <= m){

                newMul *= 10;
            }

            callWhenEqual(n, m, newMul);
        }
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n, m;
        
        cin >> n >> m;

        solve(n, m);
    }
}

