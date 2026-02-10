#ifndef CONFIG_H
#define CONFIG_H

#include <gtk/gtk.h>

typedef struct {
	GdkModifierType leaderKey;
	guint searchKey;
	guint splitHorizontal;
	guint splitVertical;
	guint focusUp;
	guint focusDown;
	guint focusLeft;
	guint focusRight;
	bool isDefaultSplitHorizontal;
} Config;

Config defaultConfig = {
	.leaderKey = GDK_MOD1_MASK,
	.searchKey = GDK_KEY_s,
	.splitHorizontal = GDK_KEY_h,
	.splitVertical = GDK_KEY_v,
	.focusUp = GDK_KEY_uparrow,
	.focusDown = GDK_KEY_downarrow,
	.focusLeft = GDK_KEY_leftarrow,
	.focusRight = GDK_KEY_rightarrow,
	.isDefaultSplitHorizontal = true
};

#endif /* CONFIG_H */
