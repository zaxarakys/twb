#ifndef CONFIG_H
#define CONFIG_H

#include "twb.h"

typedef struct {
	GdkModifierType leaderKey;
	guint searchKey;
	guint splitHorizontal;
	guint splitVertical;
	guint focusUp;
	guint focusDown;
	guint focusLeft;
	guint focusRight;
	gboolean isDefaultSplitHorizontal;
} Config;

Config defaultConfig = {
	.leaderKey = GDK_ALT_MASK,
	.searchKey = GDK_KEY_s,
	.splitHorizontal = GDK_KEY_h,
	.splitVertical = GDK_KEY_v,
	.focusUp = GDK_KEY_uparrow,
	.focusDown = GDK_KEY_downarrow,
	.focusLeft = GDK_KEY_leftarrow,
	.focusRight = GDK_KEY_rightarrow,
	.isDefaultSplitHorizontal = TRUE
};

#endif /* CONFIG_H */
