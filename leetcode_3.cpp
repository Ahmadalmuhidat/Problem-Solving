// Given a strings, find the length of the longest substring without repeating characters.

#include <iostream>
#include <string>
#include <set>
#include <algorithm>

int solve(const std::string &s)
{
  std::set<char> window;
  int left = 0, right = 0;
  int maxLen = 0;

  while (right < s.size())
  {
    if (window.find(s[right]) == window.end())
    {
      window.insert(s[right]);
      maxLen = std::max(maxLen, (int)window.size());
      right++;
    }
    else
    {
      window.erase(s[left]);
      left++;
    }
  }

  return maxLen;
}

int main()
{
  int N;
  std::cin >> N;

  while (N--)
  {
    std::string s;
    std::cin >> s;

    std::cout << solve(s) << std::endl;
  }

  return 0;
}