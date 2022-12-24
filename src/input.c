#include <string.h>
#include "tophat.h"

extern th_global *thg;

#ifdef __linux__
#include <X11/keysym.h>

#define LINUX_KEY_SHIFT XK_Shift_L
#define LINUX_KEY_BACKSPACE XK_BackSpace
#define LINUX_KEY_DELETE XK_Delete
#define LINUX_KEY_LEFT_ARROW XK_Left
#define LINUX_KEY_RIGHT_ARROW XK_Right
#define LINUX_KEY_TOP_ARROW XK_Up
#define LINUX_KEY_BOTTOM_ARROW XK_Down
#define LINUX_KEY_ESCAPE XK_Escape
#define LINUX_KEY_ENTER XK_Return
#define LINUX_KEY_ALT XK_Alt_L
#define LINUX_KEY_CTRL XK_Control_L
#define LINUX_KEY_TAB XK_Tab
#define LINUX_KEY_PG_DOWN XK_Page_Down
#define LINUX_KEY_PG_UP XK_Page_Up
#define LINUX_KEY_HOME XK_Home
#define LINUX_KEY_END XK_End
#define LINUX_KEY_INSERT XK_Insert
#define LINUX_KEY_FN XK_F1
#endif

// https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
#define WIN_KEY_SHIFT (16 + 0x7f)
#define WIN_KEY_BACKSPACE (8 + 0x7f)
#define WIN_KEY_DELETE (46 + 0x7f)
#define WIN_KEY_LEFT_ARROW (37 + 0x7f)
#define WIN_KEY_RIGHT_ARROW (39 + 0x7f)
#define WIN_KEY_TOP_ARROW (38 + 0x7f)
#define WIN_KEY_BOTTOM_ARROW (40 + 0x7f)
#define WIN_KEY_ESCAPE (27 + 0x7f)
#define WIN_KEY_ENTER (13 + 0x7f)
#define WIN_KEY_ALT (0x12 + 0x7f)
#define WIN_KEY_CTRL (0x11 + 0x7f)
#define WIN_KEY_TAB (0x09 + 0x7f)
#define WIN_KEY_PG_DOWN (0x22 + 0x7f)
#define WIN_KEY_PG_UP (0x21 + 0x7f)
#define WIN_KEY_HOME (0x24 + 0x7f)
#define WIN_KEY_END (0x23 + 0x7f)
#define WIN_KEY_INSERT (0x2d + 0x7f)
#define WIN_KEY_FN (0x70 - 1)

void HandleKey( int keycode, int bDown ) { }
void HandleButton( int x, int y, int button, int bDown ) { }
void HandleMotion( int x, int y, int mask ) { }
void HandleDestroy() { }

void th_input_key(int keycode, int bDown) {
#ifdef __linux__
	switch (keycode) {
	case LINUX_KEY_SHIFT:
		keycode = WIN_KEY_SHIFT;
		break;
	case LINUX_KEY_BACKSPACE:
		keycode = WIN_KEY_BACKSPACE;
		break;
	case LINUX_KEY_DELETE:
		keycode = WIN_KEY_DELETE;
		break;
	case LINUX_KEY_LEFT_ARROW:
		keycode = WIN_KEY_LEFT_ARROW;
		break;
	case LINUX_KEY_RIGHT_ARROW:
		keycode = WIN_KEY_RIGHT_ARROW;
		break;
	case LINUX_KEY_TOP_ARROW:
		keycode = WIN_KEY_TOP_ARROW;
		break;
	case LINUX_KEY_BOTTOM_ARROW:
		keycode = WIN_KEY_BOTTOM_ARROW;
		break;
	case LINUX_KEY_ESCAPE:
		keycode = WIN_KEY_ESCAPE;
		break;
	case LINUX_KEY_ENTER:
		keycode = WIN_KEY_ENTER;
		break;
	case LINUX_KEY_ALT:
		keycode = WIN_KEY_ALT;
		break;
	case LINUX_KEY_CTRL:
		keycode = WIN_KEY_CTRL;
		break;
	case LINUX_KEY_TAB:
		keycode = WIN_KEY_TAB;
		break;
	case LINUX_KEY_PG_DOWN:
		keycode = WIN_KEY_PG_DOWN;
		break;
	case LINUX_KEY_PG_UP:
		keycode = WIN_KEY_PG_UP;
		break;
	case LINUX_KEY_HOME:
		keycode = WIN_KEY_HOME;
		break;
	case LINUX_KEY_END:
		keycode = WIN_KEY_END;
		break;
	case LINUX_KEY_INSERT:
		keycode = WIN_KEY_INSERT;
		break;
	case LINUX_KEY_FN:
		keycode = WIN_KEY_FN;
	}
#endif

	if (keycode > 255)
		return;

	if (!bDown) {
		if (thg->pressed[keycode])
			thg->just_released[keycode] = 1;
		thg->pressed[keycode] = 0;
		thg->just_pressed[keycode] = 0;
		return;
	}

	if (!thg->pressed[keycode]) {
		thg->pressed[keycode] = 1;
		thg->just_pressed[keycode] = 1;
		return;
	}

	thg->just_pressed[keycode] = 0;
}

void th_input_cycle() {
	memset(thg->just_pressed, 0, 255 * sizeof(uu));
	memset(thg->just_released, 0, 255 * sizeof(uu));
}
