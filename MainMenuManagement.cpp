//
// Created by user on 6/25/2021.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <windows.h>
#include <tuple>
#include <map>
#include <cmath>

using namespace std;

#include "StorageManagement.h"
#include "MainMenuManagement.h"
#include "ConvertionsSystem.h"

string trim(string str) {
  string chars = "\t\n\v\f\r ";
  str.erase(0, str.find_first_not_of(chars));
  str.erase(str.find_last_not_of(chars) + 1);
  return str;
}

string RepeatChar(int Times, char value) {
  string v = "";
  for (int i = 0; i < Times; i++) {
    v += value;
  }
  return trim(v);
}

string RepeatString(int Times, string value) {
  string v = "";
  for (int i = 0; i < Times; i++) {
    v += value;
  }
  return trim(v);
}

string RepeatBreaksChar(int Times, char value, char BreakChar, int BreakEvery) {
  string v;
  for (int i = 1; i < Times; i++) {
    if (i % BreakEvery == 0) {
      v += BreakChar;
    } else {
      v += value;
    }
  }
  return v;
}

void TheShow(const string Text) {
  char Zero = '0';
  cout << '+' << RepeatChar(46, '-') << '+' << endl;
  cout << '|' << setw(47) << '|' << endl;
  cout << '|' << setw(18 - (Text.length() / 4)) << "";
  cout << Text;
  cout << setw(47 - (18 - (Text.length() / 4) + Text.length())) << '|' << endl;
  cout << '|' << setw(47) << '|' << endl;
  cout << '+' << RepeatChar(46, '-') << '+' << endl;
}

void printMenu(int numberOfRaw, int numberOfColumns) {
    vector<string> names = getProductsName();
    vector<double> prices = getProductsPrice();
    vector<int> quantities = getProductsQuantity();
    vector<int> ides = getProductsId();

    /*for(auto x:names)
        cout << x << endl;
    cout << endl<<endl;

    for(auto x:prices)
        cout << x << endl;
    cout << endl<<endl;

    for(auto x:quantities)
        cout << x << endl;*/

    //cout << prices[0] << endl << endl;

    int highestLen=0;
    for (auto name:names)
        if(name.size() > highestLen) highestLen = name.size();

    cout << "ID" << setw(10) << "Product" << setw(highestLen) << "Price" << setw(15) << "Quantity" << endl; // Header

    for(int i = 0; i < names.size(); i++){
        cout << left << ides[i] << right << setw(3+names[i].size());
        cout << trim(names[i]) << setw(37-names[i].size());

        if(numToStr(prices[i]).size() <= 3){
           cout << numToStr(prices[i])+'0' << setw(13);
        }else{
           cout << numToStr(prices[i]) << setw(13);
        }

        cout<< numToStr(quantities[i]) << endl;
    }

    //cout << highestLen;
}

int casher(){
    vector<tuple<int, string, double, int>> storage = getStorage();
    int selectedId=0;

    cout << "Please Type Id of Product To Select it: ";
    cin >> selectedId;

    cout << get<0>(getProductNameById(selectedId));

    char addToCart;
    //cout << "Add To Cart (y or n): ";
    //cin >> addToCart;

// FIXME (user#1#06/28/21): how we do decress the quantity


    return 0;
}

int initlize(){
    TheShow("SuperMarket");
    Sleep(2000);
    printMenu(1,0);
    casher();
    return 0;
}





