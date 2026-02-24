#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

void fixMap(ll currInd, ll prevInd, vector<ll> &v, unordered_map<ll, ll> &mp, ll &n, ll diff){

        // cout << "currInd: " << currInd + 1 << " prevInd: " << prevInd << nl;

        mp.erase(diff);

        swap(v[currInd], v[prevInd-1]);

        ll newDiff = prevInd - v[prevInd-1];

        // cout << "newDiff: " << newDiff << nl;  
        
        ll NewprevInd = mp[newDiff];

        while(NewprevInd != 0){

            fixMap(prevInd-1, NewprevInd, v, mp, n, newDiff);
            newDiff = prevInd - v[prevInd-1];
            NewprevInd = mp[newDiff];
        }

        newDiff = prevInd - v[prevInd-1];

        mp[newDiff] = prevInd;
}

void solve(vector<ll> &v, ll &n){

    unordered_map<ll, ll> mp; // diff, ind

    for(ll i = 0; i < n; i++){

        ll diff = (i+1) - v[i];

        // cout << "diff: " << diff << endl;

        ll prevInd = mp[diff];

        while(prevInd != 0){

            fixMap(i, prevInd, v, mp, n, diff);
            diff = (i+1) - v[i];
            prevInd = mp[diff];
        }

        diff = (i+1) - v[i];

        mp[diff] = i+1;

    }

    // for(auto it : mp){

    //     cout << it.first << ": " << it.second << endl;
    // }
    
    // cout << "ans: " << sp;
    for(auto ele : v){

        cout << ele << sp;
    }

    cout << nl;
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

