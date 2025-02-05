#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition()
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;
}

CellPosition::CellPosition(int v, int h)
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition(int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v)
{
	if (v >= 0 && v <= 8)
	{
		vCell = v;
		return true;
	}
	else
	{
		return false;
	}

}

bool CellPosition::SetHCell(int h)
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (h >= 0 && h <= 10)
	{
		hCell = h;
		return true;
	}
	else
	{
		return false;
	}

}

int CellPosition::VCell() const
{
	return vCell;
}

int CellPosition::HCell() const
{
	return hCell;
}

bool CellPosition::IsValidCell() const
{
	if (vCell >= 0 && vCell <= 8 && hCell >= 0 && hCell <= 10)
		return true;
	else
		return false;
}

int CellPosition::GetCellNum() const
{

	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition& cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	///TODO: Implement this function as described in the .h file
	int cellnum = cellPosition.HCell() - cellPosition.VCell() * 11 + 89;


	return cellnum; // this line should be changed with your implementation
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;

	if (cellNum >= 0 && cellNum <= 99)
	{
		for (int i = 0; i <= 8; ++i)
		{
			if (cellNum >= 1 + 11 * i && cellNum <= 11 + 11 * i)
				position.SetVCell(8 - i);
		}

		position.SetHCell(cellNum + position.VCell() * 11 - 89);
		/// TODO: Implement this function as described in the .h file



		// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
		//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it
	}



	return position;
}

void CellPosition::AddCellNum(int addedNum)
{

	/// TODO: Implement this function as described in the .h file
	int current_cell_num = GetCellNum();
	current_cell_num += addedNum;
	CellPosition newCell = GetCellPositionFromNum(current_cell_num);
	SetVCell(newCell.VCell());
	SetHCell(newCell.HCell());

	// Note: this function updates the data members (vCell and hCell) of the calling object

}