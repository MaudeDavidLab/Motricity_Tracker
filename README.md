# Motricity_Tracker
Source code and analysis pipeline for the low-cost voluntary running activity tracking system.

1. Arduino source code

2. Analysis pipeline in R

# Mousewheel Tracker Code Installation

### This README file functions to detail the process of installation of the Mousetracker Code on an Arduino Uno.

##### Author: Nicholas Bira, updated October 26th, 2020.

1) Have a current installation of the Arduino IDE [LINK](https://www.arduino.cc/en/main/software).
2) Download the relevant script, specifically EnableInterrupt_Mousewheels.ino, from the MaudeDavidLab GitHub repository.
3) Install the [EnableInterrupt](https://github.com/GreyGnome/EnableInterrupt) Library, required to enable the interrupt function on all pins of an Arduino or other microcontrollers.
4) Connect the relevant Arduino or microcontroller and upload the program, following standard procedure as documented on either the Arduino website or in the documentation of whichever microcontroller is being used.

# Conversion and Processing Pipeline

## This details the process of converting and processing raw data off the tracker into a usable format.

#### Author: Grace Deitzler, updated January 7th, 2021.

1) Have a current installation of R or RStudio (https://rstudio.com/products/rstudio/)
2) Download the conversion script Conversion_And_Processing.Rmd: https://github.com/MaudeDavidLab/Motricity_Tracker/blob/master/Conversion_and_Processing.Rmd.
3) If needed, install the relevant packages included in the script (ggplot2 and reshape2.)
4) Load the table into the read.table() command in the R Markdown script (line 25). You may load in a raw .txt file directly from the Arduino, or you may choose to open that file in Notebook or another text editing app first, and then save it as a .csv file. The script will take both.
4) Follow the rest of the instructions in the R Markdown file to convert your data. We have converted the numbers into miles for distance here, but you may choose to convert this into kilometers instead.
