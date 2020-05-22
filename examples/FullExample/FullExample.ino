/**
 * @file FullExample.ino
 * @date 24.03.2020
 * @author Grandeur Technologies
 *
 * Copyright (c) 2019 Grandeur Technologies LLP. All rights reserved.
 * This file is part of the Arduino SDK for Grandeur Cloud.
 *
 * Apollo.h is used for device's communication to Grandeur Cloud.
 */

#include <Apollo.h>

String deviceID = "YOUR-DEVICE-ID";
String apiKey = "YOUR-PROJECT-APIKEY";
String token = "YOUR-ACCESS-TOKEN";
String ssid = "YOUR-WIFI-SSID";
String passphrase = "YOUR-WIFI-PASSWORD";

unsigned long current = millis();
ApolloDevice device;

void setup() {
    Serial.begin(9600);
    // Initialize the global object "apollo" with your configurations.
    device = apollo.init(deviceID, apiKey, token, ssid, passphrase);
    
    // This sets a callback function to be called when the device's makes/breaks
    // its WiFi connection
    device.onWiFiConnection([](JSONObject updateObject) {
      switch((int) updateObject["event"]) {
        case CONNECTED:
          Serial.println("Device WiFi is connected.");
          break;
        case DISCONNECTED:
          Serial.println("Device WiFi is disconnected.");
          break;
      }
    });

    // This sets a callback function to be called when the device makes/breaks
    // connection with the cloud
    device.onConnection([](JSONObject updateObject) {
      switch((int) updateObject["event"]) {
        case CONNECTED:
          Serial.println("Device is connected to the cloud.");

          // Initializing the millis counter for the five
          // seconds timer.
          current = millis();
          break;
        case DISCONNECTED:
          Serial.println("Device is disconnected from the cloud.");
          break;
      }
    });

    // This sets a callback function to be called when someone changes device's
    // summary on the Cloud.
    device.onSummaryUpdated([](JSONObject updatedSummary) {
      Serial.printf("Updated Voltage is: %d\n", (int) updatedSummary["voltage"]);
      Serial.printf("Updated Current is: %d\n", (int) updatedSummary["current"]);

      /* Here you can set some pins or trigger events that depend on
      ** device's summary update.
      */
    });

    // This sets a callback function to be called when someone changes device's
    // parms on the Cloud.
    device.onParmsUpdated([](JSONObject updatedParms) {
      Serial.printf("Updated State is: %d\n", (bool) updatedParms["state"]);

      /* Here you can set some pins or trigger events that depend on
      ** device's parms update.
      */  
    });
}

void loop() {
  if(device.getState() == APOLLO_CONNECTED) {
    if(millis() - current >= 5000) {
      // This if-condition makes sure that the code inside this block runs only after
      // every five seconds.

      // Requests the cloud for device's summary.
      Serial.println("Getting Summary");
      device.getSummary([](JSONObject payload) {
        if(payload["code"] == "DEVICE-SUMMARY-FETCHED") {
          // If there were no problems in fetching the device's summary.
          Serial.printf("voltage: %d, current: %d\n",
              (int) payload["deviceSummary"]["voltage"],
              (int) payload["deviceSummary"]["current"])
          ;

          /* You can set some pins or trigger events that depend on
          ** device's summary here.
          */

          return;
        }
        // If for some reason, summary could not be fetched.
        Serial.println("Failed to Fetch Summary");
        return;
      });


      // Gets the device's parms from the Cloud
      Serial.println("Getting Parms");
      device.getParms([](JSONObject payload) {
        if(payload["code"] == "DEVICE-PARMS-FETCHED") {
          Serial.printf("state: %d\n", (int) payload["deviceParms"]["state"]);

          /* You can set some pins or trigger events that depend on
          ** device's parms here.
          */
          return;
        }
        Serial.println("Failed to Fetch Parms");
        return;
      });

      // This updates the device's summary on the Cloud
      Serial.println("Setting Summary");
      JSONObject summary;
      summary["voltage"] = 3.3;
      summary["current"] = 0.01;
      device.setSummary(summary, [](JSONObject payload) {
        if(payload["code"] == "DEVICE-SUMMARY-UPDATED") {
          Serial.printf("Voltage is updated to: %d\n", (int) payload["update"]["voltage"]);
          Serial.printf("Current is updated to: %d\n", (int) payload["update"]["current"]);

          /* You can set some pins or trigger events that depend on successful
          ** device summary update here.
          */
          return;
        }
        Serial.println("Failed to Update Summary");
      });

      // This updates the device's parms to "true" on the Cloud
      Serial.println("Setting Parms");
      JSONObject parms;
      parms["state"] = true;
      device.setParms(parms, [](JSONObject payload) {
        if(payload["code"] == "DEVICE-PARMS-UPDATED") {
          Serial.printf("State is updated to: %d\n", (bool) payload["update"]["state"]);

          /* You can set some pins or trigger events that depend on successful
          ** device parms update here.
          */
          return;
        }
        Serial.println("Failed to Update Parms");
        return;
      });

      // This updates the millis counter for
      // the five seconds scheduler.
      current = millis();
    }
  }
  // Keep updating the TCP buffer
  device.update();
}
