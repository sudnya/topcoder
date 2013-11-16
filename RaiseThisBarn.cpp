/* SRM 593 DIV2 250 point problem
 * http://apps.topcoder.com/wiki/display/tc/SRM+593
 * Notes to self : lost points due to missing out a corner case (when string has no cows -> should do size -1). Got 202.57 :(
 */

#include <string>
#include <iostream>

class RaiseThisBarn
{
public:
	int calc(std::string s)
	{
		int cows = findTotalCows(s);
		
		if (cows%2 != 0)
			return 0;
		if (cows == 0)
			return s.size()-1;
			
		int firstHalfEnd = first(s, cows);
		int secondHalfBegin = second(s, cows);
		return (secondHalfBegin - firstHalfEnd);
	}

private:
	int findTotalCows(std::string s)
	{
		int cows = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == 'c')
				++cows;
		}
		return cows;
	}
	
	int first(std::string s, int cows)
	{
		int firstEnd = 0;
		int idx = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == 'c')
				++firstEnd;
			if (firstEnd == cows/2)
			{	idx = i;
				break;
			}
		}
		return idx;
	}
	
	
	int second(std::string s, int cows)
	{
		int secondStart = 0;
		int idx = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == 'c')
				++secondStart;
			if (secondStart > cows/2)
			{	idx = i;
				break;
			}
		}
		return idx;
	}
};

int main()
{
	RaiseThisBarn barn;
	std::cout << barn.calc(".c.c...c..ccc.c..c.c.cc..ccc") << "\n";
	return 0;
}
