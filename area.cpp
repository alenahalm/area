#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Point {
private:
	double x, y;
public:
	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}
	double get_X() {
		return x;
	}
	double get_Y() {
		return y;
	}
};

int main()
{
	ifstream f("file.txt");
	int k;
	f >> k;
	vector <Point> points;
	for (int i = 0; i < k; i++) {
		double x, y;
		f >> x >> y;
		Point p(x, y);
		points.push_back(p);
	}
	double s = 0;
	for (int i = 0; i < points.size(); i++) {
		if (i < points.size() - 1) {
			s += points[i].get_X() * points[i + 1].get_Y();
			s -= points[i].get_Y() * points[i + 1].get_X();
		}
		else {
			s += points[i].get_X() * points[0].get_Y();
			s -= points[i].get_Y() * points[0].get_X();
		}
	}
	cout << abs(s) << endl;
}