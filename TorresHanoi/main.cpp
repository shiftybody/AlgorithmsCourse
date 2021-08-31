#include <iostream>
using namespace std;
void hanoi (int, char, char, char);

int main()
{
    int n;
    char auxiliar,B,C;

    cin>>n;
    hanoi(n,'A','C','B');

}

void hanoi(int n,char A,char C,char B)
{
    if(n ==1 )
    {
        cout<<"Mover el disco "<< n<<" de "<<A<<" a "<<C<<endl;
    }
    else
    {
        hanoi(n-1,A,B,C);
        cout<<"Mover el disco "<<n<<" de "<<A<<" a "<<C<<endl;
        hanoi(n-1,B,C,A);
    }
}

