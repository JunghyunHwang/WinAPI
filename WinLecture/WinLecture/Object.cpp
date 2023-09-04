#include "Object.h"

namespace assort
{
	Object::Object()
		: mPos{0, 0}
		, mScale{0, 0}
	{
	}

	Object::Object(int pX, int pY, int sX, int sY)
		: mPos{pX, pY}
		, mScale{sX, sY}
	{
	}
}
