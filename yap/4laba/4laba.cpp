#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

using namespace std;

bool palindrom(char* text, int n)
{
	for (int f = 0, l = n - 1; f <= l; f++, l--) {
		if (text[f] != text[l])
			return false;
	}
	return true;
}

bool search(char* text, int n, int* res)
{
	res[256] = 0;
	int n2 = 0;
	char text2[255];
	cin >> text2[n2];
	while (text2[n2] != '.')
	{
		n2++;
		cin >> text2[n2];
	}
	text2[n2] = '\n';
	for (int i = 0; i < n; i++) {
		if (text[i] == text2[0]) {
			bool pr = true;
			for (int t1 = i + 1, t2 = 1; t2 < n2; t2++, t1++) {
				if (text[t1] != text2[t2]) {
					pr = false;
					break;
				}
			}
			if (pr) {
				res[res[256]] = i;
				res[256]++;
			}
		}
	}
	if (res[256] > 0)
		return true;
	return false;
}

void varios4_1_1() {
	int i = 0;
	char text[255];
	cin >> text[i];
	while (text[i] != '.')
	{
		i++;
		cin >> text[i];
	}
	text[i] = '\n';
	cout << palindrom(text, i);
}

void varios4_1_2() {
	int i = 0;
	char text[255];
	cin >> text[i];
	while (text[i] != '.')
	{
		i++;
		cin >> text[i];
	}
	text[i] = '\n';
	int res[256];
	cout << search(text, i, res);
	for (int j = 0; j < res[256]; j++)
		cout << res[j] << " ";
}

void varios4_1_3() {
	int i = 0;
	char text[255];
	cin >> text[i];
	while (text[i] != '.')
	{
		i++;
		cin >> text[i];
	}
	text[i] = '\n';
	int kl; cin >> kl;
	for (int j = 0; j < i; j++) {
		cout << char((int(text[j]) - 97 + kl) % 26 + 97);
	}
}

void varios4_1_4() {
	int i = 0;
	char text[255];
	cin >> text[i];
	while (text[i] != '.')
	{
		i++;
		cin >> text[i];
	}
	text[i] = '\n';
	bool pol = false;
	char kov[1] = { '"' };
	for (int j = 0; j < i; j++) {
		if (pol and text[j] != kov[0])
			cout << text[j];
		else if (pol and text[j] == kov[0])
			pol = false;
		else if (!pol and text[j] == kov[0])
			pol = true;
	}
}

void lab4_1() {
	int v; cin >> v;
	if (v == 1)
		varios4_1_1();
	else if (v == 2)
		varios4_1_2();
	else if (v == 3)
		varios4_1_3();
	else if (v == 4)
		varios4_1_4();
}

string file_format(string file_path_full) {
	string res = "", t = ".";
	for (int i = file_path_full.length() - 1; file_path_full[i] != t[0]; i--) {
		res = file_path_full[i] + res;
	}
	return res;
}

string file_name(string file_path_full) {
	string res = "", t = "."; int toch;
	for (int i = file_path_full.length(); file_path_full[i] != t[0]; i--) {
		res = file_path_full[i] + res;
		toch = i;
	}
	res = ""; t[0] = '\\'; toch -= 2;
	for (int i = toch; file_path_full[i] != t[0]; i--) {
		res = file_path_full[i] + res;
		toch = i;
	}
	return res;
}

string file_path(string file_path_full) {
	string res = "";
	int c = file_path_full.length() - 1;
	while (file_path_full[c] != '\\')
		c--;
	while (file_path_full[c] != ':') {
		res = file_path_full[c] + res;
		c--;
	}
	return res;
}

char file_disk(string file_path_full) {
	return file_path_full[0];
}

string file_rename(string file_path_full, string new_name) {
	return file_disk(file_path_full) + ":" + file_path(file_path_full) + new_name + "." + file_format(file_path_full);
}

bool file_copy(const string file_path_full) {
	ofstream G;
	ifstream F;
	F.open(file_path_full, 'in');
	if (!F)
		return false;
	G.open(file_rename(file_path_full, file_name(file_path_full) + "copy"), 'out');
	string text;
	while (!F.eof()) {
		F >> text;
		G << text;
	}
	F.close();
	G.close();
	return true;
}

int main()
{
	string s; cin >> s;
	cout << file_path(s);
}
