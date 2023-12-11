void writeSD( float res, float temp){
  myFile = SD.open(fname, FILE_WRITE );
  //DateTime now = rtc.now();
  
  // if the file opened okay, write to it:
  if (myFile) {

    myFile.print(res);
    myFile.print(',');
    myFile.println(temp);
   // myFile.print(',');
   // myFile.print(resL);
   // myFile.print(',');
   // myFile.println(light);
 
	 // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening file");

    //same as print to serial but it puts the code on an excel sheet. pretty cool
    //the ',' puts it in different cells hehe

  }
}