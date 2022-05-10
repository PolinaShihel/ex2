#include "Card.h"
#include "Player.h"
#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) :
	m_player(Player(playerName)), m_cards(new Card[numOfCards])
{
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
	Card topCard = m_cards[m_topCardIndex];
	topCard.printInfo();
	topCard.applyEncounter(this->m_player);
	this->m_player.printInfo();
	m_topCardIndex = (++m_topCardIndex) % m_cardsCount;
}

bool Mtmchkin::isOver()
{
	return this->m_gameStatus != GameStatus::MidGame;
}

