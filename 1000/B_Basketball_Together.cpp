#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(priority_queue<ll> &pq, ll &n, ll &D){

    ll ans = 0;
    ll used = 0;

    while(!pq.empty()){

        ll top = pq.top();

        ll need = (D+1)/top + ((D+1) % top != 0);

        if(pq.size() + ans - used >= need){

            ans++;
            used += need;
            pq.pop();
        }
        else{

            break;
        }
        
    }

    cout << ans << endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;

    while(t > 0){

        ll n, D;
        
        cin >> n >> D;

        priority_queue<ll> pq;

        ll temp;

        for(ll i = 0; i < n; i++){
            
            cin >> temp;
            pq.push(temp);
        } 

        solve(pq, n, D);

        t--;
    }
}

