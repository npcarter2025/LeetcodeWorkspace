#include <iostream>
#include <vector>
#include "two_sum.cpp"

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    auto result = twoSum(nums, 9);
    if (result == std::vector<int>({0, 1})) {
        std::cout << "PASS\n";
        return 0;
    } else {
        std::cout << "FAIL\n";
        return 1;
    }
}