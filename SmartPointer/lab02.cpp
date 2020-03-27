//============================================================================
// Name        : lab02.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/* Proszê dopisaæ kod, dodaæ nowe pliki, tak aby program siê wykonywa³
   a wynik jego dzia³ania by³ taki sam, jak podany na koñcu tego pliku.

   Celem zadania jest napisanie klasy sprytnego wskaŸnika,
   w którym liczona jest iloœæ referencji do tego wskaŸnika.
   Podczas konstruowania takiego sprytnego wskaŸnika przekazujemy do niego
   wskaŸnik do obiektu stworzonego operatorem new i startujemy licznik.
   Ka¿dy nastêpny sprytny wskaŸnik pokazuj¹cy na ten obiekt (stworzony
   z innego sprytnego wskaŸnika) zwiêksza ten licznik, a ka¿de zniszczenie
   sprytnego wskaŸnika (np przez wyjœcie poza zakres) zmniejsza licznik.
   Gdy licznik dochodzi do zera, nale¿y zwolniæ pamiêæ.

   Kluczow¹ spraw¹ jest zapewnienie wspó³dzielenia licznika pomiêdzy ró¿nymi
   instancjami klasy sprytnego licznika (static nie jest rozwi¹zaniem).

   Sprytny wskaŸnik ma obs³ugiwaæ trywialn¹ klasê TestClass,
   która posiada jedynie konstruktory i destruktory
   wypisuj¹ce informacje o swoim wywo³aniu (patrz oczekiwany wynik)
   oraz metodê nazwa().

 * Mo¿na korzystaæ z biblioteki standardowej std::string.
   Zamiana liczby na std::string: std::to_string(int).

* Proszê pamiêtaæ o dokumentacji kodu.
 * Napisz Makefile albo skonfiguruj plik konfiguracyjny cmake tak, aby:
   - plikiem wynikowym by³ main
   - program kompilowa³ siê z flagami -Wall - pedantic.
   - by³y zdefiniowane cele u¿ytkownika run, clean, check oraz all (main+run)

 * Kody Ÿród³owe powinny znajdowaæ siê w katalogu nazwisko_lab2
 * do którego nikt oprócz w³aœciciela nie ma praw dostêpu.
 * UWAGA! Wysy³amy spakowany katalog, nie oddzielne pliki!!!!!!
 * Wczeœniej KASUJEMY niepotrzebne pliki.

 * Podczas wykonywania zadania nie wolno korzystaæ z internetu, notatek,
 * ani ¿adnych innych materia³ów.
 */

#include <iostream>

#include "SmartPointer.h"
#include "TestClass.h"
using namespace std;

void print(const TestClass& t) {
    cout <<"..... TestClass nazwa: " << t.name() << endl;
}

int main() {

  {
    TestClass a("test_A0");
    print(a);
  }
  cout << endl;
  SmartPointer smart1(new TestClass("test_A1"));
  SmartPointer smart2(new TestClass("test_A2"));
  smart2 = smart1; // kasujemy  A2 bo zaden wskaznik na niego nie wskazuje
  {
    SmartPointer smart3 = smart2; // juz trzy wskazniki pokazuja na obiekt A1
    print(*smart3);
    std::cout << "-- " << smart3->name() << std::endl;
  }
  std::cout << "== " << smart2->name() << std::endl;
}
/* oczekiwany wynik
.. Konstruuje TestClass test_A0
..... TestClass nazwa: test_A0
.. Usuwam  TestClass test_A0

.. Konstruuje TestClass test_A1
.. Konstruuje TestClass test_A2
.. Usuwam  TestClassA test_A2
..... TestClass nazwa: test_A1
-- test_A1
== test_A1
.. Usuwam  TestClassA test_A1

 */
