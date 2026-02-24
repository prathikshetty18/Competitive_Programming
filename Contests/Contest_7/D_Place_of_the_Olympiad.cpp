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

bool possible(ll &m, ll &n, ll &benchSize, ll &kids){
    
    ll maxStudents = 0;

    if(m == benchSize){

        maxStudents = m * n;
    }
    else{

        maxStudents = (m / (benchSize + 1)) * benchSize;

        ll rem = m % (benchSize + 1);
        maxStudents += rem;
        maxStudents *= n;
    }

    // cout << "mid: " << benchSize << " maxStu: " << maxStudents << nl;


    if(maxStudents >= kids) return true;
    else return false;
}

void solve(ll &n, ll &m, ll &k){

    ll l = 1; ll r = m;

    while(l <= r){

        // cout << "l: " << l << " r: " << r << nl;

        ll mid = l + (r-l)/2;

        if(possible(m, n, mid, k)){

            r = mid-1;
        }
        else l = mid + 1;
    }

    cout << l << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n, m, k;
        
        cin >> n >> m >> k;

        solve(n, m, k);
    }
}

