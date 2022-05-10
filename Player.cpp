#include <iostream>
#include "utilities.h"
#include "player.h"

#define MAX(x,y) x > y ? x : y
#define MIN(x,y) x < y ? x : y

Player::Player(const char* playerName, unsigned int initialForce, unsigned int maxHp) :
    m_name(playerName), m_force(initialForce), m_maxHp(maxHp), m_hp(maxHp)
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
    printPlayerInfo(this->m_name, this->m_level, this->m_force, this->m_hp, this->m_coins);
}

void Player::levelUp()
{
    this->m_level += this->m_level < MAXIMUM_LEVEL;
}

int Player::getLevel() const
{
    return this->m_level;
}

void Player::buff(unsigned int force)
{
    this->m_force += force;
}

void Player::heal(unsigned int points)
{
    this->m_hp = MIN(this->m_hp + points, this->m_maxHp);
}

void Player::damage(unsigned int points)
{
    this->m_hp = MAX(this->m_hp - points, MIN_HP);
}

bool Player::isKnockedOut() const
{
    return m_hp == MIN_HP;
}

void Player::addCoins(int addedCoins)
{
    if (addedCoins > 0) {
        m_coins += addedCoins;
    }
}

bool Player::pay(int payment)
{
    if (this->m_coins - payment < 0) {
        return false;
    }
    m_coins -= payment;
    return true;
}

int Player::getAttackStrength() const
{
    return m_force + m_level;
}