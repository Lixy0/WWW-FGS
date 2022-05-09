#include <fstream>
#include <string>
#include <iostream>

using std::ifstream;
using std::string;

using namespace std;

struct Page
{
    string val;
    Page* suivant;
};


Page* creerliste()
{
    ifstream entree("wildwildwestlyrics.txt");
    string i;
    Page* premier;
    Page* precedent;
    Page* nouveau;

    premier = new Page;
    entree >> premier->val;
    precedent = premier;
    while (entree >> i)
    {
        nouveau = new Page;
        precedent->suivant = nouveau;
        precedent = nouveau;
        nouveau->val = i;
    }
    precedent->suivant = 0;

    return premier;
}

void compare(Page* debut)
{
    int i = 0;
    ifstream ifs("wildwildwestlyrics.txt");
    string s;
    Page* head = debut;

    while (ifs >> s)
    {
        debut = head;
        while (debut != 0)
        {
            if (s == debut->val)
                i = i + 1;
            debut = debut->suivant;
        }

        cout << "le nombre d'occurence du mot " << s << " est " << i << endl;
        i = 0;
    }
}

int main()
{
    Page* premier = creerliste();
    compare(premier);
    system("pause");
    return 0;
}