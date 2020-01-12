#include <iostream>
#include <string>
#include<cctype>
using namespace std;


double maxValue(double* test, int size, int index = 0, double max = 0) {
	if (index == 0)
		max = test[0];

	if (size >= 2 && index < size - 1) {
		index++;
		if (max < test[index])
			max = test[index];

		return maxValue(test, size, index, max);
	}
	return max;

}

double* Sort(double* arr, int size, int index = 0, int secIndex = 1) {
	if (size >= 2 && index < size - 1) {
		if (arr[index] < arr[secIndex]) {
			int tempData = arr[index];
			arr[index] = arr[secIndex];
			arr[secIndex] = tempData;
		}
		if (secIndex < size)
			secIndex++;
		else {
			index++;
			secIndex = index + 1;
		}
		return Sort(arr, size, index, secIndex);
	}

	return arr;
}

bool isPrime(int n, int i = 2) {

	if (n <= 2)
		return (n == 2) ? true : false;
	if (n % i == 0)
		return false;
	if (i * i > n)
		return true;

	return isPrime(n, i + 1);
}

bool isPalidrome(string text, int index = 0) {
	if (index <= text.length() / 2 && text[index] == text[text.length() - 1 - index])
		return isPalidrome(text, index + 1);
	else if (index > text.length() / 2)
		return true;

	return false;
}

string removeChar(string text, char c, int index = 0)
{
	if (index < text.length()) {
		if (text[index] == c)
			text = text.substr(0, index) + text.substr(index + 1, text.length() - 1);
		return removeChar(text, c, index + 1);
	}
	return text;
}

string Flip(string text, int index = 0) {
	int size = 0;
	if (text.length() % 2)
		size = text.length() / 2 + 1;
	else
		size = text.length() / 2;
	if (index >= size)
		return text;

	char c = text[index];
	text[index] = text[text.length() - 1 - index];
	text[text.length() - 1 - index] = c;
	return Flip(text, index + 1);
}

string toUpper(string text, int index = 0) {
	if (index < text.length())
	{
		text[index] = toupper(text[index]);
		return toUpper(text, index + 1);
	}
	return text;
}

string toLower(string text, int index = 0) {
	if (index < text.length())
	{
		text[index] = tolower(text[index]);
		return toUpper(text, index + 1);
	}
	return text;
}

string toBinary(int num, string out = "") {
	if (num > 0) {
		out += to_string(num % 2);
		num /= 2;
		out = toBinary(num, out);
		out = Flip(out);
	}
	out = Flip(out);
	return out;
}

string toOctal(int num, string out = "") {
	if (num > 0) {
		out += to_string(num % 8);
		num /= 8;
		out = toOctal(num, out);
	}
	return Flip(out);
}

string Divisors(int x, int index = 1, string out = "")
{
	if (index <= x) {
		if (x % index == 0)
			out += to_string(index) + " ";
		return Divisors(x, index + 1, out);
	}
	return out;
}

int Pow(int n, int m) {
	if (m == 0)
		return 1;
	return (n * pow(n, m - 1));
}

int Pmmp(int n, int m)
{
	if (m == 0) return n;
	return Pmmp(m, n % m);
}

