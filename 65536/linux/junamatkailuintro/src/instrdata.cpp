#include "parameters.h"
#include "common.hpp"
static int syn1_channel_params[k_num_synth_params] =
{
  58981,
  0,
  27647,
  19797,
  32767,
  0,
  58981,
  3071,
  40275,
  20479,
  53247,
  0,
  58981,
  7167,
  37203,
  21161,
  32767,
  0,
  65535,
  32779,
  32767,
  49151,
  65535,
  65535,
  65535,
  32789,
  32767,
  49151,
  65535,
  65535,
  65535,
  32802,
  32767,
  49151,
  65535,
  65535,
  32767,
  0,
  0,
  0,
  0,
  0,
  2047,
  65535,
  0,
  32767,
  32767,
  32874,
  13107,
  2790,
  0,
  8874,
  32767,
  32767,
  32767,
  0,
  3071,
  0,
  0,
  32083,
  7577,
  0,
  0,
  0,
  0,
  64,
  2047,
  60755,
  0,
  0,
  32767,
  65535,
  0,
  0,
  0,
  65535,
  65535,
};

static int syn2_channel_params[k_num_synth_params] =
{
  26214,
  32985,
  32767,
  65535,
  32767,
  0,
  65535,
  32985,
  32767,
  0,
  32767,
  0,
  65535,
  25994,
  32767,
  0,
  32767,
  0,
  39321,
  41220,
  15700,
  15359,
  32767,
  17065,
  65535,
  36560,
  47103,
  65535,
  65535,
  0,
  65535,
  32804,
  32767,
  49151,
  65535,
  0,
  65535,
  0,
  6143,
  0,
  0,
  39321,
  18089,
  65535,
  50857,
  65535,
  32767,
  32767,
  13107,
  9898,
  7987,
  11604,
  32767,
  32767,
  32767,
  63,
  12970,
  65535,
  0,
  12287,
  6893,
  0,
  0,
  0,
  0,
  130,
  6825,
  0,
  0,
  0,
  24575,
  65535,
  7509,
  8533,
  0,
  65535,
  65535,
};

static int syn3_channel_params[k_num_synth_params] =
{
  65535,
  65535,
  31060,
  34815,
  24575,
  35152,
  65535,
  65535,
  36522,
  24916,
  39935,
  40618,
  26214,
  32818,
  32767,
  65535,
  32767,
  0,
  65535,
  32789,
  32767,
  49151,
  57343,
  34130,
  65535,
  65535,
  32767,
  49151,
  8191,
  27988,
  65535,
  65535,
  32767,
  49151,
  16383,
  18773,
  32767,
  0,
  0,
  0,
  0,
  13107,
  35152,
  0,
  7167,
  0,
  32767,
  32767,
  39321,
  44368,
  65535,
  0,
  10922,
  19796,
  36522,
  63,
  6553,
  29695,
  13107,
  16383,
  5868,
  0,
  0,
  0,
  0,
  4,
  13107,
  3411,
  1365,
  0,
  40959,
  65535,
  8191,
  13994,
  0,
  65535,
  65535,
};

static int syn4_channel_params[k_num_synth_params] =
{
  26214,
  60073,
  38228,
  65535,
  64851,
  65535,
  65535,
  49151,
  30719,
  0,
  43348,
  65535,
  65535,
  32820,
  32767,
  65535,
  32767,
  0,
  65535,
  32791,
  32767,
  49151,
  65535,
  33450,
  65535,
  65535,
  32767,
  65535,
  65535,
  40618,
  65535,
  11605,
  32767,
  0,
  65535,
  36863,
  32767,
  0,
  0,
  0,
  0,
  26214,
  20479,
  10581,
  0,
  32767,
  32767,
  53588,
  65535,
  26963,
  65535,
  0,
  43007,
  24916,
  36522,
  13,
  64852,
  0,
  0,
  10922,
  42734,
  0,
  0,
  0,
  0,
  65,
  40959,
  0,
  0,
  0,
  41300,
  9557,
  19455,
  33450,
  0,
  65535,
  65535,
};

static int syn5_channel_params[k_num_synth_params] =
{
  58981,
  26214,
  32767,
  65535,
  32767,
  0,
  13107,
  19660,
  32767,
  33450,
  32767,
  0,
  65535,
  25994,
  32767,
  0,
  32767,
  0,
  65535,
  20833,
  31401,
  32767,
  40959,
  65535,
  65535,
  32791,
  37887,
  49151,
  40959,
  0,
  65535,
  32805,
  0,
  32767,
  65535,
  0,
  32767,
  0,
  0,
  0,
  0,
  0,
  5461,
  19796,
  32425,
  32767,
  32767,
  34131,
  13107,
  2417,
  0,
  0,
  32767,
  32767,
  32767,
  682,
  19455,
  7850,
  13107,
  12629,
  6553,
  0,
  0,
  0,
  0,
  130,
  3071,
  59391,
  4437,
  0,
  32767,
  65535,
  0,
  0,
  0,
  65535,
  65535,
};

static int syn6_channel_params[k_num_synth_params] =
{
  19660,
  32985,
  34473,
  52223,
  37886,
  0,
  58981,
  32985,
  31743,
  58708,
  39593,
  0,
  65535,
  36590,
  32767,
  50515,
  17407,
  0,
  65535,
  5119,
  16383,
  49151,
  65535,
  44713,
  65535,
  32791,
  32767,
  49151,
  65535,
  0,
  65535,
  32804,
  32767,
  49151,
  65535,
  0,
  32767,
  0,
  0,
  0,
  0,
  0,
  20821,
  7167,
  0,
  44713,
  33450,
  36863,
  39321,
  18431,
  14335,
  0,
  34474,
  32767,
  32767,
  63,
  6210,
  7849,
  8874,
  11604,
  6553,
  0,
  0,
  0,
  0,
  129,
  11466,
  65535,
  3754,
  0,
  32767,
  65535,
  48127,
  24916,
  0,
  65535,
  37887,
};

static int syn7_channel_params[k_num_synth_params] =
{
  58981,
  26214,
  32767,
  65535,
  32767,
  0,
  65535,
  32985,
  32767,
  0,
  32767,
  0,
  65535,
  25995,
  32767,
  0,
  32767,
  0,
  65535,
  32780,
  32767,
  49151,
  0,
  0,
  65535,
  32793,
  32767,
  49151,
  8191,
  1023,
  65535,
  32806,
  32767,
  49151,
  16383,
  0,
  32767,
  0,
  0,
  0,
  0,
  0,
  16383,
  0,
  0,
  32767,
  32767,
  32767,
  65535,
  65535,
  13107,
  0,
  32767,
  32767,
  32767,
  65,
  6553,
  32767,
  13107,
  15223,
  6553,
  0,
  0,
  0,
  0,
  131,
  4300,
  60292,
  19797,
  0,
  37546,
  48127,
  30036,
  30378,
  0,
  65535,
  65535,
};

static int fx1_channel_params[FX::k_num_fx_params] =
{
  65535,
  1023,
  46761,
  38911,
  42324,
  4094,
};

#if defined(USE_REVERB)
 static int fx2_channel_params[FX::k_num_fx_params] =
{
  39321,
  0,
  7167,
  26622,
  11946,
  3412,
};

#endif