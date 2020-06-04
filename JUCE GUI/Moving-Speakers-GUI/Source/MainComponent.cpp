/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (800, 600);

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
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

	addAndMakeVisible(_logComponent);
	addAndMakeVisible(_tabsComponent);
	addAndMakeVisible(_gridComponent);
}

void MainComponent::resized()
{
	Grid grid;
	using Track = Grid::TrackInfo;

	//_tabsComponent.setSize(getWidth(), 30);

	grid.templateRows = {Track(30_px), Track(3_fr), Track(1_fr)};
	grid.templateColumns = {Track(1_fr)};
	grid.items = {GridItem(_tabsComponent), GridItem(_gridComponent), GridItem(_logComponent)};
	grid.performLayout(getLocalBounds());

}
