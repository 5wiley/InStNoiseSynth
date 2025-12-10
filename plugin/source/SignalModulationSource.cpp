// generates a new value every nHz when called every sample

#include "SignalModulationSource.h"

namespace audio_plugin {

SignalModulationSource::SignalModulationSource() {
  linearSmoothedValue.setCurrentAndTargetValue(random.nextFloat());
}
SignalModulationSource::~SignalModulationSource() {}

void SignalModulationSource::prepare(double newSampleRate) {
  sampleRate = newSampleRate;
  samplesPerSymbol = sampleRate / rate;
  sampleCounter = 0.0;

  // 1000 / rate = signal rate in Ms
  double smoothingPeriodMs = (1000 / rate) / 0.2;
  linearSmoothedValue.reset(sampleRate, smoothingPeriodMs);
}

void SignalModulationSource::setRate(double rateHz) {
  rate = rateHz;
  samplesPerSymbol = sampleRate / rate;

  // 1000 / rate = signal rate in Ms
  double smoothingPeriodMs = (1000 / rate) * smoothingPeriodIndex;
  linearSmoothedValue.reset(sampleRate, smoothingPeriodMs);
}

void SignalModulationSource::setSlewIndex(double slewIndex) {
  smoothingPeriodIndex = slewIndex;
}

float SignalModulationSource::getNextValue() {
  sampleCounter += 1.0;

  if (sampleCounter >= samplesPerSymbol) {
    sampleCounter -= samplesPerSymbol;
    // update linear smoothed value
    generateNewValue();
  }

  return linearSmoothedValue.getNextValue();
}

void SignalModulationSource::reset() {
  sampleCounter = 0.0;
  generateNewValue();
}

void SignalModulationSource::generateNewValue() {
  targetValue = random.nextFloat();
  // returned in getNextValue
  linearSmoothedValue.setTargetValue(targetValue);
}
}  // namespace audio_plugin