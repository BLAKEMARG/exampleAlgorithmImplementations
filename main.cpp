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

    container<char> s1 = container<char>(s);
    s.bubbleSort();
    cout << s.toString() << endl;
    s1.selectSort();
    cout << s1.toString() << endl;

}
