/**
 * \file    
 * \brief		Wi-Fi network scanner.
 * \details		Teacher version.
 * 				Final app must have two modes:
 * 					1. Scan available networks, print through Serial Monitor. -- DONE
 * 					2. Scan available networks, connect to the highest RSSI.
 * \author		Alexandre Quenon, Reseach & Teaching Assitant, Ph.D. Student.
 * \version		1.0
 * \date		Created on: 2017-08-01
 * \date		Last modification: 2017-08-04
 * \copyright	GNU General Public License V3
 */



// *** Includes, class and enum definitions *** //
#include "ESP8266WiFi.h"



// *** Globals *** //
const char* ssid = "SEMI_PUBLIC";
const char* password = "microelecpub";

const unsigned long baudrate = 115200;



// *** Functions declaration *** //
/**
 * \brief     Properly disconnects any existing connection, then configure the Wi-Fi connection mode.
 * \param     wifiMode A WiFiMode_t enum. Possible values are: WIFI_OFF, WIFI_STA, WIFI_AP, WIFI_AP_STA.
 * \attention Look at the delay which is added before exiting the function.
 */
void configWifiMode(WiFiMode_t wifiMode);
/**
 * \brief     Connects to the specified Wi-Fi access point and prints information through the Serial.
 * \param     ssid A constant character pointer.
 * \param     password A constant character pointer.
 * \attention Why is it interesting to use const char* type for passing arguments to a function?
 * \attention Look at the delay in the while loop. Can you explain the trade-off?
 * \bug       This function has a big weakness... Can you find it?
 */
void connectToWifi(const char* ssid, const char* password);

/**
 * \attention Look at the type of numberNetworks variable. Do you know something about type deduction?
 * \attention Look at iterator of the for loop. This is the same.
 */
void scanAvailableWifiNetworks();


/**
 * \brief Prints the SEMi acronym through Serial, which ensures that it works.
 */
void printSemi();

/**
 * \brief     Prints information of a Wi-Fi network identified by the scanNetworks() method.
 * \param     number A constant reference to an 8-bit unsigned integer.
 * \attention Why is it interesting to use constant references for passing arguments to a function?
 */
void printInfoWifiNetwork(const uint8_t& number);



// *** Arduino SETUP and LOOP functions *** //
void setup(){// Run once
	// 1. Start serial connection to send info to the computer through Arduino IDE Serial Monitor
	Serial.begin(baudrate);
	Serial.println("\n");

	printSemi();


	// 2. Set the device up according to your application
	Serial.println("Setup ongoing...\n");

	configWifiMode(WIFI_STA);
	scanAvailableWifiNetworks();

	Serial.println("Setup done!\n\n");
}


void loop(){//Run repeatedly
	/* --- DO something --- */
}



// *** Wi-Fi management functions *** //
void configWifiMode(WiFiMode_t wifiMode){
	// 1. Properly disconnect any existing connection
	WiFi.disconnect();        // Disconnect any existing STA connection.
	WiFi.softAPdisconnect();  // Disconnect any existing AP connection.

	// 2. Select Wi-Fi mode
	WiFi.mode(wifiMode);

	// 3. Small delay (100 ms) to ensure that everything has been set properly
	delay(100);
}

void connectToWifi(const char* ssid, const char* password){
	// 1. Start connecting the device to the Wi-Fi
	Serial.print("Attempting to connect to Wi-Fi network, SSID: ");
	Serial.println(ssid);
	Serial.print("Connecting");

	WiFi.begin(ssid, password);

	// 2. Check status while waiting for connection
	while (WiFi.status() != WL_CONNECTED){
		delay(500);
		Serial.print(".");
	}

	// 3. Connection succeeded: warn the user
	Serial.print("\nWi-Fi connected to ");
	Serial.print(ssid);
	Serial.println("\n");
}


void scanAvailableWifiNetworks(){
	// 1. Scanning available networks
	Serial.println("Scanning available Wi-Fi networks...");

	auto numberNetworks = WiFi.scanNetworks();  // Returns a byte (8-bit unsigned number): number of found networks

	// 2. Process information
	Serial.print("Scan done: ");
	if (numberNetworks == 0)
		Serial.println("no networks found.\n");
	else{
		Serial.print(numberNetworks, DEC);
		Serial.println(" network(s) found.");

		Serial.println("Available Wi-Fi networks:");
		for (auto i = 0; i < numberNetworks; ++i)
			printInfoWifiNetwork(i);
		Serial.println("\n");
	}
}



// *** Serial management functions *** //
void printSemi(){
	Serial.println("*************************************");
	Serial.println("  *****    *****    *       *    *");
	Serial.println(" *         *        * *   * *");
	Serial.println("  *        **       *   *   *    *");
	Serial.println("     *     **       *       *    *");
	Serial.println("      *    *        *       *    * *");
	Serial.println(" *****     *****    *       *     *");
	Serial.println("*************************************\n");
}

void printInfoWifiNetwork(const uint8_t& number){
	Serial.print("- network [");
	Serial.print(number + 1);     // Avoid starting from zero.
	Serial.print("]: ");

	Serial.print("SSID = ");
	Serial.print(WiFi.SSID(number));  // SSID method asks for a uint8_t parameter.
	Serial.print("; RSSI = ");
	Serial.print(WiFi.RSSI(number));  // RSSI method asks for a uint8_t parameter.
	Serial.println(" dBm");
}
