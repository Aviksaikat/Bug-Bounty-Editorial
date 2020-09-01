/*
	THIS FILE IS ABSOLUTELY BUG FREE. PLEASE DO NOT CHANGE ANYTHING IN THIS FILE.
*/


unsigned long hash(char *str) {
	unsigned int hash = 0;
	int c;

	while (c = *str++)
	    hash += c;

	return hash * 84973 + 9387239;
}