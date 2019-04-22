#include "container.h"

int main() {
    container<char> s;
    string in;
    cout << "enter stuff" << endl;
    cin >> in;

    for (int i = 0; i < in.size(); i++) {
        s.addEntry(in[i]);
    }
    cout << endl;

    s.bubbleSort();
    cout << s.toString() << endl;
}
