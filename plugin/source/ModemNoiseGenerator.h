#pragma once

// Includes
#include "CarrierOscillator.h"
#include <juce_audio_processors/juce_audio_processors.h>
#include <juce_dsp/juce_dsp.h>
#include <vector>

namespace audio_plugin {
class ModemNoiseGenerator {
public:
  ModemNoiseGenerator();
  ~ModemNoiseGenerator();

  void prepare(double newSampleRate);
  float processSamples();
  void reset();

private:
  // create a vector of CarrierOscillator objects from CarrierOscillator.h/cpp
  std::vector<CarrierOscillator> carriers;
  double sampleRate = 44100.0;
  // int numCarriers = 0;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ModemNoiseGenerator)
};
}  // namespace audio_plugin