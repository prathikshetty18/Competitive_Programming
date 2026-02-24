#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int n){

    int mindiff = 1e9;

    for(int i = 0; i < n; i++){

        mindiff = min(mindiff, abs(arr[i]));
    }

    cout << mindiff << endl;

}

int main(){

    int n;

    cin >> n;

    vector<int> arr;

    for(int i = 0; i < n; i++){

        int temp;

        cin >> temp;

        arr.push_back(temp);
    }

    solve(arr, n);
}