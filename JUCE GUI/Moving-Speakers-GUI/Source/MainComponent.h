/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "LogComponent.h"
#include "TabsComponent.h"
#include "MidiSettings.h"
#include "MidiController.h"
#include "MidiInputDeviceSelectorComponent.h"
#include "MidiOutputDeviceSelectorComponent.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...

    LogComponent	_logComponent;
    TabsComponent	_tabsComponent;
	rdd::MidiSettings	_midiSettings;
	rdd::MidiController* _midiController;

	MidiInputDeviceSelectorComponent _midiInputComponent;
	MidiOutputDeviceSelectorComponent _midiOutputComponent;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
