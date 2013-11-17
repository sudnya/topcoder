/* SRM 596 DIV2 250 point problem
 * http://apps.topcoder.com/wiki/display/tc/SRM+596
 * Notes to self : struggled with this one terribly - to get the correct prevDist 
 * got only 111.38 points - somehow perf is tanking today :((( 
 */

#include <vector>
#include <algorithm>
#include <iostream>

class FoxAndSightseeing
{
public:
	int getMin(std::vector<int> position)
	{
		//std::sort(position.begin(), position.end());
		//find total distance
		int totalD = 0;
		for (auto& i : position)
		{
			totalD = std::abs(totalD - i);
		}
		//now sorted - find max diff between consecutive
		int maxDiff = 0;
		int currDiff = 0;
		int prevDist = 0;
		for (int i = 0; i < position.size() -1 ; ++i)
		{
			currDiff = std::abs(prevDist - position[i]) + std::abs(position[i] - position[i+1]);
			prevDist =position[i];
			std::cout << "Removing " << position[i] << " would reduce " << currDiff << "\n";
			if (maxDiff < currDiff)
				maxDiff = currDiff;
		}
		return std::abs(totalD - maxDiff);
	}
};

int main()
{
	std::vector<int> c;
	c.push_back(100);
    c.push_back(-100);
    c.push_back(99);
    c.push_back(-99);

	FoxAndSightseeing f;
	std::cout << f.getMin(c) << "\n";
	return 0;
}
