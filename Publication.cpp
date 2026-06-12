#include <iostream>
#include <string>
using namespace std;

class Publication
{
protected:
    string title;
    float price;

public:
    void getdata()
    {
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);

        cout << "Enter price: ";
        cin >> price;
    }

    void putdata()
    {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

class Book : public Publication
{
private:
    int pageCount;

public:
    void getdata()
    {
        Publication::getdata();

        cout << "Enter page count: ";
        cin >> pageCount;
    }

    void putdata()
    {
        Publication::putdata();
        cout << "Page Count: " << pageCount << endl;
    }
};

class Tape : public Publication
{
private:
    float playingTime;

public:
    void getdata()
    {
        Publication::getdata();

        cout << "Enter playing time (in minutes): ";
        cin >> playingTime;
    }

    void putdata()
    {
        Publication::putdata();
        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }
};

int main()
{
    Book b;
    Tape t;

    cout << "Enter details for book:" << endl;
    b.getdata();

    cout << endl;

    cout << "Enter details for tape:" << endl;
    t.getdata();

    cout << endl;

    cout << "Book Details:" << endl;
    b.putdata();

    cout << endl;

    cout << "Tape Details:" << endl;
    t.putdata();

    return 0;
}