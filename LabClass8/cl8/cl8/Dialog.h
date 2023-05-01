#pragma once
#include "Tree.h"
#include "Event.h"


class Dialog : public Tree
{
protected:
	int EndState;
public:
	Dialog();
	virtual ~Dialog();
	virtual void GetEvent(Event& event);		// Получить событие
	virtual int Execute();						// Главынй цикл обработки событий
	virtual void HandleEvent(Event& event);		// Обработчик
	virtual void ClearEvent(Event& event);		// Очистить событие
	int Valid();								// Проверка атрибута EndState
	void EndExec();								// Обработка события "конец работы"
};



