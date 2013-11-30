/* SRM 598 DIV2 250 point problem - score 184.24
 * http://apps.topcoder.com/wiki/display/tc/SRM+598
 * Notes to self : missed the corner case -> had to make substr1 as 0 to idx (and not idx-1)
 */

#include <string>
#include <set>
#include <iostream>
#include <string>

class ErasingCharacters
{
public:
	std::string simulate(std::string s)
	{
		if (s.size() <= 1)
			return s;
		bool norepeat = false;
		while (!norepeat)
		{
			//find idx where repeats
			int idx = findIdx(s);
			if (idx >= s.size())
				return s;
			std::cout << "Idx to replace " << idx << "\n";
			std::string curr = remove(s, idx);
			std::cout << "New string " << curr << "\n";
			if (curr.size() < s.size())
			{
				s = curr;
			}
			else
				norepeat = true;
		}
		return s;
	}

private:
	std::string remove(std::string s, int idx)
	{
		std::string s1 = s.substr(0, idx);
		std::string s2 = s.substr(idx+2, s.size());
		return s1.append(s2);
	}
	
	int findIdx(std::string s)
	{
		for (int i = 1; i < s.size(); ++i)
		{
			if (s[i] == s[i-1])
				return i-1;
		}
		return s.size()+1;
	}
};

int main()
{
	ErasingCharacters e;
	std::cout << e.simulate("bacaabaccbaaccabbcabbacabcbba") << "\n";
}
