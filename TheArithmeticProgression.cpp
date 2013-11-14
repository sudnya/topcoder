/* SRM 591 DIV2 250 (got 243.33 points)
 * http://apps.topcoder.com/wiki/display/tc/SRM+591
 * Notes to self : maybe it is time to move to Div1 250 point problems now :)
 */

#include <iostream>

class TheArithmeticProgression
{
public:
	double minimumChange(int x, int y, int z)
	{
		double r;
		r = (x+z-(2*y))/2;
		return r;
	}
};

int main()
{
	TheArithmeticProgression a;
	std::cout << a.minimumChange(4,4,8) << "\n";
	return 0;
}
