#include <iostream>
#include <stack>
#include <vector>

/*
Whenever we encounter a positive value, we will simply push it to the stack.
The moment we encounter a negative value, we know some or all or zero positive values will be knocked out of the stack. The negative value may itself be knocked out or it may enter the stack.
We will keep on poping the elements from the stack while the asteroids[i] > s.top(). But remember, negative asteroids can never pop another negative asteroids, since they will never meet them. So, the final condition is while(!s.empty() and s.top() > 0 and s.top() < abs(ast[i])), we will pop the elements.
We have to take care of the case when s.top() == asteroids[i]. In this case one positive element will pop out and negative asteroid won't enter the stack.
If after knocking out elements stack becomes empty() or s.top() becomes negative, that means the current asteroids[i] will enter the stack.
*/
// [8, 9, 6, -7, -9, 12, 50, -34]
std::vector<int> asteroidCollision(const std::vector<int> &asteroids) {
    std::stack<int> s;

    for (size_t i = 0; i < asteroids.size(); i++) {
        if (asteroids[i] == 0) {
            continue;
        }

        if (asteroids[i] > 0) {
            s.push(asteroids[i]);
        } else {
            while (!s.empty() && abs(asteroids[i]) > s.top()) {
                s.pop();
            }
            if (!s.empty() && abs(asteroids[i]) == s.top()) {
                s.pop();
            }
        }
    }

    std::vector<int> res(s.size());
    for (int i = s.size() - 1; i >= 0; i--) { //!!! int i
        res[i] = s.top();
        s.pop();
    }
    return res;
}

int main() {
    std::vector<int> asteroids;
    std::cout << "Number of asteroids: ";
    unsigned int n;
    std::cin >> n;

    int asteroid = 0;
    for (size_t i = 0; i < n; i++) {
        std::cin >> asteroid;
        asteroids.push_back(asteroid);
    }

    std::vector<int> res = asteroidCollision(asteroids);

    for (size_t i = 0; i < res.size(); i++) {
        std::cout << res[i] << ' ';
    }

    return 0;
}