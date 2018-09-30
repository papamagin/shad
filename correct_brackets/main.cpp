#include <iostream>
#include <string>
#include <vector>

bool isOpeningBracket(const char& bracket) {
    if (bracket == '(' || bracket == '[' || bracket == '{') {
        return true;
    }
    return false;
}

char getOpeningBracketFor(const char& closingBracket) {
    if (closingBracket == ')') {
        return '(';
    } else if (closingBracket == ']') {
        return '[';
    } else {
        return '{';
    }
}

int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    const long reserveSize = 1000000;

    std::string input;
    input.reserve(reserveSize);
    getline(std::cin, input);
    if ( input.empty() ) {
        std::cout << "CORRECT";
        return 0;
    }

    std::vector<char> stack;
    stack.reserve(reserveSize);
    long unsigned int lastCorrect = 0;

    for (long unsigned int index = 0; index < input.length(); ++index) {
        const char br = input[index];
        if ( isOpeningBracket(br) ) {
            stack.push_back(br);
            ++lastCorrect;
        } else {
            if ( stack.empty() || stack.back() != getOpeningBracketFor(br) ) {
                break;
            } else {
                stack.pop_back();
                ++lastCorrect;
            }
        }
    }

    if ( stack.empty() && lastCorrect == input.length() ) {
        std::cout << "CORRECT";
    } else {
        std::cout << lastCorrect;
    }

    return 0;
}
