/* SRM 601 DIV2 500 point problem - score 233.73
 * http://apps.topcoder.com/wiki/display/tc/SRM+602
 * Notes to self : corner cases missed */

#include<vector>
#include<iostream>
#include<algorithm>
#include <limits>
class WinterAndMandarins
{
public:
	int getNumber(std::vector<int>bags, int K)
	{
		std::sort(bags.begin(), bags.end());
        int mindiff = std::numeric_limits<int>::max();
		for (int i = 0; i < bags.size()-K; ++i) 
		{
			if (mindiff > bags[i+K-1]-bags[i]) 
                mindiff = (bags[i+K-1]-bags[i]);
		}
		return mindiff;
	}
};


int main()
{
    WinterAndMandarins w;
    std::vector<int> bags;
    bags.push_back(47);
    bags.push_back(1000000000);
    bags.push_back(1);
    bags.push_back(74);
    int K = 2;
    std::cout << "max diff = " << w.getNumber(bags, K) << "\n";
    return 0;
}
