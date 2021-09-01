#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    srand(time(0));
    map<int,int>snake = {{17,7},{21,15},{23,6},{29,15},{35,18},{47,32},{52,38},{71,34},{82,59},{95,78},{99,9}};
    map<int,int>ladder = {};
    // {2,18},{11,31},{12,28},{22,40},{36,62},{41,59},{46,55},{70,94},{77,84},{85,97}
    vector<int>pos;
    pos.resize(10,0);
    int count = 0;
    pair<int,int>best = {0,0}; 
    string win = " wins";
    while(best.second != 100){
        for(int i=0;i<10;i++){
            int chance = rand()%6 +1;
            if(pos[i] == 0 && (chance == 1 || chance == 6)){
                pos[i] += chance;
            }else if(pos[i] !=0 ){
                pos[i] += chance;
                if(snake.find(pos[i]) != snake.end()){
                    pos[i] = snake[pos[i]];
                }
                if(ladder.find(pos[i]) != ladder.end()){
                    pos[i] = ladder[pos[i]];
                }
            }
            if(pos[i]>100){
                pos[i] -= chance;
            }
            if(pos[i]>best.second){
                best = {i,pos[i]};
            }
        }
        count++;
        cout<<"chance no. "<<count<<" position is: ";
        for(int i=0;i<10;i++){
            cout<<pos[i]<<",";
        }
        cout<<endl;
        // cout<<"chance no. "<<count<<" position is: "<<pos1<<" , "<<pos2<<endl;
    }
    cout<<"player "<<best.first + 1<<win<< endl;

    return 0;
}