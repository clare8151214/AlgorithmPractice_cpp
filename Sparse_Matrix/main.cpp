#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
const int ROWS = 8;
const int COLS = 9;
const int NOTZERO = 8;


int main() {
    int i,j,tmprw,tmpcl,tmpnz;
    int temp = 1;
    int sparse[ROWS][COLS] = { };
    int compress[NOTZERO][3];
    srand(time(NULL));
    tmpnz = NOTZERO;
    for (i=1;i<tmpnz+1;i++)
    {
        tmprw = rand() % ROWS;
        tmpcl = rand() % COLS;
        if(sparse[tmprw][tmpcl] != 0)
            tmpnz++;
        sparse[tmprw][tmpcl] = i;
    }
    cout<<"sparse matrix's element"<<endl;
    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<COLS;j++)
            cout<<"["<<sparse[i][j]<<"] ";
        cout<<endl;
    }
    compress[0][0] = ROWS;
    compress[0][1] = COLS;
    compress[0][2] = NOTZERO;
    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<COLS;j++)
        {
            if(sparse[i][j] != 0)
            {
                compress[temp][0] = i;
                compress[temp][1] = j;
                compress[temp][2] = sparse[i][j];
                temp++;
            }
        }
    }
    cout<<"compress matrix"<<endl;
    for(i=0;i<NOTZERO+1;i++)
    {
        for(j=0;j<3;j++)
            cout<<"["<<compress[i][j]<<"] ";
        cout<<endl;
    }
    return 0;
}
