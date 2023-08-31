#include "CObject.h"

namespace assort
{
	CObject::CObject()
		: mPos{0, 0}
		, mScale{0, 0}
	{
	}

	CObject::CObject(int pX, int pY, int sX, int sY)
		: mPos{pX, pY}
		, mScale{sX, sY}
	{
	}
}
