#pragma once

#include "Action.h"
#include "CellPosition.h"

class DeleteGameObject : public Action
{
	CellPosition selectedCell;

public:
	DeleteGameObject(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~DeleteGameObject();
};