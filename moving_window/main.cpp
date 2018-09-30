#include <iostream>
#include <vector>

template<typename T> std::vector<T> getInput(const int size) {
    std::vector<T> res;
    res.reserve(size);
    for ( int index = 0; index < size; ++index ) {
        T t;
        std::cin >> t;
        res.push_back(t);
    }
    return std::move(res);
}

class element {
    int pos_;
    int value_;
public:
    element(int pos, int value)
        : pos_(pos), value_(value) 
    {}
    const int getPos() {
        return pos_;
    }
    const int getValue() {
        return value_;
    }
};

void processRightMove(
    std::vector<int>& data, 
    std::vector<element*>& maxesCandidates, 
    int& currentRightPos, 
    int& currentMaxPos) {

    ++currentRightPos;
    while ( maxesCandidates.size() > static_cast<long unsigned int>(currentMaxPos) 
            && maxesCandidates.back()->getValue() < data.at(currentRightPos) ) {
        maxesCandidates.pop_back();
    }
    element* newMax = new element(currentRightPos, data.at(currentRightPos));
    maxesCandidates.push_back(newMax);
    std::cout << maxesCandidates.at(currentMaxPos)->getValue() << " ";
}

void processLeftMove(
    std::vector<int>& data, 
    std::vector<element*>& maxesCandidates, 
    int& currentLeftPos, 
    int& currentMaxPos) {

    if ( currentLeftPos == maxesCandidates.at(currentMaxPos)->getPos() ) {
        ++currentMaxPos;
    }
    ++currentLeftPos;
    std::cout << maxesCandidates.at(currentMaxPos)->getValue() << " ";
}

int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int inputDataSize;
    std::cin >> inputDataSize;
    std::vector<int> data = getInput<int>(inputDataSize);

    int inputMovesSize;
    std::cin >> inputMovesSize;
    std::vector<char> moves = getInput<char>(inputMovesSize);
    
    // coz we can't use std::deque, let's do freaky moves with vector
    std::vector<element*> maxesCandidates;
    maxesCandidates.reserve(inputDataSize);
    element* startElement = new element(0, data.at(0));
    maxesCandidates.push_back(startElement);
    int currentLeftPos = 0;
    int currentRightPos = 0;
    int currentMaxPos = 0;

    // just keep current window max at first element of maxesCandidates-"deque"
    for ( long unsigned int index = 0; index < moves.size(); ++index ) {
        if ( moves.at(index) == 'R' ) {
            processRightMove(data, maxesCandidates, currentRightPos, currentMaxPos);
        } else {
            processLeftMove(data, maxesCandidates, currentLeftPos, currentMaxPos);
        }
    }

    return 0;
}
