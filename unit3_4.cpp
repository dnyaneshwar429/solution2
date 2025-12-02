// 4) Convert given infix expression Eg. a-b*c-d/e+f into postfix form using stack and 
// show the operations step by step.
#include <iostream>
#include <stack>
#include <cctype>
#include <math.h>
using namespace std;
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}
bool isoperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
string infixToPostix(string infix)
{

    stack<char> st;
    string postfix = "";

    for (char c : infix)
    {
        if (isalnum(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else if (isoperator(c))
        {
            while (!st.empty() && precedence(st.top()) >= precedence(c))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

int main()
{
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostix(infix);
    cout << "Postfix expression " << postfix << endl;

    return 0;
}
