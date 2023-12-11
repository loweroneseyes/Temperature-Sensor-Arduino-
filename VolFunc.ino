float VolFunc(int inpin){
  int vraw = analogRead(inpin);
  float vol = vraw/204.6;
  return vol;
  //this function takes raw gives me converted voltage
  //remenant of old code but i like having it since it kinda cleans up another function
  //im fond of her
}