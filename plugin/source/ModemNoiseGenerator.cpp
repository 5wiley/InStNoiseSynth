#include "ModemNoiseGenerator.h"

namespace audio_plugin {

// V.34 training sequence frequencies (21 carriers)
static const double carrierFrequencies[] = {
    150.0,  318.0,  486.0,  654.0,  822.0,  990.0,  1158.0,
    1326.0, 1494.0, 1662.0, 1830.0, 1998.0, 2166.0, 2334.0,
    2502.0, 2670.0, 2838.0, 3006.0, 3174.0, 3342.0, 3510.0};

// Constructor
ModemNoiseGenerator::ModemNoiseGenerator() {
  // create n carriers
  carriers.resize(21);
  for (size_t i = 0; i < carriers.size(); ++i) {
    carriers[i].setFrequency(carrierFrequencies[i]);
  }
}

ModemNoiseGenerator::~ModemNoiseGenerator() {}

void ModemNoiseGenerator::prepare(double newSampleRate) {
  sampleRate = newSampleRate;
}

float ModemNoiseGenerator::processSamples() {
  float mixedSample = 0.0;

  for (auto& carrier : carriers) {
    mixedSample += carrier.processSample(1.0, 0.0);
  }

  // average out the 21 oscillators
  mixedSample *= (1.0f / 21.0f);

  return mixedSample;
}

void ModemNoiseGenerator::reset() {
  for (auto& carrier : carriers) {
    carrier.reset();
  }
}

}  // namespace audio_plugin
