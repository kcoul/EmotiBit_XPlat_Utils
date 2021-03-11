#include <math.h>
#include "wiring_constants.h"
#include <Arduino.h>
class DigitalFilter {
public:
	enum class FilterType {
		IIR_LOWPASS
	};
private:
	float _filteredValue;
	float _alpha;
	FilterType _type;
	int _nInitSamples;
	int _nPoles;

public:
	DigitalFilter(FilterType type, float samplingFreq, float filterFreq1);
	float filter(float inputSample);
};