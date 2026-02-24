#include <bits/stdc++.h>
using namespace std;

#define ll long long

int_least16_t solve(vector<int> &v, int n){

    unordered_map<int, int> mp;

    int count2 = 0;

    for(int i = 0; i < n; i++){
        
        if(v[i] == 1) continue;

        count2++;

        mp[count2] = i;
    }

    if(count2 % 2 == 1) return -1;     

    return mp[count2/2] + 1; // 1 based indexing   

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

        cout << solve(v, n) << "\n";

        t--;
    }
}

