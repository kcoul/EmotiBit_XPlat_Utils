#pragma once
#ifdef ARDUINO
#include <Arduino.h>
#endif
/*!
	@brief Stores the Information about details that make up different variants
*/
// ToDo: Someday, the Hardware struct will also move here. That will expand access to the Software side

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
	static const char HARDWARE_VERSION_PREFIX = 'V';
};

enum class EmotiBitVariantDataFormat {
	V0 = 0,
	V1 = 1,
	length
};

/*!
	@brief Struct to store the HW, SKU and emotiBit number.
*/
struct EmotiBitVariantInfo {
	uint32_t emotiBitNumber;
	uint8_t hwVersion;
	uint8_t sku;
};

#ifdef ARDUINO
/*!
	@brief Prints all the information about the EmotiBit variant.
	@param emotibitVariantInfo Takes in the stuct EmotiBitVariantInfo
*/
void printEmotiBitVariantInfo(EmotiBitVariantInfo emotibitVariantInfo);
#endif

