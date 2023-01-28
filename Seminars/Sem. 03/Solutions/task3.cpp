#include <deque>
#include <iostream>
#include <vector>

std::vector<int> maxSlidingWindow(const std::vector<int> &v, size_t k) {
    std::deque<int> window;
    std::vector<int> result;

    // first window
    for (size_t i = 0; i < k; i++) {
        while (!window.empty() && window.back() < v[i]) {
            window.pop_back();
        }
        window.push_back(v[i]);
    }

    // save the result from the first window
    result.push_back(window.front());

    // move on to the next windows
    for (size_t i = k; i < v.size(); i++) {
        if (window.front() == v[i - k]) {
            window.pop_front();
        }

        while (!window.empty() && window.back() < v[i]) {
            window.pop_back();
        }

        window.push_back(v[i]);
        result.push_back(window.front());
    }

    return result;
}

int main() {
    std::vector<int> example = {1, 3, -1, -3, 5, 3};

    std::vector<int> result = maxSlidingWindow(example, 3);

    for (auto elem : result)
        std::cout << elem << " ";
}