/* SRM 594 DIV2 250 point problem
 * http://apps.topcoder.com/wiki/display/tc/SRM+594
 * Notes to self : lost points due to compilation error of not declaring set correctly as a std::pair. Got 197.22 points :-|
 */


#include <string>
#include <set>
#include <map>
#include <iostream>


class FoxAndClassroom
{
public:
	std::string ableTo(int r, int c)
	{
		//corner cases
		if (r == 0 && c == 0)
			return "Possible";
		int row = 0;
		int col = 0;
		std::set<std::pair<int, int>> seats;
		for (int i = 0; i < r*c; ++i)
		{
			seats.insert(std::make_pair(row, col));
			row = (row+1)%r;
			col = (col+1)%c;
		}
		if (seats.size() == r*c)
			return "Possible";
		
		return "Impossible";
	}
};

int main()
{
	FoxAndClassroom fc;
	std::cout << fc.ableTo(5,7) << "\n";
	return 0;
}
