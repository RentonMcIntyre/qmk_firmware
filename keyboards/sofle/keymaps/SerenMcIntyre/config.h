#pragma once

#define SPLIT_USB_DETECT

#define MASTER_LEFT

#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#define SPLIT_TRANSPORT_MIRROR

#define SPLIT_WPM_ENABLE

#define ONESHOT_TAP_TOGGLE 1  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 1000  /* Time (in ms) before the one shot key is released */

/* The way how "handedness" is decided (which half is which),

see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness

for more options.

*/