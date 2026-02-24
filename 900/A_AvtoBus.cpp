#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(ll n){

    bool divBy4 = (n % 4 == 0);
    bool divBy6 = (n % 6 == 0);



    if(!divBy4 && !divBy6){

        if(n != 2 && (n + 2) % 12 == 0){

            cout << 1 + (n-4)/6 << " " << 1 + (n-6)/4 << endl;
        }
        else if(n != 2 && (n - 2) % 12 == 0){

            cout << 2 + (n-8)/6 << " " << 1 + (n-6)/4 << endl;
        }
        else{
            cout << -1 << endl;
        }

    }
    else if(!divBy4 && !divBy6){

        cout << n/6 << " " << 1 + (n-6)/4 << endl;
    }
    else if(divBy4 && !divBy6){

        if((n-4) % 6 == 0){

            cout << (n-4)/6 + 1 << " " << n/4 << endl;
        }
        else if((n-8) % 6 == 0){
            
            cout << (n-8)/6 + 2 << " " << n/4 << endl;
        }
    }
    else{   // Divisible by Both

        cout << n/6 << " " << n/4 << endl;
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n;
        
        cin >> n;

        solve(n);

        t--;
    }
}

