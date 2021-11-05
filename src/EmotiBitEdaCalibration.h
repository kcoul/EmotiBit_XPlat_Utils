#pragma once
#ifdef ARDUINO
	#include <String.h>
	#include <WString.h>
	#include <stdint.h>
#else
	#include <string>
#endif

class EmotiBitEdaCalibration
{
public:

	static const uint8_t V0 = 0;
	struct RawValues_V0
	{
		float edl0R;
		float edl10K;
		float edl100K;
		float edl1M;
		float edl10M;
		float edrAvg;
	};

	static const uint8_t V1 = 1;
	struct RawValues_V1
	{
		float edl0R;
		float edl10K;
		float edl100K;
		float edl1M;
		float edl10M;
		float edr[5];
	};

	struct CalibPair
	{
		float res;
		float adcVal;
	};

	static const uint8_t V2 = 2;
	static const unsigned int nCalibVals_V2 = 5;
	struct RawValues_V2
	{
		unsigned int nVals = nCalibVals_V2;
		CalibPair vals[nCalibVals_V2];
	};

	/*!
	@brief Calculate EDA calibration values
	@return true if calibration calculation succeeded
	*/
	static bool calculate(const RawValues_V2 &rawVals, float &edaTransformSlope, float &edaTransformIntercept);
	static bool calculate(const RawValues_V0 &rawVals, float &vRef1, float &vRef2, float &rfeedback);

#ifdef ARDUINO
	/*!
		@brief pack a RawValues_V2 struct into a string for serial communication
		@return string with csv calibration packet data
	*/
	static bool unpackCalibPacket(const String &edaCalibPacket, uint8_t &packetVersion, RawValues_V2 &rawVals);

#else
	// ToDo: Consider templating createCalibPacket
	/*!
		@brief pack a RawValues_V2 struct into a string for serial communication
		@return string with csv calibration packet data
	*/
	static string createCalibPacket(int version, RawValues_V2 rawVals); 
#endif // ARDUINO



};