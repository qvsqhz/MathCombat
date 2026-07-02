#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include <QPointF>

#include "Player.h"
#include "Monster.h"
#include <vector>
#include <utility>

// класс сцены
class GameScene : public QGraphicsScene
{
	Q_OBJECT

public:
	explicit GameScene(std::vector<std::pair<Monster*, QPointF>> vectorMonsters,
		QString BackgroundTheme, QPointF playerPos, QObject* parent = nullptr);

	~GameScene();

	void keyPressEvent(QKeyEvent* event) override;
	void keyReleaseEvent(QKeyEvent* event) override;


	bool AllMonstersDefeated(); // Вернет true если все монстры на сцене были побеждены
	void ContinueGame();

signals:
	void CombatSignal(Difficulty diff); 

private slots:
	void updateGame(); // Обновляет игру

private:

	Player* m_player;  // главный герой
	QTimer* m_gameTimer;  //Таймер для обновления сцены

	bool m_movingLeft;
	bool m_movingRight;  

	bool m_combatBegin = false;  // True если бой идет

	std::vector<std::pair<Monster*, QPointF>> m_vectorMonsters;  // Вектор всех монстров на сцене

	int numberDefeatedMonsters = 0;
};

#endif 
