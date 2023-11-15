#include QMK_KEYBOARD_H

enum sofle_layers {
  /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */

  _QWERTY,
  _GAME,
  _GAME_MOD,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  KC_QWERTY = SAFE_RANGE,
  KC_GAME,
  KC_PRVWD,
  KC_NXTWD,
  KC_LSTRT,
  KC_LEND,
  KC_DLINE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*

* QWERTY
* ,-----------------------------------------.          ,-----------------------------------------.
* | `  |  1 |  2 |  3 |  4 |  5 |          |  6 |  7 |  8 |  9 |  0 | `  |
* |------+------+------+------+------+------|          |------+------+------+------+------+------|
* | ESC |  Q |  W |  E |  R |  T |          |  Y |  U |  I |  O |  P | Bspc |
* |------+------+------+------+------+------|          |------+------+------+------+------+------|
* | Tab |  A |  S |  D |  F |  G |-------.  ,-------|  H |  J |  K |  L |  ; | '  |
* |------+------+------+------+------+------| MUTE |  |    |------+------+------+------+------+------|
* |LShift|  Z |  X |  C |  V |  B |-------|  |-------|  N |  M |  , |  . |  / |RShift|
* `-----------------------------------------/    /   \   \-----------------------------------------'
*      | LGUI | LAlt | LCTR |LOWER | /Enter /    \Space \ |RAISE | RCTR | RAlt | RGUI |
*      |   |   |   |   |/    /     \   \ |   |   |   |   |
*      `----------------------------------'      '------''---------------------------'
*/
[_QWERTY] = LAYOUT(
 KC_GRV,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,           KC_6,  KC_7,  KC_8,  KC_9,  KC_0, KC_CAPS,
 KC_ESC,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,           KC_Y,  KC_U,  KC_I,  KC_O,  KC_P, KC_ENT,
 KC_TAB,  KC_A,  KC_S,  KC_D,  KC_F,  KC_G,           KC_H,  KC_J,  KC_K,  KC_L, KC_SCLN, KC_QUOT,
 OSM(MOD_LSFT), KC_Z,  KC_X,  KC_C,  KC_V,  KC_B, DF(_GAME),   XXXXXXX,KC_N,  KC_M, KC_COMM, KC_DOT, KC_SLSH, OSM(MOD_RSFT),
        KC_LGUI,KC_LALT,KC_LCTL, MO(_LOWER), KC_SPC,   KC_BSPC, MO(_RAISE), KC_DEL, KC_PSCR, KC_RGUI
),

/*

* COLEMAK
* ,-----------------------------------------.           ,-----------------------------------------.
* | `  |  1 |  2 |  3 |  4 |  5 |                       |  6 |  7 |  8 |  9 |  0 | `  |
* |------+------+------+------+------+------|          |------+------+------+------+------+------|
* | ESC |  Q |  W |  F |  P |  G |          |  J |  L |  U |  Y |  ; | Bspc |
* |------+------+------+------+------+------|          |------+------+------+------+------+------|
* | TAB |  A |  R |  S |  T |  D |-------.  ,-------|  H |  N |  E |  I |  O | '  |
* |------+------+------+------+------+------| MUTE |  |    |------+------+------+------+------+------|
* |LShift|  Z |  X |  C |  V |  B |-------|  |-------|  K |  M |  , |  . |  / |RShift|
* `-----------------------------------------/    /   \   \-----------------------------------------'
*      | LGUI | LAlt | LCTR |LOWER | /Enter /    \Space \ |RAISE | RCTR | RAlt | RGUI |
*      |   |   |   |   |/    /     \   \ |   |   |   |   |
*      `----------------------------------'      '------''---------------------------'

*/

[_GAME] = LAYOUT(
 KC_ESC,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,           KC_6,  KC_7,  KC_8,  KC_9,  KC_0, KC_NUM,
 KC_GRV,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,           KC_Y,  KC_U,  KC_I,  KC_O,  KC_P, KC_ENT,
 KC_TAB,  KC_A,  KC_S,  KC_D,  KC_F,  KC_G,           KC_H,  KC_J,  KC_K,  KC_L, KC_SCLN, KC_QUOT,
 OSM(MOD_LSFT), KC_Z,  KC_X,  KC_C,  KC_V,  KC_B, DF(_QWERTY),   XXXXXXX,KC_N,  KC_M, KC_COMM, KC_DOT, KC_SLSH, OSM(MOD_RSFT),
        KC_K,KC_LALT,KC_4, KC_SPC, MO(_GAME_MOD),   KC_BSPC, MO(_RAISE), KC_DEL, KC_PSCR, KC_RGUI
),


[_GAME_MOD] = LAYOUT(
 KC_6,  KC_7,  KC_8,  KC_9,  KC_0, KC_NUM,           KC_6,  KC_7,  KC_8,  KC_9,  KC_0, KC_NUM,
 KC_Y,  KC_U,  KC_I,  KC_O,  KC_P, KC_ENT,           KC_Y,  KC_U,  KC_I,  KC_O,  KC_P, KC_ENT,
 KC_H,  KC_A,  KC_S,  KC_D, KC_F, KC_QUOT,           KC_H,  KC_J,  KC_K,  KC_L, KC_SCLN, KC_QUOT,
 KC_N,  KC_M, KC_COMM, KC_C, KC_SLSH, OSM(MOD_RSFT), DF(_QWERTY),   XXXXXXX,KC_N,  KC_M, KC_COMM, KC_DOT, KC_SLSH, OSM(MOD_RSFT),
        KC_K,KC_LALT,MO(_LOWER), KC_SPC, KC_4,   KC_MPLY, MO(_RAISE), KC_MPRV, KC_MPLY, KC_MNXT
),

/* LOWER
* ,-----------------------------------------.          ,-----------------------------------------.
* |   | F1 | F2 | F3 | F4 | F5 |          | F6 | F7 | F8 | F9 | F10 | F11 |
* |------+------+------+------+------+------|          |------+------+------+------+------+------|
* | `  |  1 |  2 |  3 |  4 |  5 |          |  6 |  7 |  8 |  9 |  0 | F12 |
* |------+------+------+------+------+------|          |------+------+------+------+------+------|
* | Tab |  ! |  @ |  # |  $ |  % |-------.  ,-------|  ^ |  & |  * |  ( |  ) |  | |
* |------+------+------+------+------+------| MUTE |  |    |------+------+------+------+------+------|
* | Shift| =  | -  | +  |  { |  } |-------|  |-------|  [ |  ] |  ; |  : |  \ | Shift|
* `-----------------------------------------/    /   \   \-----------------------------------------'
*      | LGUI | LAlt | LCTR |LOWER | /Enter /    \Space \ |RAISE | RCTR | RAlt | RGUI |
*      |   |   |   |   |/    /     \   \ |   |   |   |   |
*      `----------------------------------'      '------''---------------------------'

*/

[_LOWER] = LAYOUT(
 _______,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,            KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11,
 KC_GRV,  KC_PIPE,  KC_PIPE,  KC_PIPE,  KC_PIPE,  KC_PIPE,            KC_EXLM,  KC_EXLM,  KC_EXLM,  KC_EXLM,  KC_EXLM, KC_F12,
 _______, KC_EXLM,  KC_AT, KC_HASH, KC_DLR, KC_PERC,            KC_CIRC, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_DQUO,
 _______, KC_EQL, KC_MINS, KC_PLUS, KC_AMPR, KC_ASTR, _______,    _______, KC_BSLS, KC_LBRC, KC_RBRC, KC_LT, KC_GT, _______,
           _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______

),

/* RAISE
* ,----------------------------------------.          ,-----------------------------------------.â¥?
* |   |   |   |   |   |   |          |   |   |   |   |   |   |?
* |------+------+------+------+------+------|          |------+------+------+------+------+------|
* | Esc | cut | copy |paste | prsr |   |          |   | 7 | 8 | 9 | DLine| Bspc |
* |------+------+------+------+------+------|          |------+------+------+------+------+------|
* | Tab | LEFT | UP |RIGHT |   | Caps |-------.  ,-------|   | 4 | 5 | 6 | Del | Bspc |
* |------+------+------+------+------+------| MUTE |  |    |------+------+------+------+------+------|
* |Undo | redo | DOWN | Copy | Paste|   |-------|  |-------|   | 1 |  2  | 3 |   | Shift|
* `-----------------------------------------/    /   \   \-----------------------------------------'
*      | LGUI | LAlt | LCTR |LOWER | /Enter /    \ 0 \ |RAISE | RCTR | RAlt | RGUI |
*      |   |   |   |   |/    /     \   \ |   |   |   |   |
*      `----------------------------------'      '------''---------------------------'
*/

[_RAISE] = LAYOUT(
 _______, _______ , _______ , _______ , _______ , _______,              _______, _______ , _______, _______ , _______ ,KC_CAPS,
 _______, KC_CUT, KC_COPY,  KC_PASTE, KC_PSCR, XXXXXXX,            KC_PSLS, KC_KP_7,  KC_KP_8, KC_KP_9,KC_PMNS, KC_BSPC,
 _______, KC_LALT, KC_LEFT, KC_UP, KC_RIGHT, XXXXXXX,            KC_PAST, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, KC_PDOT,
 KC_UNDO,KC_UNDO, KC_CUT, KC_DOWN, KC_PASTE, XXXXXXX, KC_BTN3,    KC_BTN1, KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3,  KC_PEQL, KC_PDOT,
            _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______
),

/* ADJUST
* ,-----------------------------------------.          ,-----------------------------------------.
* |   |   |   |   |   |   |          |   |   |   |   |   |   |
* |------+------+------+------+------+------|          |------+------+------+------+------+------|
* | QK_BOOT|   |QWERTY|COLEMAK|   |   |          |   |   |   |   |   |   |
* |------+------+------+------+------+------|          |------+------+------+------+------+------|
* |   |   |MACWIN|   |   |   |-------.  ,-------|   | VOLDO| MUTE | VOLUP|   |   |
* |------+------+------+------+------+------| MUTE |  |    |------+------+------+------+------+------|
* |   |   |   |   |   |   |-------|  |-------|   | PREV | PLAY | NEXT |   |   |
* `-----------------------------------------/    /   \   \-----------------------------------------'
*      | LGUI | LAlt | LCTR |LOWER | /Enter /    \Space \ |RAISE | RCTR | RAlt | RGUI |
*      |   |   |   |   |/    /     \   \ |   |   |   |   |
*      `----------------------------------'      '------''---------------------------'

*/

