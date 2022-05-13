#include "Card.h"
#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const string playerName, const Card* cardsArray, int numOfCards) :
    m_player(Player(playerName)), m_cards(cardsArray)
{
    Card* cardStack = new Card[numOfCards];
    for (int card = 0; card < numOfCards; card++)
    {
        cardStack[card] = Card(cardsArray[card]);
    }
    m_cards = cardStack;
    m_cardsCount = numOfCards;
    m_topCardIndex = 0;
    m_gameStatus = GameStatus::MidGame;
}

GameStatus Mtmchkin::getGameStatus() const
{
    return this->m_gameStatus;
}

void Mtmchkin::setGameStatus(GameStatus newStatus)
{
    this->m_gameStatus = newStatus;
}

void Mtmchkin::playNextCard()
{
    if (m_gameStatus != GameStatus::MidGame) {
        return;
    }
    Card topCard = m_cards[m_topCardIndex];
    topCard.printInfo();
    topCard.applyEncounter(this->m_player);
    this->m_player.printInfo();
    this->m_topCardIndex++;
    this->m_topCardIndex = this->m_topCardIndex % m_cardsCount;
}

bool Mtmchkin::isOver() const
{
    if (m_player.getLevel() == MAXIMUM_LEVEL) {
        setGameStatus(GameStatus::Win);
        return true;
    }
    if (m_player.isKnockedOut()) {
        setGameStatus(GameStatus::Loss);
        return true;
    }

    return false;
}

Mtmchkin::~Mtmchkin()
{
    delete[] m_cards;
}