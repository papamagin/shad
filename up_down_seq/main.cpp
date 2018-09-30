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

    return 0;
}
