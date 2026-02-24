#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int n){

    int plus = 0;
    int minus = 0;

    for(auto it : arr){

        if(it == 1) plus++;
        else minus++;
    }

    if(plus >= minus && minus % 2 == 0){

        cout << 0 << endl;
    }
    else if(plus >= minus && (minus % 2 == 1 || minus % 2 == -1)){

        cout << 1 << endl;
    }
    else if(plus < minus && minus % 2 == 0){

        int steps = ceil((double)(minus-plus)/(double)2);

        if(steps%2 == 1) steps++;

        cout << steps << endl;
    }
    else if(plus < minus && (minus % 2 == 1 || minus % 2 == -1)){

        int steps = ceil((double)(minus-plus)/(double)2);

        if(steps%2 == 0) steps++;

        cout << steps << endl;
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

