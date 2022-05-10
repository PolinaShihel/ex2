//
// Created by Daniel_Meents on 07/04/2022.
//

#ifndef EX2_GAME_H
#define EX2_GAME_H
#include "Card.h"
#include <iostream>

/*
 * GameStatus:
 * MidGame - The game is still active and the player continues to encounter cards.
 * Win - The player reached level 10.
 * Loss - The player's HP is 0.
*/
enum class GameStatus { Win, Loss, MidGame };

class Mtmchkin {
public:

    /*
     * C'tor of the game:
     *
     * @param playerName - The name of the player.
     * @param cardsArray - A ptr to the cards deck.
     * @param numOfCards - Num of cards in the deck.
     * @result
     *      An instance of Mtmchkin
    */
    Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards);

    /*
     * D'tor of Mtmchkin class.
     */
    ~Mtmchkin() = default;

    /*
     * Assignment operator of Mtmchkin class.
     *
     * @param reference to a Mtmchkin object.
     *@return
     *      reference to a Mtmchkin object.
     *
     */
    Mtmchkin& operator=(const Mtmchkin& other) = default;

    /*
     * Play the next Card - according to the instruction in the exercise document
     *
     * @return
     *      void
    */
    void playNextCard();


    /*
     *  Check if the game ended:
     *
     *  @return
     *          True if the game ended
     *          False otherwise
     */
    bool isOver();


    /*
     *  Get the status of the game:
     *
     *  @return
     *          GameStatus - the current status of the running game
     */
    GameStatus getGameStatus() const;

private:
    Player m_player;
    const Card* m_cards;
    int m_topCardIndex;
    int m_cardsCount;
    GameStatus m_gameStatus;
};


#endif //EX2_GAME_H
