#include "EmotiBitPacket.h"

// EmotiBit Data TagTypes
const char* EmotiBitPacket::TypeTag::EDA = "EA\0";
const char* EmotiBitPacket::TypeTag::EDL = "EL\0";
const char* EmotiBitPacket::TypeTag::EDR = "ER\0";
const char* EmotiBitPacket::TypeTag::PPG_INFRARED = "PI\0";
const char* EmotiBitPacket::TypeTag::PPG_RED = "PR\0";
const char* EmotiBitPacket::TypeTag::PPG_GREEN = "PG\0";
const char* EmotiBitPacket::TypeTag::TEMPERATURE_0 = "T0\0";
const char* EmotiBitPacket::TypeTag::TEMPERATURE_1 = "T1\0";
const char* EmotiBitPacket::TypeTag::THERMISTOR = "TH\0";
const char* EmotiBitPacket::TypeTag::HUMIDITY_0 = "H0\0";
const char* EmotiBitPacket::TypeTag::ACCELEROMETER_X = "AX\0";
const char* EmotiBitPacket::TypeTag::ACCELEROMETER_Y = "AY\0";
const char* EmotiBitPacket::TypeTag::ACCELEROMETER_Z = "AZ\0";
const char* EmotiBitPacket::TypeTag::GYROSCOPE_X = "GX\0";
const char* EmotiBitPacket::TypeTag::GYROSCOPE_Y = "GY\0";
const char* EmotiBitPacket::TypeTag::GYROSCOPE_Z = "GZ\0";
const char* EmotiBitPacket::TypeTag::MAGNETOMETER_X = "MX\0";
const char* EmotiBitPacket::TypeTag::MAGNETOMETER_Y = "MY\0";
const char* EmotiBitPacket::TypeTag::MAGNETOMETER_Z = "MZ\0";
const char* EmotiBitPacket::TypeTag::BATTERY_VOLTAGE = "BV\0";
const char* EmotiBitPacket::TypeTag::BATTERY_PERCENT = "B%\0";
const char* EmotiBitPacket::TypeTag::DATA_CLIPPING = "DC\0";
const char* EmotiBitPacket::TypeTag::DATA_OVERFLOW = "DO\0";
const char* EmotiBitPacket::TypeTag::SD_CARD_PERCENT = "SD\0";
const char* EmotiBitPacket::TypeTag::RESET = "RS\0"; // still necessary?
const char* EmotiBitPacket::TypeTag::DEBUG = "DB\0";
const char* EmotiBitPacket::TypeTag::ACK = "AK\0";
const char* EmotiBitPacket::TypeTag::REQUEST_DATA = "RD\0";
const char* EmotiBitPacket::TypeTag::TIMESTAMP_LOCAL = "TL\0";
const char* EmotiBitPacket::TypeTag::TIMESTAMP_UTC = "TU\0";
const char* EmotiBitPacket::TypeTag::TIMESTAMP_CROSS_TIME = "TX\0";
const char* EmotiBitPacket::TypeTag::EMOTIBIT_MODE = "EM\0";
const char* EmotiBitPacket::TypeTag::EMOTIBIT_INFO = "EI\0";
// Computer data TypeTags
const char* EmotiBitPacket::TypeTag::GPS_LATLNG = "GL\0";
const char* EmotiBitPacket::TypeTag::GPS_SPEED = "GS\0";
const char* EmotiBitPacket::TypeTag::GPS_BEARING = "GB\0";
const char* EmotiBitPacket::TypeTag::GPS_ALTITUDE = "GA\0";
const char* EmotiBitPacket::TypeTag::USER_NOTE = "UN\0";
const char* EmotiBitPacket::TypeTag::LSL_MARKER = "LM\0";
// Control TypeTags
const char* EmotiBitPacket::TypeTag::RECORD_BEGIN = "RB\0";
const char* EmotiBitPacket::TypeTag::RECORD_END = "RE\0";
const char* EmotiBitPacket::TypeTag::MODE_LOW_POWER = "ML\0";				// Stops sending data timestamping should be accurate
const char* EmotiBitPacket::TypeTag::MODE_MAX_LOW_POWER = "MM\0";		// Stops sending data timestamping accuracy drops
const char* EmotiBitPacket::TypeTag::MODE_HIBERNATE = "MH\0";				// Full shutdown of all operation
const char* EmotiBitPacket::TypeTag::PING = "PI\0";
const char* EmotiBitPacket::TypeTag::PONG = "PO\0";
const char* EmotiBitPacket::TypeTag::EMOTIBIT_DISCONNECT = "ED\0";
const char* EmotiBitPacket::TypeTag::KEEP_ALIVE = "KA\0";
// Advertising TypeTags
const char* EmotiBitPacket::TypeTag::HELLO_EMOTIBIT = "HE\0";
const char* EmotiBitPacket::TypeTag::HELLO_HOST = "HH\0";
//const char* EmotiBitPacket::TypeTag::HELLO_COMPUTER = "HC\0";
const char* EmotiBitPacket::TypeTag::CONTROL_PORT = "CP\0";
const char* EmotiBitPacket::TypeTag::EMOTIBIT_CONNECT = "EC\0";


