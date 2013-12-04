/*  	TCI '02 Semifinals 2 
 * http://community.topcoder.com/stat?c=problem_statement&pm=1170&rd=4371
 * shouldnt have chosen DP :(
 */


#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <set>
#include <cassert>

typedef std::map<std::pair<int,int>,int> MemoTable;
class Rectangle
{
	public:
		Rectangle(int mx, int my, int nx, int ny) : x1(mx), y1(my), x2(nx), y2(ny)
		{
		}
	public:
		int x1,y1,x2,y2;
};
class Escape
{
public:
	int lowest(std::vector<std::pair<int,int>> h, std::vector<std::pair<int,int>>d)
	{
		if ((d.size() == 0) && (h.size() == 0))
			return 0;

		assert(h.size() % 2 == 0 && d.size()%2 == 0);
		int height = 500;
		int width = 500;
		int startx = 0;
		int starty = 0;
		for (int i = 0; i < h.size(); i+=2)
		{
			Rectangle r(h[i].first, h[i].second, h[i+1].first, h[i+1].second);
			m_h.push_back(r);
		}
		
		for (int i = 0; i < d.size(); i+=2)
		{
			Rectangle r(d[i].first, d[i].second, d[i+1].first, d[i+1].second);
			m_d.push_back(r);
		}

		MemoTable memotable;
		//int cost = std::numeric_limits<int>::max();
		int cannotReach = std::numeric_limits<int>::max();
		int pathCost = findMinPoints(0, 0, memotable);
		if (pathCost < cannotReach)
			return pathCost;

		return -1;
	}
private:
	int findMinPoints(int x, int y, MemoTable& memo)
	{
		if (x < 0 || y < 0 || x > 500 || y > 500)
		{
			//std::cout << "Outside map bounds!\n";
			return std::numeric_limits<int>::max()/2;
		}

		if (x == 500 && y == 500)
		{
			std::cout << "Terminating cost : 0 \n"; 
			return 0;
		}
		auto iter = memo.find(std::make_pair(x,y));
		if (iter != memo.end())
		{
			return iter->second;
		}
		
		if (m_visited.find(std::make_pair(x, y)) != m_visited.end())//already explored
			return std::numeric_limits<int>::max()/2;

		m_visited.insert(std::make_pair(x,y));
		
	    int costSoFar2 = std::min(findMinPoints(x+1, y, memo) + getCost(x, y, x+1, y), findMinPoints(x, y+1, memo) + getCost(x, y, x, y+1));
		int costSoFar1 = std::min(findMinPoints(x-1, y, memo) + getCost(x, y, x-1, y), findMinPoints(x, y-1, memo) + getCost(x, y, x, y-1));

		int costSoFar = std::min(costSoFar1, costSoFar2);
	
		if (costSoFar == std::numeric_limits<int>::max())
			costSoFar = std::numeric_limits<int>::max()/2;

		memo.insert(std::make_pair(std::make_pair(x,y), costSoFar));
		return costSoFar;
	}

	int getCost(int x1, int y1, int x2, int y2)
	{
		int from = 0, to = 0;
		for (auto& h : m_h)
		{
			if ((x1 >= h.x1) && (x1 <= h.x2 ) && (y1 >= h.y1) && (y1 <= h.y2))
			{
				std::cout << "Walking out of harmful\n";
				from = 1;	
			}
			if ((x2 >= h.x1) && (x2 <= h.x2 ) && (y2 >= h.y1) && (y2 <= h.y2))
			{
				std::cout << "Walking into harmful\n";
				to = 1;	
			}
		}
		for (auto& d : m_d)
		{
			if ((x1 >= d.x1) && (x1 <= d.x2 ) && (y1 >= d.y1) && (y1 <= d.y2))
			{
				std::cout << "Walking out of deadly\n";
				from = std::numeric_limits<int>::max()/2;
			}
			if ((x2 >= d.x1) && (x2 <= d.x2 ) && (y2 >= d.y1) && (y2 <= d.y2))
			{
				std::cout << "Walking into deadly\n";
				to = std::numeric_limits<int>::max()/2;
			}
		}
		int cost = to; 

		std::cout << " cost from " << x1 << ", " << y1 << " -> " << x2 << ", " << y2 << " is " << cost << "\n";
		return cost;
	}
private:
	std::vector<Rectangle> m_h;
	std::vector<Rectangle> m_d;
	std::set<std::pair<int,int>> m_visited;
};

int main()
{
	Escape e;
	std::vector<std::pair<int,int>> harmful;
	std::vector<std::pair<int,int>> deadly;

	harmful.push_back(std::make_pair(0, 0));
	harmful.push_back(std::make_pair(500, 500));
	
	deadly.push_back(std::make_pair(0, 0));
	deadly.push_back(std::make_pair(0, 0));
	std::cout << "Lives lost = " << e.lowest(harmful, deadly) << "\n";
	return 0;
}
