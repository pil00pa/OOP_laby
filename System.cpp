#include "System.h"
#include "Product.h"
#include "User.h"
#include <sstream>
#include <algorithm>

using namespace std;

SocialGroup System::findUserGroup(User u)
{
    list<Product> sList = u.getShoppingList();
    int quantityOfForLower = 0, quantityOfForMiddle = 0, quantityOfforUpper = 0;

    for (auto i = sList.begin(); i != sList.end(); i++)
    {
        switch ((*i).getCategory())
        {
            case 0:
                quantityOfForLower++;
                break;
            case 1:
                quantityOfForMiddle++;
                break;
            case 2:
                quantityOfforUpper++;
                break;
            default:
                break;
        }
    }

    int maxQuantity = max(quantityOfForLower, max(quantityOfForMiddle, quantityOfforUpper));

    if (maxQuantity == quantityOfForLower) { return Lower; }
    if (maxQuantity == quantityOfForLower) { return Middle; }
    if (maxQuantity == quantityOfForLower) { return Upper; }
}

System::System()
{
}

System::System(string MarketPath, vector<string> UserBasePath)
{
    //UserBase
    int length = UserBasePath.size();
    for (int i = 0; i < length; i++)
    {
        addUser(User(UserBasePath[i]));
    }
    //Market
    ifstream InputFile;
    InputFile.open(MarketPath);
    string line = "";
    string buffer = "";
    while (getline(InputFile, line))
    {
        stringstream inputString(line);
        string name;
        int id;
        float price;
        float discount;
        Category category;

        buffer = "";

        // name
        getline(inputString, name, ',');
        // id
        getline(inputString, buffer, ',');
        id = atoi(buffer.c_str());
        buffer = "";
        // price
        getline(inputString, buffer, ',');
        price = atof(buffer.c_str());
        buffer = "";
        // discount
        getline(inputString, buffer, ',');
        discount = atof(buffer.c_str());
        buffer = "";
        // category
        getline(inputString, buffer, ',');
        category = Category(atoi(buffer.c_str()));
        buffer = "";
        
        Product TempProduct(name, id, price, discount, category);
        _Market.insert(pair<int, Product>(id, TempProduct));
        line = "";
    }
    InputFile.close();
}

System& System::addProduct(const Product p)
{
    _Market.insert(pair<int, Product>(p.getId(), p));

    return *this;
}

Product& System::getProductById(int id)
{
    return _Market.at(id);
}

System& System::addUser(const User u)
{
	switch (findUserGroup(u))
	{
		case Lower: // new user belongs to lower class
            _UserBase.insert(pair<int, User*>(u.getPhone(), new LowerClass(u)));
			break;
		case Middle:                    // middle class
            _UserBase.insert(pair<int, User*>(u.getPhone(), new MiddleClass(u)));
			break;
		case Upper:                     // upper class
            _UserBase.insert(pair<int, User*>(u.getPhone(), new UpperClass(u)));
			break;
        default:
            break;
	}	

    list<Product> uShopList = u.getShoppingList();
    for (auto i = uShopList.begin(); i != uShopList.end(); i++)
    {
        _Market.insert(pair<int, Product>(i->getId(), *i));
    }

    return *this;
}

vector<User> System::getLowerClass() const
{
    return {};
}
vector<User> System::getMiddleClass() const
{
    return {};
}
vector<User> System::getUpperClass() const
{
    return {};
}

vector<Product> System::getPopularProductForLower() const
{
    return {};
}
vector<Product> System::getPopularProductForMiddle() const
{
    return {};
}
vector<Product> System::getPopularProductForUpper() const
{
    return {};
}

User& System::getUserByPhone(int phone)
{
    return *(_UserBase.at(phone));
}

vector<Product> System::getProductsByPopularity() const
{
    return {};
}

void System::getSocialGroups() const
{

}

System::~System()
{
    for (auto i = _UserBase.begin(); i != _UserBase.end(); i++)
    {
        delete i->second;
    }
}