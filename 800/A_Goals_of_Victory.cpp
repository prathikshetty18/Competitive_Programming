#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int n){

    int ans = 0;

    for(int i = 0; i < n-1; i++){

        ans += arr[i];
    }    

    cout << ans * (-1) << endl;

}

int main(){

    int t;
    cin >> t;

    while(t > 0){

        int n;

        cin >> n;

        vector<int> arr;

        for(int i = 0; i < n-1; i++){

            int temp;

            cin >> temp;

            arr.push_back(temp);
        }

        solve(arr, n);

        t--;
    }
}

/*

x11 x21
x12 x31
x13 x41
x22 x32
x23 x42
x33 x43

x11 + x12 + x13 - (x21 + x31 + x41)
x21 + x22 + x23 - (x11 + x32 + x42)
x31 + x32 + x33 - (x12 + x22 + x43)

x13 + x23 + x33 - (x41 + x42 + x43)

x41 + x42 + x43 - (x13 + x23 + x33)

d1 + d2 + d3 + d4 = 0 (beause every team gets added once and removed once)

=> d4 = -d1 - d2 - d3

*/