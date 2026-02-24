#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(vector<int> &v, int n, int l , int r , int k, unordered_map<int, int> &mp, int totalSum){

    int sumInRange = mp[r] - mp[l-1];

    int newSum = totalSum - sumInRange + (r - l + 1) * k; 

    if(newSum % 2){

        cout << "YES\n";
    }
    else{
        
        cout << "NO\n";
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        int n, q;
        
        cin >> n >> q;

        vector<int> v (n);

        unordered_map<int, int> mp;

        mp[0] = 0;

        int currSum = 0;

        for(int i = 0; i < n; i++){
            
            cin >> v[i];

            currSum += v[i];

            mp[i+1] = currSum;
        }

        while(q > 0){

            int l, r, k;

            cin >> l >> r >> k;
            
            solve(v, n, l , r , k, mp, currSum);

            q--;
        }

        t--;
    }
}

