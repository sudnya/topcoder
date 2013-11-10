/*
 * SRM 588, Div2, 250 Points - got 92.9
 * http://apps.topcoder.com/wiki/display/tc/SRM+588
 * Notes to self: read the problem wrong, keys can be reused so the problem is simpler than I understood. 
*/

#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>

class KeyDungeonDiv2;
class Bunch;

template <typename T>
bool mysort(const T& i, const T& j)
{
    return (i.total < j.total);
}

class Bunch
{
public:
	Bunch(int t, int r, int g) : total(t), red(r), green(g)
	{}

	int total;
	int red;
	int green;

};

class KeyDungeonDiv2
{
public:
int countDoors(std::vector<int>doorR, std::vector<int>doorG, std::vector<int>keys)
{
	int redK = keys[0];
	int greenK = keys[1];
	int whiteK = keys[2];
	std::vector<Bunch> b;
	
	assert(doorG.size() == doorR.size());
	auto j = doorG.begin();
	for (auto i = doorR.begin(); i != doorR.end(); ++i)
	{
		int totalKeys = *i + *j;
		Bunch temp(totalKeys, *i, *j);
		b.push_back(temp);
		++j;
	}
	std::sort(b.begin(), b.end(), mysort<Bunch>);
	unsigned openD = 0;

	for (std::vector<Bunch>::iterator d = b.begin(); d != b.end(); ++d)
	{
		if (d->total > (redK+greenK+whiteK))
		{
			//std::cout << "Total keys for this door = " << d->total << " while we have only upto " << (redK+greenK+whiteK) << " keys available\n" ;
			continue;
		}
		if (d->red > (redK+whiteK))
		{
			//std::cout << "Total keys for this door = " << d->red << " while we have only upto " << (redK+whiteK) << " keys available\n" ;
			continue;
		}
		if (d->green > (greenK+whiteK))
		{
			//std::cout << "Total keys for this door = " << d->green << " while we have only upto " << (greenK+whiteK) << " keys available\n" ;
			continue;
		}
			
		++openD;
	}
	return openD;
	
}
};

int main()
{
	KeyDungeonDiv2 k;

	std::vector<int> r;
	std::vector<int> g;
	std::vector<int> all;

	r.push_back(2);
	r.push_back(0);
	r.push_back(5);
	r.push_back(3);

	g.push_back(1);
	g.push_back(4);
	g.push_back(0);
	g.push_back(2);


	all.push_back(2);
	all.push_back(3);
	all.push_back(1);

	int doors = k.countDoors(r,g,all);

	std::cout << doors;
	return 0;
}
