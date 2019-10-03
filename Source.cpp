#include <iostream>;
#include <cmath>;
#include <fstream>;
using namespace std;
int main() {
#define M_PI 3.14159265358979323846;
	setlocale(LC_ALL, "rus");
	string menu;
	while (true) {
		cout << "Введите номер задания для запука соответствующей программы или число 1227 для выхода\n";
		cin >> menu;
		if (atoi(menu.c_str()) == 1227) {
			break;
		}
		switch (atoi(menu.c_str()))
		{
		case 1:
		{
			cout << "Рассчитывается месячная выплата m по займу в S рублей на n лет под процент p\nS=";
			float S, n, p, m;
			cin >> S;
			cout << "n=";
			cin >> n;
			cout << "p=";
			cin >> p;
			float r = p / 100;
			m = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
			if (n == 0 || (p == 0)) { if (n == 0) { m = S; } else { m = S / (n * 12); } }
			cout << "m=" << m;
			cout << "\n----------------------Работа программы-задания завершена----------------------\n\n";
			break;
		}
		case 2: {
			cout << "Вычисляется процент p, под который выдана ссуда в S рублей на срок n лет с ежемесячной выплатой m рублей\nS=";
			float S, n, p, m, mi, r;
			cin >> S;
			cout << "n=";
			cin >> n;
			cout << "m=";
			cin >> m;
			mi = 0;
			for (float i = 0.1; mi - m < 0; i += 0.1) {
				r = i / 100;
				mi = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
				if (n == 0) { m = S; }
				p = i;
			}
			cout << "p=" << p-0.1;
			cout << "\n----------------------Работа программы-задания завершена----------------------\n\n";
			break;
		}
		case 3: {
			cout << "Выводим текст файла:\n";
			char ch;
			ifstream file;
			file.open("C:\\Users\\Admin\\Desktop\\file.txt");
			cout << "<<\n";
			while (file.get(ch)) {
				cout << ch;
			}
			cout << "\n>>";
			file.close();
			cout << "\n----------------------Работа программы-задания завершена----------------------\n\n";
			break;
		}
		case 4: {
			cout << "Выводим цифры из файла:\n";
			char ch;
			ifstream file;
			file.open("C:\\Users\\Admin\\Desktop\\file.txt");
			cout << "<<\n";
			while (file.get(ch)) {
				if (ch >= '0' && ch <= '9') {
					cout << ch;
				}
			}
			cout << "\n>>";
			file.close();
			cout << "\n----------------------Работа программы-задания завершена----------------------\n\n";
			break;
		}
		case 5: {
			cout << "Сздаём рандомную строку из 30-и букв русского алфавита и сортируем её\n";
			string str1 = "абвгдежзиклмнопрстуфхцчшщъыьэюя\n";
			string str = "";
			int q, nn = 31;
			for (int i = 0; i < 30; i++) {
				q = rand() % nn;
				str += str1[q]; str1.erase(q, 1);
				nn -= 1;
			}
			cout << "Исходная строка\t" << str << "\n";

			for (int i = 1; i < (int)(str.length()); i++) {
				for (int j = i; (j > 0) && (str[j - 1] > str[j]); j--) {
					int k = str[j - 1];
					str[j - 1] = str[j];
					str[j] = k;
				}
			}
			cout << str;
			cout << "\n----------------------Работа программы-задания завершена----------------------\n\n";
			break;
		}
		default: {
			cout << "Команда не распознана\n";
			break;
		}
		}
	}
	cout << "\n\n\n----------------------Работа корневой программы завершена----------------------";
	return 0;
}