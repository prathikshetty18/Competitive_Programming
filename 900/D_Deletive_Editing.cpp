#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(string &start, string &end){

    unordered_map<char, stack<int>> mp;

    // start = '$' + start;
    // end = '$' + end;

    int n = start.size();
    int m = end.size();

    if(m > n){

        cout << "NO\n";
        return;
    }


    for(int i = 0; i < n; i++){

        mp[start[i]].push(i);   // mark last occurence
    }

    // for the word to be possible, the last occurence of each letter must occur one after another we won't be able to trim repeating letters on the right side of the word

    for(int i = m-1; i > 0; i--){

        if(mp[end[i]].empty() || mp[end[i-1]].empty() || mp[end[i]].top() < mp[end[i-1]].top()){

            cout << "NO\n";
            return;
        }

        mp[end[i]].pop();
    }

    if(!mp[end[0]].empty()){    // handle same chars as then their last index will be the same so we need to ensure that the last char exists after popping last but 1 char as we don't check last char in the loop again

        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        string start, end;    // need to get end from start

        cin >> start >> end;

        solve(start, end);

        t--;
    }
}

