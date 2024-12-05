#include <iostream>
#include <stack>
#include <string>
using namespace std;

int prec(char c)
{
	if (c=='^')
	{
		return 3;
	}
	else if (c=='/' || c=='*')
	{
		return 2;
	}
	else if (c=='+' || c=='-')
	{
		return 1;
	}
	else {
		return -1;
	}
}
void infixToPostfix(string a)
{
	string result="";
	stack <char> st;
	
	for (char c:a)
	{
		if ('a'<=c && c<='z' || 'A'<=c && c<='Z' || 0<=c && c<=0 )
		result+=c;
	
	else if (c=='(')
	{
		st.push(c);
	}
	else if (c==')')
	{
		while (st.top()!='(')
		{
			result+=st.top();
			st.pop();
		}
		st.pop();
	}
	else {
		while ((!st.empty() && prec(c)<prec(st.top()))||(!st.empty() && prec(c)== prec(st.top())))
		{
			result+=st.top();
			st.pop();
		}
		st.push(c);
	}
}
	while (!st.empty())
	{
		result+=st.top();
		st.pop();
	}
	   cout << result << endl;
}
int main()
{	
	 string exp = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
	return 0;
}