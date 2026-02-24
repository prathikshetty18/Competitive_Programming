#include <bits/stdc++.h>
using namespace std;

void solve(int n, int x, vector<int> &arr){

    int maxi = -1;

    int size = arr.size();

    for(int i = 1; i < size-1; i++){

        maxi = max(maxi, arr[i] - arr[i-1]);
    }

    maxi = max(maxi, 2*(arr[size-1] - arr[size-2]));

    cout << maxi << endl;

    return; 
}


int main(){

    int t;
    cin >> t;

    while(t > 0){

        int n, x;

        cin >> n >> x;

        vector<int> arr;

        arr.push_back(0);

        for(int i = 0; i < n; i++){

            int temp;

            cin >> temp;

            arr.push_back(temp);
        }

        arr.push_back(x);

        solve(n, x, arr);

        t--;
    }
}