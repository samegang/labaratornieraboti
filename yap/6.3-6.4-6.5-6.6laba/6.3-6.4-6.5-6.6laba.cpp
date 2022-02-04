#include <iostream>
#include <queue>
#include <set>
#include <list>
#include <string>
#include <map>
#include <fstream>

using namespace std;

void proc6_3() {
    int n; cin >> n;

    deque<int> res;
    int temp = 0;
    for (int i = 0; i < n; i++) {
        temp += 30;
        res.push_back(temp);
    }
    while (!res.empty()) {
        cout << res.front() << " ";
        res.pop_front();
    }
}

void proc6_4() {
    int n; cin >> n;
    set<int> attempts;
    int mas[2000]; // users's results (mas[i] == result user numer i)
    for (int i = 0; i < n; i++) {
        int j; cin >> j;
        if (attempts.count(j)) {
            cin >> j;
        }
        else {
            int newJ; cin >> newJ;
            mas[j] = newJ;
            attempts.insert(j);
        }
    }
    for (auto i : attempts)
        cout << i << " " << mas[i] << " ";
}

void proc6_5() {
    int n; cin >> n;
    list<pair<int, string>> mas;
    for (int i = 0; i < n; i++) {
        int j; cin >> j;
        string surname; cin >> surname;
        mas.push_back(make_pair(j, surname));
    }
    for (auto i : mas)
        cout << i.first << " " << i.second << "\n";
}

void proc6_6() {
    ifstream in("text.txt");
    string text = "", str;
    while (getline(in, str))
        text += str;
    map<string, int> res;
    string slov = "";
    int sum = 0;
    for (int i = 0; i < text.length(); i++) {
        if (text[i] != ' ') {
            slov += text[i];
        }
        else {
            res[slov]++;
            slov = "";
            sum++;
        }
        if (i == text.length() - 1) {
            res[slov]++;
            slov = "";
            sum++;
        }
    }
    for (auto it = res.cbegin(); it != res.cend(); it++) {
        cout << it->first << " " << double(it->second) / double(sum) * 100.0 << "% \n";
    }
}

int main()
{
    while (1) {
        cout << "What lab?(if you want to exit print 0)";
        int varios; cin >> varios;
        if (varios == 3)
            proc6_3();
        else if (varios == 4)
            proc6_4();
        else if (varios == 5)
            proc6_5();
        else if (varios == 6)
            proc6_6();
        else if (varios == 0)
            return 0;
        else
            cout << "wrong number";
    }
}
/*
* 2  2    2   2   2    2    2
* 3  3    3   3   3    3    3
* 5  5    5   5   5    5    5
*    2    3   2   5    2    2
*             2        3    5
*
  60 120 180 240 300 360   600
*/