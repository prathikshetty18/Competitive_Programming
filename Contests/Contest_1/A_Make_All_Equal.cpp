#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(unordered_map<int, int> &mp, int n){

    int maxi = 0;

    for(auto it : mp){

        maxi = max(maxi, it.second);
    }

    cout << n - maxi << endl;
}

// any case you can always delete from the answer common value
// if a < ans < b, delete a or b next step
// if a > ans > b, delete b next step
// if a == ans == b, delete a or b next step

int main(){

    int t;
    cin >> t;

    while(t > 0){

        int n;

        cin >> n;

        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++){

            int temp;

            cin >> temp;

            mp[temp]++;
        }

        solve(mp, n);

        t--;
    }
}