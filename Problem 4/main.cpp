#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // If one num list is empty, return the median of the other
    if (nums1.empty()) {
        if (nums2.size() % 2 != 0) {
            return nums2[(nums2.size() / 2)];
        }
        return (nums2[(nums2.size() / 2) - 1] + nums2[(nums2.size() / 2)]) / 2.0;
    }
    
    if (nums2.empty()) {
        if (nums1.size() % 2 != 0) {
            return nums1[(nums1.size() / 2)];
        }
        return (nums1[(nums1.size() / 2) - 1] + nums1[(nums1.size() / 2)]) / 2.0;
    }
        
    // We need to only get a combined vector of size (m + n) / 2 (and then take the median)
    int combSize = ((nums1.size() + nums2.size()) / 2) + 1;
    int i = 0, j = 0;
    vector<int> combNums;
    while (combNums.size() < combSize) {
        if (i >= nums1.size()) {
            combNums.push_back(nums2[j]);
            ++j;
        }
        else if (j >= nums2.size()) {
            combNums.push_back(nums1[i]);
            ++i;
        }
        else {
            if (nums1.at(i) < nums2.at(j)) {
                combNums.push_back(nums1[i]);
                ++i;
            }
            else {
                combNums.push_back(nums2[j]);
                ++j;
            }
        }
    }

    if ((nums1.size() + nums2.size()) % 2 != 0) {
        return combNums[combSize - 1];
    }
    return (combNums[combSize - 2] + combNums[combSize - 1]) / 2.0;
}

int main(int argc, char* argv[]) {
    vector<int> nums1 = {1};
    vector<int> nums2 = {1};
    cout << findMedianSortedArrays(nums1, nums2) << "\n";
}