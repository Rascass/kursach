//
//  utils.h
//  AlexSavchuk
//
//  Created by Яна Антонюк on 5/16/20.
//  Copyright © 2020 Яна Антонюк. All rights reserved.
//

#ifndef utils_h
#define utils_h
#include <chrono>
#include <random>
using namespace std;
struct RandomInt
{
    std::mt19937 gen;
    RandomInt():gen(time(0)){}
    int operator()(int start, int end)
    {
         std::uniform_int_distribution<> uid(start, end);
        return uid(gen);
    }
} randomInt;
struct Pair
{
    int number = 0;
    bool isChecked = false;
};
class Card
{
public:
    Pair store[3][5];
    bool isField = false;
    int find(int num)
    {
        for (int i = 0; i < 15; i++) {
            if (store[0][i].number == num)
            {
                return i;
            }
        }
        return -1;
    }
    Card()
       {
           for (int i = 0; i < 3; i++) {
               for (int j = 0; j < 5; j++) {
                   int temp = randomInt(1, 90);
                   if (find(temp) == -1) {
                       store[i][j].number = temp;
                   }
                   else
                   {
                       --j;
                   }
               }
           }
       }
    void print()
    {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 5; j++) {
                cout<<store[i][j].number<<' '<<store[i][j].isChecked<<' ';
            }
            cout<<endl;
        }
    }
    void checkIsField()
    {
         isField = std::all_of(store[0], store[0] + 15, [](Pair pair){ return pair.isChecked; });
    }
    void setKeg(int keg)
    {
        int i = find(keg);
        if (i != -1) {
            store[0][i].isChecked = true;
        }
        checkIsField();
        print();
    }
};
#endif /* utils_h */
