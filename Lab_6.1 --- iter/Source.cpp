#include <iostream>
#include <iomanip>
using namespace std;

void draw_line(int size, const char& c = '-') {
	for (--size; size >= 0; size--)
		cout << c;
	cout << endl;
}

int myrand(const int& min, const int& max) {
	return min > 0 ?
		rand() % (max - min + 1) + min :
		rand() % (abs(min) + max + 1) + min;
}

void full_mass(int* mass, int size, const int* dia) {
	for (--size; size >= 0; size--)
		mass[size] = myrand(dia[0], dia[1]);
}

void draw_mass(const int* mass, const int& size, const int& c_space) {
	draw_line(size * c_space + 2);
	for (int i = 0; i < size; i++)
		cout << "|" << setw(c_space - 1) << mass[i];
	cout << " |" << endl;
	draw_line(size * c_space + 2);
}

void do_stuff(int* mass, int size, int& count, int& sum) {
	for (--size; size >= 0; size--)
		if (mass[size] > 0 && mass[size] % 2 != 0) {
			count++;
			sum += mass[size];
			mass[size] = 0;
		}
}

int main() {
	srand(time(NULL));
	const int size = 23, // розмір массиву
		c_space = 4, // кількість містя яке виділяєьбся на одну комірку массиву, при виводі в консоль
		dia[2] = { -25 , 80 }; // діапазон значень
	int mass[size], count = 0, sum = 0;

	full_mass(mass, size, dia);
	draw_mass(mass, size, c_space);
	do_stuff(mass, size, count, sum);
	cout << "count " << count << endl
		<< "sum " << sum << endl;
	draw_mass(mass, size, c_space);
}
