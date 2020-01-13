#include <iostream>
#include <string>
#include <cctype>
#include <conio.h>
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
	if (index >= text.length() / 2)
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
		return toLower(text, index + 1);
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

int main() {

	while (true) {
		system("CLS");
		int fOption;
		cout << "Funksionet e mundshme --- " << endl;

		cout << "[1] Shtyp vleren maksimale te vektorit te dhene." << endl;
		cout << "[2] Sorton vektorin e dhene." << endl;
		cout << "[3] Kontrollon se a eshte numri i dhene i thjeshte." << endl;
		cout << "[4] Kontrollon se a eshte teksti i dhene palidrom." << endl;
		cout << "[5] Largon karakterin e dhene nga teksti." << endl;
		cout << "[6] Rrotullo tekstin e dhene." << endl;
		cout << "[7] Shendrron tekstin e dhene ne shkronja te medha." << endl;
		cout << "[8] Shendrron tekstin e dhene ne shkronja te vogla." << endl;
		cout << "[9] Shendrron numrin e dhene ne numer binar." << endl;
		cout << "[10]Shendrron numrin e dhene ne numer oktal." << endl;
		cout << "[11]Gjene pjestuesit e numrit te dhene." << endl;
		cout << "[12]Ngrit ne fuqine edhe numrin e dhene" << endl;
		cout << "[13]Gjene pjestuesin me te madhe te perbashket mes dy numrave natyror." << endl;

		cout << "\nTe caktohet funksioni per perdorim: ";
		cin >> fOption;


		switch (fOption)
		{
		case 1:
		{
			const int size = 5;
			double A[5];

			cout << "Te shenohen antaret e vektorit " << endl;
			for (int i = 0; i < size; i++)
			{
				cout << "A[" << (i + 1) << "] = ";
				cin >> A[i];
			}

			cout << "Vlera maksimale ne vektor eshte " << maxValue(A, size);
		}
		break;

		case 2:
		{
			const int size = 5;
			double A[5];

			cout << "Te shenohen antaret e vektorit " << endl;
			for (int i = 0; i < size; i++)
			{
				cout << "A[" << (i + 1) << "] = ";
				cin >> A[i];
			}

			double* B = Sort(A, size);

			cout << "Vektori i sortuar eshte " << endl;

			for (int i = 0; i < size; i++)
			{
				cout << "A[" << (i + 1) << "] = " << B[i] << endl;
			}

		}
		break;
		case 3:
		{
			int cPrime;
			cout << "\nNumri per kontrollim: ";
			cin >> cPrime;

			(isPrime(cPrime) == true) ? (cout << "Eshte i thjeshte" << endl) : (cout << "Nuk eshte i thjeshte" << endl);
		}
		break;
		case 4:
		{
			string cPalidrome;
			cout << "\nTeksti per kontrollim: ";
			cin.ignore();
			getline(cin, cPalidrome);

			cout << "Teksti i dhene " << cPalidrome;
			(isPalidrome(cPalidrome) == true) ? (cout << " eshte palidrom" << endl) : (cout << " nuk eshte palidrom" << endl);
		}
		break;
		case 5:
		{
			string charText;
			char cRemove;

			cout << "\nTeksti i dhene: ";
			cin.ignore();
			getline(cin, charText);

			cout << "\nKarakteri i dhene: ";
			cin >> cRemove;

			cout << "Teksti rezultues: " << removeChar(charText, cRemove);
		}
		break;
		case 6:
		{
			string sFlip;

			cout << "\nTeksti i dhene: ";
			cin.ignore();
			getline(cin, sFlip);

			cout << "Teksti rezultues: " << Flip(sFlip);
		}
		break;
		case 7:
		{
			string sUpper;

			cout << "\nTeksti i dhene: ";
			cin.ignore();
			getline(cin,sUpper);

			cout << "Teksti rezultues: " << toUpper(sUpper);
		}
		break;
		case 8:
		{
			string sLower;

			cout << "\nTeksti i dhene: ";
			cin.ignore();
			getline(cin, sLower);

			cout << "Teksti rezultues: " << toLower(sLower);
		}
		break;
		case 9:
		{
			int iBinary;

			cout << "\nNumri i dhene: ";
			cin >> iBinary;

			cout << "Numri rezultues: " << toBinary(iBinary);
		}
		break;
		case 10:
		{
			int iOctal;

			cout << "\nNumri i dhene: ";
			cin >> iOctal;

			cout << "Numri rezultues: " << toOctal(iOctal);
		}
		break;
		case 11:
		{
			int iDiv;

			cout << "\nNumri i dhene: ";
			cin >> iDiv;

			cout << "Pjestuesit te numrit rezultues: " << Divisors(iDiv);
		}
		break;
		case 12:
		{
			int a, b;

			cout << "\nNumri i dhene: ";
			cin >> a;

			cout << "\nFuqia e dhene: ";
			cin >> b;

			cout << "Numri " << a << " i ngritur ne fuqine " << b << " eshte: " << Pow(a, b);
		}
		break;
		case 13:
		{
			int a, b;

			cout << "\nNumri i pare i dhene: ";
			cin >> a;

			cout << "\nNumri i dyte i dhene: ";
			cin >> b;

			cout << "Pjestuesi me i madh i perbashket eshte: " << Pmmp(a, b);
		}
		break;
		default:
			break;
		}

		cout << endl << "Perseriteni? [p]o" << endl;
		char contChar = _getch();
		if (contChar != 'p')
			break;


	}

	system("pause");
	return 0;
}
