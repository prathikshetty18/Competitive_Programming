#include <bits/stdc++.h>
using namespace std;

void solve(int A, int B, int C){

    int countA = A + ceil((double)C/(double)2);
    int countB = B + C/2;

    if(countA > countB){

        cout << "First\n";
        return;
    }
    else{

        cout << "Second\n";
        return;
    }

}

int main(){

    int t;
    cin >> t;

    while(t > 0){

        int A, B, C;

        cin >> A >> B >> C;

        solve(A, B, C);

        t--;
    }
}