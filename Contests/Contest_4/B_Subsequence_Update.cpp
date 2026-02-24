#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(vector<ll> &v, ll &n, ll &l, ll &r){

    priority_queue <ll, vector<ll>, greater<ll>> pq1;
    priority_queue <ll, vector<ll>, greater<ll>> pq2;


    for(ll i = l-1; i < r; i++){

        // cout << v[i] << " ";
        pq1.push(v[i]);
        pq2.push(v[i]);
    } 

    for(ll i = 0; i < l-1; i++){

        pq1.push(v[i]);
    }

    for(ll i = r; i < n; i++){

        pq2.push(v[i]);
    }

    ll seg_size = r - l + 1;

    ll mini1 = 0;
    ll mini2 = 0;


    while(seg_size > 0){

        if(!pq1.empty()){

            mini1 += pq1.top();
            pq1.pop();
        }

        if(!pq2.empty()){

            mini2 += pq2.top();
            pq2.pop();
        }

        seg_size--;
    }

    cout << min(mini1, mini2) << endl;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n, l, r;
        
        cin >> n >> l >> r;

        vector<ll> v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n, l ,r);

        t--;
    }
}

