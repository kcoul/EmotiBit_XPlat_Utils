#pragma once


class EmotiBitWifiHost
{
public:
	static const uint8_t SUCCESS = 0;
	static const uint8_t FAIL = -1;

	int8_t setup();
	int8_t processAdvertising();
	int8_t sendAdvertising(const String& message, const IPAddress& ip, const uint16_t& port);
	uint8_t readControl(String& packet);
	int8_t sendControl(String& message);
	int8_t sendUdp(WiFiUDP& udp, const String& message, const IPAddress& ip, const uint16_t& port);

};