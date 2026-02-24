#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl  "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;

void solve(vector<ll> &v, ll &n){

    ll maxi = LLONG_MIN;

    vector<ll> ind (1001, -1);

    for(int i = 0; i < n; i++){

        ind[v[i]] = i;
    }

    // for(int i = 1; i < 17; i++){

    //     cout << ind[i] << sp;
    // }

    // cout << nl;


    for(ll i = 1; i <= 1000; i++){

        for(ll j = 1; j <= i; j++){

            if((ind[i] != -1) && (ind[j] != -1) && gcd(i, j) == 1){

                maxi = max(maxi, ind[i] + ind[j] + 2);
            }
        }
    }

    if(maxi == LLONG_MIN){

        cout << -1 << nl;
    }
    else{

        cout << maxi << nl;
    }

}

// void solve(vector<ll> &v, ll &n){

//     ll maxi = LLONG_MIN;
//     ll end, start;
//     bool flag = false;

//     for(ll i = n-1; i >= 0 && !flag; i--){

//         for(ll j = i; j >= 0; j--){

//             if(gcd(v[i], v[j]) == 1){

//                 end = i;
//                 start = j;
//                 maxi = start + end + 2; 
//                 flag = true;
//                 break;
//             }
//         }
//     }

//     if(maxi == LLONG_MIN){

//         cout << -1 << nl;
//         return;
//     }


//     for(ll i = end-1; i > start; i--){

//         for(ll j = i-1; j > start; j--){

//             if(gcd(v[i], v[j]) == 1){

//                 end = i;
//                 start = j;
//                 maxi = start + end + 2;
//                 // cout << "start: " << start << " end: " << end << " maxi: " << maxi << nl; 
//                 break;
//             }
//         }
//     }


//     cout << maxi << nl;
// }

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

