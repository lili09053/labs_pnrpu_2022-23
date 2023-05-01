#pragma once

enum Events
{
	evNothing = 0,
	evMessage = 100
};

enum Commands
{
	cmAdd = 1,
	cmDel,
	cmGet,
	cmShow,
	cmElem,
	cmMake,
	cmQuit = 101
};

struct Event
{
	int what;				// Тип события
	union
	{
		int command;		// Код команды
		struct
		{
			int message;	// Сообщение
			int parameter;			// Параметр команды
		};
	};
};

