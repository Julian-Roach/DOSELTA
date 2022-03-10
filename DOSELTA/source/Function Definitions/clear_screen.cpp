#include "../DOSELTA.h"

namespace DOS
{
	void ClearScreen()
	{
		system("cls"); // BAD PRACTICE; "CLS" REQUIRES ADMIN PERMISSIONS
	}
}
