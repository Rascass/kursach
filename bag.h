//
//  bag.h
//  AlexSavchuk
//
//  Created by Яна Антонюк on 5/17/20.
//  Copyright © 2020 Яна Антонюк. All rights reserved.
//

#ifndef bag_h
#define bag_h
class Bag
{
    struct {
        int value = 0;
        int operator()()
        {
            ++value;
            return value;
        }
    }gen;
    int turn = 0;
public:
    std::array<int, 90> store;
    Bag()
    {
        std::generate(store.begin(), store.end(), gen);
        //std::for_each(store.begin(), store.end(), [](int a){std::cout<<a<<' ';});
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(store.begin(), store.end(), g);
        //std::for_each(store.begin(), store.end(), [](int a){std::cout<<a<<' ';});
    }
    int getNext()
    {
        if(turn > 90)
        {
            throw 4;
        }
        return store[turn++];
    }
};

#endif /* bag_h */
