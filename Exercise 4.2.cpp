#include<iostream>
using namespace std;
#define size 10
class stack
{
	public:
		int arr[size];
		int top;
		stack()
		{
			top = -1;
		}
		void push(int num)
		{
			if(top == size-1)
			{
				cout<<"Stack is full."<<endl;
			}
			else
			{
				arr[++top] = num;
				cout<<num<<" push in stack"<<endl;
			}
		}
		void pop()
		{
			if(top == -1)
			{
				cout<<"Stack is Empty."<<endl;
			}
			else
			{
				cout<<arr[top--]<<" pop from stack"<<endl;
			}
		}
		void display()
		{
			cout<<"Display is : "<<endl;
			for(int i=top;i>=0;i--)
			{
				cout<<arr[i]<<endl;
			}
		}
};
int main()
{
	stack s;
	int num,remainder = 0;
	cout<<"Enter Decimal Number : ";
	cin>>num;
	while(num>1)
	{
		remainder = num%2;
		num = num/2;
		s.push(remainder);
	}
	s.push(num);
	//s.pop();
	s.display();
}
