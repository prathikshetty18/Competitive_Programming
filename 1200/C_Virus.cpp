#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl  "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007

void solve(vector<ll> &inf, ll &n, ll &m){

    sort(all(inf));

    priority_queue<ll> pq;

    for(ll i = 1; i < m; i++){
        
        pq.push(inf[i] - inf[i-1] - 1);
    }

    pq.push(n - inf[m-1] + inf[0] - 1);

    ll steps = 0;
    ll ans = 0;

    while(!pq.empty()){

        ll rem = pq.top() - 2*steps;

        if(rem == 1){

            ans++;
            break;
        }
        else if(rem <= 0) break;

        ans += rem - 1;
        steps += 2;
        pq.pop();
    }

    cout << n - ans << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n, m;
        
        cin >> n >> m;

        vector<ll> inf (m);

        for(ll i = 0; i < m; i++) cin >> inf[i]; 

        solve(inf, n, m);
    }
}

