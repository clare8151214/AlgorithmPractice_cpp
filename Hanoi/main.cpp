#include <iostream>
using namespace std;
void hanoi(int n,int p1,int p2,int p3)
{
    if(n==1)
        cout<<"plate move from "<<p1<<" to "<<p3<<endl;
    else
    {
        hanoi(n-1,p1,p3,p2);
        cout<<"plate move from "<<p1<<" to "<<p3<<endl;
        hanoi(n-1,p2,p1,p3);
    }
}
int main() {
    int n;
    cin>>n;
    hanoi(n,1,2,3);
    return 0;
}
