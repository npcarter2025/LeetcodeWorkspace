/*
Compile with g++ -std=c++20 next_greater_element.cpp -o next1 && ./next1 
so that map will have the contains() member

*/


#include <cstdlib>
#include <iostream>

#include <vector>
#include <stack>
#include <map>

using namespace std; 

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> result;
        std::stack<int> monotonic;
        std::map<int, int> myMap;  // {key, value} = {nums2[i], nextGreater_val else -1 }

        for (int i = 0; i < nums2.size()-1; i++ ){
            for (int j = i; j < nums2.size(); j++) {
                if (nums2[j] > nums2[i]) {
                    std::pair<int, int> pair = std::make_pair(nums2[i], nums2[j]);
                    myMap.insert(pair);
                    break;
                }
            }
        }

        for (int key = 0; key < nums1.size(); key ++) {

            if (myMap.find(nums1[key]) != myMap.end()) {

                result.push_back(myMap[nums1[key]]);
            } else {
                result.push_back(-1);
            }
            
        }
        return result;

    }

    vector<int> nextGreaterElement_stack(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> result;
        std::stack<int> prev_seen; // previously seen
        std::unordered_map<int, int> myMap;  // {key, value} = {nums2[i], nextGreater_val else -1 }
        for (int i = nums2.size() - 1; i >= 0; i--) {
            int& elem = nums2[i];

            while (!prev_seen.empty() && prev_seen.top() < elem) {
                prev_seen.pop();
            }

            if (prev_seen.empty()) {
                myMap[elem] = -1; 
            } else {
                myMap[elem] = prev_seen.top();
            }
            prev_seen.push(elem);

        }
        for (int& key : nums1) {
            result.push_back(myMap[key]);
        }
        return result;
    }
};


int main() {

    std::vector<int> vec1 = {1, 2, 3, 4};
    std::vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7};

    std::vector<int> subArray;
    Solution sol;
    subArray = sol.nextGreaterElement_stack(vec1, vec2);

    for (int i = 0; i < subArray.size(); i++) {
        printf("Elem = %d\n", subArray[i]);
    }
}