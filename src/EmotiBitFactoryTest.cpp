#include "EmotiBitFactoryTest.h"

// Factory Test Typetags
const char* EmotiBitFactoryTest::TypeTag::EMOTIBIT_VERSION = "EV\0";
const char* EmotiBitFactoryTest::TypeTag::FIRMWARE_VERSION = "FV\0";
const char* EmotiBitFactoryTest::TypeTag::EMOTIBIT_NUMBER = "EN\0";
const char* EmotiBitFactoryTest::TypeTag::I2C_COMM_INIT = "TW\0";
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
const char* EmotiBitFactoryTest::TypeTag::LED_RED_ON = "+R\0";
const char* EmotiBitFactoryTest::TypeTag::LED_RED_OFF = "-R\0";
const char* EmotiBitFactoryTest::TypeTag::LED_BLUE_ON = "+B\0";
const char* EmotiBitFactoryTest::TypeTag::LED_BLUE_OFF = "-B\0";
const char* EmotiBitFactoryTest::TypeTag::LED_YELLOW_ON = "+Y\0";
const char* EmotiBitFactoryTest::TypeTag::LED_YELLOW_OFF = "-Y\0";
const char* EmotiBitFactoryTest::TypeTag::NULL_VAL = "\0";
const char* EmotiBitFactoryTest::TypeTag::TEST_PASS = "PASS\0";
const char* EmotiBitFactoryTest::TypeTag::TEST_FAIL = "FAIL\0";
const char* EmotiBitFactoryTest::TypeTag::VERSION_VALIDATION = "VV\0";
const char* EmotiBitFactoryTest::TypeTag::SKU_VALIDATION = "SV\0";
const char* EmotiBitFactoryTest::TypeTag::EDA_CALIBRATION_VALUES = "EC\0";
const char* EmotiBitFactoryTest::TypeTag::EDA_CALIBRATION_ACK = "EK\0";

#ifdef ARDUINO
void EmotiBitFactoryTest::updateOutputString(String &output, const char* testType, const char* result)
{
	output += testType;
	output += TypeTag::TEST_RESULT_DELIMITER;
	output += result;
	if(result != TypeTag::NULL_VAL)
	{
		output += TypeTag::TEST_TYPE_DELIMITER;
	}
	else
	{
		output += MSG_TERM_CHAR;
	}
}

void EmotiBitFactoryTest::sendMessage(String typeTag, String payload)
{
	Serial.print(EmotiBitFactoryTest::MSG_START_CHAR);
	Serial.print(typeTag);
	if (!payload.equals(""))
	{
		Serial.print(EmotiBitFactoryTest::PAYLOAD_DELIMITER);
		Serial.print(payload);
	}
	Serial.println(EmotiBitFactoryTest::MSG_TERM_CHAR);
}

	// Parses the barcode 
void EmotiBitFactoryTest::parseBarcode(Barcode* barcode)
{
	barcode->sku = barcode->code.substring(0, barcode->code.indexOf(BARCODE_DELIMITER));
	barcode->code = barcode->code.substring(barcode->code.indexOf(BARCODE_DELIMITER) + 1);
	barcode->emotibitVersion = barcode->code.substring(0, barcode->code.indexOf(BARCODE_DELIMITER));
	barcode->emotibitNumber = barcode->code.substring(barcode->code.indexOf(BARCODE_DELIMITER) + 1);
}

bool EmotiBitFactoryTest::validateVersionEstimate(String barcode, String estimate)
{
	// remove the leading "V" in version
	barcode.remove(barcode.indexOf(EmotiBitVariants::VERSION_PREFIX),1);
	estimate.remove(estimate.indexOf(EmotiBitVariants::VERSION_PREFIX),1);
	if (barcode.toInt() == estimate.toInt())
		return true;
	else
		return false;
}
#else
string EmotiBitFactoryTest::createPacket(string typeTag, string payload)
{
	string s = "";
	s += EmotiBitFactoryTest::MSG_START_CHAR;
	s += typeTag;
	if (payload.length > 0) {
		s += EmotiBitFactoryTest::PAYLOAD_DELIMITER;
		s += payload;
	}
	s += EmotiBitFactoryTest::MSG_TERM_CHAR;
}
#endif