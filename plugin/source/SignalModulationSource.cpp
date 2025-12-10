// generates a new value every nHz when called every sample

#include "SignalModulationSource.h"

namespace audio_plugin {

SignalModulationSource::SignalModulationSource() {
  generateNewValue();
}
SignalModulationSource::~SignalModulationSource() {}

void SignalModulationSource::prepare(double newSampleRate) {
  sampleRate = newSampleRate;
  samplesPerSymbol = sampleRate / rate;
  sampleCounter = 0.0;
}

void SignalModulationSource::setRate(double rateHz) {
  rate = rateHz;
  samplesPerSymbol = sampleRate / rate;
}

float SignalModulationSource::getNextValue() {
  sampleCounter += 1.0;

  if (sampleCounter >= samplesPerSymbol) {
    sampleCounter -= samplesPerSymbol;
    // update current value
    generateNewValue();
  }

  return currentValue;
}

void SignalModulationSource::reset() {
  sampleCounter = 0.0;
  generateNewValue();
}

void SignalModulationSource::generateNewValue() {
  currentValue = random.nextFloat();
}
}  // namespace audio_plugin