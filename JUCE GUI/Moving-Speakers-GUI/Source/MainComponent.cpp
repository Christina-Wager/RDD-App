/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (900, 400);

	Logger::setCurrentLogger(&_logComponent);

	File midiSettingsFile(File::getCurrentWorkingDirectory().getChildFile("../../midiconfig.json"));

	if(_midiSettings.load(midiSettingsFile)) {

		Logger::writeToLog(_midiSettings.toString());


		// init midi controller
		_midiController = new rdd::MidiController(_midiSettings);

		// let the midi controller listen for changes in the midiIO UI components
		_midiInputComponent.addChangeListener(_midiController);
		_midiOutputComponent.addChangeListener(_midiController);


		// now you could send commands to all the selected outputs, e.g.
		// _midiController->startCommand(MidiSettings::ROTATE_LEFT, 127);
		// _midiController->stopCommand(MidiSettings::ROTATE_LEFT);
		// _midiController->sendParameter(MidiSettings::MOVE_SPEED, 60)


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
	addAndMakeVisible(_midiInputComponent);
	addAndMakeVisible(_midiOutputComponent);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.

	FlexBox fb2;
	fb2.flexDirection = FlexBox::Direction::row;
	fb2.flexWrap = FlexBox::Wrap::noWrap;
	fb2.justifyContent = FlexBox::JustifyContent::center;
	fb2.alignContent = FlexBox::AlignContent::stretch;
	fb2.alignItems = FlexBox::AlignItems::stretch;

	fb2.items.add(FlexItem(300, 300, _tabsComponent));
	fb2.items.add(FlexItem(300, 300, _midiInputComponent));
	fb2.items.add(FlexItem(300, 300, _midiOutputComponent));

    
    FlexBox fb;
	fb.flexDirection = FlexBox::Direction::column;
	fb.flexWrap = FlexBox::Wrap::noWrap;
	fb.justifyContent = FlexBox::JustifyContent::center;
	fb.alignContent = FlexBox::AlignContent::stretch;
	fb.alignItems = FlexBox::AlignItems::stretch;

	fb.items.add(FlexItem(900, 300, fb2).withFlex(0.9f, 1.1f, 1.0f));
	fb.items.add(FlexItem(900, 100, _logComponent));
	
	fb.performLayout(getLocalBounds().toFloat());
	fb2.performLayout(getLocalBounds().toFloat());
}
