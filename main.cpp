#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include <string>

/*

Create a movies structure that has
the following set of fields:
 string title – the name of the movie;
 int year – the year of the film 's release;
 string genre – movie genre;
 unsigned int duration – the duration
of the movie in minutes;
 unsigned int price – price per movie disc

Создайте структуру movies, которая обладает
следующим набором полей:
 string title – название фильма;
 int year – год выхода фильма;
 string genre – жанр фильма;
 unsigned int duration – продолжительность
фильма в минутах;
 unsigned int price – цена за диск фильма
*/

struct movies {
	std::string title;
	int year;
	std::string genre;
	unsigned int duration;
	unsigned int price;
};

void show_movie(const movies& film);

movies expensive(const movies& film1, const movies& film2, const movies& film3);

void update_info(movies& film);

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);

	std::cout << "Exercise 1.\n";
	/*
		Create a show_movie function that accepts
	a structure object and outputs all information about it
	(i.e., the values of the object fields are output).

		Создайте функцию show_movie, которая принимает
	объект структуры и выводит всю информацию о нём
	(т. е. выводятся значения полей объекта).
	*/
	movies Rembo1{
		"Rembo: First blood.",
		1982,
		"action, thriller, adventure",
		93,
		299
	};

	movies Boondock_Saints{
		"Boondock saints.",
		1999,
		"action, crime, drama",
		108,
		280
	};

	movies Thursday{
		"Thursday.",
		1998,
		"thriller, crime",
		87,
		275
	};

	show_movie(Rembo1);
	std::cout << "--------------------------------------------------\n";
	show_movie(Boondock_Saints);
	std::cout << "--------------------------------------------------\n";
	show_movie(Thursday);
	std::cout << "--------------------------------------------------\n";

	std::cout << "\n\n\nExercise 2.\n";
	/*
		Create an expensive function that accepts 
	three structure objects and returns the object with the
	highest price per disk. To solve this problem
	, it is necessary to use
	the movies data type for the return value when creating 
	the function.

		Создайте функцию expensive, которая принимает
	три объекта структуры и возвращает объект с самой
	высокой ценой за диск. Для решения данной задачи
	необходимо при создании функции использовать тип
	данных movies для возвращаемого значения.
	*/
	show_movie(expensive(Thursday, Rembo1, Boondock_Saints));

	/*
		Create an update_info function that accepts
	a structure object and allows you to change some
	information about this object. To solve this
	problem, it is necessary to
	use a pointer or a reference to an object as a 
	function parameter.
	
		Создайте функцию update_info, которая принимает 
	объект структуры и позволяет поменять какую-нибудь
	информацию об этом объекте. Для решения данной 
	задачи необходимо в качестве параметра функции 
	использовать указатель или ссылку на объект.
	*/
	std::cout << "\n\n\nExercixe 3.\n";
	update_info(Rembo1);
	show_movie(Rembo1);

	return 0;
}

void show_movie(const movies& film) {
	std::cout << "The name of the movie: " << "\x1b[32m" << film.title << "\x1b[0m" << std::endl;
	std::cout << "The year of the film 's release: " << "\x1b[32m" << film.year << "\x1b[0m" << std::endl;
	std::cout << "The genre of the film: " << "\x1b[32m" << film.genre << "\x1b[0m" << std::endl;
	std::cout << "The duration of the film: " << "\x1b[32m" << film.duration << "\x1b[0m" << std::endl;
	std::cout << "Price per movie disc: " << "\x1b[32m" << film.price << "\x1b[0m" << std::endl;
}

movies expensive(const movies& film1, const movies& film2, const movies& film3) {
	if (film1.price > film2.price) {
		if (film1.price > film3.price) {
			return film1;
		}
		else {
			return film3;
		}
	}
	else if (film2.price > film3.price) {
		return film2;
	}
	else {
		return film3;
	}
}

void update_info(movies& film) {
	unsigned int n = 0;
	unsigned int num = 0;
	std::string str;
	do {
		std::cout << "\x1b[36mChoose which movie information\nyou want to update:\n\
1. Name;\n\
2. Year of release;\n\
3. Genre;\n\
4. Duration;\n\
5. Price per disk.\n\
Enter number: \x1b[0m";
		std::cin >> n;
		if (n < 1 || n > 5)
			std::cout << "\x1b[31mInput error.\x1b[0m\n";
	} while (n < 1 || n > 5);
	switch (n) {
	case 1:
		std::cout << "Enter a new movie title: ";
		std::cin.ignore();
		std::getline(std::cin, film.title);
		break;
	case 2:
		std::cout << "Enter a new year of release: ";
		std::cin >> film.year;
		break;
	case 3:
		std::cout << "Enter a new movie genre: ";
		std::cin.ignore();
		std::getline(std::cin, film.genre);
		break;
	case 4:
		std::cout << "Enter a new movie duration: ";
		std::cin >> film.duration;
		break;
	case 5:
		std::cout << "Enter a new price per disk: ";
		std::cin >> film.price;
		break;
	}
	std::cout << "\x1b[32mInformation updated.\x1b[0m\n";
}