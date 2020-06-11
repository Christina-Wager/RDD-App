/*
  Created with Projucer version: 5.4.7
*/


#include "FilePanel.h"

//==============================================================================
FilePanel::FilePanel ()
{
    addAndMakeVisible(fileButtons.add(new TextButton("Save")));
    addAndMakeVisible(fileButtons.add(new TextButton("Load")));
    addAndMakeVisible(fileButtons.add(new TextButton("Import")));
    addAndMakeVisible(fileButtons.add(new TextButton("Export")));
}

FilePanel::~FilePanel ()
{

}

//==============================================================================
void FilePanel::paint (Graphics& g)
{

}

void FilePanel::resized()
{
    FlexBox fb;
    fb.flexWrap = FlexBox::Wrap::wrap;
    fb.justifyContent = FlexBox::JustifyContent::center;
    fb.alignContent = FlexBox::AlignContent::center;

    for (auto* b : fileButtons)
        fb.items.add(FlexItem(*b).withMinWidth(60.0f).withMinHeight(40.0f));

    fb.performLayout(getLocalBounds().toFloat());
}


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="FilePanel" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif




