#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(vector<int> &v, int n){

    vector<int> pre (n), suf (n);

    int mini = INT_MAX;
    int miniInd = -1;

    for(int i = 0; i < n; i++){

        if(v[i] < mini){
            mini = v[i];
            miniInd = i;
        }

        pre[i] = miniInd;
    }

    mini = INT_MAX;
    miniInd = n;

    for(int i = n-1; i >= 0; i--){

        if(v[i] < mini){
            mini = v[i];
            miniInd = i;
        }

        suf[i] = miniInd;
    }

    for(int i = 0; i < n; i++){

        if(pre[i] != i && suf[i] != i){

            cout << "YES\n";
            cout << pre[i] + 1 << " " << i + 1 << " " << suf[i] + 1 << endl;
            return;
        }
    }

    cout << "NO\n";

    // cout << "\npre: ";

    // for(int i = 0; i < n;i++){

    //     cout << pre[i] << " ";
    // }

    //     cout << "\nsuf: ";

    // for(int i = 0; i < n;i++){

    //     cout << suf[i] << " ";
    // }

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

