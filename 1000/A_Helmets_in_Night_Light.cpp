#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool comp(pair<ll, ll> &a, pair<ll, ll> &b){

    if(a.second != b.second){

        return a.second < b.second;
    }
    else{

        return a.first > b.first;
    }
}

void solve(vector<pair<ll, ll>> &people, ll &n, ll &p){


    people.push_back({n-1, p});

    sort(people.begin(), people.end(), comp);

    // for(int i = 0; i < n; i++){

    //     cout << "p" << i + 1 << ": " << people[i].first << " c" << i+1 << ": " << people[i].second << endl;
    // }

    // cout << endl;

    ll count = 1;
    ll cost = p;

    for(int i = 0; i < n; i++){

        
        if(count + people[i].first < n){

            count += people[i].first;
            cost += people[i].first * people[i].second;
            continue;
        }

        // we can inform everyone now

        int rem = n - count;
        cost += rem * people[i].second;

        break;
    }

    cout << cost << endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n, p;
        
        cin >> n >> p;

        vector<pair<ll, ll>>  people(n);

        for(ll i = 0; i < n; i++) cin >> people[i].first; 
        for(ll i = 0; i < n; i++) cin >> people[i].second; 
        
        solve(people, n, p);

        t--;
    }
}

