Tom's keyboard layout
=====================
I have an `Atreus <https://atreus.technomancy.us/>`_ with
`this firmware <https://github.com/tlevine/tmk_keyboard/blob/tlevine/keyboard/atreus/keymap_tlevine.c>`_.
I designed this firmware with the following main goals.

* The keyboard should work well with Dvorak-style software keymaps.
* It should be easy to adjust the layout with xkb symbols maps.
* There should be only two layers, and the second layer should use a momentary
  switch rather than, for example, a toggle switch.

I intend for the keyboard to be used in X windows with this line in my ``.xinitrc``. ::

    setxkbmap -option compose:paus -option caps:shiftlock \
      -option compose:sclk -option compose:prse

It should mostly work nicely with any X keyboard layout, but I make custom
layouts for different languages so that they have different letters but similar
punctuation, as that typically changes mostly uselessly between languages.

An alternative I considered
---------------------------
I am usually of the opinion that I want as much as possible to be configured
in the main computer's operating system, as this makes the configuration and
installation more organized and generally easier for me. I used to be of this
view with keyboards, so I would do any configuration in X windows and avoid
"hardware Dvorak" keyboards. But I considered putting everything in the
firmware, for a few reasons.

1. The Dvorak-inspired keyboard layouts make many non-letter changes that
   I consider arbitrary and thus not worth learning.
2. I have seen the power of custom firmware to design layouts for particular
   hardwares.
3. When submitting a new keyboard layout to the X keyboard library,
   you are required to write a file so that it may be selected from the
   graphical interface. I usually don't install this interface, I don't know
   how to use it, and I couldn't find good documentation on the file format.
   The difficulty of submitting a keyboard layout upstream detracts from
   the utility of putting all the configuration in software.
4. I can add physical switches to my own keyboards so I can set their layouts
   without using mode keys.

I decided against it because it the USB HID keyboard protocol provides a very
small set of characters that you may send, so sending characters for languages
other than English would have been difficult.

Modes
------
Modes can change based on the layer and the language.

This firmware has two layers: Letters and functions. The keyboard is in
function mode if the function key is pressed, and it is otherwise in letter mode.

The firmware provides shift, super/gui/windows, control, and alt keys.
These modes are like layers,
but those modes are created by the operating system after it receives the input
from the keyboard, so I consider these keys to be ordinary keys within
the context of the firmware.

Top three rows
------------------------------------
The first three rows change a lot according to the layout. I base it on these
rows from standard (English) Dvorak.

Letters mode
^^^^^^^^^^^^
The top three rows form is a typical qwerty layout.

.. csv-table::

    q, w, e, r, t, y, u, i, o, p
    a, s, d, f, g, h, j, k, l, ;
    z, x, c, v, b, n, m,"," ., /


Function layer
^^^^^^^^^^^^^^^^^^^
The function layer includes some necessary to support my
use of X windows, diacritics, and vim.

.. csv-table::

    `     PAUS, UP,   DEL,  -,                =,    KP 3, KP 4, [,    ]
    PGUP, LEFT, DOWN, RGHT, HOME,             1,    2,    3,    4,    5
    PGDN, KP 1, KP 2, CAPS, END,              6,    7,    8,    9,    0

The punctuation is chosen so a Dvorak layout works nicely.

* Minus (-) and equals (=) correspond, respectively to left brace ([) and
  right brace (]) in a Dvorak layout.
* Left brace ("[") maps to slash ("/") in Dvorak.
* Right brace (]) corresponds to equal (=).
* The positions of left and right brace match those on the TypeMatrix 2030.

This number layout is nice for a few reasons.

* It's easier to type 1, 2, 3, and 0.
* 9 and 0 are next to each other, so the ( and ) are also next to each other.
* 6 is left of 4, so the vim command ^ is left of $

Some other notes

* It is easy to map pause ("PAUS") to the compose key with setxkbmap options.
* I excluded keys that I would never purposely use.
* The shift key is on the left side, and the layout is mostly split such that
  the right side contains the keys that are often pressed with shift.

Bottom row
-----------
The final row is based on the standard Atreus layout, and it is very similar
between letters and punctiation/digits mode. It purposely uses few keys that
change mappings among typical software keymaps.

.. csv-table::

    Letters,  ESC, KP /, LGUI, LSFT, BSPC, LCTL, LALT,  SPC,  FN,  \\,   SRLK, KP_ENT
    Function, ESC, RESET,RGUI, RSFT, BSPC, RCTL, RALT,  TAB,  FN,  \\,   PRSN, ENT

I try to allow for many different software configurations while making it still
easy to remember the layout.

* Whenever a shift, control, or alt key occurs in the letter layer, it is the
  left version of the key. Whenever such a key occurrs in the punctuation/digits
  layer, it is the right version of the key. This lets me set them to all
  different things in the software.
* I use enter (ENT) and keypad enter (KP_ENT) for the same effect as above.
* The reset button is for updating the keyboard's firmware. I put it in the
  place that I thought was hardest to type.
* It is easy to map scroll lock ("SRLK") and print screen ("PSRN")
  to map to the compose key with setxkbmap options.

It also should not change depending on the software keymap.

* It is unlikely that different keyboard layouts would change the mappings of
  any of the keys that I chose.
* I provide the keypad slash so I know where a slash is if I choose a software
  layout where [ does not correspond to /. Keypad slash emits a slash
  regardless of whether shift is pressed, and this is why I have put it on the
  key that becomes reset in the function layer.

And, where I can, I try to make it match what I already know.

* It mostly follows the standard Atreus layouts.
* The position of \\ matches the position on the TypeMatrix 2030

It seems like a waste that backslash appears on both layers. I will look for
some use for the second one. It might be fine to leave it, as can be hard to
press this button and the function button at the same time.
