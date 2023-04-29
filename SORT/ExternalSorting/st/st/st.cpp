#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void Distribution(string path1, string path2, string main_path) {
	ofstream f1, f2;
	ifstream mainf;
	string temp, cur;
	int itemp, icur;
	f1.open(path1);
	f2.open(path2);
	mainf.open(main_path);
	if (!f1.is_open() || !f2.is_open()) { cout << "Error" << endl; }
	else {
		bool firstfile = true;
		mainf >> cur;
		while (!mainf.eof()) {
			if (firstfile) {
				f1 << cur << "\n";
				temp = cur;
				mainf >> cur;
				if (mainf.eof()) {
					f1 << "/" << "\n";
					return;
				}
				itemp = stoi(temp);
				icur = stoi(cur);
				while (itemp <= icur) {
					if (mainf.eof()) {
						f1 << "/" << "\n";
						return;

					}
					f1 << cur << "\n";
					temp = cur;
					mainf >> cur;
					itemp = stoi(temp);
					icur = stoi(cur);
				}

				f1 << "/" << "\n";
				firstfile = false;
			}
			else {
				f2 << cur << "\n";
				temp = cur;
				mainf >> cur;
				if (mainf.eof()) {
					f2 << "/" << "\n";
					return;
				}

				itemp = stoi(temp);
				icur = stoi(cur);
				while (itemp <= icur) {
					if (mainf.eof()) {
						f2 << "/" << "\n";
						return;
					}
					f2 << cur << "\n";
					temp = cur;
					mainf >> cur;
					itemp = stoi(temp);
					icur = stoi(cur);
				}
				f2 << "/" << "\n";
				firstfile = true;
			}
		}
	}
	f1.close();
	f2.close();
	mainf.close();
}

void Merge(string path1, string path2, string main_path) {
	Distribution(path1, path2, main_path);
	ifstream f1, f2;
	ofstream mainf;
	string templ, temp2;
	int itempl, itemp2;
	f1.open(path1);
	f2.open(path2);
	mainf.open(main_path);
	if (!f1.is_open() || !f2.is_open()) { cout << "Error" << endl; }
	else {
		int i, j = 0;
		while (!(f1.eof())) {
			f1 >> templ;
			f2 >> temp2;
			if (temp2 == "") return;
			while (templ != "/" || temp2 != "/") {
				if (templ == "/") {
					mainf << temp2 << "\n";
					f2 >> temp2;
				}

				else if (temp2 == "/") {
					mainf << templ << "\n";
					f1 >> templ;
				}
				else {
					itempl = stoi(templ);
					itemp2 = stoi(temp2);
					if (itempl <= itemp2) {
						mainf << templ << "\n";
						f1 >> templ;
					}

					else {
						mainf << temp2 << "\n";
						f2 >> temp2;
					}
				}
			}
		}
	}
	f1.close();
	f2.close();
	mainf.close();
	Merge(path1, path2, main_path);
}

int main() {

	srand(time(NULL));
	int size, current;
	string result = "RESULT.txt", buff = "buffer.txt", datafile = "data.txt", temp;
	ofstream data;
	ifstream res;
	cout << "Size of an array: ";
	cin >> size;
	cout << "unsorted data" << endl;
	//заполнение файла с данными случайными значениями
	data.open(datafile);
	for (int i = 0; i < size; i++) {
		current = rand() % 100;
		cout << current << " ";
		data << current << "\n";
	}

	data.close();
	cout << endl << endl;
	Merge(result, buff, datafile); //вызов ункчии сортировки
	cout << "sorted data" << endl;
	//вывод в консоль данных в результирующем файле
	res.open(result);
	for (int i = 0; i < size; i++) {
		res >> temp;
		cout << temp << " ";
	}

	res.close();
	cout << endl;
	return 0;
}