#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <ctime>
//#include <windows.h>
using namespace std;

#define cl system("cls")

// Headers------------------------------------------------------------------------

void cls()
{
    cl;
    cout << "-----Welcome to M.P.S.E.-----\n\n";
}

char key()
{
    char c;
    while (true)
    {
        if (_kbhit())
        {
            c = _getch();
            cls();
            break;
        }
    }
    return c;
}

// Clothes constants
enum types
{
    Shirt,
    Jacket,
    Tshirt,
    Pants,
    Shorts
};
string materials[] = {"Cotton", "Wool", "Polyester", "Silk"};
string sizes[] = {"S", "M", "L", "Xl", "XXl"};
string sections[] = {"Men", "Women"};

// Shirt constants
string shirt_types[] = {"Formal", "Casual", "School"};

// Jacket constants
string jacket_types[] = {"Pump", "Baseball", "Leather"};

// tshirt constants
string tshirt_types[] = {"House", "Sleeping", "Sports"};
string sleeves[] = {"Cut", "Half-sleeves", "Full-sleeves"};

// pants constants
string pants_types[] = {"Cargo", "Jeans", "Formal", "Melton", "Sports"};
string closing_types[] = {"Button", "Zipper", "Tie"};

class clothes
{
protected:
    types type;
    string brand;
    string material;
    string size;
    string color;
    string section;
    int serial;
    int price;
    int points;
    static int count;

public:
    virtual void get_type_data() = 0;
    virtual void show_type_data() = 0;

    void set_type(char);
    types get_type();
    void get_data();
    void show_data();

    int get_pts();
};

class shirt : public clothes
{
private:
    string shirt_type;
    int number_of_buttons;

public:
    void get_type_data();
    void show_type_data();
};

class jacket : public clothes
{
private:
    string jacket_type;

public:
    void get_type_data();
    void show_type_data();
};

class tshirt : public clothes
{
private:
    string tshirt_type;
    string sleeves_type;

public:
    void get_type_data();
    void show_type_data();
};

class pants : public clothes
{
private:
    string pants_type;
    string closing_type;

public:
    void get_type_data();
    void show_type_data();
};

class shorts : public pants
{
};

// Functions---------------------------------------------------------------------------

#define prtl cout << endl

// static member initialize
int clothes::count = 0;

// Clothes functions
void clothes::get_data()
{
    cout << "Brand : ";
    cin >> brand;

    cout << "Material : ";
    cin >> material;

    cout << "Size : ";
    cin >> size;

    cout << "Color : ";
    cin >> color;

    cout << "Section : ";
    cin >> section;

    this->get_type_data();

    cout << "Points : ";
    cin >> points;

    cout << "Price : ";
    cin >> price;
}

void clothes::show_data()
{
    cout << "-----------------------------\n-";
    cout << type << " Information\n";

    cout << "Brand : " << brand;
    prtl;

    cout << "Material : " << material;
    prtl;

    cout << "Size : " << size;
    prtl;

    cout << "Color : " << color;
    prtl;

    cout << "Section : " << section;
    prtl;

    cout << "Serial no. : " << serial;
    prtl;

    show_type_data();

    cout << "Points : " << points;
    prtl;

    cout << "Price : " << price;
    prtl;
}

int clothes::get_pts()
{
    return points;
}

void clothes::set_type(char c)
{
    switch (c)
    {
        case '1':
            type = Shirt;
            break;

        case '2':
            type = Jacket;
            break;

        case '3':
            type = Tshirt;
            break;

        case '4':
            type = Pants;
            break;

        case '5':
            type = Shorts;
            break;

        default:
            break;
    }
}

types clothes::get_type()
{
    return type;
}

// Shirt functions
void shirt::get_type_data()
{
    cout << "Shirt type : ";
    cin >> shirt_type;

    cout << "Number of buttons : ";
    cin >> number_of_buttons;
}

void shirt::show_type_data()
{
    cout << "Shirt type : " << shirt_type;
    prtl;

    cout << "Number of buttons : " << number_of_buttons;
    prtl;
}

// Jacket functions
void jacket::get_type_data()
{
    cout << "Jacket type : ";
    cin >> jacket_type;
}

void jacket::show_type_data()
{
    cout << "Jacket type : " << jacket_type;
    prtl;
}

// Tshirt functions
void tshirt::get_type_data()
{
    cout << "Tshirt type : ";
    cin >> tshirt_type;

    cout << "Sleeves type : ";
    cin >> sleeves_type;
}

void tshirt::show_type_data()
{
    cout << "Tshirt type : " << tshirt_type;
    prtl;

    cout << "Sleeves type : " << sleeves_type;
    prtl;
}

// Pants functions
void pants::get_type_data()
{
    cout << "pants type : ";
    cin >> pants_type;

    cout << "Closing type : ";
    cin >> closing_type;
}

void pants::show_type_data()
{
    cout << "Pants type : " << pants_type;
    prtl;

    cout << "Closing type : " << closing_type;
    prtl;
}

// User class ---------------------------------------------------------------------------------------------
class user
{
private:
    string name;
    int number_of_clothes;
    int score;
    vector<clothes *> owned;

public:
    user();

    void set_name(string);
    string get_name();
    void add_product(clothes *product);
    void show_products();
    void delete_product(int);
    void show_user_data();
};

// user functions
user::user() : name("New user"), number_of_clothes(0), score(0) {}

void user::set_name(string input)
{
    name = input;
}

string user::get_name()
{
    return name;
}

void user::add_product(clothes *product)
{
    owned.emplace_back(product);
    number_of_clothes++;
    score += product->get_pts();
}

void user::show_products()
{
    for (auto i : owned)
    {
        i->show_data();
    }
}

