class EmotiBitUtils
{
public:
	static const char INDENT_CHAR = '>';

#ifdef ARDUINO
	static void StringIndent(char indentChar, uint8_t nIndents, String & str)
	{
		String indents;
		indents.reserve(nIndents);
		for (uint8_t i = 0; i < nIndents; i++)
		{
			indents += indentChar;
		}
		str = indents + " " + str;
	}
#endif
};
