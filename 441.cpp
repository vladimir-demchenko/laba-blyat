#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

class basic {
public:
	vector<int> arr;
	int len;
	
	void in_out() {
		int l;
		cin >> l;
		this->len = l;
		int n;
		for (int i = 0; i < len; i++) {
			cin >> n;
			arr.push_back(n);
		}
	}
};

class cl1: public basic {
public:
	int func() {
		int a0 = arr[0];
		for (int i = 1; i < len; i++) {
			a0 -= arr[i];
		}
		return a0;
	}
};

class cl2: public cl1 {
public:
	int func() {
		int s = 0;
		for (int i=0; i < len; i++) {
			s += arr[i];
		}
		return s;
	}
};

class cl3: public cl2 {
public: 
	void in_out() {
		cout << "Array dimension: " << len << endl;
		cout << "The original array:";
		for (int i = 0; i < len; i++) {
			cout << setw(5) << arr[i];
		}
		cout << "\nMin: " << cl1::func() << "\nSum: " << cl2::func();
	}
};

int main()
{
	// program here
	cl3* c = new cl3();
	c->basic::in_out();
	c->in_out();
	return(0);
}
