#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
#include <numeric>
#include <iomanip> 
#include <locale>
#include <regex>
#include <sstream>
#include <iterator>
#include <cstdlib>
#include <ctime>

using namespace std;

string primeFileName = "PrimeNums.txt", outputFilename;

int num, bign, count_of_nums = 0, num_digits = 0;

vector<int> primes;

void clearFile(string& outputFilename) {
	ofstream outputFile(outputFilename, ios::trunc);
	if (!outputFile.is_open()) {
		cout << "Unable to clear file";
	}
	outputFile.close();
}

void file(string& outputFilename) {
	ofstream outputFile(outputFilename, ios::app);
	if (outputFile.is_open()) {
		for (int i = 0; i < primes.size(); i++) {
			outputFile << primes[i] << " ";
			count_of_nums++;
			num_digits += log10(primes[i]) + 1;
			if (primes[i] > primes[i] + 1) {
				bign = primes[i];
			}
			else {
				bign = primes[i] + 1;
			}
		}
		outputFile << endl;

		outputFile.close();
	}
	else {
		cout << "Unable to open file";
	}
}

void file2(string& outputFilename, int& count_of_nums, int& num_digits, int& bign) {
	ofstream outputFile(outputFilename, ios::app);
	if (outputFile.is_open()) {
		outputFile << "Количество чисел: " << count_of_nums << endl;
		outputFile << "Количество цифр: " << num_digits << endl;
		outputFile << "Самое большое число: " << bign - 1;

		outputFile.close();
	}
	else {
		cout << "Unable to open file";
	}
}

bool isPrime(int num) {
	if (num == 1) {
		return false;
	}
	else {
		for (int i = 2; i <= num / 2; ++i) {
			if (num % i == 0)
				return false;
			else
				return true;
		}
	}
	return true;
}

int main() {

	cout << "Enter a natural number > 1: ";
	cin >> num;
	clearFile(primeFileName);

	if (isPrime(num)) {
		for (int i = 2; i <= num; ++i) {
			if (isPrime(i)) {
				primes.push_back(i);
			}
		}
		file(primeFileName);
		file2(primeFileName, count_of_nums, num_digits, bign);
		for (int prime : primes) {
			cout << prime << " ";
		}
	}
	else {
		cout << "This number is a composite- one.";
	}
	
	return 0;
}