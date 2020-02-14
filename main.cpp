#include <iostream>

using namespace std;

class Stack
{
private:
    int Tos;
    int Size;
    int* arr;

public:
    Stack ()
    {
        Tos = -1;


    }

    Stack ( int _Size)
    {
        Tos = -1;
        Size = _Size;
        arr = new int [Size];

    }


    void push( int value)
    {
        if(Tos<Size-1)
        {
            Tos ++;
            arr[Tos] = value;

/*
                cout << "Tos is :" << Tos << "\n";
                cout << "The value is:"<<arr[Tos] <<"\n";
                cout << "The address is :" << &arr[Tos]<<"\n"; */

        }
    }

    int IsEmpty()
    {
        if(Tos == -1)
            return 1;
        else
            return 0;

    }
    int pop()
    {
        if( Tos>-1 && Tos <Size-1 )
        {
            int x = arr[Tos];
            Tos --;
            return x;
        }
        else
            cout <<"\n"<<" This value is invalid"<<"\n";
    }

     Stack (const Stack & s)
    {
            Tos = s.Tos;
            Size = s.Size;
            arr = new int[Size];
            for(int i=0;i<=Tos ;i++)
            {
                arr[i] = s.arr[i];
            }
    }

    friend void viewContent(Stack & s);

    Stack operator=(const Stack & S)
    {
      Tos = S.Tos;
      Size = S.Size;
      delete arr;
      arr = new int [Size];
      for(int i=0;i<=S.Tos ;i++)
      {
          arr[i] =S.arr[i];

      }
      return *this;
    }

    Stack operator+(Stack & S)
    {
        Stack res;
        res.Size = Size + S.Size;
        delete res.arr;
        res.arr = new int[res.Size];
        //Stack res(Size + S.Size);
        for(int i=0 ; i <= Tos ; i++)
            res.push(arr[i]);
        for(int i=0;i<=S.Tos ; i++)
            res.push(S.arr[i]);
        return res;
    }


    ~Stack()
    {

         delete []arr;
    }


};
 void myfun(Stack s1)
 {
     cout<<"pop values"<<"\n"<<s1.pop();
 }

 void viewContent(Stack& s)
 {
     for(int i=0;i<=s.Tos;i++)
        cout<< "\n"<<s.arr[i];
 }
int main()
{

    Stack S1(5);

    S1.push(10);
    S1.push(5);
    S1.push(8);
    S1.push(4);
    S1.push(1);
    //viewContent(S1);

    Stack S2(3);

    S2.push(2);
    S2.push(4);
    S2.push(7);
    //viewContent(S2);

    Stack S3;
    S3 = S1 + S2;
    viewContent(S3);


    /*
    if(S.IsEmpty()==0)
        cout << S.pop();
*/

  // myfun(S3);
  // viewContent(S3);
    return 0;
}
