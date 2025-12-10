// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

std::vector<int> solve(int *nums, int numsSize, int k)
{
  std::unordered_map<int, int> num_count;

  for (int i = 0; i < numsSize; i++)
  {
    num_count[nums[i]]++;
  }

  std::vector<std::pair<int, int>> freqVec(num_count.begin(), num_count.end());
  std::sort(freqVec.begin(), freqVec.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b){ return a.second > b.second; });

  std::vector<int> result;
  for (int i = 0; i < k && i < freqVec.size(); i++)
  {
    result.push_back(freqVec[i].first);
  }

  return result;
}

int main()
{
  int N;
  std::cin >> N;

  while (N--)
  {
    int numsSize, k;
    std::cin >> numsSize >> k;

    int *nums = new int[numsSize];
    for (int i = 0; i < numsSize; i++)
    {
      std::cin >> nums[i];
    }

    auto topK = solve(nums, numsSize, k);
    for (int x: topK)
    {
      std::cout << x << " ";
    }
    std::cout << std::endl;
    delete[] nums;
  }

  return 0;
}