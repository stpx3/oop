#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<int> generate(int n) {
	vector<int> v(n);
	v[0] = 1 + rand() % 5;
	for (int i = 1; i < n; i++) {
		v[i] = v[i - 1] + 1 + rand() % 5;
	}
	return v;
}

int presjek(const vector<int>& A, const vector<int>& B) {
	int count = 0;
	for (int a : A) {
		for (int b : B) {
			if (a == b) {
				count++;
				break;
			}
		}
	}
	return count;
}

int presjek_jedan_sortiran(const vector<int>& A, const vector<int>& B) {
	int count = 0;
	for (int a : A) {
		if (binary_search(B.begin(), B.end(), a)) count++;
	}
	return count;
}

int presjek_oba_sortirana(const vector<int>& A, const vector<int>& B) {
	int i = 0, j = 0, count = 0;
	while (i < A.size() && j < B.size()) {
		if (A[i] == B[j]) {
			count++;
			i++;
			j++;
		}
		else if (A[i] < B[j]) {
			i++;
		}
		else {
			j++;
		}
	}
	return count;
}

int presjek_po_indeksima(const vector<int>& A, const vector<int>& B) {
	int maxA = *max_element(A.begin(), A.end());
	int maxB = *max_element(B.begin(), B.end());
	int size = max(maxA, maxB) + 1;
	vector<int> indexA(size, 0), indexB(size, 0);
	for (int a : A) indexA[a] = 1;
	for (int b : B) indexB[b] = 1;
	int count = 0;
	for (int i = 0; i < size; i++) if (indexA[i] && indexB[i]) count++;
	return count;
}

int main() {
	srand(time(NULL));
	int nA = 10, nB = 12;
	vector<int> A = generate(nA);
	vector<int> B = generate(nB);

	cout << "Skup A: ";
	for (int a : A) cout << a << " ";
	cout << endl;

	cout << "Skup B: ";
	for (int b : B) cout << b << " ";
	cout << endl;

	cout << "Presjek (običan): " << presjek(A, B) << endl;

	vector<int> B_sorted = B;
	sort(B_sorted.begin(), B_sorted.end());
	cout << "Presjek (jedan sortiran): " << presjek_jedan_sortiran(A, B_sorted) << endl;

	vector<int> A_sorted = A;
	sort(A_sorted.begin(), A_sorted.end());
	sort(B_sorted.begin(), B_sorted.end());
	cout << "Presjek (oba sortirana): " << presjek_oba_sortirana(A_sorted, B_sorted) << endl;

	cout << "Presjek (po indeksima): " << presjek_po_indeksima(A, B) << endl;

	return 0;
}
