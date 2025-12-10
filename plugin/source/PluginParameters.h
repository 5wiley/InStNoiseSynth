#pragma once

#include <juce_audio_processors/juce_audio_processors.h>

namespace audio_plugin {
namespace Parameters {

inline const juce::ParameterID volume{"volume", 1};
inline const juce::ParameterID symbolRate{"symbolRate", 1};
inline const juce::ParameterID slewIndex{"slewIndex", 1};
inline const juce::ParameterID modDepth{"modDepth", 1};

inline juce::AudioProcessorValueTreeState::ParameterLayout
createParameterLayout() {
  juce::AudioProcessorValueTreeState::ParameterLayout layout;

  layout.add(std::make_unique<juce::AudioParameterFloat>(
      volume, "Volume", juce::NormalisableRange<float>(0.0f, 1.0f, 0.01f),
      0.5f  // init val
      ));
  layout.add(std::make_unique<juce::AudioParameterFloat>(
      symbolRate, "Symbol Rate",
      juce::NormalisableRange<float>(500.0f, 5000.0f, 1.0f),
      0.5f  // init val
      ));
  layout.add(std::make_unique<juce::AudioParameterFloat>(
      slewIndex, "Slew Index",
      juce::NormalisableRange<float>(0.0f, 1.0f, 0.01f),
      0.5f  // init val
      ));
  layout.add(std::make_unique<juce::AudioParameterFloat>(
      modDepth, "Mod Depth", juce::NormalisableRange<float>(0.0f, 1.0f, 0.01f),
      0.5f  // init val
      ));

  return layout;
}
}  // namespace Parameters
}  // namespace audio_plugin