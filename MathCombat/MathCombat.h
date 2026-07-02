#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MathCombat.h"
#include "Utils.h"
#include "GameScene.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MathCombatClass; };
QT_END_NAMESPACE

// Основное окно игры, на котором находятся все виджеты 
class MathCombat : public QMainWindow
{
	Q_OBJECT

public:
	MathCombat(QWidget* parent = nullptr);
	~MathCombat();

	bool IsLevelPassed();

	void ShowFirstLevel();
	void ShowSecondLevel();
	void ShowThirdLevel();

	void ShowCongratulation();


public slots:
	void StartNewGame();
	void StartCombat(Difficulty diff);
	void EndCombat(bool result);
	void ShowPreview();
	void RestartLevel();

private:
	void ContinueGame();

	int currentLevel = 1;

	GameScene* m_scene; // сцена

	Ui::MathCombatClass* ui;
};
