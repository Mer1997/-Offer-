#include <iostream>
#include <vector>

using namespace std;

int getMinInRotatedArr( vector<int> &rotated, int left, int right) {
   
    //only 1 el
    if( right - left == 1) {
	return rotated[left];
    }

    //If no rotated
    if( rotated[left] < rotated[right-1]) {
	return rotated[left];
    }

    //split rotated arr to two range
    int mid = left + (right - left)/2;

    //check if mid el in left range
    if( rotated[mid] > rotated[right-1]) {
	return getMinInRotatedArr(rotated, mid, right);
    //if mid el in right range
    }else {
	return getMinInRotatedArr(rotated, left+1, mid+1);
    }
}

int main(void) {

    vector<int> rotated = {5, 8, 13, 31, 1, 2, 3, 4};
    
    int min = getMinInRotatedArr( rotated, 0, rotated.size());

    cout << "Min: " << min << endl;
    return 0;
}
