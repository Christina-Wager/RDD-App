/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (600, 400);

	Logger::setCurrentLogger(&_logComponent);

	File midiSettingsFile(File::getCurrentWorkingDirectory().getChildFile("../../midiconfig.json"));

	if(_midiSettings.load(midiSettingsFile)) {

		Logger::writeToLog(_midiSettings.toString());
	}
	else {

		AlertWindow::showMessageBox(AlertWindow::WarningIcon, "Error", "Failed to load MIDI settings from file 'midiconfig.json'", "Quit", this);
	
		JUCEApplication::getInstance()->systemRequestedQuit();
	}
}

MainComponent::~MainComponent()
{
	Logger::setCurrentLogger(nullptr);
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    //g.setFont (Font (16.0f));
    //g.setColour (Colours::white);
    //g.drawText ("Hello World!", getLocalBounds(), Justification::centred, true);
    
    
	addAndMakeVisible(_logComponent);
	addAndMakeVisible(_tabsComponent);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    
    FlexBox fb;
	fb.flexDirection = FlexBox::Direction::column;
	fb.flexWrap = FlexBox::Wrap::noWrap;
	fb.justifyContent = FlexBox::JustifyContent::center;
	fb.alignContent = FlexBox::AlignContent::stretch;
	fb.alignItems = FlexBox::AlignItems::stretch;

	fb.items.add(FlexItem(600, 300, _tabsComponent).withFlex(0.9f, 1.1f, 1.0f));
	fb.items.add(FlexItem(600, 100, _logComponent));
	
	fb.performLayout(getLocalBounds().toFloat());
}
