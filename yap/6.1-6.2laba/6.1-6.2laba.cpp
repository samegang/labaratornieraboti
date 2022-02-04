#include <iostream>
#include <stack>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
public:
    int X;
    int Y;
};

vector<point> syst;
deque<int> temp;

void lab6_1() {
    stack<char> mas;
    string strok; cin >> strok;
    for (auto i : strok) {
        if (i == '(' or i == '[' or i == '{') {
            mas.push(i);
        }
        if (i == ')' or i == ']' or i == '}') {
            if (abs(int(i) - int(mas.top()) < 3))
                mas.pop();
            else {
                cout << "NO";
                exit(0);
            }
        }
    }
    if (mas.empty())
        cout << "YES";
    else
        cout << "NO";
}

void exirces6_2_1() {
    deque<char> mas;
    string s; cin >> s;
    for (auto i : s) {
        mas.push_back(i);
    }
    for (int i = 0; i < s.length() / 2; i++) {
        if (mas.front() == mas.back()) {
            mas.pop_back();
            mas.pop_front();
        }
        else {
            cout << "NO";
            exit(0);
        }
    }
    cout << "YES";
}

struct pred {
    bool operator()(int c, int b) {
        point C = syst[c];
        point B = syst[b];
        point A = syst[temp.front()];
        double res = (B.X - A.X) * (C.Y - B.Y) - (B.Y - A.Y) * (C.X - B.X);
        if (res == 0) {
            return C.X < B.X;
        }
        return res < 0;
    } //true - C in right from AB, where A is the first point and B is final point
};

class prostr {
private:


    void newPoint() {
        point newP;
        cin >> newP.X;
        cin >> newP.Y;
        syst.push_back(newP);
    }

    void newPoint(int x, int y) {
        point newP; newP.X = x; newP.Y = y;
        syst.push_back(newP);
    }

    int searchMinByX() {
        int resIndex = 0, minX = syst[0].X;
        for (int i = 0; i < syst.size(); i++) {
            if (syst[i].X < minX) {
                resIndex = i;
                minX = syst[i].X;
            }
        }
        return resIndex;
    }

    bool compByDA(int first, int second, int prof) {
        point C = syst[second];
        point B = syst[prof];
        point A = syst[first];
        double res = (B.X - A.X) * (C.Y - B.Y) - (B.Y - A.Y) * (C.X - B.X);
        return res <= 0;//true - C in right from AB, where A is the first point and B is final point
    }

    deque<int> Grehem() {
        //the first part

        int minIndex = searchMinByX();
        temp.push_back(minIndex);
        for (int i = 0; i < syst.size(); i++) {
            if (i != minIndex)
                temp.push_back(i);
        }

        //the second part
        sort(temp.begin(), temp.end(), pred());

        //the third part
        deque<int> res;
        res.push_back(temp.front());
        int firstPoint = temp.front();
        temp.pop_front();
        res.push_back(temp.front());
        int secondPoint = temp.front();
        temp.pop_front();
        int tempSize = temp.size();
        for (int i = 0; i < tempSize; i++) {
            if (compByDA(firstPoint, secondPoint, temp.front())) {
                res.push_back(temp.front());
                firstPoint = secondPoint;
                secondPoint = temp.front();
                temp.pop_front();
            }
            else {
                res.pop_back();
                secondPoint = res.back();
                res.pop_back();
                firstPoint = res.back();
                res.push_back(secondPoint);
                i--;
            }
        }
        return res;
    }

public:


    deque<int> mas;

    void nabor() {
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            newPoint();
        }
    }

    void printGrehem() {
        deque<int> res = Grehem();
        for (int i = 0; res.size() > 0; i++) {
            cout << res.front() << " ";
            res.pop_front();
        }
    }
};

void varois2() {
    prostr Syst;
    Syst.nabor();
    Syst.printGrehem();
}

int main()
{
    varois2();
}
/*
13
2 9
3 7
5 6
7 6
9 7
9 9
7 11
5 11
4 8
6 8
5 9
6 10
7 9
*/