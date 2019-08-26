/*
 * This C++ source file was generated by the Gradle 'init' task.
 */

#include "taxes-library.h"
#include <cassert>

int main() {
    ShoppingItem item1(Shopping::TYPE_BOOK,false,12.49,"book",1); // book
    ShoppingItem item2(Shopping::TYPE_OTHER,false,14.99,"music CD", 1); // music CD
    ShoppingItem item3(Shopping::TYPE_FOOD,false,0.85, "chocolate bar",1); // chocolate bar

    ShoppingItem item4(Shopping::TYPE_FOOD,true,10.00,"box of chocolates",1);
    ShoppingItem item5(Shopping::TYPE_OTHER,true,47.50,"bottle of perfume",1);

    ShoppingItem item6(Shopping::TYPE_OTHER,true,27.99,"bottle of perfume",1);
    ShoppingItem item7(Shopping::TYPE_OTHER,false,18.99,"bottle of perfume",1);
    ShoppingItem item8(Shopping::TYPE_MEDICAL,false,9.75,"packet of headache pills",1);
    ShoppingItem item9(Shopping::TYPE_FOOD,true,11.25,"box of chocolates",1);

    std::vector<ShoppingItem> listaItemsExample;

    // TEST 1
    listaItemsExample.clear();
    listaItemsExample.push_back(item1);
    listaItemsExample.push_back(item2);
    listaItemsExample.push_back(item3);
    ext_executeTest(listaItemsExample, "Test1");

    // TEST 2
    listaItemsExample.clear();
    listaItemsExample.push_back(item4);
    listaItemsExample.push_back(item5);
    ext_executeTest(listaItemsExample, "Test2");

    // TEST 3
    listaItemsExample.clear();
    listaItemsExample.push_back(item6);
    listaItemsExample.push_back(item7);
    listaItemsExample.push_back(item8);
    listaItemsExample.push_back(item9);
    ext_executeTest(listaItemsExample,"Test3");

    return 0;
}
