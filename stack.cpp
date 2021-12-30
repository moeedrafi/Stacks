#include<iostream>
#define size 20
using namespace std;
class stack{
	private:
		int top;
		char arr[size];
	public:
		stack()
		{
			
			top=-1;
		}
		void push(char c)
		{
			if(top == size-1)
			   cout<<"Stack is Overflowed";
			else
		       ++top;
		       arr[top]=c;
		       cout<<c<<" pushed in stack\n";
		}
		char pop()
		{
			if(top == -1)
			  isEmpty();
			else
			{
			  char temp=arr[top];
			  --top;
			  cout<<temp<<" popped from stack\n";
			  return temp;
		    }
		}
		char peek()
		{
			if(top == -1)
			{
			  isEmpty();
			  return '0';
		    }
			else
			  return arr[top];
		}
		bool isEmpty()
		{
			if(top == -1)
			  return true;
			else
			  return false;
		}
		
};
int main()
{
	stack opstack;
	string s = "a*(b-c)";
	string output = "";
	for(int i=0; i<s.length(); i++)
	{
		if(s[i] == '(')
		    opstack.push(s[i]);
		else if(s[i] == '+' || s[i] == '-')
		{
			if(opstack.peek() == '+' || opstack.peek() == '-' || opstack.peek() == '*' || opstack.peek() == '/')
			{
				output += opstack.pop();
				opstack.push(s[i]);
			}
			else
			    opstack.push(s[i]);
		}
		else if(s[i] == '*' || s[i] == '/')
		{
			if(opstack.peek() == '*' || opstack.peek() == '/')
			{
				output += opstack.pop();
				opstack.push(s[i]);
			}
			else
			{
			    opstack.push(s[i]);
		    }
		}
		else if(s[i] == ')')
		{
			char c; //to remove flow error
			while(opstack.isEmpty() != true)
			{
				c = opstack.pop();
				if(c == '(')
				   break;
				else
				   output += c;
			}
		}
		else
		   output += s[i];
	}
	while(opstack.isEmpty() != true)
	{
		output += opstack.pop();
	}
	cout<<"Output is: "<<output;
}
