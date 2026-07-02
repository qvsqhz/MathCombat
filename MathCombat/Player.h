#pragma once

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QVector>
#include <QPixmap>
#include <QTimer>

// Класс главного героя
class Player : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT

public:

	Player(QObject* parent);
	~Player();

	void moveLeft();	
	void moveRight(); 
	void startAnimation(); 
	void stopAnimation();
	 
	void nextFrame(); // Меняет картинку


private:
	QVector<QPixmap> walkRightFrames;  // Вектор для бега вправо 
	QVector<QPixmap> walkLeftFrames;   // Вектор для бега влево

	QPixmap idleRight;
	QPixmap idleLeft;

	QTimer* animationTimer;

	int currentFrame;  // Индекс текущей картинки анимации
	bool movingLeft;   // Происходит движение влево 
	bool movingRight;  // Происходит движение вправо

};
