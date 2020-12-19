#include <iostream>
#include <functional>

using namespace std;


int main(void) {

    function<bool(const int&, const int&)> cmp = [](const int&lv, const int&rv)->bool {
	return lv > rv ? true : false;
    };

    int lv = 3;
    int rv = 4;

    cout << lv << " > " << rv << " ? " << endl; 
    cout << cmp(lv,rv) << endl;
    return 0;
}
