#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>


int main() {
	std::vector<int> a{ 1, 2, 3, 4, 5 };
	std::vector<int> b{ 1, 2, 3, 4, 5 };

	int arr[5]{ 1,2,3,4,5 };

	bool same{ a.size() == b.size() };

	for (size_t i{ 0 }; i < a.size() && same; i++) {
		if (a[i] != b[i]) {
			same = false;
		}
	}

	//equal
	same = equal(begin(a), end(a), begin(b), end(b));

	//mismatch
	auto firstchange{ mismatch(begin(a),end(a), begin(b)) };

	int avalue = *(firstchange.first);
	int bvalue = *(firstchange.second);
	auto distance = firstchange.first - begin(a);

	int total{ 0 };
	for (int i : a) {
		total += i;
	}


	//accumulate 
	total = accumulate(begin(a), end(a), 0);

	//accumulate with lambda
	total = accumulate(begin(a), end(a), 0,
		[](int total, int i) {if (i % 2 == 0) return total + i; return total; });
	total = accumulate(begin(a), end(a), 1, [](int total, int i) {return total * i; });

	std::vector<std::string> words{ "one", "two", "three" };
	auto allwords{ accumulate(begin(words), end(words), std::string{}) };
	auto length{ allwords.size() };
	allwords = accumulate(begin(words), end(words), std::string{ "Word: " }, [](const std::string &total, std::string &s) {return total + " " + s; });
	length = allwords.size();

		
	std::string s{ accumulate(begin(a), end(a), std::string{"The numbers are:"},
		[](const std::string& s, int number) {return s + " " + std::to_string(number); }) };

	b = a;
	for (auto it{ begin(b) }; it != end(b); it++) {
		*it = 0;
	}
	for (auto& i : b) {
		i = 1;
	}


	//for_each try when you really need loop
	for_each(begin(b), end(b), [](int &elem) {elem = 2; });

	b = a;
	auto firstthree{ find_if(begin(b),end(b), [](auto elem) {return elem == 3; }) };
	for_each(firstthree, end(b), [](int &elem) {return elem = 0; });

	system("pause");
	return 0;
}