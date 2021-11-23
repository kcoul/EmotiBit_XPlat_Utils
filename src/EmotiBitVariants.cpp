#include "EmotiBitVariants.h"
#include "EmotibItVersionController.h"

//const char* EmotiBitVariants::EmotiBitSkuTags[] = { "EM\0", "MD\0" };
const char* EmotiBitVariants::EMOTIBIT_SKU_MD = "MD\0";
const char* EmotiBitVariants::EMOTIBIT_SKU_EM = "EM\0";
#ifdef ARDUINO
void printEmotiBitVariantInfo(EmotiBitVariantInfo emotibitVariantInfo)
{
	Serial.print("EmotiBit HW Version: "); Serial.println(EmotiBitVersionController::getHardwareVersion((EmotiBitVersionController::EmotiBitVersion)emotibitVariantInfo.hwVersion));
	Serial.print("EmotiBit Sku Version: "); Serial.println(emotibitVariantInfo.sku);
	if (emotibitVariantInfo.emotiBitNumber != UINT32_MAX)
	{
		Serial.print("EmotiBit Number: "); Serial.println(emotibitVariantInfo.emotiBitNumber);
	}
}
#endif