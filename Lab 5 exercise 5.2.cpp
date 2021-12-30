#include<iostream>
using namespace std;
#define size 10
class stack
{
	private:
		int arr_num[size];
		char arr_letter[size];
		
	public:
		int top;
		stack()
		{
			top = -1;
		}
		char current_char()
		{
			return arr_letter[top];
		}
		void push_num(int num)
		{
			if(top == size-1)
			{
				cout<<"Stack is Full"<<endl;
			}
			else
			{
				arr_num[++top] = num;
			}
		}
		int pop_num()
		{
			if(empty())
			{
				cout<<"Stack is empty."<<endl;
			}
			else
			{
				int pop_num = arr_num[top--];
				return pop_num;
			}
		}
		void push_char(char letter)
		{
			if(top == size-1)
			{
				cout<<"Stack is Full"<<endl;
			}
			else
			{
				arr_letter[++top] = letter;
			}
		}
		int pop_char()
		{
			if(empty())
			{
				cout<<"Stack is empty."<<endl;
			}
			else
			{
				char pop_num = arr_letter[top--];
				return pop_num;
			}
		}
		bool empty()
		{
			if(top == -1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
};
int main()
{
	stack Operand, Operator;
	string str;
	cout<<"Enter any String : ";
	cin>>str;
	for(int i=0;i<str.length();i++)
	{
		int x = (int)str[i]-48;    //char to int
		
		if(str[i] == '(' || str[i] == '{' || str[i] == '[' || str[i] == ')' || str[i] == '}' || str[i] == ']')
		{
			cout<<"Don't use Brackets in String.";
			exit(1);
		}
		else if(str[i] == '+' || str[i] == '-')
		{
			if(Operator.current_char() == '*' || Operator.current_char() == '/')
			{
				char character = Operator.pop_char();
				int num1 = Operand.pop_num();
				int num2 = Operand.pop_num();
				if(character == '*')
				{
					Operand.push_num(num2*num1);
				}
				else
				{
					Operand.push_num(num2/num1);
				}
			}
			Operator.push_char(str[i]);
		}
		else if(str[i] == '*' || str[i] == '/')
		{
			Operator.push_char(str[i]);
		}
		else if(x>=0 && x<=9)
		{
			Operand.push_num(x);
		}
	}
	while(!Operator.empty())
	{
		char charcter = Operator.pop_char();
		int num1 = Operand.pop_num();
		int num2 = Operand.pop_num();
		if(charcter == '+')
		{
			Operand.push_num(num2+num1);
		}
		else if(charcter == '-')
		{
			Operand.push_num(num2-num1);
		}
		else if(charcter == '*')
		{
			Operand.push_num(num2*num1);
		}
		else
		{
			Operand.push_num(num2/num1);
		}
	}
	cout<<"Answer is : "<<Operand.pop_num();
}
