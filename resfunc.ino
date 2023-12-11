float resfunc(int inpinin, int inpinmid, int inpinout){
  float vol0 = VolFunc(inpinin);
  float vol2 = VolFunc(inpinmid);
  float vol1 = VolFunc(inpinout);
  float res = 10000*(vol2-vol1)/(vol0-vol2);
  return res;
  //takes voltage and gives resistance of the second, unknown resistor
}