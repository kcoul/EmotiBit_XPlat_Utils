#pragma once

class EmotiBitVariants
{
public:
	enum class EmotiBitSkuType
	{
		INVALID = -1,
		EM = 0,
		MD = 1,
		length 
	};

	static const char* EmotiBitSkuTags[2]; 
	static const char VERSION_PREFIX = 'V';
};