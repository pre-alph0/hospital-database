// ConsoleApplication10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <algorithm>

using namespace::std;
//////////////////////////////////////////////////////////////
struct hospital
{
	int specialty;
	int qualification;
	string fio;            
};
//////////////////////////////////////////////////////////////
void data_save(hospital* s , int quantity) {
	fstream f;
	f.open("data.txt", fstream::in | fstream::app);
	if (!f.is_open()) {
		cout << "Ошибка чтения файла!!!" << endl;
	}
	else
	{
		f << quantity<<endl;
		for (int i = 0; i < quantity; i++)
		{
			f << s[i].specialty << endl << s[i].qualification << endl << s[i].fio << endl;
		}
	}
	f.close();
};
//////////////////////////////////////////////////////////////
void data_find_s_q(int sp, int q, int quantity, hospital* s) {
	cout << "----------------------------------------------------------------------------" << endl;
	cout << "Специальность          " << "Квалификация          " << "Фамилия          " << endl;
	for (int i = 0; i < quantity; i++)
	{

		if (s[i].specialty == sp && s[i].qualification==q) {
			cout << "      " << s[i].specialty << "                     " << s[i].qualification << "                 " << s[i].fio << "\n";
		}
	}
	cout << "----------------------------------------------------------------------------" << endl;
};
//////////////////////////////////////////////////////////////
void data_find_surname(string surname, hospital* s, int n) {
	cout << "----------------------------------------------------------------------------" << endl;
	cout << "Специальность          " << "Квалификация          " << "Фамилия          " << endl;
    for (int i = 0; i < n; i++)
	{
		if (s[i].fio == surname) {
			cout <<"      "<< s[i].specialty << "                     " << s[i].qualification << "                 " << s[i].fio << "\n";
		}
	}
	cout << "----------------------------------------------------------------------------" << endl;
};
//////////////////////////////////////////////////////////////
void data_print(hospital* s, int n) {
	cout << "----------------------------------------------------------------------------" << endl;
	cout << "Специальность          " << "Квалификация          " << "Фамилия          " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "      " << s[i].specialty << "                     " << s[i].qualification << "                 " << s[i].fio << endl;
	}
	cout << "----------------------------------------------------------------------------" << endl;
};
//////////////////////////////////////////////////////////////
bool CompareAlphabet(hospital a, hospital b) //компаратор нужен для указания атрибута сравнения и смены направления сортировки
{
	return a.fio.compare(b.fio) < 0;
}
//////////////////////////////////////////////////////////////
int nomer_func;
void menu() {

	cout <<endl<<"Добавить новый элемент.............................1" << "\n"
		<< "Распечатать базу...................................2" << "\n"
		<< "Поиск врача по фио.................................3" << "\n"
		<< "Фильтр по квалификации и специальности.............4" << "\n"
		<< "Сортировать по алфавиту............................5" << "\n"
		<< "Выход..............................................6" << "\n"
		<< "Введите номер функции: ";
	cin >> nomer_func;
};
//////////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL, "Russian");

	SetConsoleCP(1251); //кодировка ввода
	SetConsoleOutputCP(1251); //кодировка вывода

	int quantity_data = 0;
	hospital* s = new hospital[100];

	ifstream reading("data.txt");
	if (reading)
	{
		int z;
		reading >> z;
		for (int i = 0; i < z; i++)
		{
			reading >> s[i].specialty;
			reading >> s[i].qualification;
			reading >> s[i].fio;
		}
		if (z>=0) quantity_data += z;
		cout << "файл открыт" << endl;
	}

	menu();

	while (nomer_func != 6) {
		switch (nomer_func) {
		case(1): {
			cout << "Введите количество врачей: ";
			int n;
			cin >> n;

			for (int i = 0+quantity_data; i < n+quantity_data; i++)
			{
				cout << "Специальность: ";
				cin >> s[i].specialty;
				cout << "Квалификация: ";
				cin >> s[i].qualification;
				cout << "Фамилия: ";
				cin >> s[i].fio;
				cout << endl;
			}
			quantity_data = n+quantity_data;
			menu();
			break;}
		case(2): {

			data_print(s, quantity_data);

			menu();
			break;
		    }
		case(3): {
			string find;
			cout << "Введите фамилию: ";
			cin >> find;
			data_find_surname(find, s, quantity_data);

			menu();
			break;}
		case(4): {
			int sp, q;
			cout << "Введите специальность: ";
			cin >> sp;
			cout << "Введите квалификацию: ";
			cin >> q;

			data_find_s_q(sp, q, quantity_data, s);

			menu();
			break;}
		case(5): {
			sort(s, s + quantity_data, CompareAlphabet);
			cout << "данные отсортированы" << endl;

			menu();
			break;}
		}
	}

	ofstream rewrite("data.txt");
	rewrite.write("", 0);
	rewrite.close();

	data_save(s,quantity_data);
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
