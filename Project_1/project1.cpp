// Summer 2022
// Project 1
// Computing Structures

#include <iostream>
#include <fstream>

#include <string>
#include <algorithm>

using namespace std;

const int numberOfYears = 51; // number of columns/years

// class to store one row of data
class OneCountry {
protected:
	string 	countryName; // name of the country/region
	string 	countryCode; // code of the country/region
	long int	yearsData[numberOfYears]; // number of people who travelled that year (first year starts with 1970 to 2021)
	long long int 	sumTotal; // Total of all years of travel data 

public:
	OneCountry(); // default constructor
	OneCountry(string cn, string cc, long int* data); //non-default constructor

	void display(); //display method

	string getCountryName(); //getters
	string getCountryCode();
	long int* getYearsData();
	long long int getSumTotal();

};

void OneCountry::display() {

	cout << this->getCountryName() << " (" <<this->getCountryCode() << "):" << endl;
	int year = 1970;
	long int* a = this->getYearsData();
	for (int j = 0; j < numberOfYears; j++) {
		cout << year + j << " - " << a[j] << ", ";
	}
	cout << "Total -> " << this->getSumTotal() << endl;
}

string OneCountry::getCountryName() {
	return this->countryName;	//get the current objects countryName
}
string OneCountry::getCountryCode() {
	return this->countryCode; //get the current objects countryCode
}
long int* OneCountry::getYearsData() {
	return this->yearsData;		//get the current objects yearsData
}

long long int  OneCountry::getSumTotal() {			//calculated
	sumTotal = 0;
	for (int i = 0; i < numberOfYears; i++) {		
		sumTotal = yearsData[i] + sumTotal;			//sum = sum+yearsdata
	}
	return this->sumTotal;							//return the total
}

OneCountry::OneCountry() {		//default empty constructor
	countryName = ' ';
	countryCode = ' ';
	yearsData[numberOfYears-1] = 0;
	sumTotal = 0;
}

OneCountry::OneCountry(string cn, string cc, long int* data) {	//non-default constructor
	countryName = cn;
	countryCode = cc;
	for (int i = 0; i < numberOfYears; i++) {
		yearsData[i] = data[i];
	}

}

// class to store multiple rows of data
class travelData {
protected:
	OneCountry** allCountries; // array of pointers of class OneCountry
	int numCountries; //This will be the first line in the input

public:
	travelData(); // default constructor
	travelData(int numC); // non-default constructor

	void display(); // display all rows 
	void addCountry(OneCountry* oneC,int i); // add one country
	void sortDataByCountryName(); // sort alphabetically by name of country

	//Queries
	void displayCountry(string countryCode); //command C - display specific country row given countryCode
	OneCountry* findCountry(int kthLargestTotal); //command K - sort allCountries based on sumTotal and find the kth largest country
	long int findTravelNums(string countryCode, int year); //assume yearsData[0] is year 1970 - command T - return number for given year and countryCode
	string* findAllCountries(int year, int minTravelNum, int maxTravelNum); //Range Search - command A - given range of year and min and 
																	// max number, return all countries that fall within
};
travelData::travelData() {
	numCountries = 0;
	allCountries = new OneCountry* [numCountries];	
	
}
travelData::travelData(int numC) {			
	allCountries = new OneCountry* [numC];	
	numCountries = numC;

}
void travelData::display() {					//display all countries info
	for (int i = 0; i < numCountries; i++) {
		allCountries[i]->display();
	}
}

void travelData::addCountry(OneCountry* oneC,int i) {	//add one OneCountry object to allcountries
	allCountries[i] = oneC;

}

void travelData::sortDataByCountryName() {
//	for (int i = 0; i < numCountries; i++) {
	sort(allCountries, allCountries + numCountries, //using sort algorithm,returns allCountries object sorted by countryName
			[](OneCountry* x, OneCountry* y) -> bool
			{
				return x->getCountryName() < y->getCountryName();
			});
	//}
	

}
void travelData::displayCountry(string countryCode) {	//Option C - Display info of the given countryCode
	int pos = 0;								//to store the position of the array where that countryCode is
	for (int i = 0; i < numCountries; i++) {
		if (allCountries[i]->getCountryCode() == countryCode) {	//check in allCountries, the countryCode we are looking
			 pos = i;											//once found, save the position in pos
			 break;
		}
		else {
			continue;
		}
	}
	allCountries[pos]->display();								//display the info of country stored in pos of allCountries
	
}

