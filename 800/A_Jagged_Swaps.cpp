#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int n){

    if(arr[0] != 1) cout << "NO\n";
    else cout << "YES\n";

    return;
}

// maybe if 0 index is not correctly placed output "NO" otherwise "YES"

// other "YES" always works that note that the greatest element if not in the right pos can always be swapped rightwards till it reached it's right pos
// now first and last are right, so do the same for (1, n-1), which will also have it's own greatest element which gets swapped rightwards till it's in
// the right pos and so on

int main(){

    int t;
    cin >> t;

    while(t > 0){

        int n;

        cin >> n;

        vector<int> arr;

        for(int i = 0; i < n; i++){

                int temp;

                cin >> temp;

                arr.push_back(temp);
        }

        solve(arr, n);

        t--;
    }
}