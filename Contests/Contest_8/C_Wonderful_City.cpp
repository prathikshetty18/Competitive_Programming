#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> 
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;    // find_by_order(x) -> Elements less than x, order_of_key(x) -> xth smallest element

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

ll findCost(vvll &mat, vll &a, ll &n){

    vvll dp(n, vll (2, 1e14));

    // dp[i][0] -> min cost to find rows 0 to i such that ith row was not changed (F)
    // dp[i][1] -> min cost to find rows 0 to i such that ith row was changed (T)

    dp[0][0] = 0, dp[0][1] = a[0];

    for(ll i = 1; i < n; i++){
    
        bool f1 = false, f2 = false, f3 = false;

        for(ll j = 0; j < n; j++){
        
            if(mat[i][j] == mat[i-1][j]) f1 = true;
            else if(mat[i][j] == mat[i-1][j] + 1) f2 = true;
            else if(mat[i][j] + 1 == mat[i-1][j]) f3 = true; 
        }

        // cout << f1 << sp << f2 << sp << f3 << nl;

        if(f1 && !f2 && !f3){

            dp[i][0] = min({dp[i][0], dp[i-1][1]});
            dp[i][1] = min({dp[i][1], a[i] + dp[i-1][0]});
        }
        else if(!f1 && f2 && !f3){

            dp[i][0] = min({dp[i][0], dp[i-1][0]});
            dp[i][1] = min({dp[i][1], a[i] + dp[i-1][0], a[i] + dp[i-1][1]});
        }
        else if(!f1 && !f2 && f3){

            dp[i][0] = min({dp[i][0], dp[i-1][0], dp[i-1][1]});
            dp[i][1] = min({dp[i][1], a[i] + dp[i-1][1]});
        }
        else if(f1 && f2 && !f3){

            dp[i][1] = min({dp[i][1], a[i] + dp[i-1][0]});
        }
        else if(f1 && !f2 && f3){

            dp[i][0] = min({dp[i][0], dp[i-1][1]});
        }
        else if(!f1 && f2 && f3){

            dp[i][0] = min({dp[i][0], dp[i-1][0]});
            dp[i][1] = min({dp[i][1], a[i] + dp[i-1][1]});
        }
        else if(!f1 && !f2 && !f3){     

            dp[i][0] = min({dp[i][0], dp[i-1][0], dp[i-1][1]});
            dp[i][1] = min({dp[i][1], a[i] + dp[i-1][1], a[i] + dp[i-1][0]});
        }
        else if(f1 && f2 && f3){     // not possible to make it beautiful

            continue;
        }
    }

    return min(dp[n-1][0], dp[n-1][1]);
}

void solve(vvll &mat, vll &a, vll &b, ll &n){

    ll rowCost = findCost(mat, a, n);

    if(rowCost >= 1e14){

        cout << -1 << nl;
        return;
    }

    vvll trans (n, vll (n));

    for(ll i = 0; i < n; i++){
    
        for(ll j = 0; j < n; j++){
        
            trans[i][j] = mat[j][i];
        }
    }

    ll colCost = findCost(trans, b, n);


    if(colCost >= 1e14){

        cout << -1 << nl;
        return;
    }

    cout << rowCost + colCost << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        vvll mat (n, vll (n));
        vll a (n), b (n);

        for(ll i = 0; i < n; i++){

            for(ll j = 0; j < n; j++){
            
                cin >> mat[i][j]; 
            }
        }

        for(ll i = 0; i < n; i++){
        
            cin >> a[i];
        }

        for(ll i = 0; i < n; i++){
        
            cin >> b[i];
        }

        solve(mat, a, b, n);
    }
}

