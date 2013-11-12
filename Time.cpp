// SRM 144 DIV 2 250 Points
#include <sstream>

class Time
{
public:

std::string whatTime(int seconds)
{
     if (seconds > 86399)
     {
         std::cout << "Larger than a day\n";
         return 1;
     }
     unsigned hour = seconds/3600;
     unsigned remaining = seconds - (hour*3600);
     unsigned min = remaining/60;
     remaining -= min*60;
     unsigned sec = remaining;
     
     std::stringstream ss;
     ss << hour;
     ss << ":";
     ss << min;
     ss << ":";
     ss << sec;
     
     return ss.str();
}

};
