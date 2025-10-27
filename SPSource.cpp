#include <iostream>
#include <cstddef>


#include <iostream>
#include <cstddef>  // za std::size_t

// Inline funkcije za usporedbu
inline bool ascending(int a, int b) {
	return a < b;
}

inline bool descending(int a, int b) {
	return a > b;
}

// Funkcija za sortiranje (bubble sort)
void sortt(int arr[], std::size_t size, bool(*cmp)(int, int)) {
	for (std::size_t i = 0; i < size - 1; ++i) {
		for (std::size_t j = 0; j < size - i - 1; ++j) {
			if (!cmp(arr[j], arr[j + 1])) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main() {
	int arr[] = { 5, 2, 9, 1, 7 };
	std::size_t size = sizeof(arr) / sizeof(arr[0]);

	std::cout << "Originalni niz: ";
	for (int x : arr) std::cout << x << " ";
	std::cout << "\n";

	// Uzlazno sortiranje
	sortt(arr, size, ascending);
	std::cout << "Uzlazno sortirano: ";
	for (int x : arr) std::cout << x << " ";
	std::cout << "\n";

	// Silazno sortiranje
	sortt(arr, size, descending);
	std::cout << "Silazno sortirano: ";
	for (int x : arr) std::cout << x << " ";
	std::cout << "\n";

	return 0;
}




template <typename T>
inline bool ascending(T a, T b) {
	return a < b;
}

template <typename T>
inline bool descending(T a, T b) {
	return a > b;
}

template <typename T>
void sortt(T arr[], std::size_t size, bool(*cmp)(T, T)) {
	for (std::size_t i = 0; i < size - 1; ++i) {
		for (std::size_t j = 0; j < size - i - 1; ++j) {
			if (!cmp(arr[j], arr[j + 1])) {
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main() {
	int arr1[] = { 5, 2, 9, 1, 7 };
	std::size_t size1 = sizeof(arr1) / sizeof(arr1[0]);

	std::cout << "Originalni INT niz: ";
	for (int x : arr1) std::cout << x << " ";
	std::cout << "\n";

	sortt(arr1, size1, ascending<int>);
	std::cout << "Uzlazno (INT): ";
	for (int x : arr1) std::cout << x << " ";
	std::cout << "\n";

	sortt(arr1, size1, descending<int>);
	std::cout << "Silazno (INT): ";
	for (int x : arr1) std::cout << x << " ";
	std::cout << "\n\n";

	// DOUBLE niz
	double arr2[] = { 3.5, 1.2, 9.8, 2.4 };
	std::size_t size2 = sizeof(arr2) / sizeof(arr2[0]);

	std::cout << "Originalni DOUBLE niz: ";
	for (double x : arr2) std::cout << x << " ";
	std::cout << "\n";

	sortt(arr2, size2, ascending<double>);
	std::cout << "Uzlazno (DOUBLE): ";
	for (double x : arr2) std::cout << x << " ";
	std::cout << "\n";

	sortt(arr2, size2, descending<double>);
	std::cout << "Silazno (DOUBLE): ";
	for (double x : arr2) std::cout << x << " ";
	std::cout << "\n";

	return 0;
}
#include <iostream>
#include <string>
#include <cstddef> // za std::size_t

// Definicija strukture Student
struct Student {
	std::string ime;
	std::string jmbag;
	int godina;
	int ects;
	double prosjek;
};

// Funkcija za filtriranje
void filter_students(
	Student arr[],
	std::size_t size,
	void(*akcija)(Student&),
	bool(*filter)(Student&)
) {
	for (std::size_t i = 0; i < size; ++i) {
		if (filter(arr[i])) {
			akcija(arr[i]);
		}
	}
}

// ------------------- FUNKCIJE ZA AKCIJE -------------------

void ispisi_studenta(Student& s) {
	std::cout << "Ime: " << s.ime
		<< ", JMBAG: " << s.jmbag
		<< ", Godina: " << s.godina
		<< ", ECTS: " << s.ects
		<< ", Prosjek: " << s.prosjek << '\n';
}

void povecaj_godinu(Student& s) {
	s.godina++;
}

// ------------------- MAIN -------------------

int main() {
	Student studenti[] = {
		{"Ana", "001", 1, 30, 3.2},
		{"Marko", "002", 1, 0, 2.8},
		{"Iva", "003", 2, 48, 3.9},
		{"Petar", "004", 3, 60, 4.2},
		{"Luka", "005", 1, 10, 3.7}
	};

	std::size_t size = sizeof(studenti) / sizeof(studenti[0]);

	std::cout << "1️⃣ Studenti PRVE godine koji su polozili barem jedan ispit:\n";
	filter_students(
		studenti, size,
		ispisi_studenta,
		[](Student& s) { return s.godina == 1 && s.ects > 0; }  // lambda uvjet
	);

	std::cout << "\n2️⃣ Studenti s prosjekom > 3.5:\n";
	filter_students(
		studenti, size,
		ispisi_studenta,
		[](Student& s) { return s.prosjek > 3.5; }  // lambda uvjet
	);

	std::cout << "\n3️⃣ Povecanje godine studenata s barem 45 ECTS bodova:\n";
	filter_students(
		studenti, size,
		povecaj_godinu,
		[](Student& s) { return s.ects >= 45; }  // lambda uvjet
	);

	std::cout << "\n➡️ Nakon povecanja godine:\n";
	for (auto& s : studenti) ispisi_studenta(s);

	return 0;
}
