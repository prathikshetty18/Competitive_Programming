#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(int n){

    if(n % 2 == 0){

        cout << -1 << endl;
        return;
    }

    int output = n;

    for(int i = 1; i <= n/2; i++){

        cout << output << " ";
        output--;
    }

    for(int i = 1; i <= output; i++){

        cout << i << " ";
    }

    cout << endl;
}

int main(){

    int t;
    cin >> t;

    while(t > 0){

        int n;

        cin >> n;

        solve(n);

        t--;
    }
}


