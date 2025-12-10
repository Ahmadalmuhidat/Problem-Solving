// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish
// Notation.
// Evaluate the expression. Return an integer that represents the value of the expression.

// Note that:
// • The valid operators are +', '-', "*', and "'.
// , '*.
// • Each operand may be an integer or another expression.
// • The division between two integers always truncates toward zero.
// • There will not be any division by zero.
// • The input represents a valid arithmetic expression in a reverse polish notation.
// • The answer and all the intermediate calculations can be represented in a 32-bit integer.

#include <iostream>
#include <vector>
#include <string>
#include <stack>

int solve(std::vector<std::string> &tokens)
{
  std::stack<int> stack;

  for (const std::string &token: tokens)
  {
    if (token == "+" || token == "-" || token == "*" || token == "/")
    {
      int b = stack.top();
      stack.pop();

      int a = stack.top();
      stack.pop();

      if (token == "+")
      {
        stack.push(a + b);
      }

      else if (token == "-")
      {
        stack.push(a - b);
      }

      else if (token == "*")
      {
        stack.push(a * b);
      }

      else if (token == "/")
      {
        stack.push(a / b);
      }
    }
    else
    {
      stack.push(std::stoi(token));
    }
  }

  return stack.top();
}

int main()
{
  int N;
  std::cin >> N;

  while (N--)
  {
    int M;
    std::cin >> M;
    std::vector<std::string> tokens(M);
    for (int i = 0; i < M; i++)
    {
      std::cin >> tokens[i];
    }

    std::cout << solve(tokens) << std::endl;
  }

  return 0;
}