#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

void solve(vector<ll> &v, ll &n){

    ll maxi = LLONG_MIN;

    for(ll k = 1; k*k <= n; k++){

        if(n % k == 0){     // possible choice of k trucks

            ll choice1 = k;
            ll choice2 = n/k;

            // cout << "choice1: " << choice1 << " choice2: " << choice2 << nl;

            ll minWeight = LLONG_MAX;
            ll maxWeight = LLONG_MIN;

            for(ll i = 0; i < n;){

                ll sum = 0;

                ll temp = choice1;

                while(temp > 0){


                    sum += v[i];
                    i++;
                    temp--;
                }

                // cout << "sum: " << sum << nl;

                minWeight = min(minWeight, sum);
                maxWeight = max(maxWeight, sum);
            }


            maxi = max(maxi, maxWeight - minWeight);

            // cout << "minWeight: " << minWeight << " maxWeight: " << maxWeight << " maxi: " << maxi <<  nl;

            minWeight = LLONG_MAX;
            maxWeight = LLONG_MIN;

            for(ll i = 0; i < n;){

                ll sum = 0;

                ll temp = choice2;

                while(temp > 0){

                    sum += v[i];
                    i++;
                    temp--;
                }

                // cout << "sum: " << sum << nl;

                minWeight = min(minWeight, sum);
                maxWeight = max(maxWeight, sum);
            }

            maxi = max(maxi, maxWeight - minWeight);

            // cout << "minWeight: " << minWeight << " maxWeight: " << maxWeight << " maxi: " << maxi <<  nl;
        }
    }

    cout << maxi << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n;
        
        cin >> n;

        vector<ll> v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n);

        t--;
    }
}

