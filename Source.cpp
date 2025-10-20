#include <iostream>
#include <stdexcept>
using namespace std;
/*
int* fibonacci(int n) {
	if (n <= 0) return nullptr;
	int* niz = new int[n];

	if (n >= 1) niz[0] = 0;
	if (n >= 2) niz[1] = 1;


	for (int i = 2; i < n; i++) {
		niz[i] = niz[i - 1] + niz[i - 2];
	}

	return niz;
}


int main() {
	int n;

	cout << "unesi br";
	cin >> n;

	int* fib = fibonacci(n);

	if (fib != nullptr) {
		cout << "fibniz je";

		for (int i = 0; i < n; i++) {
			cout << fib[i] << " ";
		}
		cout << endl;

		delete[] fib;
	}
	else {
		cout << "Nije mogue generirati niz za unesenu vrijednost." << endl;
	}
	return 0;
}

//3
struct Vector {
	int* data;
	int size;
	int capacity;

};

Vector vector_new(int init_capacity) {

	Vector v;
	v.data = new int[init_capacity];
	v.size = 0;
	v.capacity = init_capacity;
	return v;
}
void vector_delete(Vector& v) {
	delete[] v.data;
	v.data = nullptr;
	v.size = 0;
	v.capacity = 0;
}
void vector_push_back(Vector& v, int value) {
	if (v.size == v.capacity) {
		int new_capacity = v.capacity * 2;
		int* new_data = new int[new_capacity];

		for (int i = 0; i < v.size; i++) {
			new_data[i] = v.data[i];
		}

		delete[] v.data;
		v.data = new_data;
		v.capacity = new_capacity;
	}

	v.data[v.size] = value;
	v.size++;
}
void vector_pop_back(Vector& v) {
	if (v.size > 0) {
		v.size--;
	}
}
int vector_front(const Vector& v) {
	if (v.size > 0)
		return v.data[0];
	else
		throw std::out_of_range("Vector is empty");
}
int vector_back(const Vector& v) {
	if (v.size > 0)
		return v.data[v.size - 1];
	else
		throw std::out_of_range("Vector is empty");
}
int vector_size(const Vector& v) {
	return v.size;
}
int main() {
	Vector v = vector_new(2);

	vector_push_back(v, 10);
	vector_push_back(v, 20);
	vector_push_back(v, 30);

	std::cout << "Prvi element: " << vector_front(v) << std::endl;
	std::cout << "Zadnji element: " << vector_back(v) << std::endl;
	std::cout << "Veličina: " << vector_size(v) << std::endl;

	vector_pop_back(v);
	std::cout << "Veličina nakon pop_back: " << vector_size(v) << std::endl;

	vector_delete(v);

	return 0;

}
*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

double** alociraj_matricu(int m, int n) {
	double** mat = new double*[m];
	for (int i = 0; i < m; i++) {
		mat[i] = new double[n];
	}
	return mat;
}

void dealociraj_matricu(double** mat, int m) {
	for (int i = 0; i < m; i++) {
		delete[] mat[i];
	}
	delete[] mat;
}

void unos_matrice(double** mat, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
}

void generiraj_matricu(double** mat, int m, int n, double a, double b) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			double r = a + static_cast<double>(rand()) / RAND_MAX * (b - a);
			mat[i][j] = r;
		}
	}
}

void ispisi_matricu(double** mat, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(10) << fixed << setprecision(4) << mat[i][j];
		}
		cout << endl;
	}
}

double** zbroji_matrice(double** A, double** B, int m, int n) {
	double** C = alociraj_matricu(m, n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			C[i][j] = A[i][j] + B[i][j];
	return C;
}

double** oduzmi_matrice(double** A, double** B, int m, int n) {
	double** C = alociraj_matricu(m, n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			C[i][j] = A[i][j] - B[i][j];
	return C;
}

double** mnozi_matrice(double** A, int m1, int n1, double** B, int m2, int n2) {
	if (n1 != m2) return nullptr;
	double** C = alociraj_matricu(m1, n2);
	for (int i = 0; i < m1; i++) {
		for (int j = 0; j < n2; j++) {
			C[i][j] = 0;
			for (int k = 0; k < n1; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	return C;
}

double** transponiraj_matricu(double** A, int m, int n) {
	double** T = alociraj_matricu(n, m);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			T[j][i] = A[i][j];
	return T;
}

int main() {
	srand(time(0));
	int m = 2, n = 3;
	double** A = alociraj_matricu(m, n);
	double** B = alociraj_matricu(m, n);

	unos_matrice(A, m, n);
	generiraj_matricu(B, m, n, 1.0, 10.0);

	cout << "\nMatrica A:\n";
	ispisi_matricu(A, m, n);

	cout << "\nMatrica B (generirana):\n";
	ispisi_matricu(B, m, n);

	double** C = zbroji_matrice(A, B, m, n);
	cout << "\nZbroj A + B:\n";
	ispisi_matricu(C, m, n);

	double** D = oduzmi_matrice(A, B, m, n);
	cout << "\nRazl
