/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{

	File midiSettingsFile(File::getCurrentWorkingDirectory().getChildFile("../../midiconfig.json"));

	if(_midiSettings.load(midiSettingsFile)) {

		Logger::writeToLog(_midiSettings.toString());


		// init midi controller
		_midiController = new rdd::MidiController(_midiSettings);

		_tabsComponent = new TabsComponent(_midiController);

		Logger::setCurrentLogger(&_logComponent);

		

		setSize(1600, 900);

		// let the midi controller listen for changes in the midiIO UI components
		//_midiInputComponent.addChangeListener(_midiController);
		//_midiOutputComponent.addChangeListener(_midiController);


		// enable or disable(default) logging of Midi message sending/receiving
		_midiController->enableLogging(true);

		// now you could send commands to all the selected outputs, e.g.
		 //_midiController->startCommand(rdd::MidiSettings::ROTATE_LEFT, 127);
		 //_midiController->stopCommand(rdd::MidiSettings::ROTATE_LEFT);
		 //_midiController->sendParameter(rdd::MidiSettings::MOVE_SPEED, 60);


	}
	else {

		AlertWindow::showMessageBox(AlertWindow::WarningIcon, "Error", "Failed to load MIDI settings from file 'midiconfig.json'", "Quit", this);
	
		JUCEApplication::getInstance()->systemRequestedQuit();
	}
}

MainComponent::~MainComponent()
{
	Logger::setCurrentLogger(nullptr);
	delete _tabsComponent;
	delete _midiController;
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    //g.setFont (Font (16.0f));
    //g.setColour (Colours::white);
    //g.drawText ("Hello World!", getLocalBounds(), Justification::centred, true);
    

	addAndMakeVisible(_tabsComponent);
	addAndMakeVisible(_logComponent);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.


	auto area = getLocalBounds();

	_logComponent.setBounds(area.removeFromBottom(300));
	_tabsComponent->setBounds(area);

    
 //   FlexBox fb;
	//fb.flexDirection = FlexBox::Direction::column;
	//fb.flexWrap = FlexBox::Wrap::noWrap;
	//fb.justifyContent = FlexBox::JustifyContent::center;
	//fb.alignContent = FlexBox::AlignContent::stretch;
	//fb.alignItems = FlexBox::AlignItems::stretch;

	//fb.items.add(FlexItem(900, 300, *_tabsComponent).withFlex(0.9f, 1.1f, 1.0f));
	//fb.items.add(FlexItem(900, 100, _logComponent));
	//
	//fb.performLayout(getLocalBounds().toFloat());
}
