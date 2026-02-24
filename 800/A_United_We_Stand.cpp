#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int n){

    vector<int> a;
    vector<int> b;

    sort(arr.begin(), arr.end());

    a.push_back(arr[0]);

    for(int i = 1; i < n; i++){

        if(a[0] == arr[i]) a.push_back(arr[i]);
        else b.push_back(arr[i]);
    }

    if(b.size() == 0){

        cout << -1 << endl;
        return;
    }
    else{

        cout << a.size() << " " << b.size() << endl;

        for(auto it : a) cout << it << " ";
        cout << endl;
        for(auto it : b) cout << it << " ";
        cout << endl;
        return;
    }

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