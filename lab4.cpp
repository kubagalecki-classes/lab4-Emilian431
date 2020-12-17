#include <iostream>
using namespace std;

// zad 1,2
template < typename T >
class Para
{
public:
    Para()
    {
        e1 = 0;
        e2 = 0;
    }
    Para(T a, T b) : e1{a}, e2{b} {}
    T getPzPara() { return e1; }
    T getDzPara() { return e2; }
    T suma() { return e1 + e2; }

private:
    T e1, e2;
};

// zad 3,4
template < typename T, unsigned int n >
class TablicaPar
{
public:
    TablicaPar() {}
    Para< T >  tablica[n]; // public aby byl dostep w int main()
    Para< T >& operator[](int i) { return tablica[i]; }
    Para< T >  get_el(unsigned int i) { return tablica[i]; }
    void       set_el(int i, Para< T > p) { tablica[i] = p; }
};

// zad 6
template < typename T >
struct S
{
    void print() { puts("Szablon ogólny"); }
};

template <>
struct S< double >
{
    void print() { puts("Specjalizacja dla double"); }
};

// zad 7
template < typename T >
class TablicaPar< T, 0 >
{
public:
    TablicaPar() { puts("Tablica jest pusta"); }
};

// zad 8
template < typename T >
T Iloczyn(T tab[], int n)
{
    T Iloczyn = tab[0];
    for (int i = 0; i < n; i++) {
        Iloczyn = Iloczyn * tab[i];
    }
    return Iloczyn;
}

// zad 9
template < typename T >
T SumaPary(Para< T > para)
{
    T SumaPary = para.suma();
    return SumaPary;
}

int main()
{
    // zad 1,2
    Para< double > ObiektKlasyParaD(1.23, 5.12);
    cout << "Element pierwszy: " << ObiektKlasyParaD.getPzPara()
         << " Element drugi: " << ObiektKlasyParaD.getDzPara()
         << " suma= " << ObiektKlasyParaD.suma() << endl;

    Para< int > ObiektKlasyParaI(3, 5);
    cout << "Element pierwszy: " << ObiektKlasyParaI.getPzPara()
         << " Element drugi: " << ObiektKlasyParaI.getDzPara()
         << " suma= " << ObiektKlasyParaI.suma() << endl;

    Para< string > ObiektKlasyParaS("a", "c");
    cout << "Element pierwszy: " << ObiektKlasyParaS.getPzPara()
         << " Element drugi: " << ObiektKlasyParaS.getDzPara()
         << " suma= " << ObiektKlasyParaS.suma() << endl;
    TablicaPar< double, 3 > tab;
    cout << sizeof(tab.tablica) << endl;
    Para< double > p1{1.2, 2.3}, p2{2.4, 4.1}, p3{5.1, 9.1};
    tab[0]     = p1;
    tab[1]     = p2;
    tab[2]     = p3;
    double sum = 0;
    for (int i = 0; i < 3; ++i) {
        cout << tab[i].getPzPara() << " " << tab[i].getDzPara() << " suma=" << tab[i].suma()
             << endl;
        sum += tab[i].suma();
    }
    cout << sum << endl;

    TablicaPar< int, 3 > tab1;
    cout << sizeof(tab1.tablica) << endl;
    Para< int > c1{1, 2}, c2{2, 4}, c3{5, 9};
    tab1[0]     = c1;
    tab1[1]     = c2;
    tab1[2]     = c3;
    double sumi = 0;
    for (int i = 0; i < 3; ++i) {
        cout << tab1[i].getPzPara() << " " << tab1[i].getDzPara() << " suma=" << tab1[i].suma()
             << endl;
        sumi += tab1[i].suma();
    }
    cout << sumi << endl;
    /*tab.set_el(0, p1);
    tab.set_el(1, p2);
    tab.set_el(2, p3);
    for (int i = 0; i < 3; ++i) {
        cout << tab.get_el(i).getPzPara() << " " << tab.get_el(i).getDzPara() << endl;
    }*/

    // zad 6
    S< int >    asd;
    S< double > sdf;
    asd.print();
    sdf.print();
    // zad 7
    TablicaPar< double, 0 > pusta;
    TablicaPar< int, 0 >    pustatablica;
    // zad 8
    int tablica[] = {1, 2, 3, 4, 5};
    int silnia5   = Iloczyn(tablica, 5);
    cout << "Iloczyn=" << silnia5 << endl;
    // zad 9
    Para tablicas1{1, 2}, tablicas2{3, 6};
    int  sumapary = SumaPary(tablicas1);
    cout << sumapary << endl;
    cout << SumaPary(tablicas2) << endl;
}
