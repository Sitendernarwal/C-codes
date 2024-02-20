#include <iostream>
using namespace std;

class Hero
{

private:
    int damage = 20;

public: // this is a access modifires.
    static int time_out;
    string name;
    int health;
    char level;
    // Getter
    int getDamage()
    {
        return damage;
    }
    // setter
    void setDamage(int dmg)
    {
        this->damage = dmg;
    }
    void print()
    {
        cout << this->name << endl;
        cout << this->health << endl;
        cout << this->level << endl;
        cout << this->getDamage() << endl;
    }
};

class IronMan : public Hero
{
public:
    IronMan()
    {
        this->name = "Iron_Man";
        this->setDamage(1000);
        this->health = 100;
        this->level = 'A';
    }
};
int Hero::time_out = 10;
int main()
{ /*
      static value class se belong krti hai object se nhi to ise hm bina object bnaye bhi access kr skte hai.
  */
    cout << Hero::time_out << endl;
    // Hero h1; // hero type ka object
    // h1.health = 1000;
    // h1.level = 'A';
    // cout << h1.health << " " << h1.level << endl;

    IronMan mark1;
    mark1.print();

    return 0;
}