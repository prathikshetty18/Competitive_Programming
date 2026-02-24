#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int n){

    int size = 1;

    vector<int> res;

    res.push_back(arr[0]);

    for(int i = 1; i < n; i++){

        if(arr[i] >= arr[i-1]){

            res.push_back(arr[i]);
            size++;
        }
        else{

            res.push_back(1);
            res.push_back(arr[i]);
            size += 2;
        }
    }

    cout << size << endl;

    for(int i = 0; i < size; i++){

        cout << res[i] << " ";
    }

    cout << endl;
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