 [_ADJUST] = LAYOUT(
 XXXXXXX , XXXXXXX, XXXXXXX , XXXXXXX , XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
 QK_BOOT , XXXXXXX,KC_QWERTY,KC_GAME,CG_TOGG,XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
 XXXXXXX , XXXXXXX,CG_TOGG, XXXXXXX,  XXXXXXX, XXXXXXX,           XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
 XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
         _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
 )
};

  

#ifdef OLED_ENABLE

static void print_status_narrow(void) {
  // Print current mode
  oled_write_P(PSTR("\n\n"), false);
  oled_write_ln_P(PSTR("MODE"), false);
  oled_write_ln_P(PSTR(""), false);

  if (keymap_config.swap_lctl_lgui) {
    oled_write_ln_P(PSTR("MAC"), false);
  } else {
    oled_write_ln_P(PSTR("WIN"), false);
  }

  switch (get_highest_layer(default_layer_state)) {
    case _QWERTY:
      oled_write_ln_P(PSTR("QWERT"), false);
      break;
    case _GAME:
      oled_write_ln_P(PSTR("GAME"), false);
      break;
    case _RAISE:
      oled_write_ln_P(PSTR("NUM"), false);
      break;
    default:
      oled_write_P(PSTR("Undef"), false);
  }

  oled_write_P(PSTR("\n\n"), false);
  // Print current layer
  oled_write_ln_P(PSTR("LAYER"), false);

  switch (get_highest_layer(layer_state)) {
    case _GAME:
    case _QWERTY:
      oled_write_P(PSTR("Base\n"), false);
      break;
    case _RAISE:
      oled_write_P(PSTR("Raise"), false);
      break;
    case _GAME_MOD:
      oled_write_P(PSTR("Game Fancy"), false);
      break;
    case _LOWER:
      oled_write_P(PSTR("Lower"), false);
      break;
    case _ADJUST:
      oled_write_P(PSTR("Adj\n"), false);
      break;
    default:
      oled_write_ln_P(PSTR("Undef"), false);
  }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master()) {
    return OLED_ROTATION_270;
  }

  return OLED_ROTATION_270;
}

