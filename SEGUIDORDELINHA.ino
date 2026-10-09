
const int sensorEsq = 12;
const int sensorDir = 8;
const int ENA = 3;
const int ENB = 11;
const int IN1 = 5;
const int IN2 = 6;
const int IN3 = 9;
const int IN4 = 10;
int velReta = 120;
int velCurvaFrente = 250;
int velCurvaRe = -200;

void setup() {
pinMode(sensorEsq, INPUT);
pinMode(sensorDir, INPUT);
pinMode(ENA, OUTPUT);
pinMode(ENB, OUTPUT);
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT); }

void loop() {
bool esqDetectou = digitalRead(sensorEsq);
bool dirDetectou = digitalRead(sensorDir);
if (esqDetectou == LOW && dirDetectou == LOW) {
controlarMotores(velReta, velReta); }
else if (esqDetectou == HIGH && dirDetectou == LOW) {
controlarMotores(velCurvaRe, velCurvaFrente); }
else if (esqDetectou == LOW && dirDetectou == HIGH) {
controlarMotores(velCurvaFrente, velCurvaRe); }
else {
controlarMotores(velReta, velReta); } }

void controlarMotores(int vEsq, int vDir) {
if (vEsq >= 0) {
analogWrite(ENA, vEsq);
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW); }
else {
analogWrite(ENA, -vEsq);
digitalWrite(IN1, LOW);
digitalWrite(IN2, HIGH); }
if (vDir >= 0) {
analogWrite(ENB, vDir);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW); }
else {
analogWrite(ENB, -vDir);
digitalWrite(IN3, LOW);
digitalWrite(IN4, HIGH); } }
