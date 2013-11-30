/* SRM 598 DIV2 500 point problem - score 199.45
 * http://apps.topcoder.com/wiki/display/tc/SRM+598
 * Notes to self : assumed this was multi-knapsack. missed the point that since items weigh 101-300 there can be at most 2 per bag!
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

class BinPackingEasy
{
public:
	int minBins(std::vector<int> item)
	{
		if (item.size() == 0)
			return 0;
		if (item.size() == 1)
			return 1;

		std::map<int, int>mmap;
		for (auto& i : item)
		{
			auto key = mmap.find(i);
			if (key != mmap.end())
			{
				key->second++;
			}
			else
			{
				mmap.insert(std::make_pair(i,1));
			}
		}
		
		int count = 0;
		
		while (mmap.size() != 0)
		{
			binPack(mmap);
			++count;
		}
		return count;
	}

private:
	void binPack(std::map<int,int>& item)
	{
		int capacity = 300;
		int last = item.rbegin()->first;
		item.rbegin()->second--;
		if (item.rbegin()->second == 0)
		{
			auto it = --item.rbegin().base();
			item.erase(it);
		}
		
		if (item.begin() != item.end())
		{
		      auto it = item.begin();
		      int paired = it->first;
		      if (paired + last <= capacity)
		      {	
		          it->second--;
		          if (it->second == 0)
		          	item.erase(it);
		      }
		}

	}
	

};

