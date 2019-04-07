#include <list>
using namespace std;
struct Poly
{
	int factor;
	int index;
};
bool cmp(const Poly& a, const Poly& b);

class poly
{
	list<Poly> p;
public:
	poly():p() {}
	poly(poly& a) { p.splice(p.begin(), a.p); }
	void input();
	void Sort();
	friend ostream& operator<<(ostream& o, poly& n);
	poly operator+(poly& x);
	~poly() { p.clear(); }
};


