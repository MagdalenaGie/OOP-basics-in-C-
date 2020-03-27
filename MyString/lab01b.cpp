//============================================================================
// Name        : lab01b.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/* Proszê dopisaæ kod, dodaæ nowe pliki, tak aby program siê wykonywa³
   a wynik jego dzia³ania by³ taki sam, jak podany na koñcu tego pliku.

   Proszê zdefiniowaæ klasê MyString, która odpowiada klasie std::string.
   Nale¿y zdefiniowaæ wszystkie potrzebne kondtruktory alokuj¹ce pamiêæ
   oraz destruktor j¹ zwalniaj¹cy.
   Nale¿y przeci¹¿yæ podstawowe operatory do obs³ugi ³ancucha znaków:
   ==, =, +, *, << w ró¿nych konfiguracjach parametrycznych.
   Dodatkowo nale¿y te¿ zdefiniowaæ funkcjê print (dodaje na koñcu "\n"),
   str (zwraca wskaŸnik do napisu) oraz operator [], który pobiera element napisu.

   !!! UWAGA !!!
   * Zewnêtrzne funkcje operatorowe proszê zdefiniowaæ jako funkcje niezaprzyjaŸnione
     jedynie cout mo¿na zaprzyjaŸniæ.
   * Zadanie wykonujemy na tablicy znaków, nie wolno korzystaæ z std::string.
   * Przy wykonaniu tego zadania *** NIE WOLNO *** korzystaæ z kodów wczeœniejszych zadañ.
   * Pliku main.cpp, NIE WOLNO modyfikowaæ bez zgody prowadz¹cego. \
     Zaliczone zadanie powinno siê kompilowaæ bez ¿adnych zakomentowanych linii.
   * Kody Ÿród³owe powinny znajdowaæ siê w katalogu nazwisko_poprawa.
     Wczeœniej kasujemy niepotrzebne pliki.

 * Proszê pamietaæ o dokumentacji kodu.
 * Skonfiguruj plik konfiguracyjny cmake albo napisz Makefile tak, aby:
   - plikiem wynikowym by³ main
   - program kompilowa³ siê z flagami -Wall -g - pedantic.
   - by³y zdefiniowane cele u¿ytkownika run, clean, check oraz all (main+run)

 * Podczas wykonywania zadania nie wolno korzystaæ z internetu, notatek,
 * ani ¿adnych innych materia³ów, w tym równie¿ swoich zadañ.

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
