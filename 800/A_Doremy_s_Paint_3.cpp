#include <bits/stdc++.h>
using namespace std;

void solve(unordered_map<int, int> &mp, int n){

    if(mp.size() > 2) cout << "No\n";
    else if(mp.size() == 1) cout << "Yes\n";
    else{

        auto it = mp.begin();

        int freq1 = it->second;

        it++;

        int freq2 = it->second;

        if(abs(freq1 - freq2) > 1) cout << "No\n";
        else cout << "Yes\n";

    }

}

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