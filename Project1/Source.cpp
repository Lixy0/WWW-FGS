#include <string>
#include <fstream>
#include <string>
#include <iostream>
#include <map>


using std::ifstream;

using namespace std;

/* //--- TEST ---//
* 
#include <fstream>


size_t countOccurrences(char c, string& str)
{
    size_t count = 0;
    char tmp = static_cast<char>(tolower(static_cast<unsigned char>(c)));

    for (char i : str)
        if (tolower(static_cast<unsigned char>(i)) == tmp)
            count++;

    return count;
}


int main() {

    fstream lyrics;
    lyrics.open("wildwildwestlyrics.txt");

    char ch1 = 'w';
    string str1(lyrics);

    cout << "number of character - '" << ch1 << "' occurrences = " << countOccurrences(ch1, str1) << endl;

    exit(EXIT_SUCCESS);
}
*
* 
*/



int main()
{
ifstream ifs("wildwildwestlyrics.txt");
string s;
map<string, int> map;

while (ifs >> s)
++map[s];

typedef std::map<std::string, int>::const_iterator iter;
for (iter it = map.begin(); it != map.end(); ++it)
std::cout << "le nombre d'occurence du mot " << it->first << " est " << it->second << std::endl;

return 0;
}