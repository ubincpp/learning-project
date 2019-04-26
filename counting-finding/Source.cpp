#include <vector>
#include <string>
#include <algorithm>
#include <map>

int main() {
	//std::vector<int> v{ 2,7,1,6,2,-2,4,0 };

	////count how many entries have the target value (2)
	////count
	//int twos{ 0 };
	//int const target{ 2 };
	//for (size_t i{ 0 }; i < v.size(); i++) {
	//	if (v[i] == target) {
	//		twos++;
	//	}
	//}

	//twos = count(v.begin(), v.end(), target);
	//twos = count(begin(v), end(v), target);

	////count how many entries are odd
	////count with lambda
	//int odds{ 0 };

	//for (auto elem : v) {
	//	if (elem % 2 != 0) {
	//		++odds;
	//	}
	//}

	//odds = count_if(begin(v), end(v), [](auto elem) {return elem % 2 != 0; });

	//std::map<int, int> monthlengths{ {1,31}, {2,28}, {3,31}, {4,30}, {5,31}, {6,30}, {7,31}, {8,31}, {9,30}, {10,31}, {11,30}, {12,31} };
	//int longmonths = count_if(begin(monthlengths), end(monthlengths), [](auto elem) {return elem.second == 31; });

	////are all, any, or none of values odd? (Conclude 
	////allof noneof anyof
	//bool allof;
	//bool noneof;
	//bool anyof;
	//allof = (odds == v.size());
	//noneof = (odds == 0);
	//anyof = (odds > 0);

	//allof = all_of(begin(v), end(v), [](auto elem) { return elem % 2 != 0; });
	//noneof = none_of(begin(v), end(v), [](auto elem) {return elem % 2 != 0; });
	//anyof = any_of(begin(v), end(v), [](auto elem) {return elem % 2 != 0; });


	std::vector<int> v{ 1, 1, 4, 6, 6, 1, 3, -2, 0, 11, 2, 3, 2, 4, 4, 2, 4 };
	std::string s{ "Hello I am a sentence" };

	//find the first zero in the collection
	//find
	auto result{ find(begin(v),end(v),0) };
	int welookedfor{ *result };

	//find the first 2 after zero
	result = find(result, end(v), 2);
	if (result != end(v)) {
		welookedfor = *result;
	}

	//find the first a
	auto letter{ find(begin(s),end(s),'a') };
	char a = *letter;

	//find first odd value
	//find_if (with lambda)
	result = find_if(begin(v), end(v), [](auto elem) {return elem % 2 != 0; });
	welookedfor = *result;

	//find first even value
	//find_if_nof (lambda)
	result = find_if_not(begin(v), end(v), [](auto elem) {return elem % 2 != 0; });
	welookedfor = *result;

	//find_first_of 
	//Returns an iterator to the first element in the range [first1,last1) that matches any of 
	//the elements in [first2,last2). If no such element is found, the function returns last1.

	std::vector<int> primes{ 1, 2, 3, 5, 7, 11, 13 };
	result = find_first_of(begin(v), end(v), begin(primes), end(primes));
	welookedfor = *result;

	//Searches the range [first1,last1) for the first occurrence of the sequence defined 
	//by [first2,last2), and returns an iterator to its first element, or last1 if no occurrences are found.
	std::vector<int> subsequence{ 0, 11 };
	result = search(begin(v), end(v), begin(subsequence), end(subsequence));
	welookedfor = *result;
	result++;
	result++;
	int six{ *result };

	std::string am{ "am" };
	letter = search(begin(s), end(s), begin(am), end(am));
	a = *letter;

	result = find_end(begin(v), end(v), begin(subsequence), end(subsequence));

	if (result != end(v)) {
		welookedfor = *result;
	}

	//search_n 
	//Searches the range [first,last) for a sequence of count elements, each comparing equal 
	//to val (or for which pred returns true).
	result = search_n(begin(v), end(v), 2, 6);
	result++;
	int two{ *result };

	//adjacent_find 
	result = adjacent_find(begin(v), end(v));
	six = *result;
	result++;
	six = *result;
	system("pause");
	return 0;
}