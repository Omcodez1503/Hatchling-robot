#ifndef TURTLE_RECEIVER
#define TURTLE_RECEIVER

#include <esp_now.h>
#include <WiFi.h>
#include <esp_wifi.h>

/// @cond
typedef struct struct_message {
    
    float j1x;
    float j1y;
    bool j1z;
  
    bool butA;
    bool butB;
    bool butX;
    bool butY;

    bool butR;
    bool butL;

  } struct_message;
/// @endcond

class NetController {
    private:
        // a struct containing all data received
        //struct_message controllerData;
        // setting to display debug messages or not
        static bool displayDebugMessages;

        

    public:
        /**
         * @brief     Creates a "network controller" - basically a receiver for your HURC. Make sure to call controllerSetup() in your setup() function before using trying to get any inputs
         * @param     displayDebugMessage by default is false; if set to true will print out debug messages to serial monitor. if enabled make sure to do Serial.begin() before you initialize your NetController. This will flood your monitor, so only enable if you really need it.
         */
        NetController(bool displayDebugMessage = false);

        /// @cond 
        static bool getDebug();
        /// @endcond

        /**
         * @brief sets up stuff related to the controller, put this in ur setup function
         */
        void controllerSetup();

        /**
         * @brief returns the left joystick's x value
         * @return a float in the range [-1, 1]
         */
        float getJoy1X();

        /**
         * @brief returns the left joystick's y value
         * @return a float in the range [-1, 1]
         */
        float getJoy1Y();


        /**
         * @brief returns whether or not the left joystick is clicked down
         * @return returns true when held down, false otherwise
         */
        bool getJoy1Z();





        /**
         * @brief returns whether or not the A button is pressed down (Xbox layout)
         * @return a boolean, true if held down, false otherwise
         */
        bool getA();


        /**
         * @brief returns whether or not the B button is pressed down (Xbox layout)
         * @return a boolean, true if held down, false otherwise
         */
        bool getB();

        /**
         * @brief returns whether or not the X button is pressed down (Xbox layout)
         * @return a boolean, true if held down, false otherwise
         */
        bool getX();


        /**
         * @brief returns whether or not the Y button is pressed down (Xbox layout)
         * @return a boolean, true if held down, false otherwise
         */
        bool getY();

        /**
         * @brief returns whether or not the R button is pressed down
         * @return a boolean, true if held down, false otherwise
         */
        bool getR();

        /**
         * @brief returns whether or not the L button is pressed down 
         * @return a boolean, true if held down, false otherwise
         */
        bool getL();

        


};

/**
 * @brief function to print out your ESP32's mac address. Make sure to use Serial.begin() before calling this
 * @return nothing, just prints
 */
void printMacAddress();

/// @cond
/**
         * @brief     private callback function; gets called whenever a message gets received
         * @param     mac mac address of the sender (i think)
         * @param     incomingData byte array of the incoming data
         * @param     len length of incomingData in bytes
         */
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len);

static struct_message controllerData = {0,0,0,0,0,0,0,0,0};

/// @endcond


#endif