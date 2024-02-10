#include<bits/stdc++.h>
using namespace std;
 
class StringStack
{
  public:
    int size;
    vector<string> arr;
    StringStack(int siz)
    {
        size=siz;
    } 
    void push(string ele)
    {
        arr.push_back(ele);
        cout<<ele<<" is pushed into the stack "<<endl;
    }
    string pop()
    {
        string ele=arr.back();
        arr.pop_back();
        return ele;
    }
    void display()
    {
        cout<<endl<<"The Elements of Stack are";;
        for(auto it : arr)
        {
            cout<<" "<<it;
        }
    }

};
int main()
{
    StringStack s(5);
    while(1)
    {
        cout<<endl<<"1.Push 2.pop 3.display 4.exit"<<endl;
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:
              if(s.arr.size()==5)
              cout<<"Stack Overflow"<<endl;
              else
              {
                cout<<"Enter element to be pushed"<<endl;
                string ele;
                cin>>ele;
                s.push(ele);
              }
              break;
            case 2:
                if(s.arr.size()==0)
                cout<<"Stack UNDERFLOW"<<endl;
                else
                {
                    cout<<"The popped ele is"<<s.pop();
                }
                break;

             case 3:
                 s.display();

             case 4: 
                  exit(0);            
        }
    }
    return 0;
}