const uint8_t nAperiodicTypeTags = 2;
const uint8_t nUserMessagesTypeTags = 1;
const char* const EmotiBitPacket::TypeTagGroups::APERIODIC[nAperiodicTypeTags] = {EmotiBitPacket::TypeTag::DATA_CLIPPING,
    EmotiBitPacket::TypeTag::DATA_OVERFLOW};
const char* const EmotiBitPacket::TypeTagGroups::USER_MESSAGES[nUserMessagesTypeTags] = {EmotiBitPacket::TypeTag::USER_NOTE};

//vector<string> EmotiBitPacket::TypeTag::APERIODIC.push_back(EmotiBitPacket::TypeTag::DATA_CLIPPING);

const char EmotiBitPacket::PACKET_DELIMITER_CSV = '\n';
const uint16_t MAX_TO_EMOTIBIT_PACKET_LEN = 255;
#ifdef ARDUINO
	const String EmotiBitPacket::TIMESTAMP_STRING_FORMAT = "%Y-%m-%d_%H-%M-%S-%f";
#else
	const string EmotiBitPacket::TIMESTAMP_STRING_FORMAT = "%Y-%m-%d_%H-%M-%S-%f";
#endif


#ifdef ARDUINO
//static String getTypeTag(const Header &h);
#else
//string EmotiBitPacket::getTypeTag(const Header h) {
//}
#endif

//EmotiBitPacket::EmotiBitPacket() {
//const char* EmotiBitPacket::typeTags[(uint8_t)EmotiBitPacket::PacketType::length];
//EmotiBitPacket::typeTags[(uint8_t)EmotiBitPacket::PacketType::EDA] = &EmotiBitPacket::TypeTag::EDA;
	//typeTags[PacketType::EDL] = EmotiBitPacket::TypeTag::EDL;
	//typeTags[PacketType::EDR] = EmotiBitPacket::TypeTag::EDR;
	//typeTags[PacketType::PPG_INFRARED] = EmotiBitPacket::TypeTag::PPG_INFRARED;
	//typeTags[PacketType::PPG_RED] = EmotiBitPacket::TypeTag::PPG_RED;
	//typeTags[PacketType::PPG_GREEN] = EmotiBitPacket::TypeTag::PPG_GREEN;
	//typeTags[PacketType::TEMPERATURE_0] = EmotiBitPacket::TypeTag::TEMPERATURE_0;
	//typeTags[PacketType::THERMISTOR] = EmotiBitPacket::TypeTag::THERMISTOR;
	//typeTags[PacketType::HUMIDITY_0] = EmotiBitPacket::TypeTag::HUMIDITY_0;
	//typeTags[PacketType::ACCELEROMETER_X] = EmotiBitPacket::TypeTag::ACCELEROMETER_X;
	//typeTags[PacketType::ACCELEROMETER_Y] = EmotiBitPacket::TypeTag::ACCELEROMETER_Y;
	//typeTags[PacketType::ACCELEROMETER_Z] = EmotiBitPacket::TypeTag::ACCELEROMETER_Z;
	//typeTags[PacketType::GYROSCOPE_X] = EmotiBitPacket::TypeTag::GYROSCOPE_X;
	//typeTags[PacketType::GYROSCOPE_Y] = EmotiBitPacket::TypeTag::GYROSCOPE_Y;
	//typeTags[PacketType::GYROSCOPE_Z] = EmotiBitPacket::TypeTag::GYROSCOPE_Z;
	//typeTags[PacketType::MAGNETOMETER_X] = EmotiBitPacket::TypeTag::MAGNETOMETER_X;
	//typeTags[PacketType::MAGNETOMETER_Y] = EmotiBitPacket::TypeTag::MAGNETOMETER_Y;
	//typeTags[PacketType::MAGNETOMETER_Z] = EmotiBitPacket::TypeTag::MAGNETOMETER_Z;
	//typeTags[PacketType::BATTERY_VOLTAGE] = EmotiBitPacket::TypeTag::BATTERY_VOLTAGE;
	//typeTags[PacketType::BATTERY_PERCENT] = EmotiBitPacket::TypeTag::BATTERY_PERCENT;
	//typeTags[PacketType::DATA_CLIPPING] = EmotiBitPacket::TypeTag::DATA_CLIPPING;
	//typeTags[PacketType::DATA_OVERFLOW] = EmotiBitPacket::TypeTag::DATA_OVERFLOW;
	//typeTags[PacketType::SD_CARD_PERCENT] = EmotiBitPacket::TypeTag::SD_CARD_PERCENT;
	//typeTags[PacketType::RESET] = EmotiBitPacket::TypeTag::RESET;
	//typeTags[PacketType::GPS_LATLNG] = EmotiBitPacket::TypeTag::GPS_LATLNG;
	//typeTags[PacketType::GPS_SPEED] = EmotiBitPacket::TypeTag::GPS_SPEED;
	//typeTags[PacketType::GPS_BEARING] = EmotiBitPacket::TypeTag::GPS_BEARING;
	//typeTags[PacketType::GPS_ALTITUDE] = EmotiBitPacket::TypeTag::GPS_ALTITUDE;
	//typeTags[PacketType::TIMESTAMP_LOCAL] = EmotiBitPacket::TypeTag::TIMESTAMP_LOCAL;
	//typeTags[PacketType::TIMESTAMP_UTC] = EmotiBitPacket::TypeTag::TIMESTAMP_UTC;
	//typeTags[PacketType::RECORD_BEGIN] = EmotiBitPacket::TypeTag::RECORD_BEGIN;
	//typeTags[PacketType::RECORD_END] = EmotiBitPacket::TypeTag::RECORD_END;
	//typeTags[PacketType::USER_NOTE] = EmotiBitPacket::TypeTag::USER_NOTE;
	//typeTags[PacketType::MODE_HIBERNATE] = EmotiBitPacket::TypeTag::MODE_HIBERNATE;
	//typeTags[PacketType::ACK] = EmotiBitPacket::TypeTag::ACK;
	//typeTags[PacketType::HELLO_EMOTIBIT] = EmotiBitPacket::TypeTag::HELLO_EMOTIBIT;
	//typeTags[PacketType::REQUEST_DATA] = EmotiBitPacket::TypeTag::REQUEST_DATA;
	//typeTags[PacketType::PING] = EmotiBitPacket::TypeTag::PING;
	//typeTags[PacketType::PONG] = EmotiBitPacket::TypeTag::PONG;
