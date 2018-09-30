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

int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int inputDataSize;
    std::cin >> inputDataSize;
    std::vector<int> data = getInput<int>(inputDataSize);

    std::vector<int> withRiseAtTheEnd(inputDataSize, 1);
    std::vector<int> withDescentAtTheEnd(inputDataSize, 1);
    int longestSize = 1;

    std::cout << data.at(0) << " ";
    for ( int index = 1; index < inputDataSize; ++index ) {
        for ( int jindex = 0; jindex < index; ++jindex ) {

            if ( data.at(jindex) < data.at(index) 
                && withRiseAtTheEnd.at(index) < withDescentAtTheEnd.at(jindex) + 1 ) {
                
                withRiseAtTheEnd.at(index) = withDescentAtTheEnd.at(jindex) + 1;
            }

            if ( data.at(jindex) > data.at(index)
                && withDescentAtTheEnd.at(index) < withRiseAtTheEnd.at(jindex) + 1 ) {
                
                withDescentAtTheEnd.at(index) = withRiseAtTheEnd.at(jindex) + 1;
            }

            const int localMax = std::max(withRiseAtTheEnd.at(index), withDescentAtTheEnd.at(index));
            if ( longestSize < localMax ) {
                longestSize = localMax;
                std::cout << data.at(index) << " ";
            }

        }
    }

    return 0;
}
