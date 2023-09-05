#include "Object.h"

namespace assort
{
	Object::Object(int pX, int pY, int sX, int sY)
		: mPos{pX, pY}
		, mScale{sX, sY}
		, mSpeed(300)
	{
	}
}
