#include <bits/stdc++.h>
using namespace std;

void solve(vector<pair<int, int> > &arrow){

    int score = 0;

    for(auto it : arrow){

        if(it.first == 0 || it.first == 9 || it.second == 0 || it.second == 9){

            score += 1;    
        }
        else if(it.first == 1 || it.first == 8 || it.second == 1 || it.second == 8){ 

            score += 2;
        }
        else if(it.first == 2 || it.first == 7 || it.second == 2 || it.second == 7){
            
            score += 3;
        }
        else if(it.first == 3 || it.first == 6 || it.second == 3 || it.second == 6){ 

            score += 4;
        }
        else{

            score += 5;
        }

    }

    cout << score << endl;

}

int main(){

    int t;
    cin >> t;

    while(t > 0){

        vector<pair<int, int> > arrow;

        for(int i = 0; i < 10; i++){

            for(int j = 0; j < 10; j++){

                char temp;

                cin >> temp;

                if(temp == 'X'){

                    arrow.push_back(make_pair(i, j));
                }
            }
        }

        solve(arrow);

        t--;
    }
}