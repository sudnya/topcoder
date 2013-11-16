/* SRM 595 DIV2 250 point problem
 * http://apps.topcoder.com/wiki/display/tc/SRM+595
 * Notes to self : struggled with the getMax functions for some reasons, did not save max so far before resetting and did not check if it needs to be saved (only when greater than max so far)
 * got only 152.73 points - somehow perf is tanking today :((( 
 */
#include <string>
#include <iostream>

class LittleElephantAndBallsAgain
{
public:
	int getNumber(std::string s)
	{
		//corner cases
		if (s.size() == 0 || s.size() == 1)
			return 0;
		//if all balls are same color - return 0;
		int red = getRed(s);
		int green = getGreen(s);
		int blue = getBlue(s);
		if (red == 0 && blue == 0)
			return 0;//all green
		if (blue == 0 && green == 0)
			return 0;//all red
		if (red == 0 && green == 0)
			return 0;//all blue
		int biggestR = getMaxRed(s);
		int biggestG = getMaxGreen(s);
		int biggestB = getMaxBlue(s);
		int max = biggestR;
		if(biggestG > max)
			max = biggestG;
		if (biggestB > max)
			max = biggestB;
		return s.size() - max;
	}

private:
	int getMaxRed(std::string s)
	{
		int count = 0;
		int maxSoFar = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] != 'R')
			{
				if (count > maxSoFar)
					maxSoFar = count;
				count = 0;
			}
			else
				++count;
		}
		std::cout << "Red max = " << maxSoFar << "\n";
		return maxSoFar;
	}
	int getMaxGreen(std::string s)
	{
		int count = 0;
		int maxSoFar = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] != 'G')
			{
				if (count > maxSoFar)
					maxSoFar = count;
				count = 0;
			}
			else
				++count;
		}
		std::cout << "Green max = " << maxSoFar << "\n";
		return maxSoFar;
	}

	int getMaxBlue(std::string s)
	{
		int count = 0;
		int maxSoFar = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] != 'B')
			{
				if (count > maxSoFar)
					maxSoFar = count;
				count = 0;
			}
			else
				++count;
		}
		std::cout << "Blue max = " << maxSoFar << "\n";
		return maxSoFar;
	}
		
	int getRed(std::string s)
	{
		int count = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == 'R')
				++count;
		}
		return count;
	}
	
	int getGreen(std::string s)
	{
		int count = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == 'G')
				++count;
		}
		return count;
	}
	
	int getBlue(std::string s)
	{
		int count = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == 'B')
				++count;
		}
		return count;
	}
};


int main()
{
	LittleElephantAndBallsAgain ele;
	std::cout << ele.getNumber("RGGGBB") << "\n";
}
