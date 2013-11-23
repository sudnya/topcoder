/* SRM 597, Div2, 250pt 
 * http://apps.topcoder.com/wiki/display/tc/SRM+597
 * Notes to self: trying to get back - lost points for not declaring result initially, had to look up log2 in cmath. Got 216.7 pts
 * also in order to make all equal case work - divide each by min (after sorting) and then take log2
 */


#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

class LittleElephantAndDouble
{
public:
	std::string getAnswer(std::vector<int> A)
	{
		bool notPowTwo = false;
		double result, result2;
		std::sort(A.begin(), A.end());
		int min = A[0];
		for (auto& i : A)
		{
			result = log2(i/min);
			std::cout << "Log2 of " << i << " is = " << result << "\n";
			if (result - (int)result > 0)
				notPowTwo = true;
		}
		if (notPowTwo)
			return "NO";
		else
			return "YES";
	
	}
};

int main()
{
	LittleElephantAndDouble e;
	std::vector<int> array;
	array.push_back(94);
	array.push_back(752);
	array.push_back(94);
	array.push_back(376);
	array.push_back(1504);

	std::cout << e.getAnswer(array) << "\n";

}
