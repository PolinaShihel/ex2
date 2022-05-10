#include "Player.h"
typedef std::string string;

Player::Player(string playerName, int force, int maxHP) {
    name = playerName;
    level = INITIAL_LEVEL;
    coins = INITIAL_COINS;
    force = force;
    maxHP = maxHP;
    HP = maxHP;
}

void Player::printInfo() const {
    cout<<"Player Details:";
    cout<<"Name: "<< this->name;
    cout<<"Level: "<< this->level;
    cout<<"Force: "<< this->force;
    cout<<"HP: "<< this->HP;
    cout<<"Coins: "<< this->coins;
    cout << LINE_DIVIDER << endl;
}

void Player::levelUp() {
    if(this->level == MAXIMUM_LEVEL){
        return;
    }
    this->level += 1;
}

int Player::getLevel() {
    return this->level;
}

void Player::buff(int points) {
    this->force+=points;
}

void Player::heal(int points) {
    if(this->HP + points >= this->maxHP) {
        this->HP = this->maxHP;
        return;
    }
    this->HP += points;
}

void Player::damage(int points) {
    if(this->HP - points <= 0){
        this->HP = 0;
        return;
    }
    this->HP -= points;
}

bool Player::isKnockedOut() {
    if(this->HP == 0){
        return true;
    }
    return false;
}








