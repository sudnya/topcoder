/* SRM 590 DIV2 250 (got 108.63 points)
 * http://apps.topcoder.com/wiki/display/tc/SRM+590
 * Notes to self : silly error - had the ++row inside column loop, so r,w pairs were calculated wrong. Needed to debug using std::count :-| DONT RUSH!
 */
#include <string>
#include <vector>
#include <map>
#include <iostream>

class FoxAndGomoku
{
public:
	std::string win(std::vector<std::string> b)
	{
		std::vector<std::pair<int,int>>coordList;
		// find coordinates for 'o'
		int row = 0;
		for (auto r : b)
		{
			for (int col = 0; col < r.size(); ++col)
			{
				if (r[col] == 'o')
				{
					coordList.push_back(std::make_pair(row, col));
					std::cout << "o found at " << row << " , " << col << "\n";
				}
			}
			++row;
		}
		//test all rows same for 5
		int count = 0;
		count = checkRows(coordList);
		if (count >= 5)
			return "found";
		//test all cols same for 5
		count = checkCols(coordList);
		if (count >= 5)
			return "found";
		//test rowid == colid for 5
		count = checkDiag(coordList);
		if (count >= 5)
			return "found";		
		//test reverse diagonal (rowMax - rowId == colId) for 5
		count = checkRevDiag(coordList);
		if (count >= 5)
			return "found";

	return "not found";
	}

private:
	int checkRows(std::vector<std::pair<int,int>>coordList)
	{
		std::map<int, int>xmap;
		for (auto i : coordList)
		{
			auto iter = xmap.find(i.first);
			if (iter != xmap.end())
			{
				iter->second++;
			}
			else
			{
				xmap.insert(std::make_pair(i.first, 1));
			}
		}
		for (auto k : xmap)
		{
			if (k.second >= 5)
				return 5;
		}
		return 1;
	}
	
	int checkCols(std::vector<std::pair<int,int>>coordList)
	{
		std::map<int, int>ymap;
		for (auto i : coordList)
		{
			auto iter = ymap.find(i.second);
			if (iter != ymap.end())
			{
				iter->second++;
			}
			else
			{
				ymap.insert(std::make_pair(i.second, 1));
			}
		}
		for (auto k : ymap)
		{
			if (k.second >= 5)
				return 5;
		}
		return 1;
	}
	
	int checkDiag(std::vector<std::pair<int,int>>coordList)
	{
		std::map<int, int>xymap;
		int count = 0;
		for (auto i : coordList)
		{
			if (i.first == i.second)
			{
				++count;
			}
		}
		return count;
	}
	
	int checkRevDiag(std::vector<std::pair<int,int>>coordList)
	{
		std::map<int, int>xymap;
		for (auto i : coordList)
		{
			auto iter = xymap.find(i.second + i.first);
			if (iter != xymap.end())
			{
				std::cout << "Found " << i.first << " , " << i.second << "\n";
				iter->second++;
			}
			else
			{
				std::cout << "Adding " << i.first << " , " << i.second << "\n";
				xymap.insert(std::make_pair(i.second+i.first, 1));
			}
		}
		for (auto k : xymap)
		{
			if (k.second >= 5)
				return 5;
		}
		return 1;
	}	
};


int main()
{
	std::vector<std::string> s;
	s.push_back("....o.");
	s.push_back("...o..");
	s.push_back("..o...");
	s.push_back(".o....");
	s.push_back("o.....");
	s.push_back("......");

	FoxAndGomoku g;
	std::string num = g.win(s);
	std::cout << num << "\n";
}
