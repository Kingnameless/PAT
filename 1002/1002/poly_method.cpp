#include "poly.h"
#include <iostream>
#include <algorithm>

bool cmp(const Poly& a, const Poly& b)
{
	return a.index > b.index;
}

ostream& operator<<(ostream& o, poly& n)
{
	list<Poly>::iterator i = n.p.begin();
	if (i->index == 0)
		o << i->factor;
	o << i->factor << "x^" << i->index;
	i++;
	while (i != n.p.end())
	{
		if (i->index == 0)
			o << "+" << i->factor;
		else
			o << "+" << i->factor << "x^" << i->index;
		i++;
	}
	return o;
}
void poly::Sort()
{
	p.sort(cmp);
}
poly poly::operator+(poly& x)
{
	poly temp;Poly r;
	this->Sort();x.Sort();
	list<Poly>::iterator s, t;
	s = p.begin();t = x.p.begin();
	while (s != p.end() || t != x.p.end())
	{
		if (s->index == t->index)
		{
			r.index = s->index;r.factor = s->factor + t->factor;
			temp.p.push_back(r);
			s++;t++;
		}
		else
			if (s->index > t->index)
			{
				r.index = s->index;r.factor = s->factor;
				temp.p.push_back(r);
				s++;
			}
			else
			{
				r.index = t->index;r.factor = t->factor;
				temp.p.push_back(r);
				t++;
			}
	}
	return temp;
}