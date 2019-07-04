//1,9,10,14
int Motor_L_H = 1;
int Motor_L_L = 9;
int Motor_R_H = 10;
int Motor_R_L = 14;

//2,11,12,16
int LED_FL = 2;
int LED_FR = 11;
int LED_BL = 12;
int LED_BR = 16;

int Step = 200;

void setup()
{
    pinMode(Motor_L_H, OUTPUT);
    pinMode(Motor_L_L, OUTPUT);
    pinMode(Motor_R_H, OUTPUT);
    pinMode(Motor_R_L, OUTPUT);

    pinMode(LED_FL, OUTPUT);
    pinMode(LED_FR, OUTPUT);
    pinMode(LED_BL, OUTPUT);
    pinMode(LED_BR, OUTPUT);

    Serial.begin(9600);
}

void loop()
{
    String inputbuf = "";
    int serialFlag = 0;
    int i;
    int cnt = 0;

    while (Serial.available() > 0)
    {
            serialFlag = 1;
            inputbuf += char(Serial.read());
            cnt++;
            delay(1);
    }

    if (serialFlag)
    {
        for(i = 0; i < cnt; i++)
        {
            switch(inputbuf[i])
            {
                case 'F':   Forward();
                    break;
                case 'B':   Backward();
                    break;
                case 'L':   Turnleft();
                    break;
                case 'R':   TurnRight();
                    break;
                default:
                    break;
            }

        }

    }

}

void Forward()
{
    digitalWrite(Motor_L_H, HIGH);
    digitalWrite(Motor_L_L, LOW);
    digitalWrite(Motor_R_H, HIGH);
    digitalWrite(Motor_L_L, LOW);

    delay(Step);
    Stop();
}

void Backward()
{
    digitalWrite(Motor_L_H, LOW);
    digitalWrite(Motor_L_L, HIGH);
    digitalWrite(Motor_R_H, LOW);
    digitalWrite(Motor_L_L, HIGH);
    
    delay(Step);
    Stop();
}

void Turnleft()
{
    digitalWrite(Motor_L_H, HIGH);
    digitalWrite(Motor_L_L, LOW);
    digitalWrite(Motor_R_H, LOW);
    digitalWrite(Motor_L_L, HIGH);

    digitalWrite(LED_BL, HIGH);
    digitalWrite(LED_FL, HIGH);

    delay(Step);
    Stop();
}

void TurnRight()
{
    digitalWrite(Motor_L_H, LOW);
    digitalWrite(Motor_L_L, HIGH);
    digitalWrite(Motor_R_H, HIGH);
    digitalWrite(Motor_L_L, LOW);
 
    digitalWrite(LED_BR, HIGH);
    digitalWrite(LED_FR, HIGH);

    delay(Step);
    Stop();
}

void Stop()
{
    digitalWrite(Motor_L_H, LOW);
    digitalWrite(Motor_L_L, LOW);
    digitalWrite(Motor_R_H, LOW);
    digitalWrite(Motor_L_L, LOW);

    digitalWrite(LED_BL, LOW);
    digitalWrite(LED_BR, LOW);
    digitalWrite(LED_FL, LOW);
    digitalWrite(LED_FR, LOW);
}
