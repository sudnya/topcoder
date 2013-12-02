/* SRM 594 DIV2 500 point problem - score 185.69
 * http://apps.topcoder.com/wiki/display/tc/SRM+594
 * Notes to self : again problem understanding question clearly, lost points in trying solution to wrong answer 
 */


#include <vector>
#include <set>
#include <iostream>

class AstronomicalRecordsEasy
{
public:
	int minimalPlanets(std::vector<int> A, std::vector<int> B)
	{
		int minPlanets = A.size() + B.size();
		
		for (auto& a : A)
		{
			for (auto& b : B)
			{
				std::set<int>mySet;
				for (auto& x : A)
					mySet.insert(x*b);
				for (auto& y : B)
					mySet.insert(y*a);

				minPlanets = std::min<int>(minPlanets, mySet.size());
			}
		}
		return minPlanets;
	}


};

int main()
{
	AstronomicalRecordsEasy ar;
	std::vector<int> A;
	A.push_back(1);
	A.push_back(2);
	A.push_back(3);
	A.push_back(4);

	std::vector<int> B;
	B.push_back(6);
	B.push_back(7);
	B.push_back(8);
	B.push_back(9);

	std::cout << ar.minimalPlanets(A,B) << "\n";
}
