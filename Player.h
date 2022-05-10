#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include <string>
#include <stdbool.h>
#include "utilities.h"

#define INITIAL_LEVEL 1
#define INITIAL_COINS 0
#define DEFAULT_FORCE 5
#define DEFAULT_MAX_HP 100
#define MAXIMUM_LEVEL 10


class Player {
public:
    /*
    * C'tor of Player class
    *
    *@param playerName   - The name of the player being created.
    * @param force - The initial force od the player.
    * @param maxHP - The maximum value of health points for said player.
    * @return
    *      A new instance of Player.
   */
    Player(std::string playerName, force = DEFAULT_FORCE, int maxHP = DEFAULT_MAX_HP);

    /*
     * Copy C'tor od Player class
     *
     * @param Player& - reference to an existing Player object.
     * @return
     *      A new instance of Player.
     */
    Player(const Player&) = default;

    /*
     * D'tor of Player class.
     */
    ~Player() = default;

    /*
     * Assignment operator od Player class.
     *
     * @param reference to a Player object.
     *@return
     *      reference to a Player object.
     *
     */
    Player& operator=(const Player& other) = default;

    /*
     * Prints info od Player.
     *
     * @return
     *      void.
     */
    void printInfo() const;

    /*
     * Levels up the player by one level, if at maximum level (10) does nothing.
     *
     * @return
     *       void.
     */
    void levelUp();

    /*
     * Returns the current level of the player.
     *
     * @return
     *      current level.
     */
    int getLevel();

    /*
     * Increases player's force by given amount.
     *
     * @param points - the value that the force is to be increased by.
     * @return
     *      void.
     */
    void buff(int points);

    /*
     * Increases the player's health points by a given value.
     *
     * @param points - the value that the health points are to be increased by.
     * @return
     *      void.
     */
    void heal(int points);

    /*
     * Decreases the player's health points by a given amount.
     *
     * @param points - the value by which the HP is decreased by.
     * @return
     *      void.
     */
    void damage(int points);

    /*
     * Checks to see is the player has run out of health points.
     *
     * @return
     *      Whether the player has reached zero health points
     */
    bool isKnockedOut();

    /*
     * Increases number of coins a player has by a given amount.
     *
     * @param addedCoins - The number of coins to be added to the player
     * @return
     *      void.
     */
    void addCoins(int addedCoins);




private:
    std::string name;
    int level;
    int force;
    int maxHP;
    int HP;
    int coins;
};


#endif //EX2_PLAYER_H
