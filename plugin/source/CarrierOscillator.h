#pragma once

// Includes
#include "SignalModulationSource.h"
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

  // Move semantics (needed for use in std::vector)
  CarrierOscillator(CarrierOscillator&&) = default;
  CarrierOscillator& operator=(CarrierOscillator&&) = default;

  //==============================================================================
  void prepare(double sampleRate);
  float processSample();
  void reset();

  //==============================================================================
  void setFrequency(double frequencyHz);
  double getFrequency() const noexcept { return frequency; }

private:
  //==============================================================================
  void updatePhaseIncrement();

  //==============================================================================
  // Phase accumulation
  double frequency = 1000.0;
  double phase = 0.0;
  double phaseIncrement = 0.0;
  double sampleRate = 44100.0;

  // Modulation
  SignalModulationSource ampModulator;
  SignalModulationSource phaseModulator;

  //==============================================================================
  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CarrierOscillator)
};
}  // namespace audio_plugin
