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

void solve(vll &v, ll &n, ll &k){

    ll cntl = 0, cntg = 0, l = -1, r = -1;

    for(ll i = 0; i < n; i++){
    
        cntl += (v[i] <= k);
        cntg += (v[i] > k);

        if(cntl >= cntg){

            l = i;
            
            if((cntl + cntg) % 2 == 1 && i <= n-4 && v[i+1] > k){   
                
                // if odd, atleast 3 elements after and next ele > k then include it here and make it even as med doesn't change

                l++;
            }

            break;
        }
    }

    cntl = 0, cntg = 0;

    for(ll i = l+1; i < n-1; i++){
    
        cntl += (v[i] <= k);
        cntg += (v[i] > k);

        if(cntl >= cntg){

            r = i;
            break;
        }
    }

    if(l != -1 && r != -1){

        cout << "YES\n";
        return;
    }

    cntl = 0, cntg = 0, l = -1, r = -1;

    for(ll i = n-1; i >= 0; i--){
    
        cntl += (v[i] <= k);
        cntg += (v[i] > k);

        if(cntl >= cntg){

            l = i;
            
            if((cntl + cntg) % 2 == 1 && i >= 3 && v[i-1] > k){   
                
                // if odd, atleast 3 elements after and next ele > k then include it here and make it even as med doesn't change

                l--;
            }

            break;
        }
    }

    cntl = 0, cntg = 0;

    for(ll i = l-1; i >= 1; i--){
    
        cntl += (v[i] <= k);
        cntg += (v[i] > k);

        if(cntl >= cntg){

            r = i;
            break;
        }
    }

    if(l != -1 && r != -1){

        cout << "YES\n";
        return;
    }

    cntl = 0, cntg = 0, l = -1, r = -1;

    for(ll i = 0; i < n; i++){
    
        cntl += (v[i] <= k);
        cntg += (v[i] > k);

        if(cntl >= cntg){

            l = i;
            break;
        }
    }

    cntl = 0, cntg = 0;

    for(ll i = n-1; i >= l+2; i--){
    
        cntl += (v[i] <= k);
        cntg += (v[i] > k);

        if(cntl >= cntg){

            r = i;
            break;
        }
    }

    if(l != -1 && r != -1){

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

        ll n, k;
        
        cin >> n >> k;

        vll v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n, k);
    }
}

