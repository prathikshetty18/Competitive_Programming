#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int n){

    int count = 0;

    for(int i = 1; i < n; i++){

        if(arr[i] % 2 == arr[i-1] % 2) count++;
    }

    cout << count << endl;

    return;
}


int main(){

    int t;
    cin >> t;

    while(t > 0){

        int  n;
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