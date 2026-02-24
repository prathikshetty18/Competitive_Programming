#include <bits/stdc++.h>
using namespace std;

void solve(string &s, int n){

    int count = 0;

    int prev = -1;

    int maxi = -1;

    for(int i = 0; i < n; i++){


        if(s[i] == '#'){

            count += i-prev-1;
            maxi = max(maxi, i-prev-1);
            prev = i;
        }
        else{
            
            maxi = max(maxi, i-prev);

            if(maxi >= 3){
                count = 2;
                cout << count << "\n";
                return;
            }
        }
    }

    if(prev != n-1) count += n-1-prev;

    cout <<  count << "\n";

    return;
}




int main(){

    int t;
    cin >> t;

    while(t > 0){

        int n;
        string s;

        cin >> n >> s;

        solve(s, n);

        t--;
    }
}
