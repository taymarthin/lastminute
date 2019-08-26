#ifndef SHOPPINGITEM_H
#define SHOPPINGITEM_H

#include <iostream>
#include "definitions.h"
#include <cmath>

class ShoppingItem
{
public:
    ShoppingItem( Shopping::ItemType iType = Shopping::TYPE_OTHER,
                  bool iImported = false,
                  double iBasicPrice = 0.0,
                  std::string iDescription = "",
                  unsigned int iNum = 1) {
        type = iType;
        imported = iImported;
        basicPrice = iBasicPrice;
        description = iDescription;
        numberOfItems = iNum;

        updateTotalAmount(); // initialize amountTaxes and totalPrice variable members
    }

    void setType(Shopping::ItemType iType) { type = iType; updateTotalAmount(); }
    Shopping::ItemType getType() { return type; }

    void setImported(bool iImported) { imported = iImported; updateTotalAmount(); }
    bool getImported() { return imported; }

    void setBasicPrice(double iPrice) { basicPrice = iPrice; updateTotalAmount(); }
    double getBasicPrice() { return basicPrice; }

    void setDescription(std::string iDesc) { description = iDesc; }
    std::string getDescription() { return description; }

    void setNumberOfItems(unsigned int iNum) { numberOfItems = iNum; }
    unsigned int getNumberOfItems() { return numberOfItems; }

    double getAmountTaxes() { return amountTaxes; }

    double getTotalAmount() { return totalPrice; }

private:
    Shopping::ItemType type;
    bool imported;
    double basicPrice;
    double amountTaxes;
    double totalPrice;
    std::string description;
    unsigned int numberOfItems;

    void updateTotalAmount()
    {
        double taxesPercentage = 0.1; // taxes at 10% on all goods

        if ( type==Shopping::TYPE_BOOK ||
             type==Shopping::TYPE_FOOD ||
             type==Shopping::TYPE_MEDICAL )
            taxesPercentage = 0.0; // exempt

        if (imported)
            taxesPercentage += 0.05; // additional tax at 5%

        double taxes = taxesPercentage;
        amountTaxes =  roundTaxes(basicPrice*taxes);

        totalPrice = basicPrice + amountTaxes;
    }

    double roundTaxes(double iTax) {
        return (0.05*ceil(iTax*20));
    }
};

#endif // SHOPPINGITEM_H
