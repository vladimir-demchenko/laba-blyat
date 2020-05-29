#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

class basic {
public:
	vector<int> arr;
	int len = 0;
	int num;
};

class cl1 : virtual public basic {
public: 
	void getNewArr() {
		cin >> len;
		for (int i = 0; i < len; i++) {
			cin >> num;
			arr.push_back(num);
		}
	}
};

class cl2 : virtual public basic {
public: 
	void sort() {
		int j;
		for (int i = 0; i < len - 1; i++) {
			j = i;
			for (int k = i + 1; k < len; k++) {
				if (arr[k] < arr[j])
					j = k;
			}
			swap(arr[i], arr[j]);
		}
	}

	void printArr() {
		for (int i = 0; i < len; i++) {
			cout << setw(5) << arr[i];
		}
	}
};

class cl3 : public cl1, public cl2 {
public:
	void run() {
		getNewArr();
		cout << "Array dimension: " << len << endl;
		cout << "The original array:";
		printArr();
		sort();
		cout << "\nAn ordered array:";
		printArr();
	}
};

int main() {
	cl3 c;
	c.run();
	return 0;
}