//Dominik Zycinski
//Karp-Rabin
//30.05.17

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;



class Karp
{
public:


	long asci(unsigned char x)
	{
		return x;
	}

	long potegowanie(long a, long b)
	{
		int wynik = 1;
		for (int i = 1; i <= b; i++)
		{
			wynik = wynik*a;
		}
		return wynik;
	}
	void hash(string key, string text)
	{



		unsigned long long find;
		unsigned long long find2 = 0;
		int *liczba;
		unsigned long  long keyL;//dlugosc klucza
		unsigned long  long textL;//dlugosc tekstu
		unsigned long long  wynik;


		liczba = new int[text.length()];
		for (long long i = 0; i < text.length(); i++)
		{

			liczba[i] = NULL;

		}


		keyL = key.length() - 1;
		textL = text.length();
		long long l = keyL;
		long long k = textL;

		for (int i = 0; i < key.length(); i++)
		{

			find2 += (asci(key[i])) % 67 * (potegowanie(3, keyL)) % 67;

			keyL--;

		}

		int w = 3;
		for (long long i = 0; i < textL - key.length(); i++)
		{
			l = key.length() - 1;
			for (long long j = i; j < i + key.length(); j++)
			{

				liczba[i] += (asci(text[j])) % 67 * (potegowanie(3, l)) % 67;



				if (liczba[i] == find2)
				{
					int sprawdz = 0;
					for (long long y = 0; y < key.length(); y++)
					{
						if (asci(text[y + i]) != asci(key[y]))
						{
							break;
						}

						if (asci(text[y + i]) == asci(key[y]))
						{
							sprawdz++;

						}
					}

					if (sprawdz == key.length())
					{
						cout << " " << i;
					}
				}

				l--;
				if (l < 0)
				{

					l = key.length();
				}

			}
		}
	}






};


int main()
{


	string file, n;
	string k; //tego szukam;
	string x, t; //zczytywanie lin z pliku

	getline(cin, n);
	long m;
	m = stol(n);
	do
	{
		Karp rabin;
		getline(cin, file);

		fstream plik;
		plik.open(file, ios::in);

		if (plik.fail())
		{
			cout << "Blad" << endl;
		}

		while (getline(plik, x))
		{
			t = t + x + "\n";

		}



		getline(cin, k);
		rabin.hash(k, t);
		t.clear();
		k.clear();
		plik.close();
		m--;
	} while (m > 0);

	return 0;
}