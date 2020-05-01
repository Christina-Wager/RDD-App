/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class Movingspeakers0_1AudioProcessorEditor  : public AudioProcessorEditor
{
public:
    Movingspeakers0_1AudioProcessorEditor (Movingspeakers0_1AudioProcessor&);
    ~Movingspeakers0_1AudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Movingspeakers0_1AudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Movingspeakers0_1AudioProcessorEditor)
};
