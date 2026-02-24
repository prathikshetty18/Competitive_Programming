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

void solve(vll &v, ll &n){

    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq_uo, pq_oc;

    ll maxi = sqrt(2*n);

    // cout << "maxi: " << maxi << nl;

    for(ll i = 1; i <= 1+3*maxi; i += 3){

        for(ll j = 1; j <= 1+3*maxi; j += 3){

            vector<ll> temp = {i + j, i, j};

            pq_uo.push(temp);
        }
    }

    vector<pair<ll, ll>> ans;

    
    for(ll i = 0; i < n; i++){

        if(v[i] == 0 || pq_oc.empty()){

            vll temp = pq_uo.top();
            pq_uo.pop();

            ans.push_back({temp[1], temp[2]});
            pq_oc.push({temp[1] + temp[2] + 1, temp[1], temp[2] + 1});
            pq_oc.push({temp[1] + temp[2] + 1, temp[1] + 1, temp[2]});
            pq_oc.push({temp[1] + temp[2] + 4, temp[1] + 1, temp[2] + 1});
        }
        else{

            vll temp1, temp2;

            if(!pq_oc.empty()) temp1 = pq_oc.top();
            if(!pq_uo.empty()) temp2 = pq_uo.top();

            if(!pq_oc.empty() && !pq_uo.empty() && temp1[0] <= temp2[0]){

                pq_oc.pop();
                ans.push_back({temp1[1], temp1[2]});
            }
            else{

                pq_uo.pop();

                ans.push_back({temp2[1], temp2[2]});
                pq_oc.push({temp2[1] + temp2[2] + 1, temp2[1], temp2[2] + 1});
                pq_oc.push({temp2[1] + temp2[2] + 1, temp2[1] + 1, temp2[2]});
                pq_oc.push({temp2[1] + temp2[2] + 4, temp2[1] + 1, temp2[2] + 1});
            }
 
        }
    }

    for(auto [first, second] : ans){

        cout << first << sp << second << nl;
    }   
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        vll v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n);
    }
}

