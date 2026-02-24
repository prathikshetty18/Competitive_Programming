#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(string &s, ll &n){

    unordered_set<char> preSet;
    unordered_set<char> sufSet;

    vector<ll> pre (n);
    vector<ll> suf (n);

    ll count = 0;

    for(ll i = 0; i < n; i++){

        if(preSet.count(s[i]) == 0){

            count++;

            pre[i] = count;
            preSet.insert(s[i]);
        }
        else{

            pre[i] = count;
        }
    }

    count = 0;

    for(ll i = n-1; i >= 0; i--){

        if(sufSet.count(s[i]) == 0){

            count++;

            suf[i] = count;
            sufSet.insert(s[i]);
        }
        else{

            suf[i] = count;
        }
    }

    // for(ll i = 0; i < n; i++){

    //     cout << pre[i] << " ";
    // }

    // cout << endl;


    // for(ll i = 0; i < n; i++){

    //     cout << suf[i] << " ";
    // }

    // cout << endl << endl;

    ll maxi = 0;

    // vector<ll> candidates;

    for(ll i = 0; i < n; i++){

        ll temp = pre[i] + suf[i] - 1;

        if((i > 0 && pre[i] == pre[i-1]) || i < n-1 && suf[i] == suf[i+1]) temp++;

        maxi = max(maxi, temp);

        // if(pre[i] + suf[i] > maxi){

        //     maxi = pre[i] + suf[i];
        //     candidates.clear();
        //     candidates.push_back(i);
        // }
        // else if(pre[i] + suf[i] == maxi){
        //     candidates.push_back(i);
        // }
    }

    cout << maxi << endl;


    // preSet.clear();
    // sufSet.clear();

    // ll ind = 0;

    // for(ll i = 0; i < n; i++){

    //     if(ind < candidates.size() && candidates[ind] == i && preSet.count(s[i]) == 1){

    //         cout << maxi << endl;
    //         return;
    //     }
    //     else if(ind < candidates.size() && candidates[ind] == i && preSet.count(s[i]) == 0){

    //         ind++;
    //     }

    //     preSet.insert(s[i]);
    // }

    // ind = candidates.size()-1;

    // for(ll i = n-1; i >= 0; i--){

    //     if(ind >= 0 && candidates[ind] == i && sufSet.count(s[i]) == 1){

    //         cout << maxi << endl;
    //         return;
    //     }
    //     else if(ind >= 0 && candidates[ind] == i && sufSet.count(s[i]) == 0){

    //         ind--;
    //     }

    //     sufSet.insert(s[i]);
    // }

    // cout << maxi - 1 << endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n;
        
        cin >> n;

        string s;

        cin >> s;

        solve(s, n);

        t--;
    }
}

