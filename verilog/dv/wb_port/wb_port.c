/*
 * SPDX-FileCopyrightText: 2020 Efabless Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * SPDX-License-Identifier: Apache-2.0
 */

// This include is relative to $CARAVEL_PATH (see Makefile)
#include <defs.h>
#include <stub.c>

#define WB_BASE 0x32000000
#define CTRL_ADDR ((volatile uint32_t*)WB_BASE)

// Knight Co Processor registers
#define kiop_operation (*(CTRL_ADDR+0)) // what to do? (multiplication: 1, ...)
#define kiop_status (*(CTRL_ADDR+1)) // write -1 to start, check later for error codes
#define kiop_width_a (*(CTRL_ADDR+2)) // width of matrix A
#define kiop_height_a (*(CTRL_ADDR+3)) // height of matrix A
#define kiop_width_b (*(CTRL_ADDR+4)) // width of matrix B
#define kiop_height_b (*(CTRL_ADDR+5)) // height of matrix B

#define matrix0 (*(CTRL_ADDR+6))
#define matrix1 (*(CTRL_ADDR+7))
#define matrix2 (*(CTRL_ADDR+8))
#define matrix3 (*(CTRL_ADDR+9))

#define matrix4 (*(CTRL_ADDR+10))
#define matrix5 (*(CTRL_ADDR+11))
#define matrix6 (*(CTRL_ADDR+12))
#define matrix7 (*(CTRL_ADDR+13))
#define matrix8 (*(CTRL_ADDR+14))
#define matrix9 (*(CTRL_ADDR+15))

#define matrix10 (*(CTRL_ADDR+16))
#define matrix11 (*(CTRL_ADDR+17))
#define matrix12 (*(CTRL_ADDR+18))
#define matrix13 (*(CTRL_ADDR+19))
#define matrix14 (*(CTRL_ADDR+20))
#define matrix15 (*(CTRL_ADDR+21))
#define matrix16 (*(CTRL_ADDR+22))
#define matrix17 (*(CTRL_ADDR+23))
#define matrix18 (*(CTRL_ADDR+24))
#define matrix19 (*(CTRL_ADDR+25))

#define matrix20 (*(CTRL_ADDR+26))
#define matrix21 (*(CTRL_ADDR+27))
#define matrix22 (*(CTRL_ADDR+28))
#define matrix23 (*(CTRL_ADDR+29))
#define matrix24 (*(CTRL_ADDR+30))
#define matrix25 (*(CTRL_ADDR+31))
#define matrix26 (*(CTRL_ADDR+32))
#define matrix27 (*(CTRL_ADDR+33))
#define matrix28 (*(CTRL_ADDR+34))
#define matrix29 (*(CTRL_ADDR+35))

#define matrix30 (*(CTRL_ADDR+36))
#define matrix31 (*(CTRL_ADDR+37))
#define matrix32 (*(CTRL_ADDR+38))
#define matrix33 (*(CTRL_ADDR+39))
#define matrix34 (*(CTRL_ADDR+40))
#define matrix35 (*(CTRL_ADDR+41))
#define matrix36 (*(CTRL_ADDR+42))
#define matrix37 (*(CTRL_ADDR+43))
#define matrix38 (*(CTRL_ADDR+44))
#define matrix39 (*(CTRL_ADDR+45))

#define matrix40 (*(CTRL_ADDR+46))
#define matrix41 (*(CTRL_ADDR+47))
#define matrix42 (*(CTRL_ADDR+48))


/*
  Wishbone Test:
    - Configures MPRJ lower 8-IO pins as outputs
    - Checks counter value through the wishbone port
*/

