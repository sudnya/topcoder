/* SRM 144 DIV1 300 points (got 100 points)
 * http://community.topcoder.com/tc?module=Static&d1=match_editorials&d2=srm144 
 * Notes to self : dont work on old SRMs, the latest the better. Dont waste attempts in compiling errors etc.
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class BinaryCode
{
private:
char writeIntToChar(unsigned i)
{
    std::stringstream s;
    s << i;
    return s.str().front();
}

unsigned writeCharToInt(char a)
{
    std::stringstream s;
    s << a;
    unsigned value = 0;
    s >> value;
    return value;
}
std::string decodeStartingZero(const std::string& enc)
{
    std::vector<unsigned>encoded;
    for (unsigned i = 0 ; i < enc.size(); ++i)
    {
        encoded.push_back(writeCharToInt(enc[i]));
    }
    //P[i] = Q[i-1] - P[i-2] - P[i-1] where P0 = 0, P[-1]=0
    std::vector<unsigned>decoded;
    decoded.push_back(0); //0th
    decoded.push_back(encoded[0]);//1st
    
    for (unsigned i = 2; i < encoded.size(); ++i)
    {
        decoded.push_back(encoded[i-1] - decoded[i-2] - decoded[i-1]);
    }
    std::string dec;
    for (std::vector<unsigned>::iterator j = decoded.begin(); j != decoded.end(); ++j)
    {
        if (*j > 1)
            return "NONE";

        char temp = writeIntToChar(*j);             
        dec.push_back(temp);
        
    }
    return dec;
}

std::string decodeStartingOne(const std::string& enc)
{
    std::vector<unsigned>encoded;
    for (unsigned i = 0 ; i < enc.size(); ++i)
    {
        encoded.push_back(writeCharToInt(enc[i]));
    }
    //P[i] = Q[i-1] - P[i-2] - P[i-1] where P0 = 0, P[-1]=0
    std::vector<unsigned>decoded;
    decoded.push_back(1); //0th
    decoded.push_back(encoded[0]-1);//1st
    
    for (unsigned i = 2; i < encoded.size(); ++i)
    {
        decoded.push_back(encoded[i-1] - decoded[i-2] - decoded[i-1]);
    }
    std::string dec;
    for (std::vector<unsigned>::iterator j = decoded.begin(); j != decoded.end(); ++j)
    {
        char temp = writeIntToChar(*j); 
        
        if (*j > 1)
            return "NONE";
            
        dec.push_back(temp);
        
    }
    return dec;
}
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class BinaryCode
{
private:
char writeIntToChar(unsigned i)
{
    std::stringstream s;
    s << i;
    return s.str().front();
}

unsigned writeCharToInt(char a)
{
    std::stringstream s;
    s << a;
    unsigned value = 0;
    s >> value;
    return value;
}
std::string decodeStartingZero(const std::string& enc)
{
    std::vector<unsigned>encoded;
    for (unsigned i = 0 ; i < enc.size(); ++i)
    {
        encoded.push_back(writeCharToInt(enc[i]));
    }
    //P[i] = Q[i-1] - P[i-2] - P[i-1] where P0 = 0, P[-1]=0
    std::vector<unsigned>decoded;
    decoded.push_back(0); //0th
    decoded.push_back(encoded[0]);//1st
    
    for (unsigned i = 2; i < encoded.size(); ++i)
    {
        decoded.push_back(encoded[i-1] - decoded[i-2] - decoded[i-1]);
    }
    std::string dec;
    for (std::vector<unsigned>::iterator j = decoded.begin(); j != decoded.end(); ++j)
    {
        if (*j > 1)
            return "NONE";

        char temp = writeIntToChar(*j);             
        dec.push_back(temp);
        
    }
    return dec;
}

std::string decodeStartingOne(const std::string& enc)
{
    std::vector<unsigned>encoded;
    for (unsigned i = 0 ; i < enc.size(); ++i)
    {
        encoded.push_back(writeCharToInt(enc[i]));
    }
    //P[i] = Q[i-1] - P[i-2] - P[i-1] where P0 = 0, P[-1]=0
    std::vector<unsigned>decoded;
    decoded.push_back(1); //0th
    decoded.push_back(encoded[0]-1);//1st
    
    for (unsigned i = 2; i < encoded.size(); ++i)
    {
        decoded.push_back(encoded[i-1] - decoded[i-2] - decoded[i-1]);
    }
    std::string dec;
    for (std::vector<unsigned>::iterator j = decoded.begin(); j != decoded.end(); ++j)
    {
        char temp = writeIntToChar(*j); 
        
        if (*j > 1)
            return "NONE";
            
        dec.push_back(temp);
        
    }
    return dec;
}

public:
std::vector<std::string> decode(const std::string& encrypted)
{
    //if P[0] = 0
    std::vector<std::string> decoded;
    decoded.push_back(decodeStartingZero(encrypted));
    decoded.push_back(decodeStartingOne(encrypted));
    return decoded;
}
};
public:
std::vector<std::string> decode(const std::string& encrypted)
{
    //if P[0] = 0
    std::vector<std::string> decoded;
    decoded.push_back(decodeStartingZero(encrypted));
    decoded.push_back(decodeStartingOne(encrypted));
    return decoded;
}
};
