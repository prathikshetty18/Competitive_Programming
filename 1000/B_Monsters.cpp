
#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(priority_queue <pair<ll, ll>> &pq, ll &n, ll &k){

    vector<ll> ans;

    while(!pq.empty()){

        ll curr = pq.top().first;
        ll ind = pq.top().second;
        pq.pop();



        ans.push_back(n - ind);
    }

    for(auto ele : ans){

        cout << ele << " ";
    }

    cout << endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n, k;
        
        cin >> n >> k;

        priority_queue <pair<ll, ll>> pq; 

        ll temp;

        for(ll i = 0; i < n; i++){

            cin >> temp;

            pq.push({temp % k == 0 ? k : temp % k, n - (i+1)});
        } 

        solve(pq, n, k);

        t--;
    }
}


// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long

// void solve(vector<ll> &v, ll &n, ll &k){

//     vector<vector<ll>> temp (k+1);

//     for(int i = 0; i < n; i++){

//         temp[v[i]].push_back(i+1);
//     }

//     vector<ll> ans;

//     for(int i = k; i >= 0; i--){

//         for(auto ele : temp[i]){

//             ans.push_back(ele);
//         }
//     }

//     for(auto ele : ans){

//         cout << ele << " ";
//     }

//     cout << endl;

// }

// int main(){

//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;

//     while(t > 0){

//         ll n, k;
        
//         cin >> n >> k;

//         vector<ll> v (n);

//         for(ll i = 0; i < n; i++){
            
//             cin >> v[i]; 

//             v[i] = v[i] % k == 0 ? k : v[i] % k;
//         }

//         solve(v, n, k);

//         t--;
//     }
// }



