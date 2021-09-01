#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    srand(time(0));
    map<int,int>snake = {{17,7},{54,34},{64,60},{87,36},{92,73},{95,75},{98,25}};
    map<int,int>ladder = {{2,38},{4,14},{9,31},{21,42},{28,84},{51,67},{72,91},{80,99}};
    int pos1 = 0,pos2 = 0;
    int count = 0;
    string p1 = "player1 ",p2 = "player2 ",win = "wins",lose = "loses like his mom's virginity";
    while(pos1 != 100 && pos2 != 100){
        int chance1 = rand()%6 +1;
        int chance2 = rand()%6 +1;
        if(pos1 == 0 && (chance1 == 1 || chance1 == 6)){
            pos1 += chance1;
        }else if(pos1 !=0 ){
            pos1 += chance1;
            if(snake.find(pos1) != snake.end()){
                pos1 = snake[pos1];
            }
            if(ladder.find(pos1) != ladder.end()){
                pos1 = ladder[pos1];
            }
        }
        if(pos1 == 100){
            break;
        }
        if(pos2 == 0 && (chance2 == 1 || chance2 == 6)){
            pos2 += chance2;
        }else if(pos2 != 0){
            pos2 += chance2;
            if(snake.find(pos2) != snake.end()){
                pos2 = snake[pos2];
            }
            if(ladder.find(pos2) != ladder.end()){
                pos2 = ladder[pos2];
            }
        }
        count++;
        if(pos1>100){
            pos1 -= chance1;
        }
        if(pos2>100){
            pos2 -= chance2;
        }
        cout<<"chance no. "<<count<<" position is: "<<pos1<<" , "<<pos2<<endl;
    }
    cout<< ((pos1==100) ? p1+win+" & "+p2+lose:p2+win+" "+p1+lose) << endl;

    return 0;
}