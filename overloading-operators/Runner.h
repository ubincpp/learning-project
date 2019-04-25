#pragma once
#include <iostream>
#include <string>

struct Time {
	short hour;
	short minute;
	short second;

	Time() : hour(0), minute(0), second(0) {};
	Time(short hour, short minute, short second) : hour(hour), minute(minute), second(second) {};
};

std::istream &operator>>(std::istream &in, Time &time) {
	std::cout << "Enter hours: ";
	std::cin >> time.hour;
	std::cout << "Enter minutes: ";
	std::cin >> time.minute;
	std::cout << "Enter seconds: ";
	std::cin >> time.second;
	return in;
}

class Runner
{
private:
	std::string name;
	int age;
	std::string bidnumber;
	float distance;
	Time bestpr;
public:
	Runner() : name(""), age(0), bidnumber("0000"), distance(0), bestpr(Time(0, 0, 0)) {};
	Runner(std::string name, int age, std::string bid, float distance, Time pr) : name(name), age(age), bidnumber(bid), distance(distance), bestpr(pr) {};
	
	std::string getName() const {
		return this->name;
	}

	int getAge() const {
		return this->age;
	}

	std::string getBid() const {
		return this->bidnumber;
	}

	float getDistance() const {
		return this->distance;
	}

	Time getBestPr() const {
		return this->bestpr;
	}

	bool operator<(const Runner &man) {
		return (bestpr.hour * 3600 + bestpr.minute * 60 + bestpr.second) > (man.bestpr.hour * 3600 + man.bestpr.minute * 60 + man.bestpr.second);
	}

	bool operator>(const Runner &man) {
		return !(*this < man);
	}

	const Runner &operator=(const Runner &man) {
		this->name = man.name;
		this->age = man.age;
		this->bidnumber = man.bidnumber;
		this->distance = man.distance;
		this->bestpr = man.bestpr;
		return *this;
	}

	friend std::istream &operator>>(std::istream& in, Runner &man) {
		std::cout << "Enter fullname: ";
		std::string fullname{ "" };
		std::getline(std::cin, fullname);
		std::cin.ignore(1024, '\n');
		for (std::string::iterator it{ begin(fullname) }; it != end(fullname); it++) {
			man.name.push_back(*it);
		}
		std::cout << "Enter age: ";
		std::cin >> man.age;
		std::string bid{ "" };
		std::cin.ignore(1024, '\n');
		std::cout << "Enter bidnumber: ";
		std::getline(std::cin, bid);
		for (std::string::iterator it{ begin(bid) }; it != end(bid); it++) {
			man.bidnumber.push_back(*it);
		}
		std::cout << "Enter distance: ";
		std::cin >> man.distance;
		std::cin >> man.bestpr;
		return in;
	}

};

std::ostream &operator<<(std::ostream &out, const Time &time) {
	out << time.hour << ":" << time.minute << ":" << time.second;
	return out;
}

std::ostream &operator<<(std::ostream &out, const Runner &man) {
	out << "Name: " << man.getName() << "\n" << "Age: " << man.getAge() << "\n" << "Bid number:" << man.getBid() << "\n" << "Distance: " << man.getDistance() << "\n" << "Best PR: " << man.getBestPr();
	return out;
}

Time operator+(const Time &first_man, const Time &second_man) {
	int first_man_time{ first_man.hour * 3600 + first_man.minute * 60 + first_man.second };
	int second_man_time{ second_man.hour * 3600 + second_man.minute * 60 + second_man.second };
	int total{ first_man_time + second_man_time };
	int hours{ total / 3600 };
	int minute{ (total - hours * 3600) / 60 };
	int second{ total - hours * 3600 - minute * 60 };

	return Time(hours, minute, second);
}

//Time operator-(const Time &first_man, const Time &second_man) {
//	int first_man_time{ first_man.hour * 3600 + first_man.minute * 60 + first_man.second };
//	int second_man_time{ second_man.hour * 3600 + second_man.minute * 60 + second_man.second };
//
//}

Time operator*(const Runner &first_man, const Runner &second_man) {
	return (first_man.getBestPr() + second_man.getBestPr());
}





