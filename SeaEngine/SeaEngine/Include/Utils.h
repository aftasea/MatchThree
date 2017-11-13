#pragma once
#ifndef UTILS_H
#define UTILS_H

#include <string>

namespace Sea
{
	class Utils
	{
	public:
		static int getRandom(int min, int max);
		static int getNewId();

	private:
		static int id;
	};
}

#endif // !UTILS_H