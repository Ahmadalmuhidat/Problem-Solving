// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

std::vector<std::vector<std::string>> solve(std::vector<std::string> &strs)
{
  std::unordered_map<std::string, std::vector<std::string>> map;

  for (auto &str : strs)
  {
    std::string key = str;
    std::sort(key.begin(), key.end());
    map[key].push_back(str);
  } 

  std::vector<std::vector<std::string>> result;
  for (auto &pair: map)
  {
    result.push_back(pair.second);
  }

  return result;
}

int main()
{
  int strsSize;
  std::cin >> strsSize;
  std::vector<std::string> strs(strsSize);

  for (int i = 0; i < strsSize; i++)
  {
    std::cin >> strs[i];
  }

  auto result = solve(strs);
  for (auto &group : result)
  {
    for (auto &word : group)
    {
      std::cout << word << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}