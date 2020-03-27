//============================================================================
// Name        : lab01b.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/* Prosz� dopisa� kod, doda� nowe pliki, tak aby program si� wykonywa�
   a wynik jego dzia�ania by� taki sam, jak podany na ko�cu tego pliku.

   Prosz� zdefiniowa� klas� MyString, kt�ra odpowiada klasie std::string.
   Nale�y zdefiniowa� wszystkie potrzebne kondtruktory alokuj�ce pami��
   oraz destruktor j� zwalniaj�cy.
   Nale�y przeci��y� podstawowe operatory do obs�ugi �ancucha znak�w:
   ==, =, +, *, << w r�nych konfiguracjach parametrycznych.
   Dodatkowo nale�y te� zdefiniowa� funkcj� print (dodaje na ko�cu "\n"),
   str (zwraca wska�nik do napisu) oraz operator [], kt�ry pobiera element napisu.

   !!! UWAGA !!!
   * Zewn�trzne funkcje operatorowe prosz� zdefiniowa� jako funkcje niezaprzyja�nione
     jedynie cout mo�na zaprzyja�ni�.
   * Zadanie wykonujemy na tablicy znak�w, nie wolno korzysta� z std::string.
   * Przy wykonaniu tego zadania *** NIE WOLNO *** korzysta� z kod�w wcze�niejszych zada�.
   * Pliku main.cpp, NIE WOLNO modyfikowa� bez zgody prowadz�cego. \
     Zaliczone zadanie powinno si� kompilowa� bez �adnych zakomentowanych linii.
   * Kody �r�d�owe powinny znajdowa� si� w katalogu nazwisko_poprawa.
     Wcze�niej kasujemy niepotrzebne pliki.

 * Prosz� pamieta� o dokumentacji kodu.
 * Skonfiguruj plik konfiguracyjny cmake albo napisz Makefile tak, aby:
   - plikiem wynikowym by� main
   - program kompilowa� si� z flagami -Wall -g - pedantic.
   - by�y zdefiniowane cele u�ytkownika run, clean, check oraz all (main+run)

 * Podczas wykonywania zadania nie wolno korzysta� z internetu, notatek,
 * ani �adnych innych materia��w, w tym r�wnie� swoich zada�.

*/

#include "myString.h"
#include <iostream>

using namespace std;

int main() {
	MyString s0("Powodzenia na Kolokwium");
	MyString s1("Powodzenia na kolokwium");
	const MyString s2(s1);

	s0.print(); s1.print(); s2.print();
	cout << "\n*** Porownywanie napisow ***" << endl;
	cout << "Napisy s0 i s1 " << (s0 == s1 ? "sa identyczne" :"nie sa identyczne")<<endl;
	cout << "Napisy s1 i s2 " << (s1 == s2 ? "sa identyczne" :"nie sa identyczne") <<endl;
	cout << "Napisy s0 i s1 " << (s2 == s1 ? "sa identyczne" :"nie sa identyczne") <<endl;
	cout << "Napisy s2 i \"Powodzenia na kolokwium\" " << (s2 == "Powodzenia na kolokwium" ? "sa identyczne" :"nie sa identyczne") <<endl;

	cout << "\n*** Dodawanie i przypisywanie napisow ***" << endl;
	cout << s1 << endl; //s1.print();
	s1 = "Samych sukcesow!!!";
	cout << s1 << endl;
	MyString s3 = s2 + " tu i teraz...";
	cout << s3 << endl; //s3.print();
	MyString s4 = s2 + ": " + s1 + " - " + s2 + '!'; // uwaga na typ char
	cout << s4 << endl; //s4.print();

	cout << "\n*** Powielanie napisow ***" << endl;
	MyString s5 = 2 * MyString(":-)");
	MyString s6 = ":-D " + (const MyString&)s5*4;
	s6.print();

	s6 = s1;
	cout << s6 << endl;
	cout << "Siodmy znak: " << s6[7] << endl;

   //Zadanie dodatkowe (do odkomentowania po zrobieniu)
	s6[7] = 'S';
	cout << s6 << endl;
}

/* Oczekiwany wynik ./main
Powodzenia na Kolokwium
Powodzenia na kolokwium
Powodzenia na kolokwium

*** Porownywanie napisow ***
Napisy s0 i s1 nie sa identyczne
Napisy s1 i s2 sa identyczne
Napisy s0 i s1 sa identyczne
Napisy s2 i "Powodzenia na kolokwium" sa identyczne

*** Dodawanie i przypisywanie napisow ***
Powodzenia na kolokwium
Samych sukcesow!!!
Powodzenia na kolokwium tu i teraz...
Powodzenia na kolokwium. Samych sukcesow!!! - Powodzenia na kolokwium!

*** Powielanie napisow ***
:-D :-):-):-):-):-):-):-):-)
Samych sukcesow!!!
*/
