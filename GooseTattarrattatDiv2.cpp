/* SRM 589, Div 2 - 250 point 
 * http://apps.topcoder.com/wiki/display/tc/SRM+589
 * Notes to self: having coded the div 1 problem right before this one really helped. Got 223.5 points .. getting there :)
*/

#include <string>
#include <map>
#include <iostream>

class GooseTattarrattatDiv2
{
public:
int getmin(std::string S)
{
	//find the letter with max frequency
	int maxF = maxFrequencyLetter(S);
	return S.size() - maxF;
}

private:
int maxFrequencyLetter(const std::string& S)
{
	std::map<char, int>charToFreq;
	for (int i = 0; i < S.size(); ++i)
	{
		auto iter = charToFreq.find(S[i]);
		if (iter == charToFreq.end())//not found
		{
			charToFreq.insert(std::make_pair(S[i], 1));
		}
		else
		{
			iter->second++;
		}
	}
	int maxSoFar = 0;
	for (auto i : charToFreq)
	{
		if (i.second > maxSoFar)
			maxSoFar = i.second;
	}
	return maxSoFar;
}
};

int main()
{
	std::string g1("geese");
	std::string g2("tattarrattat");
	std::string g3("xrepayuyubctwtykrauccnquqfuqvccuaakylwlcjuyhyammag");
	GooseTattarrattatDiv2 g;	
	int min = g.getmin(g1);
	std::cout << "Min count to convert to smooth is " << min << "\n";
	
	min = g.getmin(g2);
	std::cout << "Min count to convert to smooth is " << min << "\n";
	min = g.getmin(g3);
	std::cout << "Min count to convert to smooth is " << min << "\n";

}
