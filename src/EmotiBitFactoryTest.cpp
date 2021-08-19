#include "EmotiBitFactoryTest.h"

// Factory Test Typetags
const char* EmotiBitFactoryTest::TypeTag::EMOTIBIT_VERSION = "EV\0";
const char* EmotiBitFactoryTest::TypeTag::FIRMWARE_VERSION = "FV\0";
const char* EmotiBitFactoryTest::TypeTag::EMOTIBIT_NUMBER = "EN\0";
const char* EmotiBitFactoryTest::TypeTag::I2C_COMM_INIT = "TW";
const char* EmotiBitFactoryTest::TypeTag::FLASH = "FL\0";
const char* EmotiBitFactoryTest::TypeTag::SERIAL_NUMBER_WRITE = "SW\0";
const char* EmotiBitFactoryTest::TypeTag::LED_CONTROLLER = "LC\0";
const char* EmotiBitFactoryTest::TypeTag::PPG_SENSOR = "PG\0";
const char* EmotiBitFactoryTest::TypeTag::IMU_ID = "II\0";
const char* EmotiBitFactoryTest::TypeTag::ACCEL_GYRO = "AG\0";
const char* EmotiBitFactoryTest::TypeTag::MAGNETOMETER = "MG\0";
const char* EmotiBitFactoryTest::TypeTag::TEMP_SENSOR = "TE\0";
const char* EmotiBitFactoryTest::TypeTag::THERMOPILE = "TI\0";
const char* EmotiBitFactoryTest::TypeTag::ADC_INIT = "AD\0";
const char* EmotiBitFactoryTest::TypeTag::SD_CARD = "SD\0";
const char* EmotiBitFactoryTest::TypeTag::WIFI = "WF\0";
const char* EmotiBitFactoryTest::TypeTag::SETUP_COMPLETE = "SC\0";
const char* EmotiBitFactoryTest::TypeTag::AVDD_VOLTAGE = "AV\0";
const char* EmotiBitFactoryTest::TypeTag::DVDD_VOLTAGE = "DV\0";
const char* EmotiBitFactoryTest::TypeTag::TOTAL_CURRENT = "TC\0";
const char* EmotiBitFactoryTest::TypeTag::WIFI_OFF_CURRENT = "WC\0";
const char* EmotiBitFactoryTest::TypeTag::HIBERNATE_CURRENT = "HC\0";
const char* EmotiBitFactoryTest::TypeTag::TEST_RESULT_DELIMITER = ":\0";
const char* EmotiBitFactoryTest::TypeTag::TEST_TYPE_DELIMITER = "+\0";
const char* EmotiBitFactoryTest::TypeTag::TEST_PASS = "PASS\0";
const char* EmotiBitFactoryTest::TypeTag::TEST_FAIL = "FAIL\0";
const char* EmotiBitFactoryTest::TypeTag::LED_RED_ON = "+R";
const char* EmotiBitFactoryTest::TypeTag::LED_RED_OFF = "-R";
const char* EmotiBitFactoryTest::TypeTag::LED_BLUE_ON = "+B";
const char* EmotiBitFactoryTest::TypeTag::LED_BLUE_OFF = "-B";
const char* EmotiBitFactoryTest::TypeTag::LED_YELLOW_ON = "+Y";
const char* EmotiBitFactoryTest::TypeTag::LED_YELLOW_OFF = "-Y";
const char* EmotiBitFactoryTest::TypeTag::NULL_VAL = "\0";

void EmotiBitFactoryTest::updateOutputString(char* output, const char* testType, const char* result)
{
	//char output[10]; // max posible for any test
	strcat(output,testType);
	strcat(output,TypeTag::TEST_RESULT_DELIMITER);
	strcat(output,result);
	if(result != TypeTag::TEST_FAIL && result != TypeTag::NULL_VAL)
	{
		strcat(output,TypeTag::TEST_TYPE_DELIMITER);
	}
	else
	{
		strcat(output, "***");
	}
}

