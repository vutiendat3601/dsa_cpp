#include <iostream>
#include <stack>
#include <string>

int precedence(char opr)
{
    if (opr == '*' || opr == '/')
    {
        return 2;
    }
    return 1;
}

std::string infixToPostfix(std::string infix)
{
    std::string res;
    std::stack<char> s;
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
        {
            s.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                res += s.top();
                s.pop();
            }
            s.pop();
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
        {
            while (!s.empty() && s.top() != '(' && precedence(s.top()) >= precedence(infix[i]))
            {
                res += s.top();
                s.pop();
            }
            s.push(infix[i]);
        }
        else
        {
            res += infix[i];
        }
    }
    while (!s.empty())
    {
        res += s.top();
        s.pop();
    }
    return res;
}

int main()
{
    std::string res = infixToPostfix("(3+2/2)*1");
    std::cout << res << std::endl;
}