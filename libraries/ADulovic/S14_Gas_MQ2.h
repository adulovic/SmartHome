/*
    Gas Detection (MQ2)
    
    - Pins  1	+5VDC
			2	GND
			3	
			4	A0
*/

/* Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgS14(S14, V_LEVEL);


/* Extras
=========1=========2=========3=========4=========5=========6=========7========*/

/****************** MQResistanceCalculation ****************************************
Input:   raw_adc - raw value read from adc, which represents the voltage
Output:  the calculated sensor resistance
Remarks: The sensor and the load resistor forms a voltage divider. Given the voltage
         across the load resistor and its resistance, the resistance of the sensor
         could be derived.
************************************************************************************/
float MQResistanceCalculation(int raw_adc){
    return ( ((float)RL_VALUE*(1023-raw_adc)/raw_adc));
}

/***************************** MQCalibration ****************************************
Input:   pinS14 - analog channel
Output:  Ro of the sensor
Remarks: This function assumes that the sensor is in clean air. It use
         MQResistanceCalculation to calculates the sensor resistance in clean air
         and then divides it with RO_CLEAN_AIR_FACTOR. RO_CLEAN_AIR_FACTOR is about
         10, which differs slightly between different sensors.
************************************************************************************/
float MQCalibration(int pinS14){
    int i;
    float valueS14=0;

    for (i=0; i<CALIBARAION_SAMPLE_TIMES; i++) {          //take multiple samples
        valueS14 += MQResistanceCalculation(analogRead(pinS14));
        delay(CALIBRATION_SAMPLE_INTERVAL);
    }
    valueS14 = valueS14/CALIBARAION_SAMPLE_TIMES;                   //calculate the average value

    valueS14 = valueS14/RO_CLEAN_AIR_FACTOR;                        //divided by RO_CLEAN_AIR_FACTOR yields the Ro
    //according to the chart in the datasheet

    return valueS14;
}
/*****************************  MQRead *********************************************
Input:   pinS14 - analog channel
Output:  Rs of the sensor
Remarks: This function use MQResistanceCalculation to caculate the sensor resistenc (Rs).
         The Rs changes as the sensor is in the different consentration of the target
         gas. The sample times and the time interval between samples could be configured
         by changing the definition of the macros.
************************************************************************************/
float MQRead(int pinS14){
    int i;
    float rs=0;

    for (i=0; i<READ_SAMPLE_TIMES; i++) {
        rs += MQResistanceCalculation(analogRead(pinS14));
        delay(READ_SAMPLE_INTERVAL);
    }

    rs = rs/READ_SAMPLE_TIMES;

    return rs;
}

/*****************************  MQGetPercentage **********************************
Input:   rs_ro_ratio - Rs divided by Ro
         pcurve      - pointer to the curve of the target gas
Output:  ppm of the target gas
Remarks: By using the slope and a point of the line. The x(logarithmic value of ppm)
         of the line could be derived if y(rs_ro_ratio) is provided. As it is a
         logarithmic coordinate, power of 10 is used to convert the result to non-logarithmic
         value.
************************************************************************************/
int  MQGetPercentage(float rs_ro_ratio, float *pcurve){
    return (pow(10,( ((log(rs_ro_ratio)-pcurve[1])/pcurve[2]) + pcurve[0])));
}

/*****************************  MQGetGasPercentage **********************************
Input:   rs_ro_ratio - Rs divided by Ro
         gas_id      - target gas type
Output:  ppm of the target gas
Remarks: This function passes different curves to the MQGetPercentage function which
         calculates the ppm (parts per million) of the target gas.
************************************************************************************/
int MQGetGasPercentage(float rs_ro_ratio, int gas_id){
    if ( gas_id == GAS_LPG ) {
        return MQGetPercentage(rs_ro_ratio,LPGCurve);
    } else if ( gas_id == GAS_CO ) {
        return MQGetPercentage(rs_ro_ratio,COCurve);
    } else if ( gas_id == GAS_SMOKE ) {
        return MQGetPercentage(rs_ro_ratio,SmokeCurve);
    }

    return 0;
}


/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS14(){
    Ro = MQCalibration(pinS14);
    // Calibrating the sensor. Please make sure the sensor is in clean air
	Serial.print("Calibrated to :");Serial.println(Ro);
}

/* Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS14(){
    uint16_t valMQ = MQGetGasPercentage(MQRead(pinS14)/Ro,GAS_CO);
    Serial.print("Raw:");Serial.println(valueS14);

    Serial.print("LPG:");
    Serial.print(MQGetGasPercentage(MQRead(pinS14)/Ro,GAS_LPG) );
    Serial.print( "ppm" );
    Serial.print("    ");
    Serial.print("CO:");
    Serial.print(MQGetGasPercentage(MQRead(pinS14)/Ro,GAS_CO) );
    Serial.print( "ppm" );
    Serial.print("    ");
    Serial.print("SMOKE:");
    Serial.print(MQGetGasPercentage(MQRead(pinS14)/Ro,GAS_SMOKE) );
    Serial.print( "ppm" );
    Serial.print("\n");

    if (valMQ != lastMQ) {
        send(msgS14.set((int16_t)ceil(valMQ)));
        lastMQ = ceil(valMQ);
    }
}

