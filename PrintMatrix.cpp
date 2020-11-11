#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int>> matrix = {
    {1,  2,  3,  4},
    {5,  6,  7,  8},
    {9,  10, 11, 12},
    {13, 14, 15, 16},
};

void printCircle( const vector<vector<int>> &matrix, int height, int width, int layer) {
    //cout << "layer: " << layer << endl;
    int endX = width - 1 - layer;
    int endY = height - 1 - layer;

    for( int i = layer; i <= endX; ++i) {
	cout << matrix[layer][i] << " ";
    }

    if( layer < endY) {
	for( int i = layer+1; i <= endY; ++i) {
	    cout << matrix[i][endX] << " ";   
	}
    }

    if( layer < endX && layer < endY) {
	for( int i = endX - 1; i >= layer; --i) {
	    cout << matrix[endY][i] << " ";
	}
    }

    if( layer < endX && layer < endY - 1) {
	for( int i = endY-1; i >= layer+1; --i) {
	    cout << matrix[i][layer] << " ";
	}
    }
    return;
}

void printMatrix( const vector<vector<int>> &matrix) {

    if( matrix.size() == 0 || matrix[0].size() == 0) return;

    int height = matrix.size();
    int width  = matrix[0].size();

    int start = 0;
    while( start*2 < height && start*2 < width ){
	printCircle(matrix, height, width, start);
	++start;
    }

    cout << endl;
}

int main(void) {
    
    printMatrix(matrix);

    return 0;
}
