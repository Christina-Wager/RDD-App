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

#include "SettingsComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
SettingsComponent::SettingsComponent (rdd::MidiController* controller)
    : _midiController(controller)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..

	_midiInputComponent.addChangeListener(_midiController);
	_midiOutputComponent.addChangeListener(_midiController);

	addAndMakeVisible(_midiInputComponent);
	addAndMakeVisible(_midiOutputComponent);

    //[/Constructor]
}

SettingsComponent::~SettingsComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void SettingsComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void SettingsComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..

	// compute sum of child components' heights and maximum of child components' widths
	// to set as bounds of this component

	int w = 300;
	int h = 0;

	_midiInputComponent.resized();

	h += _midiInputComponent.getBounds().getHeight();

	if (_midiInputComponent.getBounds().getWidth() > w)
		w =  _midiInputComponent.getBounds().getWidth();


	_midiOutputComponent.resized();

	h += _midiOutputComponent.getBounds().getHeight();

	if (_midiOutputComponent.getBounds().getWidth() > w)
		w = _midiOutputComponent.getBounds().getWidth();

	setBounds(0, 0, w, h);

    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..

	// now position the child components

	auto area = getLocalBounds();

	_midiInputComponent.setBounds(area.removeFromTop(_midiInputComponent.getBounds().getHeight()));

	_midiOutputComponent.setBounds(area.removeFromTop(_midiOutputComponent.getBounds().getHeight()));


    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="SettingsComponent" componentName=""
                 parentClasses="public Component" constructorParams="rdd::MidiController* controller"
                 variableInitialisers="_midiController(controller)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="0"
                 initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

