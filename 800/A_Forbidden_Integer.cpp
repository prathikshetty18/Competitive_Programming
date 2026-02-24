#include <bits/stdc++.h>
using namespace std;

void solve(int n, int k, int x){

    if(k == 1 && x == 1) cout << "NO\n";
    else if(k == 2 && x == 1 && n%2 == 1) cout << "NO\n";
    else if(k == 2 && x == 1 && n%2 == 0){

        cout << "YES\n";

        cout << n/2 << " " << endl;

        for(int i = 0; i < n/2; i++) cout << 2 << " ";

        cout << endl;
    }
    else if(x != 1){

        cout << "YES\n";

        cout << n << endl;

        for(int i = 0; i < n; i++) cout << 1 << " ";

        cout << endl;
    }
    else{

        if(n % 2 == 0){

            cout << "YES\n";

            cout << n/2 << " " << endl;

            for(int i = 0; i < n/2; i++) cout << 2 << " ";

            cout << endl;
        }
        else{

            cout << "YES\n";

            cout << (n-3)/2 + 1 << " " << endl << 3 << " ";

            for(int i = 0; i < (n-3)/2 ; i++) cout << 2 << " ";

            cout << endl;
        }
    }



}

int main(){

    int t;
    cin >> t;

    while(t > 0){

        int n, k, x;

        cin >> n >> k >> x;

        solve(n, k, x);

        t--;
    }
}
