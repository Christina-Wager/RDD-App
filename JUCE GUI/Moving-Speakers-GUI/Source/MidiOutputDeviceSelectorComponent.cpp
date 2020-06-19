/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.7

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "MidiOutputDeviceSelectorComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MidiOutputDeviceSelectorComponent::MidiOutputDeviceSelectorComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
	_deviceManager.addChangeListener(this);
	refreshDeviceList();

	//[/Constructor_pre]


	//[UserPreSize]
	//[/UserPreSize]

	setSize(300, 200);


	//[Constructor] You can add your own custom stuff here..
	setSize(300, 20 + (1 + _buttons.size()) * 30);
    //[/Constructor]
}

MidiOutputDeviceSelectorComponent::~MidiOutputDeviceSelectorComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MidiOutputDeviceSelectorComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MidiOutputDeviceSelectorComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
	int y = 10;

	setSize(300, 20 + (1 + _buttons.size()) * 30);

	_label.setBounds(10, y, getWidth() - 20, 20);

	for (std::map<String, ToggleButton*>::iterator it = _buttons.begin(); it != _buttons.end(); it++) {
		y += 30;
		it->second->setBounds(10, y, getWidth() - 20, 20);
	}
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void MidiOutputDeviceSelectorComponent::refreshDeviceList() {

	// for every device check the tmp buttons array if a button already exists. If not create new button
	std::map<String, ToggleButton*>::iterator it;
	std::map<String, ToggleButton*> tmpButtons;

	auto midiOutputs = MidiOutput::getAvailableDevices();

	for (auto output : midiOutputs) {
		it = _buttons.find(output.identifier);

		// if device already existed
		if (it != _buttons.end()) {
			tmpButtons.insert(std::pair<String, ToggleButton*>(output.identifier, it->second));
			_buttons.erase(it);
		}
		else {
			ToggleButton* b = new ToggleButton(output.name);
			addAndMakeVisible(b);
			b->onClick = [this, output] { onDeviceButtonToggled(output.identifier); };
			tmpButtons.insert(std::pair<String, ToggleButton*>(output.identifier, b));
		}
	}

	// delete buttons of devices not available anymore
	for (it = _buttons.begin(); it != _buttons.end(); it++) {
		delete it->second;
	}

	_buttons = tmpButtons;
}


void MidiOutputDeviceSelectorComponent::onDeviceButtonToggled(String identifier) {

	std::map<String, ToggleButton*>::iterator it = _buttons.find(identifier);

	if (it != _buttons.end()) {

		if (it->second->getToggleState()) {
			_selectedDeviceIdentifiers.insert(identifier);
		}
		else {
			_selectedDeviceIdentifiers.erase(identifier);
		}
	}
}


void MidiOutputDeviceSelectorComponent::changeListenerCallback(ChangeBroadcaster* source) {
	refreshDeviceList();
}

const std::set<String>& MidiOutputDeviceSelectorComponent::getSelectedDeviceIdentifiers() {
	return _selectedDeviceIdentifiers;
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MidiOutputDeviceSelectorComponent"
                 componentName="" parentClasses="public Component, public ChangeListener"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="300"
                 initialHeight="200">
  <BACKGROUND backgroundColour="ff323e44"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

