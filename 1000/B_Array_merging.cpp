#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(vector<ll> &a, vector<ll> &b, ll &n){

    unordered_map<ll, ll> mpa;
    unordered_map<ll, ll> mpb;

    ll count = 1;

    for(ll i = 1; i < n; i++){

        if(a[i] == a[i-1]){

            count++;
        }
        else{

            mpa[a[i-1]] = max(mpa[a[i-1]], count);
            count = 1;
        }
    }

    mpa[a[n-1]] = max(mpa[a[n-1]], count);

    count = 1;

    for(ll i = 1; i < n; i++){

        if(b[i] == b[i-1]){

            count++;
        }
        else{

            mpb[b[i-1]] = max(mpb[b[i-1]], count);
            count = 1;
        }
    }

    mpb[b[n-1]] = max(mpb[b[n-1]], count);

    ll ans = 1;

    for(auto ele : mpa){

        ll curr = ele.first;
        ll currCount = ele.second;

        if(mpb.find(curr) != mpb.end()){

            currCount += mpb[curr];
            mpb.erase(curr);
        }

        ans = max(ans, currCount);
    }

    for(auto ele : mpb){

        ll curr = ele.first;
        ll currCount = ele.second;

        if(mpa.find(curr) != mpa.end()){

            currCount += mpb[curr];
        }

        ans = max(ans, currCount);
    }

    cout << ans << endl;
}   

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n;
        
        cin >> n;

        vector<ll> a (n);
        vector<ll> b (n);


        for(ll i = 0; i < n; i++) cin >> a[i]; 
        for(ll i = 0; i < n; i++) cin >> b[i]; 

        solve(a, b, n);

        t--;
    }
}

