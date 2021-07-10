/**
 * @file Grandeur.cpp
 * @date 24.03.2020
 * @author Grandeur Technologies
 *
 * Copyright (c) 2019 Grandeur Technologies LLP. All rights reserved.
 * This file is part of the Arduino SDK for Grandeur.
 *
 */

#include "Grandeur.h"

Grandeur grandeur;

Grandeur::Grandeur() {}

Grandeur::Project::Project() {}

Grandeur::Project::Project(DuplexHandler* duplex) : _duplex(duplex) {}

Grandeur::Project Grandeur::init(String apiKey, String token) {
  // Setting config.
  _config = {apiKey, token};
  // Initializing duplex channel.
  _duplexHandler.init(_config);
  // Returning project.
  return Project(&_duplexHandler);
}

void Grandeur::Project::onConnection(void connectionCallback(bool)) {
  // Specifying connection handler for underlying duplex channel.
  _duplex->onConnectionEvent(connectionCallback);
}

void Grandeur::Project::clearConnectionCallback(void) {
  // Clearing connection handler of its underlying duplex channel.
  _duplex->clearConnectionCallback();
}

bool Grandeur::Project::isConnected(void) {
  return (_duplex->getStatus() == CONNECTED);
}

Grandeur::Project::Device Grandeur::Project::device(String deviceId) {
  // Return the new device object.
  return Device(_duplex, deviceId);
}

Grandeur::Project::Datastore Grandeur::Project::datastore(void) {
  // Return the new datastore object.
  return Datastore(_duplex);
}

void Grandeur::Project::loop(bool valve) {
  // Running duplex loop.
  _duplex->loop(valve);
}

void Grandeur::Project::loop() {
  // Running duplex loop.
  _duplex->loop(true);
}