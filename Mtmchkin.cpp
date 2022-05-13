#include "Card.h"
#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(string playerName, const Card* cardsArray, int numOfCards) :
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

    if (m_player.getLevel() == MAXIMUM_LEVEL) {
        this->m_gameStatus = GameStatus::Win;
    }
    if (m_player.isKnockedOut()) {
        this->m_gameStatus = GameStatus::Loss;
    }
}

bool Mtmchkin::isOver() const
{
    return this->m_gameStatus != GameStatus::MidGame;
}

Mtmchkin::~Mtmchkin()
{
    delete[] m_cards;
}