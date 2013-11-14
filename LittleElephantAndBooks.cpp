/* SRM 592 DIV2 250 (got 242.66 points)
 * http://apps.topcoder.com/wiki/display/tc/SRM+592
 * Notes to self : maybe it is time to move to Div1 250 point problems now :)
 */
#include <vector>
#include <algorithm>
#include <iostream>

class LittleElephantAndBooks
{
public:
	int getNumber(std::vector<int>books, int hw)
	{
		int pages = 0;
		std::sort(books.begin(), books.end());
		for (int i = 0; i<hw-1; ++i)
		{
			pages += books[i];
		}
		pages += books[hw];
		
		return pages;
	}
};

int main()
{
	LittleElephantAndBooks e;
	std::vector<int> b;
	b.push_back(74);
	b.push_back(86);
	b.push_back(32);
	b.push_back(13);
	b.push_back(100);
	b.push_back(67);
	b.push_back(77);
	std::cout << e.getNumber(b, 2) << "\n";

}
