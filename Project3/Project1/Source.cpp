
#include <queue>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class ZigzagIterator {
public:
	//vector<vector<int>::iterator> itv;
	vector<int>::iterator v1it, v2it;
	vector<int>::iterator v1e, v2e;
	bool f;
	ZigzagIterator(vector<int>& v1, vector<int>& v2) {
		v1it = v1.begin();
		v2it = v2.begin();
		v1e = v1.end();
		v2e = v2.end();
		f = true;
	}

	int next() {
		int res = 0;
		if ((f && v1it != v1e) || v2it == v2e) {
			res = *v1it;
			v1it++;
			f = false;
		}
		else {
			f = true;
			res = *v2it;
			v2it++;
		}
		return res;
	}

	bool hasNext() {
		if (v1it != v1e || v2it != v2e){
			return true;
		}
		else {
			return false;
		}
	}
};


int main()
{	
	vector<int> a = { 1,2,3 };
	vector<int> b = { 4,5,6 };
	ZigzagIterator* z = new ZigzagIterator(a, b);
	return 0;
}

