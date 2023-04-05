#include "header.h"




curDay getDay() {
	std::cout << "Please, write current day, month and year (in format dd/mm/yyyy): ";
	std::string line, temp;
	curDay A;
	std::getline(std::cin, line);
	temp = line.substr(0, 2);
	A.date = stoi(temp);
	temp = line.substr(3, 2);
	A.month = stoi(temp);
	temp = line.substr(6, 4);
	A.year = stoi(temp);

	return A;
}



void writeFile(std::string filename) {

	std::ofstream write(filename, std::ios::binary | std::ios::app);
	int n;
	std::string check = "N";
	Customer A;
	
	do {
		std::cout << "Please, enter a number of customers: ";
		std::cin >> n;
		
		for (int i = 0; i < n; i++) {
			std::cin.ignore();
			std::cout << "Please, enter a surname of person: ";
			std::cin.getline(A.surname, sizeof(A.surname));

			std::cout << "Please, enter a gender of person: ";
			std::cin.getline(A.gender, sizeof(A.gender));

			std::cout << "Please, enter a date of person birth(example: 22/10/2004): ";
			std::cin.getline(A.birth, sizeof(A.birth));

			std::cout << "Please, enter a number of good: ";
			std::cin >> A.count;
			write.write((char*)&A, sizeof(Customer));
			std::cout << std::endl;
		}

		std::cout << "Maybe, you want to add other customers(Y/N): ";
		std::cin >> check;
	} while (check == "Y" || check == "y");

	write.close();
}




void readFile(std::string filename) {
	std::ifstream read(filename, std::ios::binary);
	Customer A;


	while(read.read((char*)&A, sizeof(Customer))) {
		std::cout << "Surname: " << A.surname << std::endl;
		std::cout << "Gender: "  << A.gender  << std::endl;
		std::cout << "Birth: "   << A.birth   << std::endl;
		std::cout << "Count: "   << A.count   << std::endl;
	}

	read.close();

}


float discount(std::string filename_1, curDay D) {
	int calculateAge(std::string line, curDay D);
	void fillSecond(Customer);
	std::ifstream read(filename_1, std::ios::binary);
	//std::ofstream write(filename_2, std::ios::binary);
	Customer A;
	std::string temp, line;
	float total = 0;
	
	while (read.read((char*)&A, sizeof(Customer))) {
		int age = calculateAge(A.birth, D);
		float x = A.count;
		if (age >= 60) {
			x = (x - (float)age / 100) * 0.95;
			total += x;
		}
		else {
			x = x - (float)age/100;
			total += x;
		}

		if (x*100 > 250) {
			fillSecond(A);
		}

	}

	total *= 100;
	//write.close();
	read.close();

	std::cout << "TOTAL SUM = " << total << std::endl;
	return total;
}




int calculateAge(std::string line, curDay D) {
	std::string temp;
	int birth_date, birth_month, birth_year, age;
	int cur_date = D.date,
		cur_month = D.month,
		cur_year = D.year;

	temp = line.substr(0, 2);
	birth_date = stoi(temp);
	temp = line.substr(3, 2);
	birth_month = stoi(temp);
	temp = line.substr(6, 4);
	birth_year = stoi(temp);
	
	int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (birth_date > cur_date) {
		cur_date += month[birth_month - 1];
		cur_month--;
	}

	if (birth_month > cur_month) {
		cur_year--;
		cur_month += 12;
	}
	age = cur_year - birth_year;
	return age;
}


void fillSecond(Customer B) {
	std::string filename_1 = "final_file.bin";
	std::ofstream write(filename_1, std::ios::binary | std::ios::app);
	write.write((char*)&B, sizeof(Customer));
}




void functionCaller() {
	std::string check = "N";
	curDay B = getDay();
	do {
		std::string filename_1 = "first_file.bin";
		std::string filename_2 = "final_file.bin";
		writeFile(filename_1);
		std::ofstream clean("final_file.bin", std::ios::trunc);
		clean.close();
		discount(filename_1, B);
		std::cout << "Final_file: " << std::endl;
		readFile(filename_2);

		std::cout << "Maybe, you want to add other customers(Y/N): ";
		std::cin >> check;
	} while (check == "Y" || check == "y");
}























//const int n = 100;
//Customer customers[n];
/*dateOfBirth date1 = {
	2005, 10, 01
};
Customer cus1 = {"Khomenko", "M", date1 ,5};
*/
//std::cout << cus1;
/*
std::cout << "Surmane: " << cus1.surname << std::endl;
std::cout << "Gender: "  << cus1.gender  << std::endl;
std::cout << "Year: "    << date1.year   << std::endl;
std::cout << "Month: "   << date1.month  << std::endl;
std::cout << "Day: "     << date1.day   << std::endl;
std::cout << "Count: "   << cus1.count   << std::endl;

std::cout << "Day: " <<  std::setw(2) << std::setfill('0') << date1.day << std::endl;
*/





/*int day = 11, month = 11, year = 1965;
std::cout << "Day = " << day << std::endl;
std::cout << "Month = " << month << std::endl;
std::cout << "Year = " << year << std::endl;
struct tm date = { 0 };
date.tm_year = year - 1900;
date.tm_mon = month - 1;
date.tm_mday = day;
time_t normal = mktime(&date);
time_t current;
time(&current);
int age = (difftime(current, normal) + 86400L / 2) / 86400L;
std::cout << age / 365 << std::endl;
write.write((char*)&A, sizeof(Customer));*/