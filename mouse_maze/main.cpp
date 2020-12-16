#include <iostream>
#define EAST MAZE[x][y+1]
#define WEST MAZE[x][y-1]
#define SOUTH MAZE[x+1][y]
#define NORTH MAZE[x-1][y]
using namespace std;
const int exitX = 8;
const int exitY = 10;
struct list{
    int x,y;
    struct list* next;
};
typedef struct list node;
typedef node* link;
int MAZE[10][12] = {1,1,1,1,1,1,1,1,1,1,1,1,
                    1,0,0,0,1,1,1,1,1,1,1,1,
                    1,1,1,0,1,1,0,0,0,0,1,1,
                    1,1,1,0,1,1,0,1,1,0,1,1,
                    1,1,1,0,0,0,0,1,1,0,1,1,
                    1,1,1,0,1,1,0,1,1,0,1,1,
                    1,1,1,0,1,1,0,1,1,0,1,1,
                    1,1,1,1,1,1,0,1,1,0,1,1,
                    1,1,0,0,0,0,0,0,1,0,0,1,
                    1,1,1,1,1,1,1,1,1,1,1,1};
link push(link stack,int x,int y)
{
    link newnode;
    newnode = new node;
    if(!newnode)
    {
        cout<<"Error"<<endl;
        return NULL;
    }
    newnode->x = x;
    newnode->y = y;
    newnode->next = stack;
    stack = newnode;
    return stack;
}
link pop(link stack,int* x,int* y)
{
    link top;
    if(stack!=NULL)
    {
        top = stack;
        stack = stack->next;
        *x = top->x;
        *y = top->y;
        delete top;
        return stack;
    }
    else
        *x = -1;
    return stack;
}
int chkExit(int x, int y,int ex,int ey)
{
    if(x==ex && y==ey)
    {
        if(NORTH == 1 || SOUTH == 1 || WEST == 1 || EAST == 2)
            return 1;
        if(NORTH == 1 || SOUTH == 1 || WEST == 2 || EAST == 1)
            return 1;
        if(NORTH == 1 || SOUTH == 2 || WEST == 1 || EAST == 1)
            return 1;
        if(NORTH == 2 || SOUTH == 1 || WEST == 1 || EAST == 1)
            return 1;
    }
    return 0;
}
int main() {
    int i,j;
    link path = NULL;
    int x=1,y=1;
    cout<<"MAZE0"<<endl;
    for (i=0;i<10;i++)
    {
        for(j=0;j<12;j++)
            cout<<MAZE[i][j]<<" ";
        cout<<endl;
    }
    while(x<=exitX && y<=exitY)
    {
        MAZE[x][y]  = 2;
        if(NORTH == 0)
        {
            x--;
            path = push(path,x,y);
        }
        else if(SOUTH == 0)
        {
            x++;
            path = push(path,x,y);
        }
        else if(WEST == 0)
        {
            y--;
            path = push(path,x,y);
        }
        else if(EAST == 0)
        {
            y++;
            path = push(path,x,y);
        }
        else if(chkExit(x,y,exitX,exitY))
            break;
        else
        {
            MAZE[x][y]=2;
            path = pop(path,&x,&y);
        }
    }
    cout<<"MAZE2"<<endl;
    for (i=0;i<10;i++)
    {
        for(j=0;j<12;j++)
            cout<<MAZE[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
