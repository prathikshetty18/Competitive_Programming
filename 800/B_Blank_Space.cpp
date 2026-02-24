#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int n){

    int maxlen = 0;

    int count = 0;

    for(int i = 0; i < n; i++){

        if(arr[i] == 0){

            count++;
        }
        else{

            maxlen = max(maxlen, count);
            count = 0;
        }
    }

    maxlen = max(maxlen, count);

    cout << maxlen << endl;
}

int main(){

    int t;
    cin >> t;

    while(t > 0){

        int n;

        cin >> n;

        vector<int> arr(n);

        for(int i = 0; i < n; i++){

            cin >> arr[i];
        }

        solve(arr, n);

        t--;
    }
}