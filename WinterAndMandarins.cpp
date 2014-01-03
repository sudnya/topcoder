/* SRM 601 DIV2 500 point problem - score 233.73
 * http://apps.topcoder.com/wiki/display/tc/SRM+602
 * Notes to self : corner cases missed */

#include<vector>
#include<iostream>
#include<algorithm>

class WinterAndMandarins
{
public:
	int getNumber(std::vector<int>bags, int K)
	{
		std::sort(bags.begin(), bags.end());
		return (bags[K-1]-bags[0]);
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
    std::cout << "max diff = " << w.getNumber(bags, K);
    return 0;
}
