#include <iostream>
#include <vector>
#include <locale>
#include "Stack.h"

using namespace std;

string open_brackets  = "([{<";
string close_brackets = ")]}>";

void task1(string str) {
	// Обработать строку:
	// in : evangelist
	// out: gnavetsile
	int len = str.length();
	if (len & 1) throw invalid_argument("Length of the string should be even num");
	Stack<char> st(len);
	for (int i = len / 2; i < len; i++) st.push(str[i]);
	for (int i = 0; i < len / 2; i++) st.push(str[i]);
	cout << st;

}


int task2(vector<int> levels) { 
	// Вернуть количество зданий, которые увидит человек,
	// если задан вектор условных высот этих зданий, стоящих в ряд перед смотрящим человеком
	Stack<int> st(levels.size());
	st.push(-1);
	for (int level : levels) 
		if (level > st.top()) st.push(level);
	return st.getSize() - 1;
}

void task3(int num) {
	// Вывести все натуральные делители числа в приведенном формате:
	// in:  100
	// out: 1 | 100 | 2 | 50 | 4 | 25 | 5 | 20 | 10 | 10
	int current = std::sqrt(num);
	Stack<int> deviders;
	for (current; current; current--) 
		if (num % current == 0) {
			deviders.push(num / current);
			deviders.push(current);
		}
	cout << deviders;
}

void task4(string sequence) {
	// Проверить на корректность переданную строку, состоящую из скобок.
	// Если есть ошибка - false;
	// если все верно - true + количество пар скобок в последовательности
	int counter = 0;
	Stack<char> st;
	for (char sym : sequence) {
		if (open_brackets.find(sym) != string::npos) st.push(sym); 
		else {
			int ind = close_brackets.find(sym);
			if (ind == string::npos) throw invalid_argument("Unsupported symbol found in sequence");
			else {
				if ((st.isEmpty()) || (st.top() != open_brackets[ind])) { cout << "false"; return; }
				else {
					st.pop();
					counter++;
				}
			}
		}
	}
	if (st.getSize() == 0) cout << "true (" << counter << " pairs" << ")";
	else cout << "false";
}


int main() {
	setlocale(LC_CTYPE, "ru");
	string delimiter = "======================================";

	cout << delimiter << endl;
	cout << "Задача 1: Обработка строки" << endl;
	cout << "in  : evangelist" << endl;
	cout << "out : ";
	task1("evangelist");
	cout << endl << endl;

	cout << delimiter << endl;
	cout << "Задача 2: Этажи" << endl;
	cout << "in  : [1, 2, 2, 4, 6, 5, 2, 15, 2, 3]" << endl;
	cout << "out : " << task2({ 1, 2, 2, 4, 6, 5, 2, 15, 2, 3 });
	cout << endl << endl;

	cout << delimiter << endl;
	cout << "Задача 3: Натуральные делители" << endl;
	cout << "in  : 100" << endl;
	cout << "out : ";
	task3(100);
	cout << endl << endl;

	cout << delimiter << endl;
	cout << "Задача 4: Последовательность скобок" << endl;
	for (string str : { "{}", "{()}<>", "{<}>", "{()}[", "}({})", "{()(){<<>>}}[]" }) {
		cout << "in  : " << str << endl;
		cout << "out : ";
		task4(str);
		cout << endl << endl;
	}
}