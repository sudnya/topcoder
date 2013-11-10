/*
 * SRM 587 DIV2 250 points - got 140 points
 * http://apps.topcoder.com/wiki/display/tc/SRM+587
 *
*/
#include <string>
#include <iostream>

class InsertZ
{
public:
std::string canTransform(std::string init, std::string goal)
{
if (init.compare(goal) == 0)
return "Yes";

if (init.size() > goal.size())
return "No";

bool notEq = false;
unsigned j = 0, i = 0;
while (i < goal.size())
{
    if (goal[i] == 'z')
	{
        ++i; 
	}
	else if (goal[i] == init[j])
    {
		++i;
        ++j;
    }
	else if (goal[i] != init[j])
		return "No";
}

return "Yes";
}
};

int main()
{
	InsertZ i;
	std::string ans = i.canTransform("topcoder", "zopzoder");
	std::cout << ans;
}
