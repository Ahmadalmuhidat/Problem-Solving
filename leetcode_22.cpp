// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

#include <iostream>
#include <vector>
#include <string>

void backtrack(std::string current, int open, int close, int n, std::vector<std::string> &result)
{
  if (current.size() == 2 * n)
  {
    result.push_back(current);
    return;
  }

  if (open < n)
  {
    backtrack(current + "(", open + 1, close, n, result);
  }

  if (close < open)
  {
    backtrack(current + ")", open, close + 1, n, result);
  }
}

std::vector<std::string> solve(int n)
{
  std::vector<std::string> result;
  backtrack("", 0, 0, n, result);
  return result;
}

int main()
{
  int m;
  std::cin >> m;

  std::vector<std::string> result = solve(m);

  for (const std::string &str : result)
  {
    std::cout << str << std::endl;
  }

  return 0;
}
