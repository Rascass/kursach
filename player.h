//
//  player.h
//  AlexSavchuk
//
//  Created by Яна Антонюк on 5/16/20.
//  Copyright © 2020 Яна Антонюк. All rights reserved.
//

#ifndef player_h
#define player_h
using namespace std;
class Player
{
public:
    std::vector<Card> cards;
    int m_score = 0;
    string m_name = "";
    void getKeg(int keg)
    {
        for (int i = 0; i < cards.size(); ++i) {
            cards[i].setKeg(keg);
        }
    }
    Player() = default;
    Player(int score, int numCards, string name):m_score(score), m_name(name){
        for (int i = 0; i < numCards; ++i) {
            cards.push_back(Card());
        }
    }
    void show()
    {
        for (auto i = cards.begin(); i < cards.end(); ++i) {
            i->print();
            cout<<"*******************************"<<endl;
        }
    }
    bool isFieldCards()
    {
        for (auto i = cards.begin(); i < cards.end(); ++i)
        {
            if(!(i->isField))
            {
                return false;
            }
        }
        return true;
    }
};
#endif /* player_h */
