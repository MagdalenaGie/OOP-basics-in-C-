//============================================================================
// Name        : janas03.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/* Celem zadania jest napisanie klasy, bêd¹cej przyk³adem sprytnego wskaŸnika.
 * Jest to klasa opakowuj¹ca wskaŸnik w sposób, w którym liczona jest iloœæ
 * referencji do tego wkaŸnika.
 *
 * Podczas konstruowania takiego sprytnego wskaŸnika przekazujemy do niego
 * wskaŸnik do obiektu stworzonego operatorem new i startujemy licznik.
 * Ka¿dy nastêpny sprytny wskaŸnik pokazuj¹cy na ten obiekt (stworzony z
 * innego sprytnego wskaŸnika) zwiêksza ten licznik, a ka¿de zniszczenie
 * sprytnego wskaŸnika (np przez wyjœcie poza zakres) zmniejsza licznik.
 * Gdy licznik dochodzi do zera, pamiêæ nale¿y zwolniæ.
 *
 * Kluczow¹ spraw¹ jest zapewnienie wspó³dzielenia licznika pomiêdzy ró¿nymi
 * instancjami klasy sprytnego licznika (static nie jest rozwi¹zaniem).
 *
 * Sprytny wskaŸnik ma obslugiwaæ banaln¹ klasê InfoClass, która nic nie
 * robi, tylko du¿o mówi (g³oœny konstruktor/destruktor, metoda info()).
 *
 * Mo¿na korzystaæ ze wszelkich dobrodziejstw biblioteki standardowej.
 * Zamiana liczby na std::string: std::to_string(int).
 */

#include "InfoSmartPtr.h"
#include "InfoClass.h"
#include <iostream>

void printInfo(const InfoClass& info)
{
	std::cout << "** printInfo: " << info.info() << std::endl;
}

int main()
{
	// -------------------------
	{
		InfoClass info("InfoAAA");
		printInfo(info);
	}
	std::cout << std::endl;
	// -------------------------
	{
		InfoSmartPtr info( new InfoClass("InfoBBB") );
		printInfo(*info);
	}
	std::cout << std::endl;

	// -------------------------
	InfoSmartPtr infoOne( new InfoClass("InfoCCC") );
	InfoSmartPtr infoTwo( new InfoClass("InfoDDD") );
	infoTwo = infoOne;                           // Kasowanie InfoDDD!!!
	std::cout << std::endl;

	// -------------------------
	infoTwo->info("InfoXXX");
	std::cout << "== " << infoOne->info() << std::endl;
	std::cout << "== " << infoTwo->info() << std::endl;
	std::cout << std::endl;

	// -------------------------
	{
		const InfoSmartPtr infoThree = infoTwo;
		printInfo(*infoThree);
		std::cout << "== " << infoThree->info() << std::endl;
	}
	std::cout << "== " << infoTwo->info() << std::endl;
	std::cout << std::endl;

	// -------------------------
	InfoSmartPtr infoFour( new InfoSuperClass("InfoSSS", 2019) );
	/*infoOne = infoFour;
	std::cout << "== " << infoOne->info() << std::endl;
	std::cout << "== " << infoTwo->info() << std::endl;
	std::cout << "== " << infoFour->info() << std::endl;*/
	std::cout << std::endl;

	return 0;
}

/* wynik dzia³ania programu:
++ Tworze obiekt InfoClass: info = InfoAAA
** printInfo: info = InfoAAA
++ Usuwam obiekt InfoClass: info = InfoAAA

++ Tworze obiekt InfoClass: info = InfoBBB
** printInfo: info = InfoBBB
++ Usuwam obiekt InfoClass: info = InfoBBB

++ Tworze obiekt InfoClass: info = InfoCCC
++ Tworze obiekt InfoClass: info = InfoDDD
++ Usuwam obiekt InfoClass: info = InfoDDD

== info = InfoXXX
== info = InfoXXX

** printInfo: info = InfoXXX
== info = InfoXXX
== info = InfoXXX

++ Tworze obiekt InfoClass: info = InfoSSS
== info = InfoSSS, num = 2019
== info = InfoXXX
== info = InfoSSS, num = 2019

++ Usuwam obiekt InfoClass: info = InfoXXX
++ Usuwam obiekt InfoClass: info = InfoSSS
*/
