#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool checkAllEqual(vector<int> &v, int n){


    for(int i = 1; i < n; i++){

        if(v[i] != v[i-1]){
            
            return false;
        }
    }

    return true;
}

void solve(vector<int> &v, int n){

    if(checkAllEqual(v, n) == true){
        
        cout << "NO\n";
        return;
    }

    sort(v.begin(), v.end(), greater<int>());

    cout << "YES\n";

    if(n >= 2 && v[0] == v[1]){

        swap(v[1], v.back());
    }

    for(int i = 0; i < n; i++){

        cout << v[i] << " ";
    }

    cout << "\n";
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

