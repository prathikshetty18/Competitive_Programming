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


vll toposort(vvll &adj, ll &n){

    vll indegree (n);
    vll topo;

    for(ll i = 0; i < n; i++){
    
        for(auto &adjNode : adj[i]){

            indegree[adjNode]++;
        }
    }

    queue<ll> q;

    for(ll i = 0; i < n; i++){
    
        if(indegree[i] == 0){

            q.push(i);
        }
    }

    while(!q.empty()){

        ll node = q.front();
        q.pop();
        topo.pb(node);

        for(auto &adjNode : adj[node]){

            indegree[adjNode]--;
            if(indegree[adjNode] == 0){

                q.push(adjNode);
            }
        }
    }

    return topo;
}

void solve(vll &v, ll &n, ll &maxi){

    vvll adj (n);
    
    // print(v);

    vll ind (n);
    iota(all(ind), 0);

    // print(ind);
    
    char sign = '$';   // 0 means > and 1 means <
    
    for(ll level = 1; level < maxi; level++){

        // cout << "Level: " << level << nl;
        
        ll prev = -1;
        vll newv;
        vll newind;
    
        for(ll i = 0; i < v.size(); i++){

            if(v[i] > level){
                newv.pb(v[i]);
                newind.pb(ind[i]);
            }

            if(level % 2 == 1){     // local minimas survive

                // cout << "Here" << nl;

                if(prev == -1){ // first ele lite

                    if(v[i] > level) sign = '<';    // is local minima
                    else sign = '>';
                    prev = i;

                    // cout << sign << sp;
                }
                else{

                    if(sign == '<'){

                        // cout << "Added1 " << prev << " to " << i << nl;
                        
                        adj[ind[prev]].pb(ind[i]);
                    }
                    else{

                        // cout << "Added1 " << i << " to " << prev << nl;
                        
                        adj[ind[i]].pb(ind[prev]);
                    }

                    if(v[i] > level){   // this survives => local minima

                        sign = '<';
                    }
                    else if(i + 1 >= n || v[i+1] > level){  // next one also survives => local minima

                        sign = '>';
                    }

                    // cout << sign << sp;

                    prev = i;
                }
            }   
            else{

                if(prev == -1){ // first ele lite

                    if(v[i] > level) sign = '>';    // is local maxima
                    else sign = '<';
                    prev = i;

                    // cout << sign << sp;

                }
                else{

                    if(sign == '<'){

                        // cout << "Added2 " << prev << " to " << i  << nl;
                        
                        adj[ind[prev]].pb(ind[i]);
                    }
                    else{

                        // cout << "Added2 " << i << " to " << prev << nl;
                    
                        adj[ind[i]].pb(ind[prev]);
                    }

                    
                    if(v[i] > level){   // this survives => local maxima
                        
                        // cout << "here1\n";
                        
                        sign = '>';
                    }
                    else if(i + 1 >= n || v[i+1] > level){  // next one also survives => local maxima
                        
                        // cout << "here2\n";
                        
                        sign = '<';
                    }
                    
                    prev = i;
                    // cout << sign << sp;
                }
            }

            // cout << sign << sp;
        }
        // cout << nl;

        // print(v);
        // print(ind);

        v = newv;
        ind = newind;
    }   

    // for(ll i = 0; i < n; i++){
    
    //     cout << "node: " << i << ": ";

    //     print(adj[i]);
    // }

    vll perm (n);
    iota(all(perm), 1);

    vll topo = toposort(adj, n);

    // print(topo);

    for(ll i = 0; i < n; i++){
    
        perm[topo[i]] = i+1;
    }

    print(perm);
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

        ll maxi = 0, ind;

        for(ll i = 0; i < n; i++){
            
            cin >> v[i]; 
            maxi = max(maxi, v[i]);
            if(v[i] == -1) ind = i;
        }

        maxi++;

        v[ind] = maxi;

        solve(v, n, maxi);
    }
}

