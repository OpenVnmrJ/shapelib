/* makempf - C code to create MPFn (n=1-10) decoupling files for 64k PPM modules

      Ref: T. Fujiwara and K. Nagayama: JMR 77 56-63 (1988).
           T. Fujiwara, T. Anai, N. Kurihara, and K. Nagayama:
                               JMR Series A 104 103-105 (1993).

              Peter Sandor Jun. 1994.          */

#include <stdio.h>

void displayhelp()
{
  printf("makempf - Create MPFn decoupling files for n=1-10 \n");
  printf("Usage: makempf number_of_180_pulses\n\n");
  printf("Example:\n");
  printf("   makempf 7        : Make MPF7.DEC decoupling file \n");
  printf("\nCAUTION: No check is made to verify a unique file name.  If a file with\n");
  printf("  the same name exists, it will be overwritten.  There is no provision here\n");
  printf("  for writing the output to anything other than the current directory.\n");
}

main(argc, argv)
int argc;
char *argv[];
{
  int i, j, k, n, m, numfreq;
  char outfname[64], fname[64], comname[64];
  FILE *outf;
  int flip[11];
  float freq[11], tycko[5], mlev[4];
  double phase, nfreq, lastphase;
  double atof();

  strcpy(outfname, "MPF");
  strcat(outfname, argv[1]);
  strcpy(comname, outfname);
  strcat(outfname, ".DEC");
  nfreq = atof(argv[1]);
  numfreq = (int) (nfreq + 0.5);

  /*check for proper input*/
  if (argc != 2)
  {
    displayhelp();
    return (1);
  }
  if (numfreq < 1 || numfreq > 10)
  {
    displayhelp();
    return (1);
  }

  /*check for output file*/
  outf = fopen(outfname, "w");
  if (outf == NULL)
  {
    printf("\nCould not open %s for writing. Exiting", outfname);
    exit(0);
  }
  else
  {
    printf("makempf - Creating MPF%s decoupler file \n", argv[1]);
  }
  fprintf(outf, "# %s decoupling file for BB heteronuclear decoupling.\n", outfname);
  fprintf(outf, "# For Unity or Unity+ systems with PPM module in the dec. channel.\n");
  fprintf(outf, "# Literature: T. Fujiwara and K. Nagayama: JMR 77,56-63 (1988).\n");
  fprintf(outf, "#             T. Fujiwara, T. Anai, N. Kurihara, and K. Nagayama:\n");
  fprintf(outf, "#                     JMR Series A 104,103-105 (1993).\n");
  fprintf(outf, "# Usage: Set dseq='%s', dres=1.0 and dmm='p',\n", comname);
  fprintf(outf, "#        Set dmf as calibrated for the current power level.\n");
  fprintf(outf, "#        To keep the cyclic sideband intensities at a low level\n");
  fprintf(outf, "#             dmf>12000 is recommended.\n#\n");


  /* Constant definitions */
  if (numfreq == 1)
  {
    flip[1] = 180;
    freq[1] = 0.0;
  }
  if (numfreq == 2)
  {
    flip[1] = 170;
    freq[1] = -0.920;
    flip[2] = 170;
    freq[2] = 0.920;
  }
  if (numfreq == 3)
  {
    flip[1] = 180;
    freq[1] = -1.550;
    flip[2] = 180;
    freq[2] = 0;
    flip[3] = 180;
    freq[3] = 1.550;
  }
  if (numfreq == 4)
  {
    flip[1] = 166;
    freq[1] = -2.200;
    flip[2] = 198;
    freq[2] = -0.660;
    flip[3] = 198;
    freq[3] = 0.660;
    flip[4] = 166;
    freq[4] = 2.200;
  }
  if (numfreq == 5)
  {
    flip[1] = 175;
    freq[1] = -2.900;
    flip[2] = 190;
    freq[2] = -1.400;
    flip[3] = 195;
    freq[3] = 0;
    flip[4] = 190;
    freq[4] = 1.400;
    flip[5] = 175;
    freq[5] = 2.900;
  }
  if (numfreq == 6)
  {
    flip[1] = 166;
    freq[1] = -3.600;
    flip[2] = 195;
    freq[2] = -2.060;
    flip[3] = 182;
    freq[3] = -0.660;
    flip[4] = 182;
    freq[4] = 0.660;
    flip[5] = 195;
    freq[5] = 2.060;
    flip[6] = 166;
    freq[6] = 3.600;
  }
  if (numfreq == 7)
  {
    flip[1] = 168;
    freq[1] = -4.270;
    flip[2] = 190;
    freq[2] = -2.710;
    flip[3] = 192;
    freq[3] = -1.370;
    flip[4] = 174;
    freq[4] = 0;
    flip[5] = 192;
    freq[5] = 1.370;
    flip[6] = 190;
    freq[6] = 2.710;
    flip[7] = 168;
    freq[7] = 4.270;
  }
  if (numfreq == 8)
  {
    flip[1] = 172;
    freq[1] = -5.090;
    flip[2] = 184;
    freq[2] = -3.500;
    flip[3] = 186;
    freq[3] = -2.100;
    flip[4] = 181;
    freq[4] = -0.710;
    flip[5] = 181;
    freq[5] = 0.710;
    flip[6] = 186;
    freq[6] = 2.100;
    flip[7] = 184;
    freq[7] = 3.500;
    flip[8] = 172;
    freq[8] = 5.090;
  }
  if (numfreq == 9)
  {
    flip[1] = 174;
    freq[1] = -5.690;
    flip[2] = 191;
    freq[2] = -4.190;
    flip[3] = 185;
    freq[3] = -2.790;
    flip[4] = 177;
    freq[4] = -1.410;
    flip[5] = 188;
    freq[5] = 0;
    flip[6] = 177;
    freq[6] = 1.410;
    flip[7] = 185;
    freq[7] = 2.790;
    flip[8] = 191;
    freq[8] = 4.190;
    flip[9] = 174;
    freq[9] = 5.690;
  }
  if (numfreq == 10)
  {
    flip[1] = 181;
    freq[1] = -6.450;
    flip[2] = 185;
    freq[2] = -5.050;
    flip[3] = 181;
    freq[3] = -3.550;
    flip[4] = 180;
    freq[4] = -2.120;
    flip[5] = 181;
    freq[5] = -.700;
    flip[6] = 181;
    freq[6] = 0.700;
    flip[7] = 180;
    freq[7] = 2.120;
    flip[8] = 181;
    freq[8] = 3.550;
    flip[9] = 185;
    freq[9] = 5.050;
    flip[10] = 181;
    freq[10] = 6.450;
  }

  /* determine the first phase cycle */
  tycko[1] = 0.0;
  tycko[2] = 150.0;
  tycko[3] = 60.0;
  tycko[4] = 150.0;
  tycko[5] = 0.0;

  /* determine MLEV phase cycle */
  mlev[1] = 0.0;
  mlev[2] = 180.0;
  mlev[3] = 180.0;
  mlev[4] = 0.0;

  /* pattern calculation */
  phase = 0.0;
  lastphase = 0.0;
  for (m = 1; m <= 4; m++)
  {
    for (k = 1; k <= 5; k++)
    {
      for (j = 1; j <= numfreq; j++)
      {
	for (i = 1; i <= flip[j]; i++)
	{
	  phase = lastphase + (i - 1) * freq[j] + tycko[k] + mlev[m];
	  if (phase > 360)
	    while (phase >= 360.0)
	      phase -= 360.0;
	  if (phase < 0.0)
	    while (phase < 0.0)
	      phase += 360.0;
	  fprintf(outf, "1.0\t%6.2f\t1023.0\n", phase);
	}
	lastphase = phase - tycko[k] - mlev[m];
      }
    }
  }
  printf("\nCreated %s .\n", outfname);
}
