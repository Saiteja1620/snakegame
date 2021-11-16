#include <iostream>
#include<conio.h>
using namespace std;
bool gameover;
const int height=20;
const int width=20;
int score,x,y,fx,fy;
enum eDirection {STOP=0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
int tailX[100],tailY[100];
int nTail;
/*
    Setup function is for building the wall
*/
void Setup()
{
    gameover=false;
    dir = STOP;
    x=width/2;
    y=height/2;
    fx=rand()%width;
    fy=rand()%height;
    score=0;
}
void Draw(){
    system("cls");
    for(int i=0;i<width+1;i++)
    cout<<"#";
    cout<<endl;
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(j==0)
            cout<<"#";
            if(i==y&& j==x)
            cout<<"O";
            else if(i==fy && j==fx)
            cout<<"F";
            else
            {
                bool print=false;
                for(int k=0;k<nTail;k++){
                    if(tailX[k]==j && tailY[k]==x){
                        cout<<"o";
                        print=true;
                    }
                }
                if(!print)
                        cout<<" ";
                
            }
            if(j==width-1)
            cout<<"#";
        }
        cout<<endl;
    }
    for(int i=0;i<width+1;i++)
    cout<<"#";
    cout<<endl<<"Total_Score:"<<score<<endl;
    
}
void Input()
{   
    if(_kbhit()){
        switch(_getch()){
            case 'a':   dir=LEFT;
            break;
            case 's':   dir=DOWN;
            break;
            case 'w':   dir=UP;
            break;
            case 'd':   dir=RIGHT;
            break;
            case 'x':   gameover=true;
        }
    }
}
void Logic(){
    int prevX=tailX[0];
    int prevY=tailY[0];
    int prev2X,prev2Y;
    tailX[0]=x;
    tailY[0]=y;
    for(int i=0;i<nTail;i++){
        prev2X=tailX[i];
        prev2Y=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;
    }
    switch(dir){
        case LEFT:
        x--;
        break;
        case RIGHT:
        x++;
        break;
        case UP:
        y--;
        break;
        case DOWN:
        y++;
        break;
        default:
        break;
    }
    if(x>width || x<0 || y>height || y<0){
        gameover=true;
    }
    if(x==fx && y==fy){
        score=score+10;
        fx=rand()%width;
        fy=rand()%height;
    }
}
int main(){
    Setup();
        while(!gameover){
        Draw();
        Input();
        Logic();
        }
    return 0;
}
