#include <bits/stdc++.h>
using namespace std;

bool check_substring(string &s1, string &s2, int n, int m){

    // s1: abbabbabbabb 
    // s2: babba 

    // int i = 0;
    // int j = 0;
    // int nextstart = 1;

    // while(i < n && j < m){

    //     // cout << "i: " << i << " j: " << j << " n: " << n << " m: " << m << endl;

    //     if(s1[i] == s2[j]){

    //         i++;
    //         j++;

    //         if(j == 1) nextstart = i;

    //         if(j == m) return true;
    //     }
    //     else{

    //         i = nextstart;
    //         j = 0;
    //     }
    // }

    // return false;

    if(s1.find(s2) != string::npos) return true;
    else return false;
}

void solve(string &s1, string &s2, int n, int m){

    int steps = 0;

    while(n < m){

        s1 = s1 + s1;
        n = 2 * n;
        steps++;
    }

    if(n >= m){ 
        
        // we only only double once as then the new substrings will be from size (2 -> 2*n) if it is the first time we double otherwise lower bound will be > n as substrings from (2, n) would have been gotten when doubling before;
        // we only double 1 more time if required as after that doubling will only lead to new substrings whose size are > 2*n > m since n > m, thus those substrings won't be s2 which is of size m;

        if(check_substring(s1, s2, n, m) == true){
            
            cout << steps << endl;
            return;
        }
        else{

            s1 = s1 + s1;
            n = 2 * n;
            steps++;

            // cout << "s1: " << s1 << " s2: " << s2 << " steps: " << steps << endl;

            if(check_substring(s1, s2, n, m) == true){
                
                cout << steps << endl;
                return;
            }
            else{

                cout << -1 << endl;
                return;
            }
        }
    }
}

int main(){

    int t;
    cin >> t;

    while(t > 0){

        int n, m;

        cin >> n >> m;

        string s1;
        string s2;

        cin >> s1 >> s2;

        solve(s1, s2, n, m);

        t--;
    }
}
