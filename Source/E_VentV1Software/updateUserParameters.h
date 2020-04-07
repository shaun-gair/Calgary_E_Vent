#ifndef UPDATE_USER_PARAMETERS_H
#define UPDATE_USER_PARAMETERS_H

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "UserParameter.h"
#include "Encoder.h"
#include "LCD.h"

const uint8_t PARAMETER_ENCODER_PUSH_BUTTON_PIN = 20;
const uint8_t PARAMETER_ENCODER_PIN_1 = 18;
const uint8_t PARAMETER_ENCODER_PIN_2 = 19;

//volatile boolean PARAMETER_SELECT = false;
//volatile boolean PARAMETER_SET = false;

//Encoder PARAMETER_SELECT_ENCODER(parameterEncoderPin1, parameterEncoderPin2);

enum SelectedParameter{
	e_ThresholdPressure,
	e_BPM,
	e_InspirationTime,
	e_TidalVolume,
  e_PlateauPauseTime,
  e_HighPIPAlarm,
  e_LowPIPAlarm,
  e_HighPEEPAlarm,
  e_LowPEEPAlarm,
  e_LowPlateauPressureAlarm,
  e_None
};

//SelectedParameter CURRENTLY_SELECTED_PARAMETER = e_None;

void setUpParameterSelectButtons(UserParameter *userParameters, const uint8_t NUM_USER_PARAMETERS, const uint8_t parameterEncoderPushButtonPin);

void updateSelectedParameter(SelectedParameter &currentlySelectedParameter, 
							Encoder &parameterSelectEncoder, UserParameter *userParameters, const uint8_t NUM_USER_PARAMETERS);
							
void updateParameterValue(SelectedParameter &currentlySelectedParameter, 
						Encoder &parameterSelectEncoder, UserParameter *userParameter);

void setParameters(SelectedParameter &currentlySelectedParameter,
				volatile boolean &parameterSet, UserParameter *userParamter);

void updateUserParameters(SelectedParameter &currentlySelectedParameter,volatile boolean &parameterSet,
            Encoder &parameterSelectEncoder, UserParameter *userParameters, const uint8_t NUM_USER_PARAMETERS);

void displayUserParameters(SelectedParameter &currentlySelectedParameter, LiquidCrystal &displayName, machineStates machineState, vcModeStates vcState, acModeStates acState, 
                          float measuredPIP, float measuredPlateau, const int LCD_MAX_STRING, UserParameter *userParameters);

void parameterSetISR();

#endif
