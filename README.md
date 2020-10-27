# Motricity_Tracker
Source code and analysis pipeline for the low-cost voluntary running activity tracking system.

1. Arduino source code
    This is used to set up the Arduino Uno microcontroller apparatus.

2. Analysis pipeline in R
    This pipeline takes the .txt file output from the Arduino, converts the counts to number of rotations, and then to distance (in mi.)
    The output of this pipeline is a .csv file that can then be used to plot and compare data.


