#include <set>
#include <vector>
#include <iostream>

using namespace std;


int main(void ) {

    multiset<int, greater<int>> intSet;

    intSet.insert(3);
    intSet.insert(9);
    intSet.insert(1);
    intSet.insert(2);
    intSet.insert(7);
    intSet.insert(-1);
    intSet.insert(31);

    cout << "max is " << *intSet.begin() << endl;
    return 0;
}
