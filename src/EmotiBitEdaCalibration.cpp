
#include "EmotiBitEdaCalibration.h"
#include "EmotiBitFactoryTest.h"
#include "EmotiBitPacket.h"

bool EmotiBitEdaCalibration::calculate(const RawValues_V0 &rawVals, float &vRef1, float &vRef2, float &rfeedback)
{
	vRef1 = rawVals.edl0R;
	vRef2 = rawVals.edrAvg;

	// using 1M to find Rfeedback
	rfeedback = (1000000.f / ((rawVals.edl1M / vRef1) - 1));
	return true;
}

bool EmotiBitEdaCalibration::calculate(const RawValues_V2 &rawVals, float &edaTransformSlope, float &edaTransformIntercept)
{
	// ToDo: Consider optimizing calculation for maintaining float resolution
	float meanRes = 0;
	float meanAdcVal = 0;

	for (size_t i = 0; i < rawVals.nVals; i++)
	{
		meanRes += rawVals.vals[i].res;
		meanAdcVal += rawVals.vals[i].adcVal;
	}
	meanRes /= rawVals.nVals;
	meanAdcVal /= rawVals.nVals;

	float normRes;
	float normAdcVal;
	float normResMultNormAdcVal;
	float sumNormResMultNormAdcVal = 0;
	float normResSquare;
	float sumNormResSquare = 0;

	for (size_t i = 0; i < rawVals.nVals; i++)
	{
		normRes = rawVals.vals[i].res - meanRes;
		normAdcVal = rawVals.vals[i].adcVal - meanAdcVal;
		normResMultNormAdcVal = normRes * normAdcVal;
		sumNormResMultNormAdcVal += normResMultNormAdcVal;
		normResSquare = pow(normRes, 2.f);
		sumNormResSquare += normResSquare;
	}

	edaTransformSlope = sumNormResSquare / sumNormResMultNormAdcVal;
	edaTransformIntercept = meanRes - meanAdcVal * edaTransformSlope;

	return true;
}

#ifdef ARDUINO
bool EmotiBitEdaCalibration::unpackCalibPacket(const String &edaCalibPacket, uint8_t &packetVersion, RawValues_V2 &rawVals)
{

	String element;
	int16_t nextStartChar;

	nextStartChar = EmotiBitPacket::getPacketElement(edaCalibPacket, element, 0);
	if (element.equals(String(EmotiBitFactoryTest::TypeTag::EDA_CALIBRATION_VALUES)))
	{
		nextStartChar = EmotiBitPacket::getPacketElement(edaCalibPacket, element, nextStartChar);
		packetVersion = element.toInt();
		if (packetVersion != 3) return false; // error: packetVersion mismatch with fn signature

		nextStartChar = EmotiBitPacket::getPacketElement(edaCalibPacket, element, nextStartChar);
		rawVals.nVals = element.toInt();

		for (size_t i = 0; i < rawVals.nVals; i++)
		{
			nextStartChar = EmotiBitPacket::getPacketElement(edaCalibPacket, element, nextStartChar);
			rawVals.vals[i].res = element.toFloat();
			if (nextStartChar == -1) return false; // error: ran out of packet elements before nVals

			nextStartChar = EmotiBitPacket::getPacketElement(edaCalibPacket, element, nextStartChar);
			rawVals.vals[i].adcVal = element.toFloat();
			if (i < rawVals.nVals - 1 && nextStartChar == -1) return false; // error: ran out of packet elements before nVals
		}
		return true;
	}
	else
	{
		return false;
	}
}

void EmotiBitEdaCalibration::print(const RawValues_V0 &rawVals)
{
	Serial.print("0R, \t");
	Serial.println(rawVals.edl0R);
	Serial.print("10K, \t");
	Serial.println(rawVals.edl0K);
	Serial.print("1M, \t");
	Serial.println(rawVals.edl1M);
	Serial.print("10M, \t");
	Serial.println(rawVals.edl10M);
	Serial.print("EDR, \t");
	Serial.println(rawVals.edrAvg);
}

void EmotiBitEdaCalibration::print(const RawValues_V2 &rawVals)
{
	for (uint8_t i; i < rawVals.nVals; i++)
	{
		if (rawVals.vals[i].res < 1000) {
			Serial.print(rawVals.vals[i].res);
			Serial.print("R");
		}
		else if (rawVals.vals[i].res < 1000000) {
			Serial.print(rawVals.vals[i].res / 1000.f);
			Serial.print("K");
		}
		else 
			Serial.print(rawVals.vals[i].res / 1000000.f);
			Serial.print("M");
		}
		Serial.print(", \t");
		Serial.print(rawVals.vals[i].val);
		Serial.println("");
	}	
}
#endif // ARDUINO

#ifndef ARDUINO
string EmotiBitEdaCalibration::createCalibPacket(int payloadVersion, RawValues_V3 rawVals)
{
	string out;
	out += ofToString(EmotiBitFactoryTest::TypeTag::EDA_CALIBRATION_VALUES) + EmotiBitPacket::PAYLOAD_DELIMITER;
	out += ofToString(payloadVersion) + EmotiBitPacket::PAYLOAD_DELIMITER;
	out += ofToString(rawVals.nVals) + EmotiBitPacket::PAYLOAD_DELIMITER;
	for (size_t i = 0; i < rawVals.nVals; i++)
	{
		out += rawVals.vals[i].res + EmotiBitPacket::PAYLOAD_DELIMITER;
		out += rawVals.vals[i].adcVal;
		if (i < rawVals.nVals - 1)
		{
			out += EmotiBitPacket::PAYLOAD_DELIMITER;
		}
	}
	return out;
}
#endif // !ARDUINO

