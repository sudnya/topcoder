/* SRM 596, Div 2, 500point
 * http://apps.topcoder.com/wiki/display/tc/SRM+596
 * My first 500pt problem, did not want to solve by brute force, so couldnt finish DP in time to test score
 */
#include <string>
#include <iostream>
#include <limits>

class ColorfulRoad
{
	public:
		int getMin(std::string road)
		{
			int maxCost = std::numeric_limits<int>::max();
			int pathCost = getMinCost(road, road.size()-1, road.size()-1, true);
			if (pathCost < maxCost)
				return pathCost;
			else
				return -1;
		}

	private:
		char getNextColor(char currentColor)
		{
			if (currentColor == 'R')
				return 'G';
			if (currentColor == 'G')
				return 'B';
			if (currentColor == 'B')
				return 'R';
			else
			{
				std::cout << "Illegal format input with char " << currentColor << "\n";
				return 'Z';
			}
		}

		bool invalid(std::string s, int from, int to)
		{
			if (getNextColor(s[to]) == s[from])
				return false;//valid
			return true;
		}

		int getMinCost(std::string s, int f, int t, bool skipped)
		{
			//terminating condition
			if (skipped && (t == 0) )
			{
				std::cout << "First element is skipped, so invalid \n";
				return std::numeric_limits<int>::max();
			}
			
		    if (!skipped && (invalid(s, f,t)))
			{
				std::cout << "Invalid color combination from " << t << " to " << f << " i.e. " << s[t] << " -> " << s[f] << "\n";
				return std::numeric_limits<int>::max();
			}
			
			if (t == 0)
			{
				std::cout << "Reached the start : " << t << " to " << f << " i.e. " << s[t] << " -> " << s[f] << "\n";
				return 0;
			}
			//recurrence
			int from;
			
			if (skipped)
				from = f;
			else//taken
				from = t;

			int to = t - 1;;

			int takenCost = getMinCost(s, from, to, false);

			if (takenCost < std::numeric_limits<int>::max())
				takenCost += ((from-to)*(from-to));

			int min = std::min(getMinCost(s, from, to, true), takenCost);
			
			std::cout << "Finished recursion (min cost is " << min << ") from : " << t << " to " << f << " i.e. " << s[t] << " -> " << s[f] << "\n";
			
			return min;
			
			//memoization
			//

			
		}

};

int main()
{
	ColorfulRoad c;
	std::cout << c.getMin("RBRGBGBGGBGRGGG") << "\n";

	return 0;
}
