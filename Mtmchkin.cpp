#include "Card.h"
#include "Mtmchkin.h"

#define MAXIMUM_LEVEL 10

Mtmchkin::Mtmchkin(const string playerName, const Card* cardsArray, int numOfCards) :
	m_player(Player(playerName)), m_cards(cardsArray)
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
	if (m_gameStatus != GameStatus::MidGame) {
		return;
	}
	Card topCard = m_cards[m_topCardIndex];
	topCard.printInfo();
	topCard.applyEncounter(this->m_player);
	this->m_player.printInfo();
	this->m_topCardIndex = (++this->m_topCardIndex) % m_cardsCount;
}

bool Mtmchkin::isOver()
{
	if (m_player.getLevel() == MAXIMUM_LEVEL) {
		m_gameStatus = GameStatus::Win;
		return true;
	}
	if (m_player.isKnockedOut()) {
		m_gameStatus = GameStatus::Loss;
		return true;
	}

	return false;
}