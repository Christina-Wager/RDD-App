Read Me:
Copy "sequencer sample.xml" into JUCE/examples/Assets in your JUCE directory. 
This is where sample data is kept to test the table list box model used for the sequencer at the moment.

The Icons folder contains all external images used in the app. If they do not show up or throw missing reference errors, open the project in Projucer, create a new group called "Binary Assets" and drag and drop all images from Icons into this group. Projucer will then automatically detect them as binary resources and they can be referenced in-code.

Next steps:
> Currently, the components are in different tabs for testing purposes. The next step is to merge all Manual Control panels into the Manual Control tab.
> Add the logging component and animated map component to the Manual Control tab
> Incorporate the MIDI command interface for the map and rotation sliders
> Improve usability via aesthetics (new file option buttons, custom look-and-feel to avoid having to set colors for new components, improved rotary sliders, new sequencer background, resize components to accomodate PC users, compare grid vs flexbox vs hard-coded layouts regarding resizability)

Changes:
> Fewer header and class files (all Manual Control components are in the Manual Control header file). Separating GUI components into dozens of cpp and header files is good practice in C++, but creates a big mess with the JUCE API.
> Removal of the drag-and-drop panel functionality (for now). Letting the user resize and move panels around produced buggy layouts (laying out components in JUCE statically is difficult enough). For the moment, all components are added according to a pre-defined layout. If the drag-and-drop feature is something that end-users want to have very much, it can still be implemented in the future.

30.06.: merge all MC components, clean up layout, add the finished logging and map components.
01.07.: incorporate the MIDI command interface and set a default MIDI device
02.07.: test on MacOS (XCode) using VMWare on Windows