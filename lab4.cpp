#include <iostream>
using namespace std;

template < typename T >
class Para
{
public:
    Para(T a, T b) : e1{a}, e2{b} {}
    T getPzPara() { return e1; }
    T getDzPara() { return e2; }
    T suma() { return e1 + e2; }

private:
    T e1, e2;
};

int main()
{
    Para< double > ObiektKlasyParaD(1.23, 5.12);
    cout << ObiektKlasyParaD.getPzPara() << " " << ObiektKlasyParaD.getDzPara()
         << " suma=" << ObiektKlasyParaD.suma() << endl;

    Para< int > ObiektKlasyParaI(3, 5);
    cout << ObiektKlasyParaI.getPzPara() << " " << ObiektKlasyParaI.getDzPara()
         << " suma=" << ObiektKlasyParaI.suma() << endl;

    Para< string > ObiektKlasyParaS("a", "c");
    cout << ObiektKlasyParaS.getPzPara() << " " << ObiektKlasyParaS.getDzPara()
         << " suma=" << ObiektKlasyParaS.suma() << endl;
}
