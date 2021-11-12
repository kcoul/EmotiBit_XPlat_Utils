#include "EmotiBitVariants.h"
#include "EmotibItVersionController.h"

const char* EmotiBitVariants::EmotiBitSkuTags[] = { "EM\0", "MD\0" };

#ifdef ARDUINO
void printEmotiBitVariantInfo(EmotiBitVariantInfo emotibitVariantInfo)
{
	Serial.print("EmotiBit HW Version: "); Serial.println(EmotiBitVersionController::getHardwareVersion((EmotiBitVersionController::EmotiBitVersion)emotibitVariantInfo.hwVersion));
	if (emotibitVariantInfo.sku != 255)
	{
		Serial.print("EmotiBit Sku Version: "); Serial.println(EmotiBitVariants::EmotiBitSkuTags[emotibitVariantInfo.sku]);
	}
	if (emotibitVariantInfo.emotiBitNumber != UINT32_MAX)
	{
		Serial.print("EmotiBit Number: "); Serial.println(emotibitVariantInfo.emotiBitNumber);
	}
}
#endif