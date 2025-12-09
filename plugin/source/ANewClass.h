#pragma once

// Includes

// Forward declarations (if needed)
// class SomeClass;

/**
 * Brief description of what this class does
 */
class ANewClass {
public:
  //==============================================================================
  // Constructor & Destructor
  ANewClass();
  ~ANewClass();

  // Delete copy constructor and assignment (JUCE convention for audio classes)
  ANewClass(const ANewClass&) = delete;
  ANewClass& operator=(const ANewClass&) = delete;

  //==============================================================================
  // Public Interface - what users of this class need

  /** Prepares the processor for playback */
  void prepare(const juce::dsp::ProcessSpec& spec);

  /** Processes audio */
  void process(juce::dsp::ProcessContextReplacing<float>& context);

  /** Resets internal state */
  void reset();

  //==============================================================================
  // Getters/Setters (if needed)

private:
  //==============================================================================
  // Private helper methods

  //==============================================================================
  // Member variables

  double sampleRate = 44100.0;

  //==============================================================================
  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ANewClass)
};