void user::delete_product(int index)
{
    score -= owned[index]->get_pts();
    owned.erase(owned.begin() + index);
    number_of_clothes--;
}

void user::show_user_data()
{
    cout << "----------User Data----------\n\n";

    cout << "Name : " << name;
    prtl;

    cout << "Number of clothes : " << number_of_clothes;
    prtl;

    cout << "Score : " << score;
    prtl;

    cout << "----------Owned clothes----------\n";
    show_products();
}

// Shop class------------------------------------------------------------------------------

class shop
{
private:
    int number_of_products;
    int number_of_users;

    string password;

    vector<user> users;
    vector<clothes *> products;

    bool check_username(string);

public:
    shop();

    void add_product();
    void add_user();
    void show_products();
    bool check_password(string);
    void change_password(string);
    vector<user> get_users();
    vector<clothes *> get_products();
};

shop::shop() : number_of_products(0), number_of_users(0), password("admin") {}

vector<clothes *> shop::get_products()
{
    return products;
}

void shop::show_products()
{
    for (int i = 1, end = products.size() + 1; i < end; i++)
    {
        cout << i << "-";
        products[i]->show_data();
        prtl;
    }
}

bool shop::check_username(string input)
{
    for (auto i : users)
    {
        if (input == i.get_name())
        {
            return true;
        }
    }
    return false;
}

void shop::add_product()
{
    clothes *temp;
    char choice;

    cls();
    cout << "1-Shirt\n2-Jacket\n3-Tshirt\n4-Pants\n5-Shorts\n";
    while (true)
    {
        if(_kbhit())
        {
            choice = _getch();
            cls();
            break;
        }
    }
    if (choice > '5' && choice < '1')
    {
        add_product();
    }
    else
    {
        temp->set_type(choice);

        switch (temp->get_type())
        {
            case Shirt:
            {
                shirt st;
                temp = &st;
                break;
            }

            case Tshirt:
            {
                tshirt tst;
                temp = &tst;
                break;
            }

            case Jacket:
            {
                jacket jt;
                temp = &jt;
                break;
            }

            case Pants:
            {
                pants tst;
                temp = &tst;
                break;
            }

            case Shorts:
            {
                shorts tst;
                temp = &tst;
                break;
            }
        }

        temp->get_data();
        products.emplace_back(temp);
    }

}

void shop::add_user()
{
    user temp;
    string input;
    cout << "Enter your name : ";
    cin >> input;

    if (check_username(input))
    {
        cls();
        cout << "User name is used\n";
        add_user();
    }
    else
    {
        temp.set_name(input);
        users.emplace_back(temp);
        cls();
        cout << "User has been added\n\n";
    }
}

bool shop::check_password(string s)
{
    if (s == password)
        return true;
    return false;
}

void shop::change_password(string s)
{
    password = s;
}

 class interface
 {
 private:
     shop shop1;

 public:
     void shop_page();
     void user_page(user);
     void user_page();
     void add_user_page();
     void main_page();
 };

 void interface::main_page()
 {
     char c;

     cls();
     cout << "1-Shop data\n2-User data\n3-New user\n4-Exit";

     c = key();

     switch (c) {
         case '1': {
             shop_page();
             break;
         }

         case '2': {
             user_page();
             break;
         }

         case '3': {
             add_user_page();
             break;
         }

         case '4': {
             return;
         }

         default: {
             cout << "----Invalid input----\n";
             main_page();
         }
     }
 }

vector<user> shop::get_users()
{
     return users;
}

 void interface::shop_page()
 {
//     cls();
     cout << "Enter password";
     string password;
     cin >> password;

     if (shop1.check_password(password))
     {
         char c;
         cout << "1-Add product\n2-Show products\n3-Change password\n4-Return to main page\n";

         c = key();

         switch(c)
         {
             case '1':
             {
                 shop1.add_product();
                 break;
             }

             case '2':
             {
                 shop1.show_products();
                 cout << "\nHit any key to back to shop page\n";
                 if (key())
                 {
                     shop_page();
                 }
                 break;
             }

             case '3':
             {
                 string new_pass;
                 cout << "Enter new password : ";
                 cin >> new_pass;
                 shop1.change_password(new_pass);
                 cls();
                 shop_page();
                 break;
             }

             case '4':
             {
                 cls();
                 main_page();
                 break;
             }

             default:
             {
                 cls();
                 cout << "Invalid input\n\n";
                 shop_page();
                 break;
             }
         }
     }
     else
     {
         cls();
         cout << "Wrong password\n\n";
         shop_page();
     }
 }

 void interface::user_page(user u)
 {
     char c;
     cout << "1-Show user data\n2-add product\n3-return to main page\n";

     c = key();

     switch (c)
     {
         case '1':
         {
             u.show_user_data();
             cout << "\nHit any key to return to user page\n";
             if (key())
             {
                 user_page(u);
             }
             break;
         }

         case '2':
         {
             int n;
             shop1.show_products();
             cout << "Enter product number : ";
             cin >> n;

             u.add_product(shop1.get_products()[n - 1]);

             cls();
             user_page(u);
             break;
         }

         case '3':
         {
             cls();
             main_page();
             break;
         }

         default:
         {
             cls();
             cout << "Invalid input\n\n";
             user_page(u);
         }
     }
 }

void interface::user_page()
{
     vector<user> users = shop1.get_users();

     string name;
     cout << "Enter user name : ";
     cin >> name;

     for (auto u : users)
     {
         if (u.get_name() == name)
         {
             user_page(u);
             return;
         }
     }
     cls();
     cout << "User doesn\'t exist\n\n";
     main_page();
}

void interface::add_user_page()
{
     shop1.add_user();
     main_page();
}


int main()
{
    interface prog1;
    prog1.main_page();
}