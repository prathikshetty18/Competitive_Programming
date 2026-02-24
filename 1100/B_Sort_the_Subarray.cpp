#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

void solve(vector<ll> &a, vector<ll> &b, ll &n){

    ll maxi = 0;
    ll lmaxi = 0;
    ll rmaxi = 0;

    ll l = 0;
    ll r = 0;

    ll temp = 1;

    bool flag = false;

    if(a[0] != b[0]) flag = true;

    for(ll i = 1; i < n; i++){

        if(b[i] >= b[i-1]){

            if(a[i] != b[i]) flag = true;

            temp++;
            r++;
        }
        else{

            if((temp > maxi) && flag){

                maxi = temp;
                lmaxi = l;
                rmaxi = r;
            }

            l = i;
            r = i;
            temp = 1;
            flag = false;

            if(a[i] != b[i]) flag = true;
        }
    }

    if(temp > maxi && flag){

        maxi = temp;
        lmaxi = l;
        rmaxi = r;
    }

    cout << lmaxi+1 << sp << rmaxi+1 << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n;
        
        cin >> n;

        vector<ll> a (n), b (n);

        for(ll i = 0; i < n; i++) cin >> a[i]; 
        for(ll i = 0; i < n; i++) cin >> b[i]; 

        solve(a, b, n);

        t--;
    }
}

