# makempf
 makempf - Program for creating MPF waveform generator decoupling pattern

 Copyright 2016 University of Oregon

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.

                                SUBMISSION FORM

Your name:              Peter Sandor, Agilent
Date submitted:         1994-11-01

File name:              makempf
Directory:              shapelib
Description:            Program for creating MPF waveform generator
                        decoupling pattern

Related files:          bin/makempf.c   maclib/makempf  manual/makempf
                        (creates shapelib/MPFn.DEC )

Existing VnmrJ / VNMR files which are superseded or
otherwise affected by this submission:  none
Hardware configuration limitations:     WFG required
Known software version compatibility:   VNMR 4.x, 5.1
Known OS version compatibility:         SunOS 4.1.x
Special instructions for installation:
    If you are downloading from the Internet, store
    the file makempf.tar.Z in /vnmr/userlib/shapelib, then use

**This software has not been tested on OpenVnmrJ. Use at your own risk.**

To install this user contribution:  
Download the repository from GitHub and checkout the tag of the contribution you want.
Typically tags end in the version (e.g. -v1.0)

     git clone https://github.com/OpenVnmrJ/shapelib  
     cd shapelib  
     git checkout makempf-v1.0


You may also download the archive directly from github at

    https://github.com/OpenVnmrJ/maclib/archive/makempf-v1.0.zip

Read makempf.README for installation instructions.

In most cases, move the contribution to /vnmr/userlib/shapelib 
then use extract to install the contribution:  

    extract shapelib/makempf