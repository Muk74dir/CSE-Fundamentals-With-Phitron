#include<bits/stdc++.h>
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

int evaluatePostfix(string expression)
{
    stack<int> s;

    for (int i = 0; i < expression.length(); i++)
    {
        char c = expression[i];

        if (isdigit(c))
        {
            s.push(c - '0');
        }
        else
        {
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();

            int result;
            switch (c)
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            }

            s.push(result);
        }
    }

    return s.top();
}

string infixToPostfix(string expression)
{
    stack<char> s;
    string postfix = "";

    for (int i = 0; i < expression.length(); i++)
    {
        char c = expression[i];

        if (c == ' ')
            continue;

        if (isdigit(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(')
                s.pop();
        }
        else
        {
            while (!s.empty() && precedence(c) <= precedence(s.top()))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main()
{
    string expression;
    cin>>expression;
    string postfix = infixToPostfix(expression);
    cout <<evaluatePostfix(postfix)<< endl;
    return 0;
}
