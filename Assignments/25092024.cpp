// Question 1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0];
    int currentSum = nums[0];
    
    for (int i = 1; i < nums.size(); ++i) {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }
    
    return maxSum;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int maxSum = maxSubArray(nums);
    cout << "Maximum sum: " << maxSum << endl;

    return 0;
}


// Question 2
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;


vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> nge(nums2.size(), -1);
    stack<int> s;

    for (int i = nums2.size() - 1; i >= 0; --i) {
        while (!s.empty() && s.top() <= nums2[i]) {
            s.pop();
        }
        if (!s.empty()) {
            nge[i] = s.top();
        }
        s.push(nums2[i]);
    }

    vector<int> result;
    for (int num : nums1) {
        auto it = find(nums2.begin(), nums2.end(), num);
        if (it != nums2.end()) {
            int index = distance(nums2.begin(), it);
            result.push_back(nge[index]);
        } else {
            result.push_back(-1);
        }
    }

    return result;
}
