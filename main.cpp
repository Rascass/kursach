#include <iostream>
#include <fstream>
#include "utils.h"
#include <algorithm>
#include <vector>
#include "player.h"
#include <array>
#include "bag.h"
//Реализовывать: игру по правилам русского лото с бочонками, фишками и картами с рандомными числами; обеспечить игру от
//2 до 8 игроков, каждый из которых получает по 1-2 карте с рандомно сгенерированными
//числами и рандомно раздаваемыми программой фишками; обеспечить рандомную
//генерацию значения «вытаскиваемого» игроком бочонка со значением в диапазоне от 1 до 90
//и блокировку повторной генерации данного числа в текущей игровой партии; реализовать
//карты для игроков с пустыми и рандомно заполненными ячейками со значениями от 1 до 90;
//формирование общего суммарного рейтинга игроков за все сыгранные ими игры.
using namespace std;

class Game
{
public:
    vector<Player> players;
    vector<Player> winners;
    int m_numCards = 1;
    Bag bag;
    Game() = default;
    Game(int numPlayers, int numCards){
        for (int i = 0; i < numPlayers; ++i) {
            players.push_back(Player(0, numCards, ""));
        }
    }
    Game(int numCards):m_numCards(numCards){}
    void addPlayer(const Player& player)
    {
        players.push_back(player);
    }
    bool turn(){
        int keg = bag.getNext();
        for (auto i = players.begin(); i != players.end(); ++i) {
            i->getKeg(keg);
        }
       for (auto i = players.begin(); i != players.end(); ++i) {
            if(i->isFieldCards())
            {
                winners.push_back(*i);
            }
        }
        return winners.size() == 0;
    }
};
int main(int argc, const char * argv[])
{
    Player p1(0, 2, "Kevin");
    Player p2(0, 2, "Claris");
    Game game(2);
    game.addPlayer(p1);
    game.addPlayer(p2);
    for (; game.turn();) {
    }
    cout<<game.winners[0].m_name;
    return 0;
}
