/* SRM 592 DIV2 500 point problem - score 167.82
 * http://apps.topcoder.com/wiki/display/tc/SRM+592
 * Notes to self : struggled with generating permutations and did not coiterate correctly - bad 2x bug due to it 
 */

#include<set>
#include<vector>
#include <iostream>
#include <sstream>

static std::string toString(const std::vector<int>& p)
{
	std::stringstream stream;

	stream << "(";
	
	for(std::vector<int>::const_iterator i = p.begin(); i != p.end(); ++i)
	{
		if(i != p.begin()) stream << ", ";

		stream << *i;
	}

	stream << ")";

	return stream.str();
}

class LittleElephantAndPermutationDiv2
{
public:
	long long getNumber(int N, int K)
	{
		if (N == 1)
			return N >= K;
		std::set<int>remainingSet;
		for (int i = 1; i <= N; ++i)
			remainingSet.insert(i);
		//generate all possible As and Bs
		std::vector<int> perm;
		std::vector<std::vector<int>> allPerms;
		generateSubProblems(N, 0, remainingSet, perm, allPerms);
		
		int count = 0;
		
		for (auto& a : allPerms)
		{
			for (auto& b : allPerms)
			{
				std::cout << "for A " << toString(a) << " and B " << toString(b) << "\n"; 

				int magic = 0;
				for (std::vector<int>::iterator j = a.begin(), k = b.begin(); j != a.end(); ++j, ++k)
				{
					magic += std::max(*j, *k);
					//std::cout << "\nMax of " << *j << " , " << *k << "\n"; 
				}
				if (magic >= K)
				{
					std::cout << " Magic = " << magic << "\n";
					++count;
				}
			}
		}
		return count;
	}

private:
	void generateSubProblems(int N, int id, std::set<int>remaining, std::vector<int> perm, std::vector<std::vector<int>>& allperms)
	{
		if(id != 0)
			perm.push_back(id);
		
		if(remaining.empty())
		{
			allperms.push_back(perm);
			return;
		}
		
		for (std::set<int>::iterator i = remaining.begin(); i != remaining.end(); ++i)
		{
			std::set<int> newRemaining = remaining;
			
			newRemaining.erase(*i);
			
			generateSubProblems(N, *i, newRemaining, perm, allperms);
		}
	}

};

int main()
{
	LittleElephantAndPermutationDiv2 ele;
	std::cout << ele.getNumber(3,8) << "\n";
}
