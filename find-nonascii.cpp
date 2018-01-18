#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    // Configure local via LANG environment variable.
    setlocale(LC_ALL, "");

    for (int i = 1; i < argc; i++) {
        char *fileName = argv[i];
        wifstream in(fileName);
        if (in.is_open()) {
            int c;
            unsigned int lineNumber = 1;
            while ((c = in.get()) != traits::eof()) {
                if ((wchar_t) c == L'\n') {
                    lineNumber++;
                }
                else if (c > 127) {
                    cout << "Non-ASCII character " << (wchar_t) c << " found at line " << lineNumber << endl;
                }
            }
            // in.close() is done automatically by destructor at end-of-scope.
        }
    }
}