void main()
{
    /*
    IO Control Registers
    | DM     | VTRIP | SLOW  | AN_POL | AN_SEL | AN_EN | MOD_SEL | INP_DIS | HOLDH | OEB_N | MGMT_EN |
    | 3-bits | 1-bit | 1-bit | 1-bit  | 1-bit  | 1-bit | 1-bit   | 1-bit   | 1-bit | 1-bit | 1-bit   |
    Output: 0000_0110_0000_1110  (0x1808) = GPIO_MODE_USER_STD_OUTPUT
    | DM     | VTRIP | SLOW  | AN_POL | AN_SEL | AN_EN | MOD_SEL | INP_DIS | HOLDH | OEB_N | MGMT_EN |
    | 110    | 0     | 0     | 0      | 0      | 0     | 0       | 1       | 0     | 0     | 0       |

    Input: 0000_0001_0000_1111 (0x0402) = GPIO_MODE_USER_STD_INPUT_NOPULL
    | DM     | VTRIP | SLOW  | AN_POL | AN_SEL | AN_EN | MOD_SEL | INP_DIS | HOLDH | OEB_N | MGMT_EN |
    | 001    | 0     | 0     | 0      | 0      | 0     | 0       | 0       | 0     | 1     | 0       |
    */

    /*
     * Set up the housekeeping SPI to be connected internally so
     * that external pin changes don't affect it.
     */

    reg_wb_enable = 1;
    reg_spi_enable = 1;
    //reg_spimaster_config = 0xa002;	// Enable, prescaler = 2,
                                          // connect to housekeeping SPI

    // All GPIO pins are configured to be output
    // Used to flad the start/end of a test
    reg_mprj_io_31 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_30 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_29 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_28 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_27 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_26 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_25 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_24 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_23 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_22 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_21 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_20 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_19 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_18 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_17 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_16 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_6 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_0  = GPIO_MODE_USER_STD_OUTPUT;

     /* Apply configuration */
    reg_mprj_xfer = 1;
    while (reg_mprj_xfer == 1);

    reg_la2_oenb = reg_la2_iena = 0x00000000;    // [95:64]

    // Flag start of the test
    reg_mprj_datal = 0xAB600000;

    /*
    DIM==2:

    -3  -15  x  9  -15 =     3   120
    -6   7      -2 -5      -68    55

    -3*9 + -15*-2 = -27 + 30 = 3
    -3*-15 + -15*-5 = 45 + 75 = 120
    -6*9 + 7*-2 = -54 + -14 = -68
    -6*-15  + 7*-5 = 90 + -35 = 55

    Correct!
    */

    // test square
#if 0
    // Matrix A 2x2
    matrix0 = -3;
    matrix1 = -15;
    matrix2 = -6;
    matrix3 = 7;

    // Matrix B 2x2
    matrix4 = 9;
    matrix5 = -15;
    matrix6 = -2;
    matrix7 = -5;

    kiop_operation = 1;
    // A 2 x 2
    kiop_width_a = 2;
    kiop_height_a = 2;
    // B 2 x 2
    kiop_width_b = 2;
    kiop_height_b = 2;

    kiop_status = -1; // shoot and go

    reg_mprj_datal = matrix8;
    reg_mprj_datal = matrix9;
    reg_mprj_datal = matrix10;
    reg_mprj_datal = matrix11;
#endif

    // test non square
    /*
     * -3 * -12 +  -15 * -6 = 126
     * 
     * 
     */

#if 0
   /*  
   Matrix A 3x2
   -3 -15 -7
    8 -15 -5

   Matrix B 2x3
   -12  13
    -6  5
     7  12
   */
    // A 3 x 2
    kiop_width_a = 3;
    kiop_height_a = 2;
    // B 2 x 3
    kiop_width_b = 2;
    kiop_height_b = 3;
#endif
   /*  
    Matrix A 2x3
    -3 -15
    -7   8
    -15 -5

   Matrix B 3x2
   -12 -13  -6
     5   7  12
   */

#if 0
    // Matrix A
    matrix0 = -3;
    matrix1 = -15;
    matrix2 = -7;
    matrix3 = 8;
    matrix4 = -15;
    matrix5 = -5;

    // Matrix B
    matrix6 =  -12;
    matrix7 =  -13;
    matrix8 =  -6;
    matrix9 =  5;
    matrix10 =  7;
    matrix11 =  12;

    kiop_operation = 1; // set one for multiplication
    // A 3 x 2
    kiop_width_a = 2;
    kiop_height_a = 3;
    // B 2 x 3
    kiop_width_b = 3;
    kiop_height_b = 2;

    kiop_status = -1; // shoot and go
#endif

#if 1
    // Matrix A 5x5
    matrix0 = 42;
    matrix1 = 2;
    matrix2 = 3;
    matrix3 = 4;
    matrix4 = 5;

    matrix5 = 6;
    matrix6 = 7;
    matrix7 = 8;
    matrix8 = 9;
    matrix9 = 10;

    matrix10 = 11;
    matrix11 = 12;
    matrix12 = 13;
    matrix13 = 14;
    matrix14 = 15;

    matrix15 = 16;
    matrix16 = 17;
    matrix17 = 18;
    matrix18 = 19;
    matrix19 = 20;
    
    matrix20 = 21;
    matrix21 = 22;
    matrix22 = 23;
    matrix23 = 24;
    matrix24 = 23;

    // Filter F 3x3
    matrix25 = 1;
    matrix26 = 1;
    matrix27 = 1;

    matrix28 = 0;
    matrix29 = 0;
    matrix30 = 0;

    matrix31 = -1;
    matrix32 = -1;
    matrix33 = -1;

    kiop_operation = 2; // Set 2 for selecting convolution
    // A 3 x 2
    kiop_width_a = 5;
    kiop_height_a = 5;
    // B 2 x 3
    kiop_width_b = 3;
    kiop_height_b = 3;

    kiop_status = -1; // shoot and go

    reg_mprj_datal = matrix34;
    reg_mprj_datal = matrix35;
    reg_mprj_datal = matrix36;

    reg_mprj_datal = matrix37;
    reg_mprj_datal = matrix38;
    reg_mprj_datal = matrix39;

    reg_mprj_datal = matrix40;
    reg_mprj_datal = matrix41;
    reg_mprj_datal = matrix42;

    /*
    11 -30 -30
   -30 -30 -30
   -30 -30 -28
   */
#endif

    reg_mprj_datal = 0xAB610000; // exit

}
