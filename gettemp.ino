float gettemp(float res){
  float bR=log(res);
  float cR=bR*bR*bR;
  float oneoverTempK = (0.012604)+(-0.00166*bR)+(0.00000794801*cR);
  float TempK = 1/oneoverTempK;
  float TempC = TempK -273.15;
  return TempC;
//uses the steinhart hart equation to find the temperature from the changing resistance. does it step by step
}