/*
  ==============================================================================

    MidiController.cpp
    Created: 18 Jun 2020 10:21:26am
    Author:  Oliver Mayer

  ==============================================================================
*/

#include "MidiController.h"
#include "MidiInputDeviceSelectorComponent.h"
#include "MidiOutputDeviceSelectorComponent.h"

using namespace rdd;

MidiController::MidiController(const MidiSettings& settings) {
	reconfigure(settings);
}


MidiController::~MidiController() {

}


void MidiController::reconfigure(const MidiSettings& settings) {
	_midiSettings = settings;
}


bool MidiController::addMidiInput(String midiInputIdentifier) {

	if (_midiInputIdentifiers.find(midiInputIdentifier) == _midiInputIdentifiers.end()) {

		if (!_deviceManager.isMidiInputDeviceEnabled(midiInputIdentifier))
			_deviceManager.setMidiInputDeviceEnabled(midiInputIdentifier, true);

		_deviceManager.addMidiInputDeviceCallback(midiInputIdentifier, this);

		_midiInputIdentifiers.insert(midiInputIdentifier);

		return true;
	}
	else
		return false;
}


bool MidiController::removeMidiInput(String midiInputIdentifier) {

	std::set<String>::iterator it = _midiInputIdentifiers.find(midiInputIdentifier);

	if (it != _midiInputIdentifiers.end()) {
		_deviceManager.removeMidiInputCallback(midiInputIdentifier, this);
		_midiInputIdentifiers.erase(it);
		return true;
	}
	else
		return false;
}


bool MidiController::addMidiOuput(String midiOutputIdentifier) {

	for (size_t i = 0; _midiOutputs.size(); i++) {
		if (_midiOutputs[i]->getIdentifier() == midiOutputIdentifier)
			return false;
	}


	auto outputsInfo = MidiOutput::getAvailableDevices();

	for (auto output : outputsInfo) {
		if (output.identifier == midiOutputIdentifier) {
			_midiOutputs.push_back(MidiOutput::openDevice(midiOutputIdentifier));
			return true;
		}
	}
	
	return false;
}


bool MidiController::removeMidiOutput(String midiOutputIdentifier) {

	for (std::vector<std::unique_ptr<MidiOutput>>::iterator it = _midiOutputs.begin(); it != _midiOutputs.end(); it++) {
		if ((*it)->getIdentifier() == midiOutputIdentifier) {
			_midiOutputs.erase(it);
			return true;
		}
	}

	return false;
}


void MidiController::startCommand(MidiSettings::BotCommand cmd, uint8 velocity) {

	MidiMessage m = MidiMessage::noteOn(_midiSettings.getChannel(), _midiSettings.getNote(cmd), velocity);

	for (size_t i = 0; i < _midiOutputs.size(); i++) {
		_midiOutputs[i]->sendMessageNow(m);
	}
}


void MidiController::stopCommand(MidiSettings::BotCommand cmd) {

	MidiMessage m = MidiMessage::noteOff(_midiSettings.getChannel(), _midiSettings.getNote(cmd));

	for (size_t i = 0; i < _midiOutputs.size(); i++) {
		_midiOutputs[i]->sendMessageNow(m);
	}
}


void MidiController::sendParameter(MidiSettings::BotParameter param, uint8 value) {
	MidiMessage m = MidiMessage::controllerEvent(_midiSettings.getChannel(), _midiSettings.getCC(param), value);

	for (size_t i = 0; i < _midiOutputs.size(); i++) {
		_midiOutputs[i]->sendMessageNow(m);
	}
}


void MidiController::handleIncomingMidiMessage(MidiInput* source, const MidiMessage& message) {
	// ....
}

void MidiController::changeListenerCallback(ChangeBroadcaster* source) {

	// ### QUICK AND DIRTY: remove all inputs and add all selected ones.
	//     TODO: only remove deselected and add newly selected.

	auto midiInSelector = dynamic_cast<MidiInputDeviceSelectorComponent*>(source);

	if (midiInSelector) {
		auto selectedInputs = midiInSelector->getSelectedDeviceIdentifiers();

		for (auto id : _midiInputIdentifiers) {
			removeMidiInput(id);
		}

		for (auto id : selectedInputs) {
			addMidiInput(id);
		}

		return;
	}



	// ### QUICK AND DIRTY: remove all outputs and add all selected ones.
	//     TODO: only remove deselected and add newly selected.

	auto midiOutSelector = dynamic_cast<MidiOutputDeviceSelectorComponent*>(source);

	if (midiOutSelector) {
		auto selectedOutputs = midiOutSelector->getSelectedDeviceIdentifiers();

		_midiOutputs.clear();

		for (auto id : selectedOutputs) {
			addMidiOuput(id);
		}


		startCommand(MidiSettings::ROTATE_LEFT, 127);

		stopCommand(MidiSettings::ROTATE_LEFT);

		sendParameter(MidiSettings::SPEAKER_SPEED, 40);

		return;
	}


}
