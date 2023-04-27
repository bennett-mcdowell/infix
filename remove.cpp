#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string input;
    while (getline(cin, input)) {
        if (input.empty())
        {
            break;
        }
        // Remove the line number and period from the beginning of the line
        basic_string<char>::size_type index = input.find(". ");
        if (index != std::string::npos) {
            input = input.substr(index + 2);
        }
        cout << input << endl;
    }
    return 0;
}
