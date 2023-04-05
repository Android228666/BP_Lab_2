#include "header.h"



int main() {

	functionCaller();

	return 0;
}


























/*std::string filename_1 = "first_file.bin";
std::string filename_2 = "final_file.bin";
curDay B = getDay();
writeFile(filename_1);
discount(filename_1, B);
std::cout << "Final_file: " << std::endl;
readFile(filename_2);*/


/*std::cout << "DayB " << B.date << std::endl;
	std::cout << "Month: " << B.month << std::endl;
	std::cout << "Year: " << B.year << std::endl;*/
	/*std::string line = "01/12/1929";
	int res = calculateAge(line, B);
	std::cout << "Age: " << res;*/






/*time_t ct = time(0);
string current_time_1;
char current_time[100];
ctime_s(current_time, sizeof(current_time), &ct);
std::cout << current_time;

getline(std::cin, current_time_1);
cout << __DATE__ << endl;

std::cout << "Time = " << current_time_1;*/
//cout << __TIME__ << endl;


/*auto t = std::time(nullptr);
auto tm = *std::localtime(&t);
std::cout << std::put_time(&tm, "%d-%m-%Y %H-%M-%S") << std::endl;
*/

/*int day, month, year;
struct tm date = { 0 };
cout << "Enter Your Date of Birth ( Year Month Day): ";
cin >> year >> month >> day;
date.tm_year = year - 1900;
date.tm_mon = month - 1;
date.tm_mday = day;
time_t normal = mktime(&date);
time_t current;
time(&current);
int age = (difftime(current, normal) + 86400L / 2) / 86400L;
cout << "You are " << age / 365 << " years old.";*/






























/*struct Student {
	char name[50];
	int age;
	float gpa;
};*/



/*
	Student stu = { "Hank", 13, 4.8 };

	std::fstream f;

	f.open("records.bin", std::ios::out | std::ios::binary);

	if (f.is_open()) {
		f.write(reinterpret_cast<char*>(&stu), sizeof(Student));
		f.close();
	}
	else {
		std::cout << "Error!\n";
	}


	Student newStu;

	f.open("records.bin", std::ios::in | std::ios::binary);
	if (f.is_open()) {
		f.read(reinterpret_cast<char*>(&newStu), sizeof(Student));
		f.close();
	}
	else {
		std::cout << "Error!\n";
	}

	std::cout << "Name: " << newStu.name << ", Age: " << newStu.age << ", Gpa: " << newStu.gpa;
	*/
	/*

	const int SIZE = 3;
	Student old_students[SIZE] = {
		{ "Hanks", 13, 4.8 },
		{ "Anna", 25, 5 },
		{ "Mark", 10, 4.3}
	};

	Student new_students[SIZE];

	std::fstream fm;

	fm.open("records.dat", std::ios::out | std::ios::binary);

	if (fm.is_open()) {
		fm.write(reinterpret_cast<char*>(old_students), SIZE * sizeof(Student));
		fm.close();
	}
	else {
		std::cout << "Error!\n";
	}


	fm.open("records.dat", std::ios::in | std::ios::binary);
	if (fm.is_open()) {
		fm.read(reinterpret_cast<char*>(new_students), SIZE * sizeof(Student));
		fm.close();
	}
	else {
		std::cout << "Error!\n";
	}

	for (int i = 0; i < SIZE; i++) {
		std::cout << "Student: " << i + 1 << std::endl;
		std::cout << "Name[" << i << "]: " << new_students[i].name << std::endl;
		std::cout << "Age[" << i << "]: " << new_students[i].age << std::endl;
		std::cout << "Gpa[" << i << "]: " << new_students[i].gpa << std::endl;
	}

	for (Student& s : new_students) {
		std::cout << s.name << std::endl;
		std::cout << s.age << std::endl;
		std::cout << s.gpa << std::endl;
	}*/

	/*int n = 100;
	Customer* customers = new Customer[n];


	delete[] customers;A*/