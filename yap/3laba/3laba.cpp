#include <iostream>
#include <algorithm>

using namespace std;

void MERGE(int* mas[1001], int f_part, int mid, int l_part);

int* Sort1(int mas[1001], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (mas[j] > mas[j + 1])
				swap(mas[j], mas[j + 1]);
		}
	}
	return mas;
}

void Sort2(char mas[1001], int n, char* res) {
	int counting[26];
	for (int i = 0; i < 26; i++)
		counting[i] = 0;
	for (int i = 0; i < n; i++) {
		counting[int(mas[i]) - 97]++;
	}
	int tek = 0;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < counting[i]; j++, tek++) {
			res[tek] = char(i + 97);
		}
	}
}

void Sort3(int* mas, int f_part, int l_part) {
	if (l_part > f_part) {
		Sort3(mas, f_part, (f_part + l_part) / 2);
		Sort3(mas, (f_part + l_part) / 2 + 1, l_part);
		int res[1001];
		int mid = (f_part + l_part) / 2;
		int part1 = f_part, part2 = mid + 1, tek = f_part;
		for (int i = f_part; i <= l_part; i++) {
			if ((part1 <= mid) and (mas[part1] < mas[part2] or part2 > l_part)) {
				res[i] = mas[part1];
				part1++;
			}
			else {
				res[i] = mas[part2];
				part2++;
			}
		}
		/*while (part1 < mid) {
			res[tek] = mas[part1];
			part1++;
			tek++;
		}
		while (part2 <= l_part) {
			res[tek] = mas[part2];
			part2++;
			tek++;
		}*/
		for (int i = f_part; i <= l_part; i++)
			mas[i] = res[i];
	}
}

void MERGE(int(&mas)[1001], int f_part, int mid, int l_part) {
	int res[1001];
	int part1 = 0, part2 = mid, tek = f_part;
	while (part1 < mid and part2 <= l_part) {
		if (mas[part1] <= mas[part2]) {
			res[tek] = mas[part1];
			part1++;
		}
		else {
			res[tek] = mas[part2];
			part2++;
		}
		tek++;
	}
	while (part1 < mid) {
		res[tek] = mas[part1];
		part1++;
		tek++;
	}
	while (part2 <= l_part) {
		res[tek] = mas[part2];
		part2++;
		tek++;
	}
	for (int i = f_part; i <= l_part; i++)
		mas[i] = res[i];
}

void varios1() {
	int mas[1001];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> mas[i];
	int* res = Sort1(mas, n);
	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
}

void varios2() {
	char mas[1001];
	int n;
	char res[1001];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> mas[i];
	Sort2(mas, n, res);
	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
}

void varios3() {
	int mas1[1001];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> mas1[i];
	Sort3(mas1, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << mas1[i] << " ";
	}
}

int lab3_1() {
	while (1) {
		int v; cin >> v;
		if (v == 1)
			varios1();
		else if (v == 2)
			varios2();
		else if (v == 3)
			varios3();
		else
			return 0;
	}
}

int sum_nums(int a) {
	int c = 0, res1 = 0, res2 = 0;
	while (a > 0) {
		if (c % 2 == 0)
			res1 += a % 10;
		else
			res2 += a % 10;
		c++;
		a /= 10;
	}
	if (c % 2 == 1)
		return res2;
	else
		return res1;
}

bool comp1(int a, int b) {
	return sum_nums(a) < sum_nums(b);
}

void Sort3_2_1(int* mas, int n) {
	sort(mas, mas + n, comp1);
}

bool comp2(int a, int b) {
	if (a % 10 == b % 10)
		return a > b;
	return a % 10 < b % 10;
}

void Sort3_2_2(int* mas, int n) {
	sort(mas, mas + n, comp2);
}

int lab3_2() {
	int n;
	int* mas = new int;
	while (1) {

		int v; cin >> v;
		if (v == 1) {
			cin >> n;
			mas = new int[n];
			for (int i = 0; i < n; i++)
				cin >> mas[i];
		}
		if (v == 2) {
			for (int i = 0; i < n; i++) {
				cout << mas[i] << " ";
			}
		}
		if (v == 3) {
			Sort3_2_1(mas, n);
		}
		if (v == 4) {
			Sort3_2_2(mas, n);
		}
		if (v == 5) {
			cout << "exit";
			return 0;
		}
	}
}

int main()
{
	cout << "chose lab(1 or 2)";
	int v; cin >> v;
	if (v == 1)
		v = lab3_1();
	else if (v == 2)
		v = lab3_2();
}
