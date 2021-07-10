# Grandeur [![Version](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://cloud.grandeur.tech)

Building a smart (IoT) product is an art because it is about unifying the physical world with the digital one. When you put a piece of hardware on the web, magic happens. But one device on the web is one thing. Think about tens of them, interconnected, forging an automated ecosystem of pure reverie. Now imagine tens of thousands of these ecosystems spread throughout the globe. Seems profound, no? But developing an IoT product and then managing it is just as profoundly difficult. It involves development across a huge technology stack (your IoT hardware itself, your apps to monitor/control your hardware and a server backend to manage them both) to make such products work in production. And then in production comes the hardest challenge; you are going to have to scale it up as your user base grows.

We understand this because we have been there.

Introducing Grandeur: A backend as a service (Baas) platform for IoT. We have designed this platform so you do not have to worry about the backend of your next big thing, and can focus on what matters the most: your hardware and your apps. It is designed specifically to accelerate your IoT product development and push your products to market in weeks rather than in months or years. So you can then actually build *grandeur* ecosystems like the one above.

## Why Grandeur

Grandeur is designed keeping in mind all the challenges a hardware engineer can face in developing and commercializing a smart (IoT) product. And we made available out-of-the-box APIs to help you integrate your devices and apps.

For example, you can use the **Auth API** to create *register* and *login* flows and make sure each user has access to its own data and no one other than the device admin itself should be able to interact with its device. You can store a humongous amount of data in cloud database to analyze and extract intelligent information from it and display useful graphs. Use our **datastore API** for that. You can host your product's website and your web app on Grandeur as well. It's **as simple as running literally a single command**. Also, your hardware device can listen for events and updates from your app, your app can listen for events and updates from your hardware device, and they can communicate with each other in realtime (with a latency of ~200ms). **Devices API** and **Device SDK** come into play here. But in no way would you have to waste your time in mixing and matching the APIs, checking which one works for your use case, and go through a huge learning curve -- like you would do while working with AWS or Google Cloud Platform. All the Grandeur APIs are completely integrated and speed and security is built in. The SDKs are designed around the whole ideology of **seamless integration.** 

Grandeur is not a regular IoT backend. It's a complete IoT product development and management platform, designed for production environments. Here's how:

* Grandeur is product-centered. It is much more than just a medium of communication between your app and your hardware device. Focusing on expediting IoT product development, it offers an ecosystem of the most necessary tools integrated to make the most head-cracking development problems seamless. What problems you may ask?
  * Huge development stack (Your IoT product which is generally hardware, your web app, your server API, and the communication between all of these).
  * Your database design and management.
  * Setting up and maintaining your servers handling your compute, storage, and networking.
  * Web development (backend of your server, frontend of your web apps).
  * Your IoT product development itself.
  * Scaling your system up to hundreds of thousands of devices as your business grows.

* No need to mix and match various services to come up with your own solution. Grandeur is a single spot solution for all of your needs, from **built-in authentication** of your users and devices to **an integrated database** to an **out-of-the-box file storage system** and a registry of data for all of your devices. And You can manage absolutely everything from a single dashboard.

