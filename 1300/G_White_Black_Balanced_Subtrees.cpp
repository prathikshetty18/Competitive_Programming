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

void dfs(ll node, vector<vector<ll>> &adj, string &s, vll &white, vll &black, vll &vis){

    vis[node] = 1;
    white[node] = s[node-1] == 'W';
    black[node] = s[node-1] == 'B';

    for(auto adjNode : adj[node]){

        if(vis[adjNode] == 0){

            dfs(adjNode, adj, s, white, black, vis);
            white[node] += white[adjNode];
            black[node] += black[adjNode];
        }
    }

    return;
}

void solve(vll &v, string &s, ll &n){

    vector<vector<ll>> adj (n+1);     // undirected graph

    for(ll i = 1; i < n; i++){

        adj[i+1].push_back(v[i]);
        adj[v[i]].push_back(i+1);
    }

    // for(ll i = 1; i <= n; i++){

    //     cout << "node: " << i << ": ";

    //     for(auto adjNode: adj[i]){

    //         cout << adjNode << sp;
    //     }

    //     cout << nl;
    // }

    vll vis(n+1, 0);

    vll white (n+1, 0);
    vll black (n+1, 0);

    dfs(1, adj, s, white, black, vis);

    ll cnt = 0;

    for(ll i = 1; i <= n; i++){

        if(white[i] == black[i]) cnt++;
    }

    cout << cnt << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        vll v (n+1, 0);

        for(ll i = 1; i < n; i++) cin >> v[i]; 

        string s; cin >> s;

        solve(v, s, n);
    }
}

