#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// this should be done with dequeue
void slidingWindow(const vector<int>& nums, int k) {
    queue<int> elems;
    queue<int> tmp;
    vector<int> calcMax;
    vector<int> res;

    for (size_t i = 0; i < nums.size(); i++) {
        elems.push(nums[i]);
    }

    // [1,3,-1],-3,5,3,6,7
    int c = k;
    int max = INT_MIN;

    while (elems.size() != k - 1) {
        tmp = elems;
        while (c) {
            calcMax.push_back(tmp.front());
            tmp.pop();
            c--;
        }

        for (size_t i = 0; i < calcMax.size(); i++) {
            if (calcMax[i] < 0) {
                if (calcMax[i] > max) {
                    max = calcMax[i];
                }
            }
            else if (calcMax[i] > max) {
                max = calcMax[i];
            }
        }
        res.push_back(max);
        calcMax.clear();

        elems.pop();
        c = k;
        max = INT_MIN;
    }

    for (size_t i = 0; i < res.size(); i++) {
        cout << res[i] << ' ';
    }
}

int main() {
    vector<int> nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
    int k = 3;
    slidingWindow(nums, k);

    vector<int> nums1 = { 1, -1 };
    int k1 = 1;
    slidingWindow(nums1, k1);

    return 0;
}