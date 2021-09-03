#ifdef ARDUINO
	#include <Arduino.h>
#else
	// ToDo: Remove OF dependency for ofToString()
	#include "ofMain.h"
#endif // !ARDUINO
class EmotiBitFactoryTest{
public:
	class TypeTag
	{
	public:
				// Factory Test Typetags
		static const char* EMOTIBIT_VERSION;
		static const char* FIRMWARE_VERSION;
		static const char* EMOTIBIT_NUMBER;
		static const char* I2C_COMM_INIT;
		static const char* FLASH;
		static const char* SERIAL_NUMBER_WRITE;
		static const char* LED_CONTROLLER;
		static const char* PPG_SENSOR;
		static const char* IMU_ID;
		static const char* ACCEL_GYRO;
		static const char* MAGNETOMETER;
		static const char* TEMP_SENSOR;
		static const char* THERMOPILE;
		static const char* ADC_INIT;
		static const char* SD_CARD;
		static const char* WIFI;
		static const char* SETUP_COMPLETE;
		static const char* AVDD_VOLTAGE;
		//static const char* AVDD_PASS;
		static const char* DVDD_VOLTAGE;
		//static const char* DVDD_PASS;
		static const char* TOTAL_CURRENT;
		static const char* WIFI_OFF_CURRENT;
		static const char* HIBERNATE_CURRENT;
		static const char* TEST_RESULT_DELIMITER;
		static const char* TEST_TYPE_DELIMITER;
		static const char* TEST_PASS;
		static const char* TEST_FAIL;
		static const char* LED_RED_ON;
		static const char* LED_RED_OFF;
		static const char* LED_BLUE_ON;
		static const char* LED_BLUE_OFF;
		static const char* LED_YELLOW_ON;
		static const char* LED_YELLOW_OFF;
		static const char* NULL_VAL;
	};

	static const char MSG_START_CHAR = '@';
	static const char MSG_TERM_CHAR = '~';
	static const char PAYLOAD_DELIMITER = ',';

	static void updateOutputString(char * output, const char* testType, const char* result);
	#ifdef ARDUINO
		static void sendMessage(String typeTag, String payload = "");
	#endif
};