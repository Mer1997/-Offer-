#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int getMaxValInWindow( const vector<int> &vec, const int &size) {

    int ans;

    deque<int> _slide;

    for(int i = 0; i != vec.size(); ++i) {

	while(!_slide.empty() && vec[i] > vec[_slide.back()] ) {
	    _slide.pop_back();
	}

	_slide.push_back(i);

	if( i-size == _slide.front() ) {
	    _slide.pop_front();
	}

	if( i < 2 ) continue;

        for( auto iter = _slide.begin(); iter != _slide.end(); ++iter) {
	   cout << vec[*iter] << " ";
        }
        cout << endl;
    }


    return ans;

}

int main(void) {

    vector<int> _window = {2, 3, 4, 2, 6, 2, 5, 1};

    int _max = getMaxValInWindow(_window, 3);

    cout << "the max value of slide window is " << _max << endl;
    return 0;
}
