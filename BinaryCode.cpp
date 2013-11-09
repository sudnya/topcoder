/* #TODO SRM 144 DIV1 300 points (got 100 points)
 * Problem Statement
    
Let's say you have a binary string such as the following:
011100011
One way to encrypt this string is to add to each digit the sum of its adjacent digits. For example, the above string would become:
123210122
In particular, if P is the original string, and Q is the encrypted string, then Q[i] = P[i-1] + P[i] + P[i+1] for all digit positions i. Characters off the left and right edges of the string are treated as zeroes.
An encrypted string given to you in this format can be decoded as follows (using 123210122 as an example):
Assume P[0] = 0.
Because Q[0] = P[0] + P[1] = 0 + P[1] = 1, we know that P[1] = 1.
Because Q[1] = P[0] + P[1] + P[2] = 0 + 1 + P[2] = 2, we know that P[2] = 1.
Because Q[2] = P[1] + P[2] + P[3] = 1 + 1 + P[3] = 3, we know that P[3] = 1.
Repeating these steps gives us P[4] = 0, P[5] = 0, P[6] = 0, P[7] = 1, and P[8] = 1.
We check our work by noting that Q[8] = P[7] + P[8] = 1 + 1 = 2. Since this equation works out, we are finished, and we have recovered one possible original string.
Now we repeat the process, assuming the opposite about P[0]:
Assume P[0] = 1.
Because Q[0] = P[0] + P[1] = 1 + P[1] = 1, we know that P[1] = 0.
Because Q[1] = P[0] + P[1] + P[2] = 1 + 0 + P[2] = 2, we know that P[2] = 1.
Now note that Q[2] = P[1] + P[2] + P[3] = 0 + 1 + P[3] = 3, which leads us to the conclusion that P[3] = 2. However, this violates the fact that each character in the original string must be '0' or '1'. Therefore, there exists no such original string P where the first digit is '1'.
Note that this algorithm produces at most two decodings for any given encrypted string. There can never be more than one possible way to decode a string once the first binary digit is set.
Given a string message, containing the encrypted string, return a vector <string> with exactly two elements. The first element should contain the decrypted string assuming the first character is '0'; the second element should assume the first character is '1'. If one of the tests fails, return the string "NONE" in its place. For the above example, you should return {"011100011", "NONE"}.
Definition
    
Class:
BinaryCode
Method:
decode
Parameters:
string
Returns:
vector <string>
Method signature:
vector <string> decode(string message)
(be sure your method is public)
    

Constraints
-
message will contain between 1 and 50 characters, inclusive.
-
Each character in message will be either '0', '1', '2', or '3'.
Examples
0)

    
"123210122"
Returns: { "011100011",  "NONE" }
The example from above.
1)

    
"11"
Returns: { "01",  "10" }
We know that one of the digits must be '1', and the other must be '0'. We return both cases.
2)

    
"22111"
Returns: { "NONE",  "11001" }
Since the first digit of the encrypted string is '2', the first two digits of the original string must be '1'. Our test fails when we try to assume that P[0] = 0.
3)

    
"123210120"
Returns: { "NONE",  "NONE" }
This is the same as the first example, but the rightmost digit has been changed to something inconsistent with the rest of the original string. No solutions are possible.
4)

    
"3"
Returns: { "NONE",  "NONE" }

5)

    
"12221112222221112221111111112221111"
Returns: 
{ "01101001101101001101001001001101001",http://community.topcoder.com/tc?module=Static&d1=applet&d2=no-support
  "10110010110110010110010010010110010" }

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
