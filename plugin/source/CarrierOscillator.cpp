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

  // Allocate buffers, prepare child objects, etc.
}

//==============================================================================
float CarrierOscillator::processSample(float amplitudeModulation,
                                       float phaseModulation) {
  // Generate sine wave with AM
  auto currentPhase = phase + phaseModulation;
  auto sample = std::sin(currentPhase);

  // Apply AM
  sample *= amplitudeModulation;

  // Advance phase
  phase *= phaseIncrement;

  // Wrap phase
  while (phase >= std::numbers::pi * 2) {
    phase -= std::numbers::pi * 2;
  }

  return static_cast<float>(sample);
}

//==============================================================================

void CarrierOscillator::setFrequency(float frequencyHz) {
  frequency = frequencyHz;
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