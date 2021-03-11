#include "DigitalFilters.h"

DigitalFilter::DigitalFilter(FilterType type, float samplingFreq, float filterFreq1)
{
	//Serial.print("crossOver Freq: "); Serial.println(filterFreq1);
	//Serial.print("Sampling Rate: "); Serial.println(samplingFreq);
	_type = type;
	_filteredValue = -1;
	_alpha = pow(M_E, -2.f * PI * filterFreq1 / samplingFreq);
	_nInitSamples = 0;
	_nPoles = 1;
}

float DigitalFilter::filter(float inputSample)
{
	if (_nInitSamples < _nPoles)
	{
		// initialize filter
		_filteredValue = inputSample;
		_nInitSamples++;
	}
	if (_type == FilterType::IIR_LOWPASS)
	{
		_filteredValue = inputSample * (1. - _alpha) + _filteredValue * _alpha;
		return _filteredValue;
	}
	else
	{
		// resolve for other filter types
	}
}