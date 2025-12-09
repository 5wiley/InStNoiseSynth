#pragma once

// Includes
#include <juce_audio_processors/juce_audio_processors.h>
#include <juce_dsp/juce_dsp.h>

// Forward declarations (if needed)
// class SomeClass;

/**
 * Brief description of what this class does
 */
namespace audio_plugin {
class CarrierOscillator {
public:
  //==============================================================================
  // Constructor & Destructor
  CarrierOscillator();
  ~CarrierOscillator();

  //==============================================================================
  void prepare(double sampleRate);
  float processSample(float amplitudeModulation, float phaseModulation);
  void reset();

  //==============================================================================
  void setFrequency(float frequencyHz);
  float getFrequency() const noexcept { return frequency; };

private:
  //==============================================================================
  void updatePhaseIncrement();

  //==============================================================================
  float frequency = 1000.0f;
  double phase = 0.0;
  double phaseIncrement = 0.0;
  double sampleRate = 44100.0f;

  //==============================================================================
  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CarrierOscillator)
};
}  // namespace audio_plugin