//}

#ifdef ARDUINO
int16_t EmotiBitPacket::getHeader(const String & packet, Header &packetHeader) 
{
	//ToDo: Add malformed packet checks

	uint16_t dataStartChar = 0;

	uint16_t commaN;
	uint16_t commaN1;
	// timestamp
	commaN = 0;
	commaN1 = packet.indexOf(',', commaN);
	packetHeader.timestamp = packet.substring(commaN, commaN1).toInt();
	// packet_number
	commaN = commaN1 + 1;
	commaN1 = packet.indexOf(',', commaN);
	packetHeader.packetNumber = packet.substring(commaN, commaN1).toInt();
	// data_length
	commaN = commaN1 + 1;
	commaN1 = packet.indexOf(',', commaN);
	packetHeader.dataLength = packet.substring(commaN, commaN1).toInt();
	// typetag
	commaN = commaN1 + 1;
	commaN1 = packet.indexOf(',', commaN);
	packetHeader.typeTag = packet.substring(commaN, commaN1);
	// protocol_version
	commaN = commaN1 + 1;
	commaN1 = packet.indexOf(',', commaN);
	packetHeader.protocolVersion = packet.substring(commaN, commaN1).toInt();
	// data_reliability
	commaN = commaN1 + 1;
	commaN1 = packet.indexOf(',', commaN);
	packetHeader.dataReliability = packet.substring(commaN, commaN1).toInt();
	// data payload
	dataStartChar = commaN1 + 1;

	return dataStartChar;
}
#else
bool EmotiBitPacket::getHeader(const vector<string>& packet, Header &packetHeader) 
{

	if (packet.size() >= EmotiBitPacket::headerLength) {

		try {

			if (packet.at(0) != "") {
				packetHeader.timestamp = stoi(packet.at(0));
			}
			else return false;

			if (packet.at(1) != "") {
				//uint16_t tempPacketNumber = stoi(packet.at(1));
				//if (tempPacketNumber - packetHeader.packetNumber > 1) {
				//	cout << "**  Missed packet: " << packetHeader.packetNumber << "," << tempPacketNumber << "**" << endl;
				//}
				// ToDo: Figure out a way to deal with multiple packets of each number
				//packetHeader.packetNumber = tempPacketNumber;
				packetHeader.packetNumber = stoi(packet.at(1));
			}
			else return false;

			if (packet.at(2) != "") {
				packetHeader.dataLength = stoi(packet.at(2));
			}
			else return false;

			if (packet.at(3) != "") {
				packetHeader.typeTag = packet.at(3);
			}
			else return false;

			if (packet.at(4) != "") {
				packetHeader.protocolVersion = stoi(packet.at(4));
			}
			else return false;

			if (packet.at(5) != "") {
				packetHeader.dataReliability = stoi(packet.at(5));
			}
			else return false;

		}
		catch (exception e) {
			// non-specific exception.. probably malformed packet garbage
			return false;
		}

		if (packet.size() < (size_t) EmotiBitPacket::headerLength + packetHeader.dataLength) {
			//malformedMessages++;
			//cout << "**** MALFORMED MESSAGE " << malformedMessages << ", " << messageLen << " ****" << endl;
			return false;
		}

	}
	else {
		return false;
	}
	return true;
}
#endif

EmotiBitPacket::Header EmotiBitPacket::createHeader(string typeTag, uint32_t timestamp, uint16_t packetNumber, uint16_t dataLength, uint16_t protocolVersion, uint16_t dataReliability)
{
	EmotiBitPacket::Header header;
	header.typeTag = typeTag;
	header.timestamp = timestamp;
	header.packetNumber = packetNumber;
	header.dataLength = dataLength;
	header.protocolVersion = protocolVersion;
	header.dataReliability = dataReliability;

	return header;
}
