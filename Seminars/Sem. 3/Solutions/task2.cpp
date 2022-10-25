#include <array>
#include <iostream>
#include <queue>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-compare"

template <unsigned boardSize = 8>
class minMoves {
private:
    // typedefs
    using position = std::pair<int, int>;                             // pair<0,0>, where pair has to member objects first & second
    using positionAndSteps = std::pair<position, int>;                // pair<<0,0>,steps>
    using board = std::array<std::array<bool, boardSize>, boardSize>; // 2D array of bools (bool [8][8])

    board chessBoard; // == std::array<std::array<bool, boardSize>,boardSize> chessBoard;

    // set the bool board to zeros
    void cleanBoard() {
        for (size_t row = 0; row < boardSize; row++) {
            for (size_t col = 0; col < boardSize; col++) {
                chessBoard[row][col] = false;
            }
        }
    }

    // pair<1,2> = pair<1,2> ?
    bool equalPositions(const position &firstP, const position &secondP) const {
        return (firstP.first == secondP.first) && (firstP.second == secondP.second);
    }

    // check if we are in the bounds of the board
    bool isValidPos(const position &pos) const {
        return (pos.first >= 0 && pos.second >= 0) && (pos.first <= boardSize && pos.second <= boardSize);
    }

    // mark position
    void markPos(const position &pos) {
        chessBoard[pos.first][pos.second] = true;
    }

    // tell if the position is marked
    bool isMarkedPos(const position &pos) const {
        return chessBoard[pos.first][pos.second];
    }

    // if the position is valid and not marked then push it to the queue and mark it
    void pushAndMarkIfValid(std::queue<positionAndSteps> &q, const position &toPush, int steps) {
        if (isValidPos(toPush) && !isMarkedPos(toPush)) {
            q.push({toPush, steps});
            markPos(toPush);
        }
    }

    int moveTheHorse(const position &startPos, const position &endPos) {
        std::queue<positionAndSteps> q;

        q.push({startPos, 0});
        markPos(startPos);

        while (!q.empty()) {
            positionAndSteps currPos = q.front();
            q.pop();
            if (equalPositions(currPos.first, endPos)) { // get the coordinates of the currPos<position, steps> and == with endPos
                return currPos.second;                   // this returns the steps
            }

            int x = currPos.first.first;
            int y = currPos.first.second;
            std::cout << "Info: (" << x << ", " << y << ") moves - " << currPos.second << '\n';
            int moves = currPos.second + 1;

            pushAndMarkIfValid(q, {x + 1, y + 2}, moves);
            pushAndMarkIfValid(q, {x - 1, y - 2}, moves);
            pushAndMarkIfValid(q, {x + 1, y - 2}, moves);
            pushAndMarkIfValid(q, {x - 1, y + 2}, moves);
            pushAndMarkIfValid(q, {x + 2, y - 1}, moves);
            pushAndMarkIfValid(q, {x + 2, y + 1}, moves);
            pushAndMarkIfValid(q, {x - 2, y + 1}, moves);
            pushAndMarkIfValid(q, {x - 2, y - 1}, moves);
        }
        return -1;
    }

public:
    minMoves() { // the constructor will clean the board
        cleanBoard();
    }

    int getMinMoves(const position &startPos, const position &endPos) {
        cleanBoard();
        return moveTheHorse(startPos, endPos);
    }
};

#pragma GCC diagnostic pop

int main() {
    minMoves m;
    std::cout << m.getMinMoves({0, 0}, {2, 1}) << std::endl;
    std::cout << m.getMinMoves({0, 0}, {3, 3}) << std::endl;
    std::cout << m.getMinMoves({0, 0}, {4, 1}) << std::endl;
    std::cout << m.getMinMoves({0, 0}, {5, 3}) << std::endl;

    minMoves<12> ms;
    std::cout << ms.getMinMoves({0, 0}, {11, 11}) << std::endl;

    minMoves<2> mt;
    std::cout << mt.getMinMoves({0, 0}, {12, 212});
    return 0;
}