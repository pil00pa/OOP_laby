#include "System.h"
#include "Product.h"
#include <sstream>

Product& System::getProductByName(string name)
{
    // TODO: insert return statement here
    
    for (int i = 0; i < Market.size(); i++) {
        Product current(Market[i]);
        if (current.getName() == name) {
            return current;
        }
    }
}

User& System::getUserByPhone(int phone)
{
    for (auto i =UserBase.begin(); i != UserBase.end(); i++) {
        User current(*i);
        if (current.getPhone() == phone) {
            return current;
        }
    }
}

System::System(string MarketPath, vector<string> UserBasePath)
{
    //UserBase
    int length = UserBasePath.size();
    for (int i = 0; i < length; i++)
    {
        UserBase.push_back(User(UserBasePath[i]));
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
        float price;
        float discount;
        buffer = "";

        getline(inputString, name, ',');

        getline(inputString, buffer, ',');
        price = atof(buffer.c_str());
        buffer = "";

        getline(inputString, buffer, ',');
        discount = atof(buffer.c_str());
        buffer = "";

        Product TempProduct(name, price, discount);
        Market.push_back(TempProduct);
        line = "";
    }
    InputFile.close();
}