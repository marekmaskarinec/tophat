#ifndef PIXELFONT_H
#define PIXELFONT_H
static char pixelfont[128][25] = {
	[' '] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	['!'] = { 0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0, },
	['"'] = { 0,1,0,1,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	['#'] = { 0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0, },
	['$'] = { 0,1,1,1,1,1,0,1,0,0,0,1,1,1,0,0,0,1,0,1,1,1,1,1,0, },
	['%'] = { 1,1,0,0,1,1,1,0,1,0,0,0,1,0,0,0,1,0,1,1,1,0,0,1,1, },
	['&'] = { 0,0,1,1,0,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,1,1,0,1, },
	['\''] = { 0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	['('] = { 0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0, },
	[')'] = { 0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0, },
	['*'] = { 0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0, },
	['+'] = { 0,0,0,0,0,0,0,1,0,0,0,1,1,1,0,0,0,1,0,0,0,0,0,0,0, },
	[','] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0, },
	['-'] = { 0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0, },
	['.'] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0, },
	['/'] = { 0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0, },
	['0'] = { 1,1,1,1,1,1,0,0,0,1,1,0,1,0,1,1,0,0,0,1,1,1,1,1,1, },
	['1'] = { 0,0,1,0,0,0,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,1,1,0, },
	['2'] = { 0,1,1,0,0,1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,0, },
	['3'] = { 0,1,1,0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,1,0,0,1,1,0,0, },
	['4'] = { 0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,0,0,0,1,0,0, },
	['5'] = { 1,1,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0, },
	['6'] = { 0,1,1,1,0,1,0,0,0,0,1,1,1,1,0,1,0,0,0,1,0,1,1,1,0, },
	['7'] = { 1,1,1,1,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0, },
	['8'] = { 0,1,1,1,0,1,0,0,0,1,0,1,1,1,0,1,0,0,0,1,0,1,1,1,0, },
	['9'] = { 0,1,1,1,0,1,0,0,0,1,0,1,1,1,1,0,0,0,0,1,0,1,1,1,0, },
	[':'] = { 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0, },
	[';'] = { 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0, },
	['<'] = { 0,0,0,1,1,0,1,1,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1, },
	['='] = { 0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0, },
	['>'] = { 1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,1,1,0,1,1,0,0,0, },
	['?'] = { 0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0, },
	['@'] = { 0,1,1,1,0,1,0,1,0,1,1,0,1,1,0,1,0,0,0,0,0,1,1,0,0, },
	['A'] = { 0,1,1,1,0,1,0,0,0,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,1, },
	['B'] = { 1,1,1,1,0,1,0,0,0,1,1,1,1,1,0,1,0,0,0,1,1,1,1,1,0, },
	['C'] = { 0,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,1,1,1, },
	['D'] = { 1,1,1,1,0,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,1,1,1,0, },
	['E'] = { 1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1, },
	['F'] = { 1,1,1,1,1,1,0,0,0,0,1,1,1,1,0,1,0,0,0,0,1,0,0,0,0, },
	['G'] = { 1,1,1,1,1,1,0,0,0,0,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1, },
	['H'] = { 1,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,1, },
	['I'] = { 0,1,1,1,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,1,1,0, },
	['J'] = { 0,0,1,1,1,0,0,0,1,0,0,0,0,1,0,1,0,0,1,0,0,1,1,0,0, },
	['K'] = { 1,0,0,1,0,1,0,1,0,0,1,1,0,0,0,1,0,1,0,0,1,0,0,1,0, },
	['L'] = { 1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,1,1,1,1, },
	['M'] = { 1,0,0,0,1,1,1,0,1,1,1,0,1,0,1,1,0,0,0,1,1,0,0,0,1, },
	['N'] = { 1,0,0,0,1,1,1,0,0,1,1,0,1,0,1,1,0,0,1,1,1,0,0,0,1, },
	['O'] = { 0,1,1,1,0,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,0,1,1,1,0, },
	['P'] = { 1,1,1,1,0,1,0,0,0,1,1,1,1,1,0,1,0,0,0,0,1,0,0,0,0, },
	['Q'] = { 0,1,1,1,0,1,0,0,0,1,1,0,0,0,1,1,0,0,1,0,0,1,1,0,1, },
	['R'] = { 1,1,1,1,0,1,0,0,0,1,1,1,1,1,0,1,0,1,0,0,1,0,0,1,0, },
	['S'] = { 0,1,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,1,1,0, },
	['T'] = { 1,1,1,1,1,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0, },
	['U'] = { 1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,0,1,1,1,0, },
	['V'] = { 1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,0,1,0,1,0,0,0,1,0,0, },
	['W'] = { 1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,1,0,1,0,1,1,1,0, },
	['X'] = { 1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1, },
	['Y'] = { 1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0, },
	['Z'] = { 1,1,1,1,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,1, },
	['['] = { 0,0,1,1,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,1,0, },
	['\\'] = { 1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1, },
	[']'] = { 0,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,1,0,0, },
	['^'] = { 0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	['_'] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1, },
	['`'] = { 0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	['a'] = { 0,0,0,0,0,0,1,1,0,0,1,0,0,1,0,1,0,0,1,0,0,1,1,0,1, },
	['b'] = { 0,1,0,0,0,0,1,1,1,0,0,1,0,0,1,0,1,0,0,1,0,0,1,1,0, },
	['c'] = { 0,0,0,0,0,0,0,1,1,0,0,1,0,0,0,0,1,0,0,0,0,0,1,1,0, },
	['d'] = { 0,0,0,1,0,0,1,1,1,0,1,0,0,1,0,1,0,0,1,0,0,1,1,0,0, },
	['e'] = { 0,0,0,0,0,0,1,1,0,0,1,1,1,1,0,1,0,0,0,0,0,1,1,0,0, },
	['f'] = { 0,0,1,1,0,0,1,0,0,0,0,1,1,0,0,0,1,0,0,0,0,1,0,0,0, },
	['g'] = { 0,0,1,1,0,0,1,0,1,0,0,0,1,1,0,0,0,0,1,0,0,0,1,0,0, },
	['h'] = { 0,1,0,0,0,0,1,0,0,0,0,1,1,1,0,0,1,0,0,1,0,1,0,0,1, },
	['i'] = { 0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0, },
	['j'] = { 0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0, },
	['k'] = { 0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,1,1,0,0,0,1,0,1,0, },
	['l'] = { 0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0, },
	['m'] = { 0,0,0,0,0,1,1,0,1,0,1,0,1,0,1,1,0,0,0,1,1,0,0,0,1, },
	['n'] = { 0,0,0,0,0,1,1,1,0,0,1,0,0,1,0,1,0,0,1,0,1,0,0,1,0, },
	['o'] = { 0,0,0,0,0,0,1,1,1,0,1,0,0,0,1,1,0,0,0,1,0,1,1,1,0, },
	['p'] = { 0,0,0,0,0,0,1,1,0,0,0,1,0,1,0,0,1,1,0,0,0,1,0,0,0, },
	['q'] = { 0,0,0,0,0,0,0,1,1,0,0,1,0,1,0,0,0,1,1,0,0,0,0,1,0, },
	['r'] = { 0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0, },
	['s'] = { 0,0,0,0,0,0,1,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,1,0, },
	['t'] = { 0,0,1,0,0,0,1,1,1,0,0,0,1,0,0,0,0,1,0,0,0,0,1,1,0, },
	['u'] = { 0,0,0,0,0,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,0,1,1,1,0, },
	['v'] = { 0,0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,1,0,1,0,0,0,1,0,0, },
	['w'] = { 0,0,0,0,0,1,0,0,0,1,1,0,0,0,1,1,0,1,0,1,0,1,1,1,0, },
	['x'] = { 0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0, },
	['y'] = { 0,0,0,0,0,0,1,0,1,0,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0, },
	['z'] = { 0,0,0,0,0,0,1,1,1,0,0,0,1,1,0,0,1,1,0,0,0,1,1,1,0, },
	['~'] = { 0,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,0,0,0, },
};
#endif