bool oled_tracker = false;

static const char PROGMEM image1[] = {
  // 'planet-svgrepo-com', 32x32px
  0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xe0, 0xe0, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x10, 0x38, 0x10, 0x00, 0x00, 0x40, 0xe0, 0xe0, 0x40, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xc0, 0x60, 0x60, 0x30, 0xb0, 0xd0, 0xf8, 0x78, 0x18, 0x04, 0x06, 0x02, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x03, 0x02, 0x06, 0x0c, 0x18, 0x78, 0xf8, 0xd0, 0xb0, 0x30, 0x60, 0xc0, 0xc0, 0x00,
  0x03, 0x0f, 0x0c, 0x18, 0x32, 0x37, 0x2c, 0x6f, 0x78, 0x78, 0xf8, 0xd8, 0xd0, 0xd0, 0xd0, 0xd0,
  0xd0, 0xd0, 0xd0, 0x58, 0xd8, 0xf8, 0x78, 0x6c, 0x2f, 0x2e, 0x37, 0x10, 0x18, 0x0c, 0x0f, 0x03,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x08, 0x00, 0x00, 0x01, 0x01, 0x03, 0x02, 0x02,
  0x02, 0x02, 0x03, 0x01, 0x01, 0x00, 0x04, 0x04, 0x1a, 0x1b, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00
};

