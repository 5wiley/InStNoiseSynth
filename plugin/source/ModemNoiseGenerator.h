#pragma once

// Includes
#include "CarrierOscillator.h"
#include <juce_audio_processors/juce_audio_processors.h>
#include <juce_dsp/juce_dsp.h>
#include <vector>

/**
 * This manages n oscilators and their modulators to create a din of
 * modem noise.
 */

namespace audio_plugin {
class ModemNoiseGenerator {
public:
  ModemNoiseGenerator();
  ~ModemNoiseGenerator();

  void prepare(double newSampleRate);
  float processSamples();
  void reset();

  // parameters
  void setSymbolRate(double rateHz);
  void setModulationDepth(float modDepth);
  void setSlewIndex(double slewIndex);

private:
  // create a vector of CarrierOscillator objects from CarrierOscillator.h/cpp
  std::vector<CarrierOscillator> carriers;
  double sampleRate = 44100.0;
  // int numCarriers = 0;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ModemNoiseGenerator)
};
}  // namespace audio_plugin