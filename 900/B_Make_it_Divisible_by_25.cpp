#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(string &s){

    unordered_map<char, stack<int>> mp;

    for(int i = 0; i < s.size(); i++){

        if(s[i] == '0' || s[i] == '2' || s[i] == '5' || s[i] == '7'){

            mp[s[i]].push(i);
        }
    }

    int n = s.size();

    int mini = n;

    if(mp['0'].size() >= 2){

        int temp = 0;

        int x2 = mp['0'].top();
        mp['0'].pop();

        int x1 = mp['0'].top();
        mp['0'].push(x2);

        temp += n - x2 - 1;
        temp += x2 - x1 - 1;


        mini = min(mini, temp);
    }

    if(mp['2'].size() >= 1 && mp['5'].size() >= 1){

        int temp = 0;

        int x2 = mp['5'].top();

        int x1 = mp['2'].top();
        mp['2'].pop();

        while(!mp['2'].empty() && x1 > x2){

            x1 = mp['2'].top();
            mp['2'].pop();
        }

        if(x1 < x2){

            temp += n - x2 - 1;
            temp += x2 - x1 - 1;

            mini = min(mini, temp);
        }
    }


    if(mp['7'].size() >= 1 && mp['5'].size() >= 1){

        int temp = 0;

        int x2 = mp['5'].top();

        int x1 = mp['7'].top();
        mp['7'].pop();

        while(!mp['7'].empty() && x1 > x2){

            x1 = mp['7'].top();
            mp['7'].pop();
        }

        if(x1 < x2){

            temp += n - x2 - 1;
            temp += x2 - x1 - 1;

            mini = min(mini, temp);
        }
    }

    if(mp['5'].size() >= 1 && mp['0'].size() >= 1){

        int temp = 0;

        int x2 = mp['0'].top();

        int x1 = mp['5'].top();
        mp['5'].pop();

        while(!mp['5'].empty() && x1 > x2){

            x1 = mp['5'].top();
            mp['5'].pop();
        }

        if(x1 < x2){

            temp += n - x2 - 1;
            temp += x2 - x1 - 1;

            mini = min(mini, temp);
        }
    }

    cout << mini << endl;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        string s;
        
        cin >> s;        

        solve(s);

        t--;
    }
}

