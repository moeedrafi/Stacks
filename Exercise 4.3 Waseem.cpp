#include<iostream>
using namespace std;
#define size 100
class stack
{
	public:
		int arr[size];
		int top;
		char pop_var;
		int count_pu,count_po;
		stack()
		{
			top = -1;
		}
		void push(char num)
		{
			if(top == size-1)
			{
				cout<<"Stack is full."<<endl<<endl;
			}
			else
			{
				arr[++top] = num;
				cout<<num<<" push in stack"<<endl<<endl;
			}
		}
		void pop()
		{
			if(top == -1)
			{
				cout<<"Stack is Empty."<<endl<<endl;
				cout<<"Invalid Equation.";
				exit(1);
			}
			else
			{
				pop_var = arr[top--];
				cout<<pop_var<<" pop from stack"<<endl<<endl;
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
		void brackets(string str)
		{
			stack s1,s2,s3;
			
			s1.count_pu = 0 , s1.count_po = 0 , s2.count_pu = 0 , s2.count_po = 0 , s3.count_pu = 0 , s3.count_po = 0;
			
			for(int i=0;i<str.length();i++)
			{
				if(str[i] == '(')
				{
					push(str[i]);
					s1.count_pu++;
				}
				else if(str[i] == '{')
				{
					push(str[i]);
					s2.count_pu++;
				}
				else if(str[i] == '[')
				{
					push(str[i]);
					s3.count_pu++;
				}
				else if(str[i] == ')')
				{
					pop();
					s1.count_po++;
				}
				else if(str[i] == '}')
				{
					pop();
					s2.count_po++;
				}
				else if(str[i] == ']')
				{
					pop();
					s3.count_po++;
				}
				else
				{
					continue;
				}
			}
			//if push and pop are not equal so it is invalid equation
			if(s1.count_pu == s1.count_po && s2.count_pu == s2.count_po && s3.count_pu == s3.count_po)
			{
				cout<<"Valid Equation.";
			}
			else
			{
				cout<<"Invalid Equation.";
			}

		}
};
int main()
{
	stack s;
	
	string str;
	cout<<"Enter any Equation : ";
	cin>>str;
	s.brackets(str);
}
