#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl  "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n;
        
        cin >> n;

        vector<ll> v (n);

        ll negCount = false;
        ll mini = LLONG_MAX;
        ll sum = 0;

        for(ll i = 0; i < n; i++){
            
            cin >> v[i]; 

            if(v[i] < 0) negCount++;
            mini = min(mini, abs(v[i]));
            sum += abs(v[i]);
        }

        if(negCount % 2){

            cout << sum - 2*mini << nl;
        }
        else{
            cout << sum << nl;
        }

        t--;
    }
}

