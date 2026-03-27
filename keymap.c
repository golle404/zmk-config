#include QMK_KEYBOARD_H

enum custom_keycodes {
    MC_KS = SAFE_RANGE, // Ctrl+K → Ctrl+Shift+S  (VS Code Save All)
    SR_CCAR,            // č / Č
    SR_CACU,            // ć / Ć
    SR_SCAR,            // š / Š
    SR_ZCAR,            // ž / Ž
    SR_DSTR,            // đ / Đ
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MC_KS:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                tap_code(KC_K);
                unregister_code(KC_LCTL);
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                tap_code(KC_S);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
            }
            return false;
        case SR_CCAR:
            if (record->event.pressed) {
                uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                register_unicode(mods & MOD_MASK_SHIFT ? 0x010C : 0x010D);
                set_mods(mods);
            }
            return false;
        case SR_CACU:
            if (record->event.pressed) {
                uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                register_unicode(mods & MOD_MASK_SHIFT ? 0x0106 : 0x0107);
                set_mods(mods);
            }
            return false;
        case SR_SCAR:
            if (record->event.pressed) {
                uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                register_unicode(mods & MOD_MASK_SHIFT ? 0x0160 : 0x0161);
                set_mods(mods);
            }
            return false;
        case SR_ZCAR:
            if (record->event.pressed) {
                uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                register_unicode(mods & MOD_MASK_SHIFT ? 0x017D : 0x017E);
                set_mods(mods);
            }
            return false;
        case SR_DSTR:
            if (record->event.pressed) {
                uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                register_unicode(mods & MOD_MASK_SHIFT ? 0x0110 : 0x0111);
                set_mods(mods);
            }
            return false;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT( /* Base */
        KC_ESC,  KC_1,    KC_2,          KC_3,          KC_4,          KC_5,                            KC_6,    KC_7,          KC_8,             KC_9,            KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,          KC_E,          KC_R,          KC_T,                            KC_Y,    KC_U,          KC_I,             KC_O,            KC_P,    KC_DEL,
        KC_LSFT, KC_A,    KC_S,          KC_D,          KC_F,          KC_G,                            KC_H,    KC_J,          KC_K,             KC_L,            KC_SCLN, KC_QUOT,
        KC_LCTL, KC_Z,    LALT_T(KC_X),  LSFT_T(KC_C),  LCTL_T(KC_V),  KC_B,   MO(3),    KC_RBRC,      KC_N,    RCTL_T(KC_M),  RSFT_T(KC_COMM),  LALT_T(KC_DOT),  KC_SLSH, KC_BSLS,
        KC_LALT, KC_LGUI, LT(1,KC_DEL),  LT(4,KC_SPC),  LT(3,KC_ENT),  LT(2,KC_BSPC),    KC_APP,       KC_NO
    ),

    [1] = LAYOUT( /* Function / Symbols */
        KC_NO, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO, KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_NO,   KC_TILD, KC_PLUS, KC_EQL,  KC_LBRC, KC_RBRC, KC_NO,
        KC_NO, KC_F9,  KC_F10, KC_F11, KC_F12, KC_NO,   KC_GRV,  KC_UNDS, KC_MINS, KC_LCBR, KC_RCBR, KC_NO,
        KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
        KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO
    ),

    [2] = LAYOUT( /* Navigation */
        KC_NO, C(KC_GRV), KC_NO, KC_NO,         KC_NO, KC_NO,   KC_INS,  KC_HOME, KC_PSCR, KC_PGUP, KC_NO, KC_VOLU,
        KC_NO, KC_NO,     KC_NO, LCA(KC_EQL),   KC_NO, KC_NO,   KC_DEL,  KC_END,  KC_UP,   KC_PGDN, KC_NO, KC_VOLD,
        KC_NO, KC_NO,     MC_KS, KC_NO,         KC_NO, KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_MUTE,
        KC_NO, KC_NO,     KC_NO, KC_NO,         KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO, KC_NO,
        KC_NO, KC_NO,     KC_NO, KC_NO,         KC_NO, KC_NO,   KC_NO,   KC_NO
    ),

    [3] = LAYOUT( /* Mouse */
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,    MS_WHLU, MS_UP,   MS_WHLD, KC_NO,   KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   MS_BTN1,  MS_LEFT, MS_DOWN, MS_RGHT, MS_BTN2, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, MS_BTN3, KC_NO, KC_NO, KC_NO,    KC_NO
    ),

    [4] = LAYOUT( /* Numbers / Serbian */
        KC_NO, KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,                    SR_CCAR,  SR_CACU,    SR_SCAR,    SR_ZCAR,    SR_DSTR,    KC_NO,
        KC_NO, KC_EXLM, KC_AT,  KC_HASH, KC_DLR,  KC_PERC,                  KC_CIRC,  KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_NO,
        KC_NO, KC_1,    KC_2,   KC_3,    KC_4,    KC_5,                     KC_6,     KC_7,       KC_8,       KC_9,       KC_0,       KC_NO,
        KC_NO, KC_NO,   KC_NO,  KC_TILD, KC_GRV,  KC_NO,   KC_NO,  KC_NO,   KC_NO,    KC_UNDS,    KC_MINS,    KC_EQL,     KC_PLUS,    KC_NO,
                                KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,    KC_NO,      KC_NO
    ),

};
