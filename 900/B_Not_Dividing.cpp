#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(vector<int> &v, int n){




    for(int i = 0; i < n; i++){

        // to deal with the case of 3 6 which can be divided

        if(v[i] % v[i-1] == 0) v[i]++; 

        cout << v[i] << " ";
    }

    cout << endl;

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

        for(int i = 0; i < n; i++){
            
            cin >> v[i] ;
            
            v[i]++;     // first n operations to remove anys 1s if present
        }


        solve(v, n);

        t--;
    }
}

