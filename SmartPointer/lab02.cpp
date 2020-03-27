//============================================================================
// Name        : lab02.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/* Prosz� dopisa� kod, doda� nowe pliki, tak aby program si� wykonywa�
   a wynik jego dzia�ania by� taki sam, jak podany na ko�cu tego pliku.

   Celem zadania jest napisanie klasy sprytnego wska�nika,
   w kt�rym liczona jest ilo�� referencji do tego wska�nika.
   Podczas konstruowania takiego sprytnego wska�nika przekazujemy do niego
   wska�nik do obiektu stworzonego operatorem new i startujemy licznik.
   Ka�dy nast�pny sprytny wska�nik pokazuj�cy na ten obiekt (stworzony
   z innego sprytnego wska�nika) zwi�ksza ten licznik, a ka�de zniszczenie
   sprytnego wska�nika (np przez wyj�cie poza zakres) zmniejsza licznik.
   Gdy licznik dochodzi do zera, nale�y zwolni� pami��.

   Kluczow� spraw� jest zapewnienie wsp�dzielenia licznika pomi�dzy r�nymi
   instancjami klasy sprytnego licznika (static nie jest rozwi�zaniem).

   Sprytny wska�nik ma obs�ugiwa� trywialn� klas� TestClass,
   kt�ra posiada jedynie konstruktory i destruktory
   wypisuj�ce informacje o swoim wywo�aniu (patrz oczekiwany wynik)
   oraz metod� nazwa().

 * Mo�na korzysta� z biblioteki standardowej std::string.
   Zamiana liczby na std::string: std::to_string(int).

* Prosz� pami�ta� o dokumentacji kodu.
 * Napisz Makefile albo skonfiguruj plik konfiguracyjny cmake tak, aby:
   - plikiem wynikowym by� main
   - program kompilowa� si� z flagami -Wall - pedantic.
   - by�y zdefiniowane cele u�ytkownika run, clean, check oraz all (main+run)

 * Kody �r�d�owe powinny znajdowa� si� w katalogu nazwisko_lab2
 * do kt�rego nikt opr�cz w�a�ciciela nie ma praw dost�pu.
 * UWAGA! Wysy�amy spakowany katalog, nie oddzielne pliki!!!!!!
 * Wcze�niej KASUJEMY niepotrzebne pliki.

 * Podczas wykonywania zadania nie wolno korzysta� z internetu, notatek,
 * ani �adnych innych materia��w.
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
