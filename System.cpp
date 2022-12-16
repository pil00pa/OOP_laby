#include "System.h"

Product& System::GetProductByName(string name)
{
    // TODO: insert return statement here
    
    for (int i = 0; i < Market.size(); i++) {
        Product current(Market[i]);
        if (current.GetName() == name) {
            return current;
        }
    }
}

User& System::GetUserByPhone(int phone)
{
    for (int i = 0; i < UserBase.size(); i++) {
        User current(UserBase[i]);
        if (current.GetPhone() == phone) {
            return current;
        }
    }
}
