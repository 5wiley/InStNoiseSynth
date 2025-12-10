#include "CarrierOscillator.h"
#include <cmath>
#include <numbers>

//==============================================================================
namespace audio_plugin {
// Constructor
CarrierOscillator::CarrierOscillator() {
  updatePhaseIncrement();
}

//==============================================================================
// Destructor
CarrierOscillator::~CarrierOscillator() {
  // RAII handles most cleanup, but manual cleanup goes here if needed
}

//==============================================================================
void CarrierOscillator::prepare(double newSampleRate) {
  sampleRate = newSampleRate;
  updatePhaseIncrement();

  phaseModulator.prepare(sampleRate);
  ampModulator.prepare(sampleRate);

  // Allocate buffers, prepare child objects, etc.
}

//==============================================================================
float CarrierOscillator::processSample() {
  float ampMod = ampModulator.getNextValue();
  float phaseMod = phaseModulator.getNextValue();

  // scale and transform into a double
  double phaseModScaled =
      (static_cast<double>(phaseMod) * 2.0 - 1.0) * std::numbers::pi;
  double ampModScaled = static_cast<double>(ampMod) * 2.0 - 1.0;

  // Generate sine wave with PM
  auto currentPhase = phase + phaseModScaled;
  double sample = std::sin(currentPhase);

  // Apply AM
  sample *= ampModScaled;

  // Advance phase
  phase += phaseIncrement;

  // Wrap phase
  while (phase >= std::numbers::pi * 2) {
    phase -= std::numbers::pi * 2;
  }

  return static_cast<float>(sample);
}

//==============================================================================

void CarrierOscillator::setFrequency(double frequencyHz) {
  frequency = frequencyHz;
  updatePhaseIncrement();
}

//==============================================================================
void CarrierOscillator::updatePhaseIncrement() {
  phaseIncrement = std::numbers::pi * 2 * frequency / sampleRate;
}

//==============================================================================
void CarrierOscillator::reset() {
  phase = 0.0;
}
}  // namespace audio_plugin
