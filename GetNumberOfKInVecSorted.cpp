#include <iostream>
#include <vector>
#include <functional>
using namespace std;

//区分查找的方向，应该由comparor函数返回，但是懒得改代码了,没设计好
static int jam;

//二分查找
int binarySearch(const vector<int> &vec, const int &val, const function<bool(const vector<int>&, const int&, const int&)> &comparor, const int &left, const int &right) {

    if( left == right ) return -1;

    int mid = left + (right - left)/2;

    if( vec[mid] == val && comparor(vec, mid, val) == true) {
	return mid;
    }

    if( vec[mid] < val || (jam && comparor(vec, mid, val) == false)) {
	return binarySearch(vec, val, comparor, mid+1, right);
    }

    if( vec[mid] > val || (!jam && comparor(vec, mid, val) == false)) {
	return binarySearch(vec, val, comparor, left, mid);
    }

    return -1;
}

//获取值等于val的最大index，没有返回-1
int getMaxIndexOfKInVec( const vector<int> &vec, const int &val) {

    //匿名函数，判断当前cur是否为target的右边界
    auto comparor = [](const vector<int> &vec, const int &cur, const int &target)->bool {
	if( cur == vec.size()-1) return true;
	if( vec[cur+1] != target) return true;
	return false;
    };

    int right = binarySearch(vec, val, comparor, 0, vec.size());

    return right;
}

int getMinIndexOfKInVec( const vector<int> &vec, const int &val) {

    auto comparor = [](const vector<int> &vec, const int &cur, const int &target)->bool {
	if( cur == 0) return true;
	if( vec[cur-1] != target) return true;
	return false;
    };

    int left = binarySearch(vec, val, comparor, 0, vec.size());
    
    return left;
}

int getNumberOfKInVecSorted( const vector<int> &vec, const int &val ) {

    int left, right;

    left  = getMinIndexOfKInVec(vec, val);

    jam++;

    right = getMaxIndexOfKInVec(vec, val);

    if( left == -1 || right == -1 ) return -1;
    
    return right - left + 1;
}

int main(void) {

    vector<int> vec = {3, 3, 3, 3, 3, 3, 4, 4, 5, 12, 12, 12};

    int ans = getNumberOfKInVecSorted(vec, 3);

    cout << "ans is " << ans << endl;

    return 0;
}
