#include <iostream>
#include <vector>
#include <stack>

using namespace std;

template< typename _Type>
class squeue{
public:
    void push_back(_Type val) {
	if( push_st.size() != 0) {
	    push_st.push(val);	
	}else {
	    while( pop_st.size() != 0) {
	        push_st.push(pop_st.top());
	        pop_st.pop();
	    }
	    push_st.push(val);
	}
    }
    void pop_front() {
	if( pop_st.size() != 0) {
	    pop_st.pop();
	}else {
	    while( push_st.size() != 0) {
	        pop_st.push(push_st.top());
	        push_st.pop();
	    }
	    pop_st.pop();
	}
    }
    _Type first() {

	_Type ans;
	
	if( pop_st.size() != 0) {
	    ans = pop_st.top();
	}else {
	    while( push_st.size() != 0) {
	        pop_st.push(push_st.top());
	        push_st.pop();
	    }
	    ans = pop_st.top();
	}
	
	return ans;
    }
    
private:
    stack<_Type> push_st;
    stack<_Type> pop_st;
};

int main(void) {

    squeue<int> q;

    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    cout << q.first() << " ";
    q.pop_front();
    q.pop_front();
    q.push_back(4);
    cout << q.first() << " ";
    q.pop_front();
    cout << q.first() << " ";
    cout << endl;
    
    return 0;
}
