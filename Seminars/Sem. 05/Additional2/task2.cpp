#include <list>
#include <string>
using namespace std;

class BrowserHistory {
private:
    list<string> history;
    list<string>::iterator it;

public:
    BrowserHistory(const string &homepage) {
        history.push_back(homepage);
        it = history.begin();
    }

    void visit(string url) {
        auto next = it;
        next++;

        // clears up the forward history
        history.erase(next, history.end());
        history.push_back(url);
        it++;
    }

    string back(int steps) {
        while (it != history.begin() && steps--) {
            it--;
        }
        return *it;
    }

    string forward(int steps) {
        while (it != --history.end() && steps--) { // need to decrement the h.end() because it returns a nullptr not the actual last element
            it++;
        }
        return *it;
    }
};
