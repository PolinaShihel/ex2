#include <iostream>
#include "utilities.h"
#include "player.h"

using std::cout;
using std::min;
using std::max;

Player::Player(string playerName, unsigned int initialForce, unsigned int maxHp) :
    m_playerName(playerName), m_force(initialForce)
{
    m_level = INITIAL_LEVEL;
    m_coins = INITIAL_COINS;
    if (maxHp <= MIN_HP) {
        m_maxHp = m_hp = DEFAULT_MAX_HP;
    }
    if (initialForce <= 0) {
        m_force = DEFAULT_INITIAL_FORCE;
    }
}

void Player::printInfo() const
{
    printPlayerInfo(this.m_name, this.m_level, this.m_force, this.m_hp this.m_coins);
}

void Player::levelUp()
{
    this.m_level += this.m_level < TOP_LEVEL;
}

int Player::getLevel() const
{
    return this.m_level;
}

void Player::buff(unsigned int forceToAdd)
{
    this.m_force += forceToAdd;
}

void Player::heal(unsigned int hpToAdd)
{
    this.m_hp = min(this.m_hp + hpToAdd, this.m_maxHp);
}

void Player::damage(unsigned int hpToSubtract)
{
    this.m_hp = max(this.m_hp - hpToSubtract, MIN_HP);
}

bool Player::isKnockedOut() const
{
    return m_hp == MIN_HP;
}

void addOrSubtractCoins(int coins)
{
    this.m_coins += coins;
}

void Player::addCoins(int coinsToAdd)
{
    if (coinsToAdd > 0) {
        addOrSubtractCoins(coinsToAdd);
    }
}

bool Player::pay(unsigned int price)
{
    if (this.m_coins - price < 0) {
        return false;
    }
    addOrSubtractCoins(-price);
    return true;
}

int Player::getAttackStrength() const
{
    return m_force + m_level;
}











