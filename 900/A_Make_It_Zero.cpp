#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(vector<int> &v, int n){

    if(n % 2){

        cout << 4 << "\n";
        cout << 1 << " " << n-1 << "\n";
        cout << 1 << " " << n-1 << "\n";
        cout << n-1 << " " << n << "\n";
        cout << n-1 << " " << n << "\n";

    }
    else{

        cout << 2 << "\n";
        cout << 1 << " " << n << "\n";
        cout << 1 << " " << n << "\n";
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        int n;
        
        cin >> n;

        vector<int> v (n);

        for(int i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n);

        t--;
    }
}


/*

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(vector<int> &v, int n){

    if(n % 2){

        int ans = 0;

        for(int i = 0; i < n-1; i++){

            ans ^= v[i];
        }

        for(int i = 0; i < n-1; i++){

            v[i] = ans;
        }

        ans = 0;

        for(int i = 0; i < n-1; i++){

            ans ^= v[i];
        }

        for(int i = 0; i < n-1; i++){

            v[i] = ans;
        }

        v[n-1] ^= v[n-1];
    }
    else{

        int ans = 0;

        for(int i = 0; i < n; i++){

            ans ^= v[i];
        }

        for(int i = 0; i < n; i++){

            v[i] = ans;
        }

        ans = 0;

        for(int i = 0; i < n; i++){

            ans ^= v[i];
        }

        for(int i = 0; i < n; i++){

            v[i] = ans;
        }
    }

    for(int i = 0; i < n; i++){

        cout << v[i] << " ";
    }

    cout << endl;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        int n;
        
        cin >> n;

        vector<int> v (n);

        for(int i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n);

        t--;
    }
}

*/

