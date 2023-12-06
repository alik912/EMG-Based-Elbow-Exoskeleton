int lsone=52;
int lstwo=53;
int swr = 50;      // for reverse switch
int swst= 48;     // for stop switch at pin 3
int swf = 46;      // for foraward switch at pin 4
int RPWM_Output = 2; 
int LPWM_Output = 3; 
int tric = 1;
int bic = 2;//pin number to use the ADC
int sensorValue = 0;    //initialization of sensor variable, equivalent to EMA Y
float EMA_a = 0.3;      //initialization of EMA alpha
int EMA_t = 0; 
int EMA_b = 0; 
int sensorValue2 = 0;//initialization of EMA S

void setup() {

  pinMode(swr,INPUT);
  pinMode(swst,INPUT);
  pinMode (swf ,INPUT);
  pinMode(44,INPUT);
            
  EMA_t = analogRead(tric); 
  EMA_b = analogRead(bic);//set EMA S for t=1
  pinMode(RPWM_Output, OUTPUT);
  pinMode(LPWM_Output, OUTPUT); 
  Serial.begin(115200);//setup of Serial module, 115200 bits/second   
 
}
void loop()
{

   int  b1= digitalRead(swr);
   int  b2=digitalRead(swst);
   int  b3=digitalRead(swf);
   int  ls1 = digitalRead(lsone);
   int  ls2 = digitalRead(lstwo);
   int mansw= digitalRead(44);
   int bicep = analogRead(A2);
   int tricep = analogRead(A1);


/////////////////////////////////////////////////MANUALMODEbody//////////////////////////////////////////
   if (mansw==LOW)
    {
      ///////////////////////////////////////////////forwardbody/////////////////////////////////////////   
     
      if(ls2==LOW)
      {
      if(b1==LOW && b2==HIGH && b3== LOW  ) 
      {
        analogWrite(LPWM_Output, 254);
         analogWrite(RPWM_Output, 0);
      }}
      else
      {
        analogWrite(LPWM_Output, 0);
        analogWrite(RPWM_Output, 64);
        delay(1);
        analogWrite(LPWM_Output, 0);
        analogWrite(RPWM_Output, 0);
      
     
      }

/////////////////////////////////////////////Reversebody/////////////////////////////////////////////

     if(ls1==LOW)
       {
        if( b1 == LOW && b2== LOW && b3 == HIGH )
       {
              analogWrite(LPWM_Output, 0);
              analogWrite(RPWM_Output, 254);
         
       }}
       else 
       {
        analogWrite(LPWM_Output, 64);
        analogWrite(RPWM_Output, 0);
        delay(10);
        analogWrite(LPWM_Output, 0);
        analogWrite(RPWM_Output, 0);
      }
      if( b1 == LOW && b2== LOW && b3 == LOW )
{
      analogWrite(LPWM_Output, 0);
      analogWrite(RPWM_Output, 0);

  
}

}

////////////////////////////////////////////////stopbody////////////////////////////////////////////

       
      

/////////////////////////////////////////AUTOMODEBODY//////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////////////////////////////////////   
    else
    {
    sensorValue = analogRead(tric);                //read the sensor value using ADC
    EMA_t = (EMA_a*sensorValue) + ((1-EMA_a)*EMA_t); 
    sensorValue2 = analogRead(bic);                //read the sensor value using ADC
    EMA_b = (EMA_a*sensorValue2) + ((1-EMA_a)*EMA_b); //run the EMA
    int result = EMA_b - EMA_t;
    
    Serial.print(EMA_t);                              //print digital value to serial
    Serial.print(","); 
    Serial.print(EMA_b);  
    Serial.print (",");
    Serial.println(abs(result));
    delay(50);
      
///////when arm extended//////////
       if (result >70 && result <150)
    {
      analogWrite(LPWM_Output, 0);
      analogWrite(RPWM_Output, 0); // arm is relaxed
    }
     if(ls2==LOW)
     
      {
        if (result>0 && result<80)
        {
      analogWrite(LPWM_Output, 128); // arm intends to flex
      analogWrite(RPWM_Output, 0);
      delay (10);
        }}
       else 
       {
        analogWrite(LPWM_Output, 0);
        analogWrite(RPWM_Output, 64);
        delay(10);
        analogWrite(LPWM_Output, 0);
        analogWrite(RPWM_Output, 0);
      }
    
/////////when arm flexed/////////
    if (result>40 && result<100)
    {
      analogWrite(LPWM_Output, 0);// arm is totally flexed and relaxed
      analogWrite(RPWM_Output, 0);
    }
    if(ls1==LOW)
      {
         if(result >0 && result <100)
   {
      analogWrite(LPWM_Output, 0);
      analogWrite(RPWM_Output, 128);
      delay(10);
    }
      }
      else
      {
        analogWrite(LPWM_Output, 64);
        analogWrite(RPWM_Output, 0);
        delay(1);
        analogWrite(LPWM_Output, 0);
        analogWrite(RPWM_Output, 0);
      
     
      }  
   
    }}
