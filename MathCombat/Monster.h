#pragma once

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QVector>
#include <QPixmap>
#include <QTimer>

#include "Utils.h"

// Класс монстра.
class Monster : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT

public:

	explicit Monster(Difficulty difficulty, QObject* parent = nullptr);
	~Monster();

	void startAnimation(); 
	void stopAnimation(); 

	void nextFrame(); 

	Difficulty getDifficulty() const; // Возвращает сложность монстра

private:
	Difficulty m_difficulty;
	void UpdateSprites(); // Добавляет картинки по уровню сложности монстра

	QVector<QPixmap> Frames; 

	QPixmap idleRight; 
	QPixmap idleLeft; 

	QTimer* animationTimer;

	int m_currentFrame; // Индекс текущей картинки в векторе 

	bool m_animationForward = true; // Монстр поворачивается вперед (true) или назад (false)
};
