#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

enum Zog { KUPE, SPADE, DINARE, BATINE };

struct Karta {
	int broj;
	Zog zog;
};

class Mac {
public:
	vector<Karta> karte;
	int vrh;

	Mac() {
		for (int z = 0; z < 4; z++) {
			for (int b = 1; b <= 10; b++) {
				karte.push_back({ b, (Zog)z });
			}
		}
		vrh = 0;
	}

	void promijesaj() {
		srand(time(nullptr));
		random_shuffle(karte.begin(), karte.end());
	}

	Karta podijeli() {
		return karte[vrh++];
	}
};

class Igrac {
public:
	string ime;
	vector<Karta> ruka;
	int bodovi;

	Igrac(string i) : ime(i), bodovi(0) {}

	void dodajKartu(Karta k) {
		ruka.push_back(k);
	}

	string nazivZoga(Zog z) {
		switch (z) {
		case KUPE: return "Kupe";
		case SPADE: return "Spade";
		case DINARE: return "Dinare";
		case BATINE: return "Batine";
		default: return "?";
		}
	}

	void ispisiKarte() {
		cout << "Karte igraca " << ime << ":\n";
		for (auto &k : ruka)
			cout << "  " << k.broj << " " << nazivZoga(k.zog) << "\n";
	}

	int izracunajAkuzu() {
		int bodovi = 0;
		int brojacZog[4][11] = { 0 };

		for (auto &k : ruka)
			brojacZog[k.zog][k.broj]++;

		for (int z = 0; z < 4; z++)
			if (brojacZog[z][1] && brojacZog[z][2] && brojacZog[z][3])
				bodovi += 3;

		for (int b = 1; b <= 3; b++) {
			int ukupno = 0;
			for (int z = 0; z < 4; z++)
				if (brojacZog[z][b]) ukupno++;
			if (ukupno == 3) bodovi += 3;
			else if (ukupno == 4) bodovi += 4;
		}

		this->bodovi = bodovi;
		return bodovi;
	}
};

int main() {
	int brojIgraca;
	cout << "Unesite broj igraca (2 ili 4): ";
	cin >> brojIgraca;
	cin.ignore();

	if (brojIgraca != 2 && brojIgraca != 4) {
		cout << "Broj igraca mora biti 2 ili 4.\n";
		return 1;
	}

	vector<Igrac> igraci;
	for (int i = 0; i < brojIgraca; i++) {
		string ime;
		cout << "Unesite ime igraca " << i + 1 << ": ";
		getline(cin, ime);
		igraci.emplace_back(ime);
	}

	Mac mac;
	mac.promijesaj();

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < brojIgraca; j++)
			igraci[j].dodajKartu(mac.podijeli());

	cout << "\n--- PODJELA ---\n";
	for (auto &igrac : igraci) {
		igrac.ispisiKarte();
		cout << "Akuza: " << igrac.izracunajAkuzu() << " bodova\n\n";
	}

	cout << "--- REZULTATI ---\n";
	for (auto &igrac : igraci)
		cout << igrac.ime << ": " << igrac.bodovi << " bodova iz akuže\n";

	return 0;
}