* [Grandeur Canvas](https://grandeur.tech) is the latest addition to the Grandeur family. It lets you drag and drop widgets — like buttons, sliders, displays, and graphs — to sketch a layout which you can use instead of coding a full app. This means you do not have to have app designers in your team before starting to build IoT — a single hardware engineer is a beast with Grandeur.

* Simple pricing. Unlike Google and AWS, we do not have to deal with a different pricing model for each service and aggregate them together to compute the monthly bill making it almost impossible for the user to understand why he has to pay this much! Focusing just on solving IoT has let us develop a very simple and transparent pricing model. You can [start free][Grandeur Sign Up] for a certain quota and then pay as you go based on your resources consumption. Checkout [pricing][Grandeur Pricing] for more details.

* We have a growing [community on Hackster][Grandeur Hackster] which is equivalent to growing number of developers which are using Grandeur and improving the opensource SDKs resulting in increasing Grandeur support.

* It is terrifically simple to [get started][Get Started with Grandeur] with your IoT product development. Just create a project from the [cloud dashboard][Grandeur Dashboard], plug your project's API key into our SDKs and start developing.

Follow [our Hackster Hub][Grandeur Hackster] for quick starts and advanced development projects.

[Here][Get Started With Grandeur] is how you can create a new project on Grandeur and start using the Javascript SDK to build your IoT apps.

[Here][Get Started With Grandeur Canvas] is how you can drag-and-drop your app in seconds.

From here onwards, we'll look at how you can use the Arduino SDK for all arduino-compatible modules to put your devices live and connected on Grandeur. Let's dive in!

# Arduino SDK

**Arduino SDK** is the official SDK for arduino-compatible hardware modules and it utilizes the *Grandeur* API to connect your device to **[Grandeur][Grandeur]**.

Follow the [get started][Get Started with Arduino SDK] guidelines to quickly get into the context of integrating your devices to Grandeur or jump straight to an [Arduino example][Example] to make your hands dirty.

For a developer reference for the Arduino SDK, you can have a look at the [documentation][Documentation].

To get a deeper understanding of the core concepts Grandeur is built upon, dive into the [Grandeur Ecosystem][Ecosystem] section.

* [Get Started](#get-started)
  * [Installation](#installation)
  * [Inclusion](#inclusion)
  * [Initialization](#initialization)
  * [Handling the WiFi](#handling-the-wifi)
  * [Setting Up the Valve](#setting-up-the-valve)
  * [Events Listening](#events-listening)
  * [Fetching Device Variables and Updating Them](#fetching-device-variables-and-updating-them)
  * [Handling Updates From Grandeur](#handling-updates-from-the-cloud)
* [Example](#example)
* [The Dexterity of Arduino SDK](#the-dexterity-of-arduino-sdk)
* [Grandeur Ecosystem](#grandeur-ecosystem)
  * [A Brief Case Study](#a-brief-case-study)
  * [Concepts](#concepts)
    * [Project](#project)
    * [SDK](#SDK)
    * [User and Administrator](#user-and-administrator)
    * [Device](#device)
    * [Device Registry](#device-registry)
    * [Models](#models)
    * [Authentication and Access](#authentication-and-access)
    * [Networking](#networking)
    * [Allowed Origins](#allowed-origins)
* [Documentation](#documentation)
    * [init](#init)
  * [Project](#project)
    * [isConnected](#isconnected)
    * [onConnection](#onconnection)
    * [loop](#loop)
    * [device](#device-function)
    * [datastore](#datastore)
  * [Device](#device-class)
    * [Data](#data)
      * [get](#get)
      * [set](#set)
      * [on](#on)
  * [Datastore](#datastore)
    * [insert](#insert)
    * [search](#search)
* [Enhancements Under Consideration](#enhancements-under-consideration)

## Get Started

### Installation

1. You can search for **Grandeur** in Arduino's library manager. In Arduino IDE, open `Sketch > Include Library > Manage Libraries` and install Grandeur from there.

2. You can also download the latest release of **Arduino SDK** from [here][Latest Release] and [install it in your Arduino IDE][Installing an Arduino Library].

### Inclusion

When you include `<Grandeur.h>` in your sketch, a global object `grandeur` is created right away which you can use to give the SDK credentials so it can start connecting with Grandeur (more on it in the next step).

```cpp
#include <Grandeur.h>

// **RESULT**
// Includes the SDK in your sketch and defines the global object grandeur.
```

### Initialization

Initialization is as simple as calling `grandeur.init()` with your credentials (Your project's API Key and device's Access Token). The SDK uses your API key to know which project, and device ID and access token to know which device. It then returns a `Project` object which exposes other subclasses like `Device` and `Datastore`, and you can go programming your device from there.

```cpp
#include <Grandeur.h>

Project myProject;

void setup() {
  // You can initialize device configurations like this.
  myProject = grandeur.init(YourAPIKey, AccessToken);
}

void loop() {}

// **RESULT**
// Initializes the SDK's configurations and returns Project reference.
```

As soon as you call `grandeur.init()`, the SDK uses the configurations to start trying to connect with the your project on Grandeur. But it cannot reach Grandeur if the device is not already connected to a WiFi.

### Handling the WiFi

You can use a WiFi library corresponding to your microcontroller to handle your device's WiFi. Here are some popular ones:

* **ESP8266**: https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi
* **ESP32**:  https://github.com/espressif/arduino-esp32/tree/master/libraries/WiFi
* **Arduino WiFi Shield**: https://www.arduino.cc/en/Reference/WiFi

Here we illustrate how to handle your ESP8266's WiFi.

```cpp
#include <Grandeur.h>
#include <ESP8266WiFi.h>

Project myProject;

void setupWiFi(void) {
  Serial.begin(9600);
  // Disconnecting WiFi if it"s already connected
  WiFi.disconnect();
  // Setting it to Station mode which basically scans for nearby WiFi routers
  WiFi.mode(WIFI_STA);
  // Begin connecting to WiFi
  WiFi.begin(YourWiFiSSID, YourWiFiPassphrase);
  Serial.printf("\nDevice is connecting to WiFi using SSID %s and Passphrase %s.\n", ssid.c_str(), passphrase.c_str());
}

void setup() {
  Serial.begin(9600);
  // This sets up the device WiFi.
  setupWiFi();
  // You can initialize device configurations like this.
  myProject = grandeur.init(YourApiKey, AccessToken);
}

void loop() {
  // This runs the SDK when the device WiFi is connected.
  myProject.loop(WiFi.status() == WL_CONNECTED);
}

```

### Setting Up the Valve

You can see this line in the previous subsection: `myProject.loop(WiFi.status() == WL_CONNECTED)`, but what does that mean?

`loop` function is what runs the SDK: it connects with the cloud; when disconnected, it automatically reconnects; pulls new messages from the cloud; pushes messages to the cloud; and so on. But doing any sort of communication on the internet is useless until the WiFi isn't connected. That's exactly what the statement does: it acts like a **valve** for the SDK. The conditional expression passed to the `loop` function decides when the SDK would run and when it would not. In this case, it would only run when the WiFi is connected, causing `WiFi.status() == WL_CONNECTED` expression to evaluate to `true`. If while running, the WiFi gets disconnected, `WiFi.status() == WL_CONNECTED` would evaluate to `false` and the SDK would stop running.

### Setting Up Connection Event Handler

You can also listen on SDK's connection-related events. For example, to run some code when the device makes a successful connection to the cloud or when the device's connection to the cloud breaks, you can wrap that code in a `Callback` function and pass it to `Project`'s `onConnection()` function.

The `Callback` function is a special type of function that accepts a `Var` as a parameter and returns `void`. Read more about `Callback` and `Var` [here][var].

Here's how you can handle the connection event:

```cpp
#include <Grandeur.h>
#include <ESP8266WiFi.h>

Project myProject;

void setupWiFi(void) {
  Serial.begin(9600);
  // Disconnecting WiFi if it"s already connected.
  WiFi.disconnect();
  // Setting it to Station mode which basically scans for nearby WiFi routers.
  WiFi.mode(WIFI_STA);
  // Begin connecting to WiFi.
  WiFi.begin(YourWiFiSSID, YourWiFiPassphrase);
  Serial.printf("\nDevice is connecting to WiFi using SSID %s and Passphrase %s.\n", ssid.c_str(), passphrase.c_str());
}

void connectionCallback(bool status) {
  // This method handles the events related to device's connection with Grandeur.
  switch(status) {
    case CONNECTED:
      // If the connection event occurred.
      Serial.println("Device Connected to Grandeur!\n");
      break;
    case DISCONNECTED:
      // If the disconnection event occurred.
      Serial.println("Device Disconnected from Grandeur!\n");
      break;
  }
}

void setup() {
  Serial.begin(9600);
  // This sets up the device WiFi.
  setupWiFi();
  // You can initialize device configurations like this.
  myProject = grandeur.init(YourApiKey, YourDeviceToken);
  // Setting up listener for device's connection event
  myProject.onConnection(connectionCallback);
}

void loop() {
  // This runs the SDK when the device WiFi is connected.
  myProject.loop(WiFi.status() == WL_CONNECTED);
}

// **RESULT**
// Prints "Device Connected to Grandeur!\n" when device gets connected to the cloud.
// And prints "Device Disconnected from Grandeur!\n" when device's connection from
// the cloud breaks.
```

### Fetching Device Variables and Updating Them

On Grandeur, a device has a special space where you can store its variables as key-value pairs, for example, a device's voltage or current or its ON/OFF state. Keeping the online copy of device variables updated gives you many advantages. You can see if your device is ON/OFF just by fetching its `state` from Grandeur.

Both `data().get()` and `data().set()` are **Async functions** because they communicate with Grandeur through internet. Communication through internet takes some time and we cannot wait, for example, for a device variable to arrive from Grandeur — meanwhile blocking the rest of the device program execution. So, what we do is, we schedule a function to be called for the future when the variable arrives and resume with rest of the device program, forgetting that we ever called `data().get()`. When the variable arrives, the SDK calls our scheduled function, giving us access to that variable inside that function.

Read more about **Async functions**, `Callback`, and `Var` [here][the dexterity of arduino sdk].

Here's how we would get and set device variables:

```cpp
#include <Grandeur.h>
#include <ESP8266WiFi.h>

Project myProject;
Device myDevice;

void setupWiFi(void) {
  Serial.begin(9600);
  // Disconnecting WiFi if it"s already connected.
  WiFi.disconnect();
  // Setting it to Station mode which basically scans for nearby WiFi routers.
  WiFi.mode(WIFI_STA);
  // Begin connecting to WiFi.
  WiFi.begin(YourWiFiSSID, YourWiFiPassphrase);
  Serial.printf("\nDevice is connecting to WiFi using SSID %s and Passphrase %s.\n", ssid.c_str(), passphrase.c_str());
}

void getCallback(Var result) {
  // This function prints the variables stored in summary and sets the device pins.
  Serial.printf("Voltage: %s\n", (int) result["data"]);
  analogWrite(A0, (int) result["data"]);
}

void setCallback(Var result) {
  // This function prints the updated values of the variables stored in summary.
  Serial.printf("Updated Voltage: %s\n", (int) result["update"]);
}

void setup() {
  Serial.begin(9600);
  // This sets up the device WiFi.
  setupWiFi();
  // You can initialize device configurations like this.
  myProject = grandeur.init(YourApiKey, AccessToken);
  myDevice = myProject.device(YourDeviceID);
}

void loop() {

  if(myProject.isConnected()) {
    // Getting voltage variable
    myDevice.data().get("voltage", getCallback);
    // Updating voltage
    int voltage = analogRead(A0);
    myDevice.data().set("voltage", voltage, setCallback);
  }

  // This runs the SDK when the device WiFi is connected.
  myProject.loop(WiFi.status() == WL_CONNECTED);
}

// **RESULT**
// When the loop() starts, voltage is fetched. When it arrives from the cloud, getCallback is
// called which prints its value and sets the A0 pin.
// Then the voltage is updated with the new value from the A0 pin. When the update completes,
// setCallback is called with the updated values of voltage which is printed.
```

### Handling Updates From Grandeur

You can not only `get()/set()` but also subscribe to a device variable, which means if an update occurs in that variable at any time, you'll instantly get notified of it.
To subscribe to a variable, you just need to pass the variable name and a function to `data().on()`. The function you pass to `data().on()` is set as an **update handlers** for that variable, which means the code inside that function will be run whenever that variable is updated.

Let's set an update handler for device voltage now:

```cpp
#include <Grandeur.h>
#include <ESP8266WiFi.h>

Project myProject;
Device myDevice;

void setupWiFi(void) {
  Serial.begin(9600);
  // Disconnecting WiFi if it"s already connected.
  WiFi.disconnect();
  // Setting it to Station mode which basically scans for nearby WiFi routers.
  WiFi.mode(WIFI_STA);
  // Begin connecting to WiFi.
  WiFi.begin(YourWiFiSSID, YourWiFiPassphrase);
  Serial.printf("\nDevice is connecting to WiFi using SSID %s and Passphrase %s.\n", ssid.c_str(), passphrase.c_str());
}

void voltageUpdatedCallback(int voltage, const char* path) {
  // This function prints the new value of the voltage variable.
    Serial.printf("Updated Voltage: %d\n", voltage);
}

void setup() {
  Serial.begin(9600);
  setupWiFi();

  myProject = grandeur.init(YourApiKey, AccessToken);
  myDevice = myProject.device(YourDeviceID);

  myDevice.data().on("voltage", voltageUpdatedCallback)
}

void loop() {
  // This runs the SDK when the device WiFi is connected.
  myProject.loop(WiFi.status() == WL_CONNECTED);
}

// **RESULT**
// Whenever an update in the device's voltage variable occurs, the new value of the
// voltage is printed to Serial.
```

## Example

Here we go through a general example to explain the **Arduino SDK** in action. For a little more broken-down approach, do have a look at [these examples][Examples] as well.

To begin working with the **Arduino SDK**, the very first step is to [create a new project][Grandeur Dashboard] and [register a new device][Grandeur Devices] through the [Cloud Dashboard][Grandeur Dashboard]. Then create a new Arduino sketch in your workspace folder.

### Create a New Sketch

Create a new folder for your `arduino workspace`, create a `.ino` file in it with the same name as the folder, and open it with [Arduino IDE][Arduino IDE]. This is the sketch file where you'll write your device's program.

### Include Grandeur.h into Your Sketch

After [cloning the Arduino SDK][installation] and [installing it][Installing an Arduino Library], you can import it into your sketch like this:

```cpp
#include <Grandeur.h>
```

### Initialize the SDK's Configurations

**Arduino SDK** takes care of your device's connection with Grandeur. To use it into your sketch, you need to initialize its configurations first. You can do that using the global object `grandeur`. Initializing the SDK returns a reference to object of the `Project` class which exposes all the SDK's functions.

```cpp
#include <Grandeur.h>

Project myProject;
Device myDevice;

void setup() {
  myProject = grandeur.init(YourAPIKey, YourToken);
}
```

You can find the API Key on the [settings page][Grandeur Settings] of your project's dashboard. You get the **Access Token** when you register the device on Grandeur. But a device can only connect to Grandeur if it's paired with a user. And only the paired user has access to the device's data. For convenient testing, we have made device pairing function available on the [devices page][Grandeur Devices] too. You can find your device's ID and pair your device with a user account. If your project has no registered user yet, you can add one easily from the [accounts page][Grandeur Accounts].

### Handle the device's WiFi

Here we illustrate this with the example of an ESP8266.

```cpp
#include <Grandeur.h>
#include <ESP8266WiFi.h>

Project myProject;
Device myDevice;

void setupWiFi(void) {
  Serial.begin(9600);
  // Disconnecting WiFi if it"s already connected
  WiFi.disconnect();
  // Setting it to Station mode which basically scans for nearby WiFi routers
  WiFi.mode(WIFI_STA);
  // Begin connecting to WiFi
  WiFi.begin(YourWiFiSSID, YourWiFiPassphrase);
  Serial.printf("\nDevice is connecting to WiFi using SSID %s and Passphrase %s.\n", ssid.c_str(), passphrase.c_str());
}

void setup() {
  Serial.begin(9600);
  // This sets up the device WiFi.
  setupWiFi();
  // You can initialize device configurations like this.
  myProject = grandeur.init(YourApiKey, YourToken);
}

void loop() {
  // This runs the SDK when the device WiFi is connected.
  myProject.loop(WiFi.status() == WL_CONNECTED);
}
```

### Initialize Your Device

Before doing anything, you need to initialize your device with data from Grandeur to keep them both in sync. You can get all the device variables by using `get()` functions. Here's how you can get the device **state** from the cloud.

```cpp
#include <Grandeur.h>
#include <ESP8266WiFi.h>

Project myProject;
Device myDevice;

void setupWiFi(void) {
  Serial.begin(9600);
  // Disconnecting WiFi if it"s already connected
  WiFi.disconnect();
  // Setting it to Station mode which basically scans for nearby WiFi routers
  WiFi.mode(WIFI_STA);
  // Begin connecting to WiFi
  WiFi.begin(YourWiFiSSID, YourWiFiPassphrase);
  Serial.printf("\nDevice is connecting to WiFi using SSID %s and Passphrase %s.\n", ssid.c_str(), passphrase.c_str());
}

void getStateCallback(Var result) {
  if(result["code"] == "DEVICE-DATA-FETCHED") {
    bool state = result["data"];
    // You can set a digital pin here with the state value
    // to switch the hardware connected to it ON/OFF.
    digitalWrite(D0, state);
  }
}

void setup() {
  Serial.begin(9600);
  // This sets up the device WiFi.
  setupWiFi();
  
  myProject = grandeur.init(YourApiKey, YourToken);
  myDevice = myProject.device(YourDeviceID);
  // This gets the device's state variable from Grandeur and passes it to
  // getStateCallback() function.
  myDevice.data().get("state", getStateCallback);
}

void loop() {
  // This runs the SDK when the device WiFi is connected.
  myProject.loop(WiFi.status() == WL_CONNECTED);
}
```

### Set Update Handlers

Update handlers are the functions which are called when a device variable is updated. The update could be from a user or the device itself. Without the handlers, your device would not be notified when a user turns it off from the web app.
Here's how you can set an update handler in your sketch for the device's state.

```cpp
#include <Grandeur.h>
#include <ESP8266WiFi.h>

Project myProject;
Device myDevice;

void setupWiFi(void) {
  Serial.begin(9600);
  // Disconnecting WiFi if it"s already connected
  WiFi.disconnect();
  // Setting it to Station mode which basically scans for nearby WiFi routers
  WiFi.mode(WIFI_STA);
  // Begin connecting to WiFi
  WiFi.begin(YourWiFiSSID, YourWiFiPassphrase);
  Serial.printf("\nDevice is connecting to WiFi using SSID %s and Passphrase %s.\n", ssid.c_str(), passphrase.c_str());
}

void getStateCallback(Var result) {
  if(result["code"] == "DEVICE-DATA-FETCHED") {
    bool state = result["data"];
    // You can set a digital pin here with the state value
    // to switch the hardware connected to it ON/OFF.
    digitalWrite(D0, state);
  }
}

void stateUpdatedCallback(bool state, const char* path) {
  // You can set a digital pin here with the newState value
  // to switch the hardware connected to it ON/OFF.
  digitalWrite(D0, state);
}

void setup() {
  Serial.begin(9600);
  // This sets up the device WiFi.
  setupWiFi();
  
  myProject = grandeur.init(YourApiKey, YourToken);
  myDevice = myProject.device(YourDeviceID);
  // This gets the device's state variable from Grandeur and passes it to
  // getStateCallback() function.
  myDevice.data().get("state", getStateCallback);
  // This sets up the update handler for state. When an update to state occurs on Grandeur,
  // stateUpdatedCallback() function is called.
  myDevice.data().on("state", stateUpdatedCallback);
}

void loop() {
  // This runs the SDK when the device WiFi is connected.
  myProject.loop(WiFi.status() == WL_CONNECTED);
}
```

### Update Device Variables

To see the live state of the device on the web app, you need to keep sending the updated state after every few seconds. We'll use the `set()` function to update the state value.

```cpp
#include <Grandeur.h>
#include <ESP8266WiFi.h>

Project myProject;
Device myDevice;

void setupWiFi(void) {
  Serial.begin(9600);
  // Disconnecting WiFi if it"s already connected
  WiFi.disconnect();
  // Setting it to Station mode which basically scans for nearby WiFi routers
  WiFi.mode(WIFI_STA);
  // Begin connecting to WiFi
  WiFi.begin(YourWiFiSSID, YourWiFiPassphrase);
  Serial.printf("\nDevice is connecting to WiFi using SSID %s and Passphrase %s.\n", ssid.c_str(), passphrase.c_str());
}

void getStateCallback(Var result) {
  if(result["code"] == "DEVICE-DATA-FETCHED") {
    bool state = result["data"];
    // You can set a digital pin here with the state value
    // to switch the hardware connected to it ON/OFF.
    digitalWrite(D0, state);
  }
}

void stateUpdatedCallback(bool state, const char* path) {
  // You can set a digital pin here with the newState value
  // to switch the hardware connected to it ON/OFF.
  digitalWrite(D0, state);
}

void setStateCallback(Var result) {
  if(result["code"] == "DEVICE-DATA-UPDATED") {
    Serial.printf("State is updated to: %d\n", (bool) result["update"]);
  }
}

void setup() {
  Serial.begin(9600);
  // This sets up the device WiFi.
  setupWiFi();
  
  myProject = grandeur.init(YourApiKey, YourToken);
  myDevice = myProject.device(YourDeviceID);
  // This gets the device's state variable from Grandeur and passes it to
  // getStateCallback() function.
  myDevice.data().get("state", getStateCallback);
  // This sets up the update handler for state. When an update to state occurs on Grandeur,
  // stateUpdatedCallback() function is called.
  myDevice.data().on("state", stateUpdatedCallback);
}

void loop() {
  bool state = digitalRead(D0);
  // This sends the updated state to Grandeur and calls setStateCallback() when
  // Grandeur acknowledges the update.
  myDevice.data().set("state", state, setStateCallback);

  // This runs the SDK when the device WiFi is connected.
  myProject.loop(WiFi.status() == WL_CONNECTED);
}
```

### Test it With Your Web app

You can build a web app for your product to control your hardware device over the cloud. [Here's a simple example for that][An Example Webapp].

## The Dexterity of Arduino SDK

The Arduino SDK is aimed at providing extremely to-the-point functions, being almost invisible in your device program to make the integration of Grandeur in your product seamless. Here is what it does under the hood without you paying attention to the most painful things:

* **Arduino SDK** takes care of your device's connection to [Grandeur][Grandeur]. **It can start trying to connect with Grandeur as soon as the device boots or you can manually tell the SDK when to begin.** There's a [`loop()`][loop] function that you place in the Arduino's `loop` whose sole function is to run the SDK. It accepts a **boolean expression as argument** and the SDK runs when the boolean expression evaluates to `true`. So, let's say if you pass the expression `WiFiState == CONNECTED` to it, the SDK would only run when the device's WiFi is connected.

* As soon as the WiFi gets connected, **Arduino SDK** begins trying to connect to *[Grandeur][Grandeur]* using the **connection credentials** you provide during `grandeur.init()`. When it connects, only then does the communication with Grandeur happen. And if somehow the connection breaks, SDK handles the reconnection and everything resumes right from where it left.

*  **Arduino SDK** exposes the state of your device (`CONNECTED` or `DISCONNECTED`) through [`getState()`][getState] function to let you make your decisions based on that.

* **Arduino SDK** is event-driven. You can set **event handler** for device's connection or disconnection with Grandeur by using [`onConnection()`][onConnection]. So, when the device connects or disconnects from the cloud, the function passed to `onConnection()` is called.

* You can also set **update handlers** for device variables using [`data().on()`][on] function. So, when any of the device variables is updated, the corresponding function passed to `on()` is called.

* **Async functions** are what make the event-drive of the SDK possible. They do all the same things as regular functions plus one extra. They receive a function parameter which they schedule for later. For example, all of the following are Async functions:
  
  * `project.onConnection(Callback callback)`
  * `project.device().data().on(String path, function callback)`
  * `project.device().data().get(String path, function callback)`
  * `project.device().data().set(String path, Var data, function callback)`

  `get()` for example, requests Grandeur for a device variable and schedules the `callback` function for when the variable arrives, because obviously, they don't arrive instantaneously; there is always some latency involved in web communications.

* [`Var`][var] is a special variable type which can take form of any other type including int, double, String, etc, like in those dynamic typed languages like javascript. But it can also act like a container for other variables, like a javascript object or a C++ map, to form JSON. You can store variables in it as key-value pairs. This is device data space is — a container for device variables aka. `Var`.

```cpp
Var json; // The root
json["foo"] = "This is foo"; // "foo" key in json
json["bar"] = true; // "bar" key in json
json["foobar"]["foo"] = "This is foo inside foobar"; // "foo" key in "foobar" key in json

// In JSON, json would look like:
//  {
//    "foo": "This is foo",
//    "bar": true,
//    "foobar": {
//      "foo": "This is foo inside foobar"
//    }
//  }

// You can also store anything in Var.
Var x = 5;
x = "hello";

Serial.println(x); // Prints: hello
```

To see the **Arduino SDK** in action, jump to [Example][Example].

# Grandeur Ecosystem

The purpose of writing this is to give you a glimpse into the thought process and psychologies behind designing the Grandeur Platform the way it feels now. We believe that the first very important step towards choosing a platform for your product and company is to understand the design language of developers of the platform. So we thought of writing about it in detail. We wanted to document how you can use this platform effectively to make your life as a developer or founder a bit simpler.

Here we present a case study to help you understand exactly where, how and what Grandeur can help you with. Then we explain some of the terms and keywords we use to identify and classify things that make abstraction seamless. So here we go.

## A Brief Case Study

Suppose you are a cleantech startup and want to radicalize the home appliances market to make the appliances more eco and user friendly. You analyzed the market, did user interviews and realized that there is a really big problem in the air conditioner market. Even though millions of new air conditioners are produced every year but there are so many old and inefficient ACs already in the market installed in people's homes and offices. These old air conditioners consume a huge chunk of power and are a major cause of CFCs emissions. Something has to be done because these devices are impacting both the users and the environment. Upgrading each single one of them is just not feasible at all economically.

To resolve the energy efficiency issue of these old ACs, you decided to build an electronic solution that could be used as an extension with these old ACs. So people could control their power consumption without actually upgrading their devices. And you thought of providing your users with an interface to interact with their appliances. You wanted your users to see how much has this new extension been saving them in expenses by cutting down the power consumption. You also wanted to give your users control over how much they wanted to save through this app. In short, you decided to make your product smart (on IoT). And you decided to build a companion app for your device.

That's where the problem arose. You are a hardware startup, after all, that builds amazing electronics technology. But here you got to deal with a few more things as well. You have to build your app and figure out how to establish its communication with your hardware. You may decide to hire more engineers. But do you know how much of them will you have to hire? To give you a perspective, you generally need 8+ engineers just to do the server-end, like one to figure out your networking, one to design and manage your database, one to develop your API (the interface layer between your users and devices), about four for building your SDKs (one for each platform android, ios, web, and hardware) and then when you start scaling up a bit, one DevOps engineer. This makes it a package of $8000+ just to figure out the backend of your system and you haven't even validated your product yet. This turns out exhausting for your business. You have hit a concrete wall with no idea what to do about it.

Then one day the sun of fate shown. You came across a platform that goes by the name of Grandeur. You went through its [website][Grandeur Technologies] and discovered a perfectly fitting solution for all your headaches. You wanted a solution for authentication of your users, it has the Auth feature in it. You needed online file storage to store maybe the profile pictures of your users and other stuff, it comes with a storage builtin. You were in dire need of a scalable out-of-the-box database to store power consumption logs of your device to show your users graphs on their monthly/yearly savings, it provides a cloud datastore service. And the most important of these all, you needed a realtime communication bridge between your hardware and your apps, THANK GOD, its SDKs are available for all the stacks including Arduino, web, and mobile (both android and ios).

So here you are giving it a shot. You simply [registered for the platform][Grandeur], created your first project, downloaded their SDKs and started connecting your devices and apps through Grandeur. You didn't even have to worry about the security of your users and devices, because the data on Grandeur is protected under standard security protocols. Each user and device in a project is limited in its scope. All you had to worry about was designing your product core and develop your business logic. And in a matter of weeks, your product was out in people's hands, your apps live on app stores. People loved what you built and you were getting live feedback on it. You could see how many people have paired with your devices. You made an early entry into the market and now adding a dent to the universe.

By the way, that is the story of team SolDrive. Check out their [website][SolDrive] right now and explore how they are transforming the world with Grandeur.

## Concepts

In this subsection, we will explore the Grandeur platform in detail and see how it pulls it all off. So let's get started.

### Project

A project is the first thing you need to create to start working with Grandeur. A project is like a namespace, a completely isolated network of users and devices, along with separate file storage and a separate datastore. While you can create an unlimited number of projects, but no two projects can interact or share anything with one other.

Each project is identified by a digital signature that we call the API key, just as your identification card or social security number identifies you as a citizen. To connect your apps or hardware to your project's network, this is what you need to provide to the SDKs. The API key is sent with every request to Grandeur and this is what defines the project of the request. Check out the [SDK][SDK] section to read more about it.

> ***NOTE***: Our pricing applies separately to each project. So you get a free tier on every project and pay for each separately for what you consume when you cross your resources limit.

### SDK

Grandeur is the API that exposes Grandeur to the outside world. Our SDKs utilize this API and map each functionality to a function. We have tried our best to make the integration of our SDKs into your codebase simple. For example, while developing your web app, you simply need to drop in the link of JS SDK CDN in your codebase and you are done. We have developed our SDKs for each platform in coherence with each other so you could work and collaborate everywhere seamlessly.

This is how they work: In every SDK, there is a global object aka. `grandeur`. You can initialize your configurations (API Key and a couple of more stuff in case of hardware SDK) by calling `grandeur.init()`. This returns you a reference to your whole project (in case of your app) or just to your device (in case of hardware because hardware scope is limited to the device itself). In **JS SDK**, you can interact with the authentication API, the device API, the file storage and the datastore API. In the case of **Arduino SDK** your scope is limited to just the device's namespace. Check out the [Authentication and Access][Authentication and Access] section to get more insight into how scope varies across the different platforms (app and hardware).

### User and Administrator

This topic is about the relationship between you as an administrator and your users and the access scope of both.

You aka. **the administrator** is an entity that creates, develops and maintains one or more [projects][Project] on Grandeur. The administrator has full authority over a project's resources (users, devices, files, and data) and can monitor and control all its projects from the [dashboard][Grandeur Dashboard].

A **user** is an entity that uses your product. While you have full control over your project, a user of your product has access to his profile and delegated access limited to its device scope only.

In the real world, you would not want to add a new user or pair a device with that user manually every time someone buys your product. Therefore you delegate a part of your project authorities to the SDK when you plug your project's API Key in. And so a new user gets to sign up, pair, monitor and control your device through your product's companion app.

Using just your project's API Key for full delegation is like putting all of your eggs in one basket. A stolen API Key can give the hacker, at the minimum, user-level access to your project. He can register any number of bogus users and do whatnot. Hence the concept of CORS comes to play. Read more on CORS in [Allowed Origins][Allowed Origins] section.

### Device

Devices are the *things* in **Internet of Things** (IoT) around which the IoT product development revolves. Like a user, a device entity has a limited scope of access. But unlike users, you can register new devices only from the dashboard. Read the [Device Registry][Device Registry] section for more on what happens when you register a new device to your project.

On Grandeur, a device falls under the ownership of the project's administrator. The project's API Key delegates the device pairing authority to the SDK which the user uses to pair with the device. Pairing a device makes it live on Grandeur and the user gets delegated access to the device's data. But a user cannot delete or modify a device's inherent data because it's not within its scope.

A user can pair with any number of devices but a device can be paired with at the most one user.

The device entity, in the end, defines two things:

* What kind of data a hardware device can access in your namespace and
* Which hardware devices a user can control.

This matters a lot because you would never want your neighbor to control your air conditioner (that would be a horrible situation). That's what this entity has been designed for. A user can only interact with devices that are paired with it.

When you pair a device with a user account, an access token is generated for the device. This token is what the device uses to connect to Grandeur. This token also delegates access of the device namespace to the Arduino SDK. The Arduino SDK takes this access token along with the project's API Key while doing `grandeur.init()`. To read about the device's namespace and how the device's data is stored on Grandeur, have a look at the [Device Registry][Device Registry] section.

> ***NOTE***: A user cannot pair with a device that is already paired.

### Device Registry

The device registry constitutes one of the key elements of Grandeur. There are two types of approaches you see out there:

* Those which deal with user's authentication only e.g. firebase and
* Those which employ a device's registry e.g. Google IoT Core, to make sure no unauthorized devices get into your network.

We wanted to combine the best of both worlds. This is why at Grandeur, not do we just authenticate a device on connection, we also maintain a device's registry for you. See [Authentication and Access][Authentication and Access] section for detail on how a device is authenticated on Grandeur.

When you register a device, you make it available in your project's network. Not just that, a new namespace is created for your device in the device registry. When your device comes online, this is where all of its data is stored, in the form of i) Summary and ii) Parms.

Now let's define what you can store in **Parms** and **Summary**. To be honest, there is no hard and fast rule about it. We just created two objects instead of a single one to help you develop understanding. However, we generally take the *parms as the directly controllable device variables* and the *summary as those device variables which are not directly controllable* or are just needed to be logged or displayed to apps. In another way, the parms sometimes refer to the inputs from the user and the summary refers to the outputs of the device resulting from the inputs. Consider an example where you have a smart light bulb. The parms can store the bulb ON/OFF state which the user can control, while in summary, you can log the voltage consumption of the bulb.

We defined these two objects just to give you a basic framework to work on and build your logic fast. But we are very flexible in what and how you store data in the device registry. You can define an initial schema of these objects using [models][models] and go on from there.

### Models

### Authentication and Access

Previously, we have discussed in depth which entity (administrator, user, device) can access what. This section revisits the topic and gives you a broader picture of authentication and access scopes. Let's start by outlining the relationships. There are three major scopes:

* The global scope or project's scope
* User scope
* Device scope

You (as an administrator) create a project and therefore have global access to everything. You can access and manage your projects and their resources using the dashboard application. You want your users and devices to have limited access to your project's resources based on their scopes which you achieve by using our SDKs in your apps and hardware. Your project's API Key delegates your project's access to the SDKs and access tokens allow and limit, at the same time, this access to user and device scopes.

The user scope is wider than the device scope. A user can access its profile, the registry of the devices it's paired to, the files in the project's storage and the data in the project's datastore. When a user logs in, an Auth token is returned. This token along with the API Key, being sent with every request, is what validates the authority of the request.

The device scope is limited to the device's namespace in the device registry. When a user pairs with a device, an access token is returned for the device. This access token along with the API Key is what authenticates the device's connection to Grandeur.

This is how the global project scope is distributed among the smaller entities and we make sure that everyone gets what they are allowed to access.

### Networking

Here we write about how the networking works on Grandeur.

We work with two communication channels in **Web SDK** i) HTTP based REST API channel and ii) Duplex based realtime API channel. We use the first to do some basic things like authentication or handle big requests like file uploading, while the latter, as its name suggests, for realtime communication like fetching or updating the device's data. The realtime channel is as fast as 200ms RTT. It is based on our custom protocol aka. Duplex. We do not allow any unauthenticated communication over this channel and therefore authenticate a connection over the REST channel first.

In the **Arduino SDK**, we only use the realtime channel. A device cannot establish a connection over this channel unless and until its access token is validated. A device access token is provided while initializing the grandeur configurations through `grandeur.init()`.

### Allowed Origins

This is another amazing topic and somehow related to access delegation in the end. As mentioned in the sections above that you can interact with your project's namespace through the JS SDK by initializing grandeur with your API key. This returns an object referring to your project which can be used to interact with its resources including its devices, datastore, and files storage. Putting this much responsibility on just the API key poses a security threat particularly in case of web apps as API Key can easily be stolen. Even though a user needs to log in first before making any request to the cloud, a hacker with having your API key can still cause some serious damage. For example, Registering bogus users to your project or creating a copycat site on your name for phishing to name a few. That's where cross-origin request sharing (CORS) policies come to play.

So to allow a web app to interact with your project using the Web SDK, you first need to whitelist the domain name your web app uses via the settings page in the dashboard. You cannot even send a request from your localhost without first whitelisting it.

> ***NOTE***: Keeping localhost whitelisted in a production application is a very serious vulnerability that can make you pay as you go (pun intended).

# Documentation

`Grandeur` is the entry point — the door of the SDK. `grandeur` is the global object of the `Grandeur` that gets available right away when you include `<Grandeur.h>` in your sketch. It has just one purpose and therefore gives you only one function: `grandeur.init()`.

`Project` is the main class and all grandeur functionalities originate from it. You can safely imagine the object of `Project` class as a reference to your project on Grandeur. You get the object of this class when you initialize SDK's configurations using `grandeur.init()`.

> ***Note 2***: You cannot connect with Grandeur or even with internet without first connecting with the WiFi. Therefore, the examples below are just for reference and you are required to handle your device's WiFi yourself in order for things to work. You can see [these examples][Examples] to get a deeper understanding. They do WiFi handling too. 😉

## Grandeur

Grandeur class exposes one method — `init` — and one class — `Project`:
### init

> grandeur.init (apiKey: _String_, token: _String_) : returns _Grandeur::Project_

This method initializes SDK's connection configurations: `apiKey` and `authToken`, and returns an object of the `Project` class. `Project` class is the main class that exposes all functions you can perform on your project resources through the SDK.

#### Parameters

| Name        | Type     | Description                                                     |
|-------------|----------|-----------------------------------------------------------------|
| apiKey      | _String_ | API key of your project that your device is registered in.      |
| token       | _String_ | Access token generated when the device is paired with a user.   |

#### Example

```cpp
// Container for the object of Device class.
Grandeur::Project myProject;
void setup() {
  myProject = grandeur.init(YourApiKey, YourToken);
}

// **RESULT**
// SDK configurations are initialized.

```

## Project

Project is the main class of the SDK. When your device connects with Grandeur, this class represents your grandeur project, from the device's perspective — there are only two resources your device can interact with: **device** and **datastore**, which are represented by their respective classes.

Project class exposes the following methods:

### isConnected

> isConnected(void): returns _bool_

This method returns true if the device is connected with Grandeur.

#### Example

```cpp
Grandeur::Project myProject;
void setup() {
  myProject = grandeur.init(YourApiKey, YourToken);
}

void loop() {
  if(!myProject.isConnected()) {
    Serial.println("Device is not connected with Grandeur!\n");
  }
  else {
    Serial.println("Yay! Device has made a successful connection with Grandeur!\n");
  }

  myProject.loop(true);
}

// **RESULT**
// In the beginning, isConnected() returns false and the first *if-block* runs.
// When the SDK is connected with Grandeur, isConnected() returns true running the second
// *if-block*.
```

### onConnection

> onConnection (callback : _Callback_) : returns _void_

This method schedules a function to be called when the device's connection with Grandeur is made or broken. The function passed to it as argument is called an **event handler** for it handles events like connection/disconnection with Grandeur. Example below illustrates its usage.

#### Parameters

| Name        | Type             | Description                                                                    |
|-------------|------------------|--------------------------------------------------------------------------------|
| callback    | _void (*)(bool)_ | An event handler function for device's connection/disconnection with Grandeur. |


#### Example

```cpp
Grandeur::Project myProject;

void connectionCallback(bool status) {
  // This method handles the events related to device's connection with Grandeur.
  switch(status) {
    case CONNECTED:
      // If the connection event occurred.
      Serial.println("Device Connected to Grandeur!\n");
      break;
    case DISCONNECTED:
      // If the disconnection event occurred.
      Serial.println("Device Disconnected from Grandeur!\n");
      break;
  }
}

void setup() {
  myProject = grandeur.init(YourApiKey, YourToken);

  myProject.onConnection(connectionCallback);
}

void loop() {
  myProject.loop(true);
}

// **RESULT**
// Prints "Device Connected to Grandeur!" when device makes a successful connection with Grandeur
// and "Device Disconnected from Grandeur!" when device breaks connection from Grandeur.
```

### loop

> loop (valve: _bool_) : returns _void_

This method is the legs of the SDK. Without it, the SDK doesn't run. Therefore, it must be called in Arduino's `loop()` and without being suspected to any *delay*. **This method is what runs the underlying event loop and makes all the *Async* functions possible.**
It can also accept an argument which we call **valve**. A **valve** is a boolean expression whose value decides if the SDK would run for current `loop` or not. For example, we can use it to dictate to the SDK to run only when the device WiFi is connected.

> **A Tidbit:** [Here][Using Millis Instead of Delay] is how you can use `millis()` instead of `delay()` if you want a function to run after every few moments without blocking the loop.

#### Example

```cpp
Grandeur::Project myProject;
void setup() {
  myProject = grandeur.init(YourApiKey, YourToken);
}

void loop() {
  myProject.loop(WiFiState == CONNECTED);  // Same as "if(WiFiState == CONNECTED) myProject.loop();"
}
// **RESULT**
// Runs the SDK only when the WiFi is connected.
```

### device<a name="device-function"></a>

> device (deviceID: _String_) : returns _Grandeur::Project::Device_

This method returns an object of the **Device** class.

#### Example

```cpp
Grandeur::Project myProject;
Grandeur::Project::Device myDevice;
void setup() {
  myProject = grandeur.init(YourApiKey, YourToken);
  myDevice = myProject.device(YourDeviceID);
}

// **RESULT**
// Gets the object of Device class.
```

### datastore

> datastore (void) : returns _Grandeur::Project::Datastore_

This method returns a reference to object of the **Datastore** class. Datastore class exposes the functions of the datastore API which handles your queries to your project's datastore like: logging device variables to the cloud datastore, searching for data, etc.

#### Example

```cpp
Grandeur::Project myProject;
Grandeur::Project::Datastore myDatastore;
void setup() {
  myProject = grandeur.init(YourApiKey, YourToken);
  myDatastore = myProject.datastore();
}

// **RESULT**
// Gets the object of Datastore class.
```

## Device<a name="device-class"></a>

Device class gives you the functions to interact with your device data. Its `data` function returns the object of `Data` class that gives you the functions to get, set, and subscribe to the device's data variables. Subscribe means if you update this device's data variables from anywhere other than this device itself, this device will get the update. This is great for realtime switching ON/OFF of your device remotely from an app or changing voltage of its pins for example.

Device class exposes only the `data` function:

### data

> data () : returns _Grandeur::Project::Device::Data_

This method returns an object of the **Data** class.

#### Example

```cpp
Grandeur::Project myProject;
Grandeur::Project::Device myDevice;
Grandeur::Project::Device::Data myDeviceData;
void setup() {
  myProject = grandeur.init(YourApiKey, YourToken);
  myDevice = myProject.device(YourDeviceID);
  myDeviceData = myDevice.data();
}

// **RESULT**
// Gets the object of the Device Data class.
```

## Data

`Data` class gives you the functions to get, set, and subscribe to the device's data variables.

Here's how you can use each function of the `Data` class:

### get

> get (path: _String_, callback: _Callback_) : returns _void_
> get (callback: _Callback_) : returns _void_

This method gets a device variable from Grandeur.

#### Parameters

| Name        | Type       | Description                                                  |
|-------------|------------|--------------------------------------------------------------|
| path        | _String_   | Path of the device variable using dot notation            |
| callback    | _Callback_ | A function to be called when get response is received        |

#### Example

```cpp
Grandeur::Project myProject;
Grandeur::Project::Device myDevice;

void getVoltageCallback(Var result) {
  // This method prints *voltage* variable from device data.
  Serial.println(result["data"]<<"\n");
}

void setup() {
  myProject = grandeur.init(YourApiKey, YourToken);
  myDevice = myProject.device(YourDeviceID);
}

void loop() {
  // This requests to get "voltage" variable from device data on every loop and calls getVoltageCallback() function when the
  // data from Grandeur actually arrives.
  myDevice.data().get("voltage", getVoltageCallback);

  if(WiFiIsConnected) myProject.loop();
}

// **RESULT**
// Prints the value of the voltage variable from Grandeur on every loop.
```

You can get all device data variables with the `path`-less `get` function overload.

### set

> set (path : _String_, data : _any_, callback: _Callback_) : returns _void_
> set (path : _String_, data : _any_) : returns _void_

This method updates a device variable on Grandeur with new data.

#### Parameters

| Name        | Type          | Description                                                              |
|-------------|---------------|--------------------------------------------------------------------------|
| path        | _String_      | Path of the device variable using dot notation.                          |
| data        | _Var_         | New data to store in the variable.                                       |
| callback    | _Callback_    | A function to be called after the variable at `path` is actually updated.|

#### Example

```cpp
Grandeur::Project myProject;
Grandeur::Project::Device myDevice;

void setVoltageCallback(Var result) {
  // This method prints "voltage" value after it is updated on Grandeur.
  Serial.println(result["update"]);
}

void setup() {
  myProject = grandeur.init(YourApiKey, YourToken);
  myDevice = myProject.device(YourDeviceID);
}

void loop() {
  // Reading pin value.
  int voltage = analogRead(A0);
  // This requests to set the "voltage" variable on every loop and calls setVoltageCallback() function when the
  // variable is actually updated on Grandeur.
  myDevice.data().set("voltage", voltage, setVoltageCallback);

  if(WiFiIsConnected) myProject.loop();
}

// **RESULT**
// Sets the voltage variable and prints its updated value
// after it's updated on Grandeur, on every loop.
```

If you do not need to do anything after the successful update of a data variable, you can use the `callback`-less `set` function overload.

### on

> on (path: _String_, callback : _Callback_) : returns _void_
> on (callback : _Callback_) : returns _void_

This method schedules a function to be called when a device variable changes on Grandeur.

A variable can be changed by a paired user from an app, dashboard, or any SDKs. All three of these updates would trigger the on-callback, or you can call it the device's data update handler. But updating a device's data variable from the device itself won't trigger its own update handler.

> ***A Tidbit***: *Update is a special type of event* and the function that handles it is called an **update handler**.

#### Parameters

| Name        | Type       | Description                                    |
|-------------|------------|------------------------------------------------|
| path        | _String_   | Path of the device variable using dot notation |
| callback    | _Callback_ | An update handler for the device variable      |

More on Callback [here][callback].

#### Example

```cpp
Grandeur::Project myProject;
Grandeur::Project::Device myDevice;

void voltageUpdatedCallback(Var result) {
  // When "voltage" update occurs on Grandeur, this function extracts
  // its updated value and writes it to an analog pin.
  Serial.println("Voltage update occurred!\n");
  int voltage = result["voltage"];
  analogWrite(voltage, A0);
}

void setup() {
  myProject = grandeur.init(YourApiKey, YourToken);
  myDevice = myProject.device(YourDeviceID);

  myDevice.data().on("voltage", voltageUpdatedCallback);
}

void loop() {
  if(WiFiIsConnected) myProject.loop();
}
```

You can subscribe to all device data variables with the `path`-less `on` function overload.

## Datastore

Datastore class gives you the functions to store and search for data in Grandeur datastore which a highly scalable database where you can log data points and retrieve them later to plot trend or device health graphs. Read about Datastore [here](https://www.hackster.io/grandeurtech/data-persistence-in-iot-with-grander-fd09ee).

Datastore class exposes the following functions:

### insert

> insert (documents: _Var_, callback: _Callback_) : returns _void_

This method inserts documents into datastore.

#### Parameters

| Name        | Type         | Description                                                        |
|-------------|--------------|--------------------------------------------------------------------|
| documents   | _Var_        | An array of documents (_Var_ s) to be inserted into the datastore. |
| callback    | _Callback_   | A function to be called when insertion of documents completes.     |

#### Example

```cpp
Grandeur::Project myProject;
Grandeur::Project::Datastore myDatastore;

void insertCallback(Var insertionResult) {
  // This method just prints if the insertion is successful or not.
  if(insertionResult["code"] == "DATASTORE-DOCUMENTS-INSERTED") Serial.println("Insertion successful.");
  else Serial.println("Insertion Failed.");
}

void setup() {
  myProject = grandeur.init(YourApiKey, YourToken);
  myDatastore = myProject.datastore(YourDeviceID);
}

void loop() {
  // This inserts a document containing voltage and current readings in datastore on every loop.
  Var docs;
  // Adding voltage and current readings to the first document of docs array.
  // In JSON, the docs array looks like this:
  // [{"voltage": analogRead(A0), "current": analogRead(A1)}]
  docs[0]["voltage"] = analogRead(A0);
  docs[0]["current"] = analogRead(A1);
  // Inserting the docs in datastore. insertCallback() will be called when insertion process
  // completes.
  myDatastore.insert(docs, insertCallback);

  if(WiFiIsConnected) myProject.loop();
}

// **RESULT**
// Prints "Insertion successful." if documents are inserted. If an error occurred, it prints
// "Insertion Failed."
```

### search

> search (filter: _Var_, projection: _Var_, pageNumber: _int_, callback: _Callback_) : returns _void_

This method searches for documents in datastore based on the `filter` supplied. `Filter` describes what documents to return and `projection` describes what fields to return in those documents. Documents are returned in pages and each page is **20 documents** in size. This is what the `pageNumber` is for. You'll get first page by specifying the `pageNumber` to 0 and 1 for second page. and so on.

#### Parameters

| Name        | Type         | Description                                                                            |
|-------------|--------------|----------------------------------------------------------------------------------------|
| filter      | _Var_        | A document describing the conditions that the documents to be returned are to satisfy. |
| projection  | _Var_        | A document that describes what fields to return.                                       |
| pageNumber  | _int_        | Number of the page to return.                                                          |
| callback    | _Callback_   | A function to be called when documents are completed.                                  |

#### Example

```cpp
Grandeur::Project myProject;
Grandeur::Project::Datastore myDatastore;

void searchCallback(Var searchResult) {
  // This method just prints the documents if the search is successful.
  if(searchResult["code"] == "DATASTORE-DOCUMENTS-FETCHED") {
    Serial.print("Documents fetched from Grandeur: ");
    Serial.println(searchResult["documents"].length());
    // Printing all the fetched documents.
    for(int i = 0; i < searchResult["documents"].length(); i++) {
      Serial.println(JSON.stringify(searchResult["documents"][i]).c_str());
      // Just to keep the watchdog timer from tripping.
      delay(1);
    }
    Serial.println("");
    return;
  }
  Serial.println("Search Failed.");
}

void setup() {
  myProject = grandeur.init(YourApiKey, YourToken);
  myDatastore = myProject.datastore(YourDeviceID);
}

void loop() {
  // This fetches 1st page of all the documents stored in the datastore.
  myDatastore.collection("myCollectionName").search({}, {}, 0, searchCallback);

  if(WiFiIsConnected) myProject.loop();
}

// **RESULT**
// Prints the documents if search is successful. If an error occurred, it prints
// "Search Failed."
```

## Enhancements Under Consideration:

Here are some enhancements that we are considering to implement in the SDK. They have their corresponding issues as well. If you can relate to any one of these and would like to fast forward its implementation, just comment +1 on its issue. This would be a feedback for us to set priorities in a user-centered way. Thank you 👇

[#4][i4] — Move the error handling inside the SDK. The developer would not have to check the response code to see if the request executed successfully or not. We would do that the native C-way instead: by returning 0 for success and 1, 2, 3 for other error codes. Or we can create some macros like SUCCESS, ERROR etc.

[Grandeur Technologies]: https://grandeur.tech "Grandeur Technologies"
[Grandeur]: https://cloud.grandeur.tech "Grandeur"
[Grandeur Sign Up]: https://cloud.grandeur.tech/register "Sign up on Grandeur"
[Grandeur Dashboard]: https://cloud.grandeur.tech/dashboard "Grandeur Dashboard"
[Grandeur Accounts]: https://cloud.grandeur.tech/accounts "Grandeur Accounts"
[Grandeur Devices]: https://cloud.grandeur.tech/devices "Grandeur Devices"
[Grandeur Settings]: https://cloud.grandeur.tech/settings "Grandeur Settings"
[Grandeur Pricing]: https://grandeur.tech/pricing/ "Pricing"
[Get Started With Grandeur]: https://github.com/grandeurtech/js-sdk#get-started "Get Started With Grandeur"
[Get Started With Grandeur Canvas]: https://youtu.be/gqTmtDJkPl8 "Get Started With Grandeur Canvas"
[An Example Webapp]: https://github.com/grandeurtech/js-sdk#example "An Example Webapp"
[Examples]:  https://github.com/grandeurtech/arduino-sdk/tree/master/examples/
[Arduino IDE]: https://www.arduino.cc/en/main/software "Arduino IDE"
[Installing an Arduino Library]: https://www.arduino.cc/en/guide/libraries "Installing an Arduino Library"

[Grandeur Hackster]: https://www.hackster.io/grandeur "Hackster Community"

[Installation]: #installation "Installation"
[Example]: #example "Arduino SDK Example"
[Documentation]: #documentation "Documentation"
[Ecosystem]: #grandeur-ecosystem "Grandeur Ecosystem"

[SolDrive]: https://sol-drive.com/ "SolDrive"

[Project]: #project "Project"
[SDK]: #sdk "SDK"
[Authentication and Access]: #authentication-and-access "Authentication and Access"
[Allowed Origins]: #allowed-origins "Allowed Origins"
[Device Registry]: #device-registry "Device Registry"

[Get Started with Arduino SDK]: #get-started "Get Started with Arduino SDK"
[Arduino SDK]: https://github.com/grandeurtech/arduino-sdk "Arduino SDK"
[Latest Release]: https://github.com/grandeurtech/arduino-sdk/releases/latest "Arduino SDK's Latest Release"
[project]: #project "Project"
[summary]: #device-registry "Summary"
[parms]: #device-registry "Parms"
[callback]: #the-dexterity-of-arduino-sdk "The Dexterity of Arduino SDK"
[var]: #the-dexterity-of-arduino-sdk "The Dexterity of Arduino SDK"
[the dexterity of arduino sdk]: #the-dexterity-of-arduino-sdk "The Dexterity of Arduino SDK"
[models]: #models "Models"
[apikey]: #project "Project"
[access token]: #authentication-and-access "Authentication and Access"

[getState]: #get-state
[onConnection]: #grandeur-connection-event-listener
[onSummary]: #onSummary
[onParms]: #onParms
[loop]: #loop

[Using Millis Instead of Delay]: https://www.norwegiancreations.com/2017/09/arduino-tutorial-using-millis-instead-of-delay/ "Using millis() instead of delay()"

[i4]: https://github.com/grandeurtech/arduino-sdk/issues/4
