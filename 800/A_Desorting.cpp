#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int n){

    int mindiff = 1e9;

    for(int i = 1; i < n; i++){

        if(arr[i] >= arr[i-1]){

            mindiff = min(mindiff, arr[i] - arr[i-1]);
        }
        else{

            cout << 0 << endl;
            return;
        }
    }

    cout << mindiff/2 + 1 << endl;
}

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