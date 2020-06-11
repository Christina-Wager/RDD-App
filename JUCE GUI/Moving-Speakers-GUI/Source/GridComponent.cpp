/**
    This component contains the grid layout for the main window and renders the flexbox containers from the sub-windows.
*/

#include "GridComponent.h"


//==============================================================================
GridComponent::GridComponent ()
{
    //No reason to set window size here, it's done below and in Main.
    addAndMakeVisible(_filePanel);
}

GridComponent::~GridComponent()
{
    gridComponent = nullptr;
}

//==============================================================================
void GridComponent::paint (Graphics& g)
{
    //For the frame around the sub-window
    g.fillAll (Colour (0xff323e44));

    //For the working window (sub-window). For testing purposes it's filled with grey.
    g.setColour(Colour(84,84,84));
    g.fillRect(getLocalBounds().reduced(15,15));
}

void GridComponent::resized()
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
        grid.items = {GridItem(_filePanel)};

        grid.performLayout(window);
}

//==============================================================================
