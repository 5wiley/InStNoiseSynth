#pragma once

#include <juce_audio_processors/juce_audio_processors.h>
#include <juce_core/juce_core.h>
#include <random>

namespace audio_plugin {
class SignalModulationSource {
public:
  SignalModulationSource();
  ~SignalModulationSource();

  // Move semantics (needed for use in std::vector)
  SignalModulationSource(SignalModulationSource&&) = default;
  SignalModulationSource& operator=(SignalModulationSource&&) = default;

  void prepare(double newSampleRate);
  void setRate(double rateHz);
  float getNextValue();
  void reset();

private:
  void generateNewValue();

  juce::Random random;
  juce::LinearSmoothedValue<float> linearSmoothedValue;
  double sampleRate = 44100.0;
  double rate = 3000.0;
  double samplesPerSymbol = 0.0;
  double sampleCounter = 0.0;
  float targetValue = 0.0f;
};
}  // namespace audio_plugin