#ifndef ARMAGIC_MODELS_H_
#define ARMAGIC_MODELS_H_

#include <string>

const int NUMBER_OF_MODELS = 2;

namespace models {
	enum Model {
		DWARF,
		FAERIE,
		DINO,
		SYDNEY,
		SKELETON,
		HORSE,
		DRAGON
	};
	struct info	{
		std::string modelPath, texturePath;
	};
	static const info modelInfo[NUMBER_OF_MODELS];
};


#endif