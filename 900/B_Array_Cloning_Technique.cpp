#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(vector<int> &v, int n){

    unordered_map<int , int> mp;

    for(auto ele : v) mp[ele]++;

    int maxi = INT_MIN;

    for(auto ele : mp){

        maxi = max(maxi, ele.second);
    }

    if(maxi == n || n == 1){

         cout << 0 << endl;
         return;
    }

    // #steps to generate n 1's (assume 1 to be the max freq element)

    int s = ceil(log2(ceil((double)n/maxi)));

    cout << s + (n - maxi) << endl;

    // cout << "s-1: " << s-1 << " steps to swap: " << maxi * (pow(2, s-1) - 1) << endl;
    // cout << "final: " << s- 1 + 1 << " steps to swap: " << n - maxi - maxi * (pow(2, s-1) - 1) << endl;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        int n;
        
        cin >> n;

        vector<int> v (n);

        for(int i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n);

        t--;
    }
}