static const char PROGMEM image2[] = {
  // 'planet-svgrepo-com', 32x32px
  0x00, 0x00, 0x00, 0x00, 0x40, 0xe0, 0xe0, 0x40, 0x00, 0x00, 0x10, 0x38, 0x10, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xe0, 0xe0, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xc0, 0xc0, 0x60, 0x30, 0xb0, 0xd0, 0xf8, 0x78, 0x18, 0x0c, 0x06, 0x02, 0x03, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x02, 0x06, 0x04, 0x18, 0x78, 0xf8, 0xd0, 0xb0, 0x30, 0x60, 0x60, 0xc0, 0x00,
  0x03, 0x0f, 0x0c, 0x18, 0x10, 0x37, 0x2e, 0x2f, 0x6c, 0x78, 0xf8, 0xd8, 0x58, 0xd0, 0xd0, 0xd0,
  0xd0, 0xd0, 0xd0, 0xd0, 0xd8, 0xf8, 0x78, 0x78, 0x6f, 0x2c, 0x37, 0x32, 0x18, 0x0c, 0x0f, 0x03,
  0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x1b, 0x1a, 0x04, 0x04, 0x00, 0x01, 0x01, 0x03, 0x02, 0x02,
  0x02, 0x02, 0x03, 0x01, 0x01, 0x00, 0x00, 0x08, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void render_spacey_stuff(void) {
  oled_write_P(PSTR("\n\n"), false);
  oled_write_P(PSTR("WPM: "), false);
  oled_write(get_u8_str(get_current_wpm(), ' '), false);
  oled_write_P(PSTR("\n\n"), false);   

  if (oled_tracker) {
   oled_write_raw_P(image2, sizeof(image2));
  } else { 
    oled_write_raw_P(image1, sizeof(image1)); 
  }
}

bool oled_task_user(void) {
  if (!is_keyboard_master()) {
    print_status_narrow();
  } else {
    render_spacey_stuff();
  }

  return false;
}
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool should_process_keypress(void) { return true; }
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
   oled_tracker ^= 1;
  }

  switch (keycode) {
    case KC_QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }

      return false;
    case KC_GAME:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_GAME);
      }

      return false;
    case KC_PRVWD:
      if (record->event.pressed) {
        if (keymap_config.swap_lctl_lgui) {
          register_mods(mod_config(MOD_LALT));
        } else {
          register_mods(mod_config(MOD_LCTL));
        }

        register_code(KC_LEFT);
      } else {
        if (keymap_config.swap_lctl_lgui) {
          unregister_mods(mod_config(MOD_LALT));
        } else {
          unregister_mods(mod_config(MOD_LCTL));
        }

        unregister_code(KC_LEFT);
      }

      break;
    case KC_NXTWD:
      if (record->event.pressed) {
        if (keymap_config.swap_lctl_lgui) {
          register_mods(mod_config(MOD_LALT));
        } else {
          register_mods(mod_config(MOD_LCTL));
        }

        register_code(KC_RIGHT);
      } else {
        if (keymap_config.swap_lctl_lgui) {
          unregister_mods(mod_config(MOD_LALT));
        } else {
          unregister_mods(mod_config(MOD_LCTL));
        }

        unregister_code(KC_RIGHT);
      }

      break;
    case KC_LSTRT:
      if (record->event.pressed) {
        if (keymap_config.swap_lctl_lgui) {
          //CMD-arrow on Mac, but we have CTL and GUI swapped
          register_mods(mod_config(MOD_LCTL));
          register_code(KC_LEFT);
        } else {
          register_code(KC_HOME);
        }
      } else {
        if (keymap_config.swap_lctl_lgui) {
          unregister_mods(mod_config(MOD_LCTL));
          unregister_code(KC_LEFT);
        } else {
          unregister_code(KC_HOME);
        }

      }

      break;
    case KC_LEND:
      if (record->event.pressed) {
        if (keymap_config.swap_lctl_lgui) {
          //CMD-arrow on Mac, but we have CTL and GUI swapped
          register_mods(mod_config(MOD_LCTL));
          register_code(KC_RIGHT);
        } else {
          register_code(KC_END);
        }
      } else {
        if (keymap_config.swap_lctl_lgui) {
          unregister_mods(mod_config(MOD_LCTL));
          unregister_code(KC_RIGHT);
        } else {
          unregister_code(KC_END);
        }
      }

      break;
    case KC_DLINE:
      if (record->event.pressed) {
        register_mods(mod_config(MOD_LCTL));
        register_code(KC_BSPC);
      } else {
        unregister_mods(mod_config(MOD_LCTL));
        unregister_code(KC_BSPC);
      }

      break;
    case KC_COPY:
      if (record->event.pressed) {
        register_mods(mod_config(MOD_LCTL));
        register_code(KC_C);
      } else {
        unregister_mods(mod_config(MOD_LCTL));
        unregister_code(KC_C);
      }

      return false;
    case KC_PASTE:
      if (record->event.pressed) {
        register_mods(mod_config(MOD_LCTL));
        register_code(KC_V);
      } else {
        unregister_mods(mod_config(MOD_LCTL));
        unregister_code(KC_V);
      }

      return false;
    case KC_CUT:
      if (record->event.pressed) {
        register_mods(mod_config(MOD_LCTL));
        register_code(KC_X);
      } else {
        unregister_mods(mod_config(MOD_LCTL));
        unregister_code(KC_X);
      }

      return false;
    case KC_UNDO:
      if (record->event.pressed) {
        register_mods(mod_config(MOD_LCTL));
        register_code(KC_Z);
      } else {
        unregister_mods(mod_config(MOD_LCTL));
        unregister_code(KC_Z);
      }

      return false;
  }

  return true;
}

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  switch(index) { 
    case 0:
      tap_code(clockwise ? KC_UP : KC_DOWN);
      break;
    case 1: 
      tap_code(clockwise ? KC_LEFT : KC_RIGHT);
      break;
  }

  return false;
}
#endif