OneCountry* travelData::findCountry(int kthLargestTotal) {	//Option K - sort country on sumTotal and show the kth largest
	sort(allCountries, allCountries + numCountries,			//sort using the algorithm on sumTotal
		[]( OneCountry* x,  OneCountry* y) -> bool
		{
			return x->getSumTotal() > y->getSumTotal();
		});
	//cout << "AFTER SORT";
	//for (int i = 0; i < numCountries; i++) {
	//	allCountries[i]->display();
	//}
	return allCountries[kthLargestTotal-1];					//since the k-largest is unit indexed, access the k-1 row on the sorted array

}
/*bool travelData::validYear(int year) {
	int yearstart = 1970;
	int yearEnd = 2021;
	if (year <= yearstart && year >= yearEnd) {											//condition to test for valid year
		cout << "INVALID YEAR!";
		return 0;
	}
}*/
long int travelData::findTravelNums(string countryCode, int year) {	//Option T - find the yearData for given countryCode and year
	int yeartemp = 1970;											//store the starting year
	int yearstart = 1970;
	int yearEnd = 2021;
	if (year <= yearstart || year >= yearEnd) {											//condition to test for valid year
		cout << "INVALID YEAR!";
		return 0;
	}
		for (int i = 0; i < numCountries; i++) {
			if ((allCountries[i]->getCountryCode() == countryCode)) {	//look for the countryCode in allCountries to find that object
				for (int j = 0; j < numberOfYears; j++) {				//within each country loop through num of years to find the year Data
					if (j + yeartemp == year) {							//to find the correct year info, add the starting year to j(counter)
						long int* a = allCountries[i]->getYearsData();	//store it in a pointer
						return a[j];									//access the pointer to value,return
						break;											//once found, exit
					}
				}

			}
		}

}
string* travelData::findAllCountries(int year, int minTravelNum, int maxTravelNum) { //Option A - looks within an year in each country for the range of min-max 
	int yeartemp = 1970;											//store the starting year
	int yearstart = 1970;
	int yearEnd = 2021;
	if (year < yearstart || year > yearEnd) {											//condition to test for valid year
		cout << "INVALID YEAR!";
		return 0;
	}
	int count = 0;													//to keep track of condition satisfied
		string* ptr = new string[10];
		for (int i = 0; i < numCountries; i++) {
			long int* a = allCountries[i]->getYearsData();				//store yearsData
			if (a[year - yeartemp] >= minTravelNum && a[year - yeartemp] <= maxTravelNum) {	//to get the correct index, subtract the year given with starting year. 
				ptr[count] = allCountries[i]->getCountryCode();								//yearData for that particular year is found within range
				count++;																	//store it in the string array of count
																							//instead of i, used count to avoid empty spaces	
			}
		}

		return ptr;
}

int main() {



	travelData* allData; // object to store all the data
	OneCountry* country; // temp object to store each row

	ifstream countryFile("dataInput1.txt"); // read in the data file
	ifstream queryFile("queryInput1.txt"); // read in the query file

	int numberOfCountries;
	int numOfQueries;

	string countryN, countryCode; // temp variables to store input
	long int yearD[numberOfYears]; // static array
	char command; // to store command character from query file
	long long int sum;
	countryFile >> numberOfCountries; // read in the number of countries from 

	allData = new travelData(numberOfCountries); // allocate memory and call non default consturctor


	// loop through and store the data
	for (int i = 0; i < numberOfCountries; i++) {
		//This statment needs to be corrected; This will not work; Needs Fixing
		//countryFile >> countryN >> countryCode;
		getline(countryFile, countryN, ',');
		getline(countryFile, countryCode, ',');

		char c;
		for (int j = 0; j < numberOfYears; j++) {	//getline takes yearD data as string, since used this method
			countryFile >> yearD[j];
			//cout << yearD[j] << "<-year";			//for test
			countryFile.get(c);

			if (j == numberOfYears - 1) {			//52th row is sum, if the j counter is numberOfYears-1 (zero indexed) ie 52th row
				countryFile >> sum;					//save it as the sum
				//cout << sum << "<-sum";			//for test
			}
		}
		

		country = new OneCountry(countryN, countryCode, yearD);	
		(*allData).addCountry(country,i);
	}
	//cout << "BEFORE SORT";
	//(*allData).display();			//display allCountries info
	//cout << "AFTER SORT";
	//(*allData).sortDataByCountryName();	//sort allCountries by CountryName
	//(*allData).display();					//display after sorting
	//(*allData).displayCountry("CHN");		//for test

	queryFile >> numOfQueries;				//no of queries (mentioned at the top of the input)
	for (int i = 0; i < numOfQueries; i++) {

		queryFile >> command;
		switch (command)
		{
		case 'C': {
			queryFile >> countryCode;				//2nd argument is a countryCode	
			(*allData).displayCountry(countryCode);	//call the displayCountry function 
			break;
		}
		case 'K': {
			int kthLargest;
			queryFile >> kthLargest;				//save the k input		
			country=(*allData).findCountry(kthLargest);	//returns the country with kth largest sumtotal
			cout  << country->getCountryName() << " - " << kthLargest << " - "<< country->getCountryCode() << " - " << country->getSumTotal() << endl; //display
			//country->display();
			break;
		}
		case 'T': {
			int year;
			queryFile >> countryCode;
			queryFile >> year;
			int total =(*allData).findTravelNums(countryCode, year);	//returns the yearData for that particular CountryCode and year
			cout << endl;
			cout << countryCode << " - " << year << " - " << total << endl;	//display

			break;
		}
		case 'A': {
			int year;
			long int min;
			long int max;
			queryFile >> year;
			queryFile >> min;
			queryFile >> max;
			cout << endl << "Countries/Regions with travel passengers [" << min << "," << max << "] - " << year << ": " << endl;
			string* ptr=(*allData).findAllCountries(year, min, max);	//returns the string array with all countryCodes with yearData within the range
			for (int i = 0; i < numberOfCountries; i++) {
				cout << ptr[i] << endl;									//display
			}
			
			break;
		}
		default:
			(*allData).display();
			break;
		}

	}
}