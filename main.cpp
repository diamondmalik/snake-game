#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
class snake{
bool gameover;
const int width = 20;
const int height = 20;
int x,y; //coordinates of head
int fruitx,fruity;
int score;
enum eDirection{stop=0,left,right,up,down};
eDirection dir;
//for tail now,
int tailx[100],taily[100];
int ntail; //this specifies length of tail
public:
    void setup(){
    gameover = false;
    dir = stop; //snake moves only after we start moving it
    x = width/2;y=height/2; // snake centered in middle
    fruitx = rand()%width;
    fruity = rand()%height;
    score = 0;
    }
    void draw(){
//top
for(int i = 0;i<width+2;i++)
    cout << "#";
cout << endl;
//middle
for(int i = 0;i<height;i++){
    for(int j = 0;j<width;j++){
        if(j==0)
            cout << "#";
        if(i==y && j==x)
            cout << "O"; //head
        else if(i==fruity&&j==fruitx)
            cout << "F";
        else{
                bool print = false;
        for(int k = 0; k<ntail;k++){
            if(tailx[k]==j&&taily[k]==i){
                cout << "o";
                print = true;
            }
        }
        if(!print)
            cout << " ";}
        if(j==width-1)
            cout << "#";
    }
    cout << endl;
}
//bottom
for(int i = 0;i<width+2;i++)
    cout << "#";

cout << "SCORE" << score << endl;
}
    void input(){
    if(_kbhit()){
        switch(_getch()){
      case 'a':
        dir = left;
        break;
      case 'd':
        dir = right;
        break;
      case 's':
        dir = down;
        break;
       case 'w':
        dir = up;
        break;
        }
    }
    }
    void logic(){
    int prevx = tailx[0];
    int prevy = taily[0];
    int prev2x,prev2y;
    tailx[0] = x;
    taily[0] = y;
    for(int i = 1;i<ntail;i++){
        prev2x = tailx[i];
        prev2y = taily[i];
        tailx[i] = prevx;
        taily[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;
    }
    switch(dir){
        case left:
            x--;
            break;
         case right:
            x++;
            break;
         case up:
            y--;
            break;
        case down:
            y++;
            break;
    }
    if(x>width||x<0||y>height||y<0)
        gameover = true;
    for(int i = 0; i<ntail;i++){
        if(tailx[i]==x&&taily[i]==y)
            gameover = true;
    }
    if(x==fruitx&&y==fruity){
        score+=10;
        fruitx = rand()%width;
        fruity = rand()%height;
    }
    if(x==fruitx&&y==fruity)
        ntail++;
    }
    bool get_status(){
    return gameover;}
};
int main(){
snake s;
s.setup();
while(!s.get_status()){
    s.draw();
    s.input();
    s.logic();
}

}
