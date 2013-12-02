/* SRM 593 DIV2 500 point problem - score 210.45
 * http://apps.topcoder.com/wiki/display/tc/SRM+593
 * Notes to self : got this one fairly easily but had silly errors in indexing through the string 
 */


#include <string>
#include <vector>
#include <map>
#include <iostream>

class WolfDelaymaster
{
public:
	std::string check(std::string str)
	{
		if (str.empty())
			return "VALID";
		std::vector<std::string>sub = generateSubStr(str);
		for (auto& a : sub)
		{
			if (!checkValid(a))
			{
				std::cout << "Did not work ! = " << a << "\n";
				return "INVALID";
			}
		}
		return "VALID";
	}

private:
	std::vector<std::string> generateSubStr(std::string s)
	{
		std::vector<std::string> s1;
		std::string fw("fw");
		int begin = 0;
		while (begin != s.size())
		{
			int pos = s.find(fw, begin);
			if (pos >= s.size())
				pos = s.size()-1;

			std::string temp = s.substr(begin, pos+1-begin);
			std::cout << "Adding " << temp << "\n";
			s1.push_back(temp);
			begin = pos+1;
		
		}
		return s1;
	}
	
private:
	bool checkValid(std::string s)
	{
		if(s.size() < 4)
			return false; //wolf atleast
		std::map<char, int>wolfMap;
		wolfMap.insert(std::make_pair('w', 0));
		wolfMap.insert(std::make_pair('o', 0));
		wolfMap.insert(std::make_pair('l', 0));
		wolfMap.insert(std::make_pair('f', 0));
		
		for (int i = 0; i < s.size(); ++i)
		{
			auto iter = wolfMap.find(s[i]);
			iter->second++;
		}
		int ws = wolfMap.find('w')->second;
		int os = wolfMap.find('o')->second;
		int ls = wolfMap.find('l')->second;
		int fs = wolfMap.find('f')->second;
		
		return ((ws == os) && (os == ls) && (ls == fs) && (fs == ws));
	}
};

int main()
{
	WolfDelaymaster w;
	std::cout << w.check("wolfwwoollffwwwooolllfffwwwwoooollllffff") << "\n";
}
