#include "pico/binary_info.h"

bi_decl(bi_2pins_with_names(25, "Bit Clock", 24, "L/R Clock"));
bi_decl(bi_2pins_with_names(26, "L/R Audio In", 27, "3/4 Audio In"));
bi_decl(bi_2pins_with_names(28, "MIDI Out (from synth)", 29, "MIDI In (to synth)"));

#define LRCLK_PIN 24
#define BCLK_PIN 25
#define LRDAT_PIN 26
#define AUXDAT_PIN 27
#define MIDI_FROM_SYNTH_PIN 28
#define MIDI_TO_SYNTH_PIN 29

#define DEBUG_PIN 5