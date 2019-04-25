#include "Runner.h"
#include <vector>
#include <algorithm>
#include <random>
#include <map>


int main() {
	std::vector<Runner> listrunner{
		{"ubin", 23, "2626", 10, Time(1, 12, 25)},
		{"imin", 23, "3105", 10, Time(2, 0, 14)},
		{"susu", 23, "0911", 5, Time(1, 00, 32)},
		{"koko", 19, "1412", 22, Time(3, 44, 11)},
		{"rong", 32, "0618", 42, Time(4, 34, 1)},
		{"euclid", 41, "8888", 42, Time(2, 2, 25)},
	};

	//sort by overloaded comparison operators
	std::sort(begin(listrunner), end(listrunner));


	//sort by lambda expressions
	std::sort(begin(listrunner), end(listrunner), 
		[](Runner e1, Runner e2) {return e1.getAge() > e2.getAge(); });

	std::sort(begin(listrunner), end(listrunner), 
		[](Runner e1, Runner e2) {return e1.getName() < e2.getName(); });

	std::sort(begin(listrunner), end(listrunner),
		[](Runner e1, Runner e2) {return e1.getName() < e2.getName(); });
	
	//sort with alphabet order
	std::stable_sort(begin(listrunner), end(listrunner),
		[](Runner e1, Runner e2) {return e1.getDistance() < e2.getDistance(); });
	
	std::vector<int> v{ 2, 7, -1, 9, -5, 6, 4, -1, 2, 0, 8 };
	sort(begin(v), end(v), [](int elem1, int elem2) {return abs(elem1) > abs(elem2); });
	
	//check sort
	auto sorted{ is_sorted(begin(v),end(v)) };
	sorted = is_sorted(begin(v), end(v),
		[](int elem1, int elem2) {return abs(elem1) > abs(elem2); });


	int high{ *(max_element(begin(v),end(v))) };
	int low{ *(min_element(begin(v),end(v))) };

	std::vector<int> v2{ 1, 4, -1, 6, -8, 6, 3, 2, -2, 0, 8 };
	sort(begin(v2), end(v2));
	low = *begin(v2);
	high = *(end(v2) - 1);
	int positive = *upper_bound(begin(v2), end(v2), 0); //return first greater element

	std::sort(begin(listrunner), end(listrunner),
		[](Runner e1, Runner e2) {return e1.getName() < e2.getName(); });
	auto p{ std::lower_bound(begin(listrunner),end(listrunner), "s", //return first not smaller element
		[](Runner e1, std::string n) {return e1.getName() < n; }) };

	float dis{ p->getDistance() };

	//shuffle
	std::random_device randomdevice;

	std::mt19937 generator(randomdevice());
	std::shuffle(begin(v2), end(v2), generator);
	std::vector<int> vtemp{ v2 };

	//partial sort 3 smallest element with upper boundary middle parameter
	std::partial_sort(begin(v2), begin(v2) + 3, end(v2), [](int elem1, int elem2) {return abs(elem1) < abs(elem2); });
	/*std::vector<int> vtemp(5);
	std::partial_sort_copy(begin(v2), end(v2), begin(vtemp), end(vtemp));*/
	int break_point{ *is_sorted_until(begin(v2),end(v2)) };	

	std::vector<int> v3(3);
	std::partial_sort_copy(begin(v2), end(v2), begin(v3), end(v3));

	std::vector<Runner> medal(3);
	std::partial_sort_copy(begin(listrunner), end(listrunner), begin(medal), end(medal));


	//nth element
	v2 = { 1, 5, 4, 2, 9, 7, 3, 8, 2 };
	int i{ *begin(v2) + 4 };
	std::nth_element(begin(v2), begin(v2) + 4, end(v2));
	i = *(begin(v2) + 4);

	system("pause");
	return 0;
}