#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(vector<int> &v, int n){

    int count = 0;

    for(int i = n-2; i >= 0; i--){

        while(v[i] >= v[i+1] && v[i] > 0){

            v[i] /= 2;
            count++;
        }

        if(v[i] == v[i+1]){

            cout << -1 << endl;
            return;
        }
    }

    cout << count << endl;

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

