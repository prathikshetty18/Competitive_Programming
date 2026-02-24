#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(int n, int k, vector<int> &arr){

    if(k == 1){

        for(int i = 1; i < arr.size(); i++){

            if(arr[i] < arr[i-1]){

                cout << "NO\n";
                return;
            }
        }
    }


    cout << "YES\n";
    return;

    // test
}

int main(){

    int t;
    cin >> t;

    while(t > 0){

        int n, k;
        cin >> n >> k;

        vector<int> arr;

        for(int i = 0; i < n; i++){

            int temp;
            cin >> temp;

            arr.push_back(temp);
        }

        solve(n, k, arr);

        t--;
    }
}