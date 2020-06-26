

#include "ManualControl.h"


//==============================================================================
ManualControl::ManualControl ()
{
    addAndMakeVisible(_fileButtons);
}

ManualControl::~ManualControl()
{
    manualControl = nullptr;
}

//==============================================================================
void ManualControl::paint (Graphics& g)
{
    //For the frame around the sub-window
    g.fillAll (Colour (0xff323e44));

    //For the working window (sub-window). For testing purposes it's filled with grey.
    g.setColour(Colour(84,84,84));
    g.fillRect(getLocalBounds().reduced(15,15));
}

void ManualControl::resized()
{
    //This grid is restricted to the following sub-window
        Rectangle<int> window = getLocalBounds().reduced(15,15);

        Grid grid;

        using Track = Grid::TrackInfo;

        grid.templateRows   = { Track (1_fr), Track(1_fr), Track(1_fr), Track(1_fr)};
        grid.templateColumns = { Track(1_fr), Track(1_fr), Track(1_fr), Track(1_fr)};

        grid.justifyContent = Grid::JustifyContent::center;
        grid.alignContent = Grid::AlignContent::center;

        grid.setGap(20_px); //creates gutters between items 20 pixels wide/high

        //Wrapping logic changes relative to the shape of the window
        grid.autoFlow = (window.getHeight() > window.getWidth()) ? Grid::AutoFlow::rowDense
                                                             : Grid::AutoFlow::columnDense;

        //grid.items = {GridItem //panel items will be passed and filled into the grid
        grid.items = {GridItem(_fileButtons)};

        grid.performLayout(window);

}





//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ManualControl" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

