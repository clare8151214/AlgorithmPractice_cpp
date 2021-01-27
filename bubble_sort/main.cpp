#include <iostream>
#include <iomanip>
using namespace std;

void normal_bubbleSort(int data[])
{
    for(int i=5;i>=0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(data[j]>data[j+1])
                swap(data[j],data[j+1]);
        }
        cout<<"��"<<6-i<<"���Ƨǫ᪺���G�O:";
        for(int j=0;j<6;j++)
            cout<<data[j]<<" ";
        cout<<endl;
    }
    cout<<"�Ƨǫᵲ�G:";
    for (int i=0;i<6;i++)
        cout<<data[i]<<" ";
    cout<<endl;
}
void Improved_bubbleSort(int data[])
{

    for(int i=5;i>=0;i--)
    {
        int flag=0;
        for(int j=0;j<i;j++)
        {
            if(data[j]>data[j+1])
            {
                swap(data[j],data[j+1]);
                flag++;
            }
        }
        if(flag==0)
            break;
        cout<<"��"<<6-i<<"���Ƨǫ᪺���G�O:";
        for(int j=0;j<6;j++)
            cout<<data[j]<<" ";
        cout<<endl;
    }
    cout<<"�Ƨǫᵲ�G:";
    for (int i=0;i<6;i++)
        cout<<data[i]<<" ";
    cout<<endl;
}
int main() {
    int data[6] = {4,6,2,7,8,9};
    cout<<"bubblesort:\nnot sorted:";
    for (int i=0;i<6;i++)
        cout<<data[i]<<" ";
    cout<<endl;
    //normal_bubbleSort(data);
    Improved_bubbleSort(data);
    return 0;
}
