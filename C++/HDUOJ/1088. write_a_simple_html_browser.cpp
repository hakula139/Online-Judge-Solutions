#include <fstream>
#include <iostream>
#include <streambuf>
#include <string>

using std::cin;
using std::cout;
using std::ifstream;
using std::ios;
using std::ofstream;
using std::streambuf;
using std::string;

int main() {
    // ifstream input;
    // ofstream output;
    // input.open("input.txt", ios::in);
    // output.open("output.txt", ios::out | ios::trunc);
    // streambuf* input_buf;
    // streambuf* output_buf;
    // input_buf  = cin.rdbuf(input.rdbuf());
    // output_buf = cout.rdbuf(output.rdbuf());

    const int kMaxWidth = 80;
    int       pos       = 0;
    string    word;
    while (cin >> word) {
        if (word == "<br>") {
            cout << '\n';
            pos = 0;
        } else if (word == "<hr>") {
            if (pos) cout << '\n';
            cout << string(kMaxWidth, '-') << '\n';
            pos = 0;
        } else {
            int len = word.size();
            if (pos + len + 1 > kMaxWidth) {
                cout << '\n';
                pos = 0;
            }
            if (pos) cout << ' ';
            cout << word;
            pos += len + 1;
        }
    }
    cout << '\n';
    return 0;
}
