; this file is part of vectrex frogger, written by Christopher Salomon
; in March-April 1998 all stuff contained here is public domain (?)
; 
; Fixed to compile with AS6809 by Joakim Larsson Edström 2015.
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; this file contains includes for vectrex BIOS functions and variables      ;
; it was written by Bruce Tomlin, slighte changed by Christopher Salomon    ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

Vec_Snd_Shadow  equ     0xC800   ;Shadow of sound chip registers (15 bytes)
Vec_Btn_State   equ     0xC80F   ;Current state of all joystick buttons
Vec_Prev_Btns   equ     0xC810   ;Previous state of all joystick buttons
Vec_Buttons     equ     0xC811   ;Current toggle state of all buttons
Vec_Button_1_1  equ     0xC812   ;Current toggle state of stick 1 button 1
Vec_Button_1_2  equ     0xC813   ;Current toggle state of stick 1 button 2
Vec_Button_1_3  equ     0xC814   ;Current toggle state of stick 1 button 3
Vec_Button_1_4  equ     0xC815   ;Current toggle state of stick 1 button 4
Vec_Button_2_1  equ     0xC816   ;Current toggle state of stick 2 button 1
Vec_Button_2_2  equ     0xC817   ;Current toggle state of stick 2 button 2
Vec_Button_2_3  equ     0xC818   ;Current toggle state of stick 2 button 3
Vec_Button_2_4  equ     0xC819   ;Current toggle state of stick 2 button 4
Vec_Joy_Resltn  equ     0xC81A   ;Joystick A/D resolution (0x80=min 0x00=max)
Vec_Joy_1_X     equ     0xC81B   ;Joystick 1 left/right
Vec_Joy_1_Y     equ     0xC81C   ;Joystick 1 up/down
Vec_Joy_2_X     equ     0xC81D   ;Joystick 2 left/right
Vec_Joy_2_Y     equ     0xC81E   ;Joystick 2 up/down
Vec_Joy_Mux     equ     0xC81F   ;Joystick enable/mux flags (4 bytes)
Vec_Joy_Mux_1_X equ     0xC81F   ;Joystick 1 X enable/mux flag (=1)
Vec_Joy_Mux_1_Y equ     0xC820   ;Joystick 1 Y enable/mux flag (=3)
Vec_Joy_Mux_2_X equ     0xC821   ;Joystick 2 X enable/mux flag (=5)
Vec_Joy_Mux_2_Y equ     0xC822   ;Joystick 2 Y enable/mux flag (=7)
Vec_Misc_Count  equ     0xC823   ;Misc counter/flag byte, zero when not in use
Vec_0Ref_Enable equ     0xC824   ;Check0Ref enable flag
Vec_Loop_Count  equ     0xC825   ;Loop counter word (incremented in Wait_Recal)
Vec_Brightness  equ     0xC827   ;Default brightness
Vec_Dot_Dwell   equ     0xC828   ;Dot dwell time?
Vec_Pattern     equ     0xC829   ;Dot pattern (bits)
Vec_Text_HW     equ     0xC82A   ;Default text height and width
Vec_Text_Height equ     0xC82A   ;Default text height
Vec_Text_Width  equ     0xC82B   ;Default text width
Vec_Str_Ptr     equ     0xC82C   ;Temporary string pointer for Print_Str
Vec_Counters    equ     0xC82E   ;Six bytes of counters
Vec_Counter_1   equ     0xC82E   ;First  counter byte
Vec_Counter_2   equ     0xC82F   ;Second counter byte
Vec_Counter_3   equ     0xC830   ;Third  counter byte
Vec_Counter_4   equ     0xC831   ;Fourth counter byte
Vec_Counter_5   equ     0xC832   ;Fifth  counter byte
Vec_Counter_6   equ     0xC833   ;Sixth  counter byte
Vec_RiseRun_Tmp equ     0xC834   ;Temp storage word for rise/run
Vec_Angle       equ     0xC836   ;Angle for rise/run and rotation calculations
Vec_Run_Index   equ     0xC837   ;Index pair for run
;*                       0xC839   ;Pointer to copyright string during startup
Vec_Rise_Index  equ     0xC839   ;Index pair for rise
;*                       0xC83B   ;High score cold-start flag (=0 if valid)
Vec_RiseRun_Len equ     0xC83B   ;length for rise/run
;*                       0xC83C   ;temp byte
Vec_Rfrsh       equ     0xC83D   ;Refresh time (divided by 1.5MHz)
Vec_Rfrsh_lo    equ     0xC83D   ;Refresh time low byte
Vec_Rfrsh_hi    equ     0xC83E   ;Refresh time high byte
Vec_Music_Work  equ     0xC83F   ;Music work buffer (14 bytes, backwards?)
Vec_Music_Wk_A  equ     0xC842   ;        register 10
;*                       0xC843   ;        register 9
;*                       0xC844   ;        register 8
Vec_Music_Wk_7  equ     0xC845   ;        register 7
Vec_Music_Wk_6  equ     0xC846   ;        register 6
Vec_Music_Wk_5  equ     0xC847   ;        register 5
;*                       0xC848   ;        register 4
;*                       0xC849   ;        register 3
;*                       0xC84A   ;        register 2
Vec_Music_Wk_1  equ     0xC84B   ;        register 1
;*                       0xC84C   ;        register 0
Vec_Freq_Table  equ     0xC84D   ;Pointer to note-to-fr.EQUency table (normally 0xFC8D)
Vec_Max_Players equ     0xC84F   ;Maximum number of players for Select_Game
Vec_Max_Games   equ     0xC850   ;Maximum number of games for Select_Game
Vec_ADSR_Table  equ     0xC84F   ;Storage for first music header word (ADSR table)
Vec_Twang_Table equ     0xC851   ;Storage for second music header word ('twang' table)
Vec_Music_Ptr   equ     0xC853   ;Music data pointer
Vec_Expl_ChanA  equ     0xC853   ;Used by Explosion_Snd - bit for first channel used?
Vec_Expl_Chans  equ     0xC854   ;Used by Explosion_Snd - bits for all channels used?
Vec_Music_Chan  equ     0xC855   ;Current sound channel number for Init_Music
Vec_Music_Flag  equ     0xC856   ;Music active flag (0x00=off 0x01=start 0x80=on)
Vec_Duration    equ     0xC857   ;Duration counter for Init_Music
Vec_Music_Twang equ     0xC858   ;3 word 'twang' table used by Init_Music
Vec_Expl_1      equ     0xC858   ;Four bytes copied from Explosion_Snd's U-reg parameters
Vec_Expl_2      equ     0xC859   ;
Vec_Expl_3      equ     0xC85A   ;
Vec_Expl_4      equ     0xC85B   ;
Vec_Expl_Chan   equ     0xC85C   ;Used by Explosion_Snd - channel number in use?
Vec_Expl_ChanB  equ     0xC85D   ;Used by Explosion_Snd - bit for second channel used?
Vec_ADSR_Timers equ     0xC85E   ;ADSR timers for each sound channel (3 bytes)
Vec_Music_Freq  equ     0xC861   ;Storage for base fr.EQUency of each channel (3 words)
;*                       0xC85E   ;Scratch 'score' storage for Display_Option (7 bytes)
Vec_Expl_Flag   equ     0xC867   ;Explosion_Snd initialization flag?
;*               0xC868...0xC876   ;Unused?
Vec_Expl_Timer  equ     0xC877   ;Used by Explosion_Snd
;*                       0xC878   ;Unused?
Vec_Num_Players equ     0xC879   ;Number of players selected in Select_Game
Vec_Num_Game    equ     0xC87A   ;Game number selected in Select_Game
Vec_Seed_Ptr    equ     0xC87B   ;Pointer to 3-byte random number seed (=0xC87D)
Vec_Random_Seed equ     0xC87D   ;Default 3-byte random number seed
                                ;
;*    0xC880 - 0xCBEA is user RAM  ;
                                ;
Vec_Default_Stk equ     0xCBEA   ;Default top-of-stack
Vec_High_Score  equ     0xCBEB   ;High score storage (7 bytes)
Vec_SWI3_Vector equ     0xCBF2   ;SWI2/SWI3 interrupt vector (3 bytes)
Vec_SWI2_Vector equ     0xCBF2   ;SWI2/SWI3 interrupt vector (3 bytes)
Vec_FIRQ_Vector equ     0xCBF5   ;FIRQ interrupt vector (3 bytes)
Vec_IRQ_Vector  equ     0xCBF8   ;IRQ interrupt vector (3 bytes)
Vec_SWI_Vector  equ     0xCBFB   ;SWI/NMI interrupt vector (3 bytes)
Vec_NMI_Vector  equ     0xCBFB   ;SWI/NMI interrupt vector (3 bytes)
Vec_Cold_Flag   equ     0xCBFE   ;Cold start flag (warm start if = 0x7321)
                                ;
VIA_port_b      equ     0xD000   ;VIA port B data I/O register
;*       0 sample/hold (0=enable  mux 1=disable mux)
;*       1 mux sel 0
;*       2 mux sel 1
;*       3 sound BC1
;*       4 sound BDIR
;*       5 comparator input
;*       6 external device (slot pin 35) initialized to input
;*       7 /RAMP
VIA_port_a      equ     0xD001   ;VIA port A data I/O register (handshaking)
VIA_DDR_b       equ     0xD002   ;VIA port B data direction register (0=input 1=output)
VIA_DDR_a       equ     0xD003   ;VIA port A data direction register (0=input 1=output)
VIA_t1_cnt_lo   equ     0xD004   ;VIA timer 1 count register lo (scale factor)
VIA_t1_cnt_hi   equ     0xD005   ;VIA timer 1 count register hi
VIA_t1_lch_lo   equ     0xD006   ;VIA timer 1 latch register lo
VIA_t1_lch_hi   equ     0xD007   ;VIA timer 1 latch register hi
VIA_t2_lo       equ     0xD008   ;VIA timer 2 count/latch register lo (refresh)
VIA_t2_hi       equ     0xD009   ;VIA timer 2 count/latch register hi
VIA_shift_reg   equ     0xD00A   ;VIA shift register
VIA_aux_cntl    equ     0xD00B   ;VIA auxiliary control register
;*       0 PA latch enable
;*       1 PB latch enable
;*       2 \                     110=output to CB2 under control of phase 2 clock
;*       3  > shift register control     (110 is the only mode used by the Vectrex ROM)
;*       4 /
;*       5 0=t2 one shot                 1=t2 free running
;*       6 0=t1 one shot                 1=t1 free running
;*       7 0=t1 disable PB7 output       1=t1 enable PB7 output
VIA_cntl        equ     0xD00C   ;VIA control register
;*       0 CA1 control     CA1 -> SW7    0=IRQ on low 1=IRQ on high
;*       1 \
;*       2  > CA2 control  CA2 -> /ZERO  110=low 111=high
;*       3 /
;*       4 CB1 control     CB1 -> NC     0=IRQ on low 1=IRQ on high
;*       5 \
;*       6  > CB2 control  CB2 -> /BLANK 110=low 111=high
;*       7 /
VIA_int_flags   equ     0xD00D   ;VIA interrupt flags register
;*               bit                             cleared by
;*       0 CA2 interrupt flag            reading or writing port A I/O
;*       1 CA1 interrupt flag            reading or writing port A I/O
;*       2 shift register interrupt flag reading or writing shift register
;*       3 CB2 interrupt flag            reading or writing port B I/O
;*       4 CB1 interrupt flag            reading or writing port A I/O
;*       5 timer 2 interrupt flag        read t2 low or write t2 high
;*       6 timer 1 interrupt flag        read t1 count low or write t1 high
;*       7 IRQ status flag               write logic 0 to IER or IFR bit
VIA_int_enable  equ     0xD00E   ;VIA interrupt enable register
;*       0 CA2 interrupt enable
;*       1 CA1 interrupt enable
;*       2 shift register interrupt enable
;*       3 CB2 interrupt enable
;*       4 CB1 interrupt enable
;*       5 timer 2 interrupt enable
;*       6 timer 1 interrupt enable
;*       7 IER set/clear control
VIA_port_a_nohs equ     0xD00F   ;VIA port A data I/O register (no handshaking)

Cold_Start      equ     0xF000   ;
Warm_Start      equ     0xF06C   ;
Init_VIA        equ     0xF14C   ;
Init_OS_RAM     equ     0xF164   ;
Init_OS         equ     0xF18B   ;
Wait_Recal      equ     0xF192   ;
Set_Refresh     equ     0xF1A2   ;
DP_to_D0        equ     0xF1AA   ;
DP_to_C8        equ     0xF1AF   ;
Read_Btns_Mask  equ     0xF1B4   ;
Read_Btns       equ     0xF1BA   ;
Joy_Analog      equ     0xF1F5   ;
Joy_Digital     equ     0xF1F8   ;
Sound_Byte      equ     0xF256   ;
Sound_Byte_x    equ     0xF259   ;
Sound_Byte_raw  equ     0xF25B   ;
Clear_Sound     equ     0xF272   ;
Sound_Bytes     equ     0xF27D   ;
Sound_Bytes_x   equ     0xF284   ;
Do_Sound        equ     0xF289   ;
Do_Sound_x      equ     0xF28C   ;
Intensity_1F    equ     0xF29D   ;
Intensity_3F    equ     0xF2A1   ;
Intensity_5F    equ     0xF2A5   ;
Intensity_7F    equ     0xF2A9   ;
Intensity_a     equ     0xF2AB   ;
Dot_ix_b        equ     0xF2BE   ;
Dot_ix          equ     0xF2C1   ;
Dot_d           equ     0xF2C3   ;
Dot_here        equ     0xF2C5   ;
Dot_List        equ     0xF2D5   ;
Dot_List_Reset  equ     0xF2DE   ;
Recalibrate     equ     0xF2E6   ;
Moveto_x_7F     equ     0xF2F2   ;
Moveto_d_7F     equ     0xF2FC   ;
Moveto_ix_FF    equ     0xF308   ;
Moveto_ix_7F    equ     0xF30C   ;
Moveto_ix_b     equ     0xF30E   ; Used to be named Moveto_ix_a but this is wrong.
Moveto_ix       equ     0xF310   ;
Moveto_d        equ     0xF312   ;
Reset0Ref_D0    equ     0xF34A   ;
Check0Ref       equ     0xF34F   ;
Reset0Ref       equ     0xF354   ;
Reset_Pen       equ     0xF35B   ;
Reset0Int       equ     0xF36B   ;
Print_Str_hwyx  equ     0xF373   ;
Print_Str_yx    equ     0xF378   ;
Print_Str_d     equ     0xF37A   ;
Print_List_hw   equ     0xF385   ;
Print_List      equ     0xF38A   ;
Print_List_chk  equ     0xF38C   ;
Print_Ships_x   equ     0xF391   ;
Print_Ships     equ     0xF393   ;
Mov_Draw_VLc_a  equ     0xF3AD   ;count y x y x ...
Mov_Draw_VL_b   equ     0xF3B1   ;y x y x ...
Mov_Draw_VLcs   equ     0xF3B5   ;count scale y x y x ...
Mov_Draw_VL_ab  equ     0xF3B7   ;y x y x ...
Mov_Draw_VL_a   equ     0xF3B9   ;y x y x ...
Mov_Draw_VL     equ     0xF3BC   ;y x y x ...
Mov_Draw_VL_d   equ     0xF3BE   ;y x y x ...
Draw_VLc        equ     0xF3CE   ;count y x y x ...
Draw_VL_b       equ     0xF3D2   ;y x y x ...
Draw_VLcs       equ     0xF3D6   ;count scale y x y x ...
Draw_VL_ab      equ     0xF3D8   ;y x y x ...
Draw_VL_a       equ     0xF3DA   ;y x y x ...
Draw_VL         equ     0xF3DD   ;y x y x ...
Draw_Line_d     equ     0xF3DF   ;y x y x ...
Draw_VLp_FF     equ     0xF404   ;pattern y x pattern y x ... 0x01
Draw_VLp_7F     equ     0xF408   ;pattern y x pattern y x ... 0x01
Draw_VLp_scale  equ     0xF40C   ;scale pattern y x pattern y x ... 0x01
Draw_VLp_b      equ     0xF40E   ;pattern y x pattern y x ... 0x01
Draw_VLp        equ     0xF410   ;pattern y x pattern y x ... 0x01
Draw_Pat_VL_a   equ     0xF434   ;y x y x ...
Draw_Pat_VL     equ     0xF437   ;y x y x ...
Draw_Pat_VL_d   equ     0xF439   ;y x y x ...
Draw_VL_mode    equ     0xF46E   ;mode y x mode y x ... 0x01
Print_Str       equ     0xF495   ;
Random_3        equ     0xF511   ;
Random          equ     0xF517   ;
Init_Music_Buf  equ     0xF533   ;
Clear_x_b       equ     0xF53F   ;
Clear_C8_RAM    equ     0xF542   ;never used by GCE carts?
Clear_x_256     equ     0xF545   ;
Clear_x_d       equ     0xF548   ;
Clear_x_b_80    equ     0xF550   ;
Clear_x_b_a     equ     0xF552   ;
Dec_3_Counters  equ     0xF55A   ;
Dec_6_Counters  equ     0xF55E   ;
Dec_Counters    equ     0xF563   ;
Delay_3         equ     0xF56D   ;30 cycles
Delay_2         equ     0xF571   ;25 cycles
Delay_1         equ     0xF575   ;20 cycles
Delay_0         equ     0xF579   ;12 cycles
Delay_b         equ     0xF57A   ;5*B + 10 cycles
Delay_RTS       equ     0xF57D   ;5 cycles
Bitmask_a       equ     0xF57E   ;
Abs_a_b         equ     0xF584   ;
Abs_b           equ     0xF58B   ;
Rise_Run_Angle  equ     0xF593   ;
Get_Rise_Idx    equ     0xF5D9   ;
Get_Run_Idx     equ     0xF5DB   ;
Get_Rise_Run    equ     0xF5EF   ;
Rise_Run_X      equ     0xF5FF   ;
Rise_Run_Y      equ     0xF601   ;
Rise_Run_Len    equ     0xF603   ;
Rot_VL_ab       equ     0xF610   ;
Rot_VL          equ     0xF616   ;
Rot_VL_Mode_a   equ     0xF61F   ;
Rot_VL_Mode     equ     0xF62B   ;
Rot_VL_dft      equ     0xF637   ;
Xform_Run_a     equ     0xF65B   ;
Xform_Run       equ     0xF65D   ;
Xform_Rise_a    equ     0xF661   ;
Xform_Rise      equ     0xF663   ;
Move_Mem_a_1    equ     0xF67F   ;
Move_Mem_a      equ     0xF683   ;
Init_Music_chk  equ     0xF687   ;
Init_Music      equ     0xF68D   ;
Init_Music_x    equ     0xF692   ;
Select_Game     equ     0xF7A9   ;
Clear_Score     equ     0xF84F   ;
Add_Score_a     equ     0xF85E   ;
Add_Score_d     equ     0xF87C   ;
Strip_Zeros     equ     0xF8B7   ;
Compare_Score   equ     0xF8C7   ;
New_High_Score  equ     0xF8D8   ;
Obj_Will_Hit_u  equ     0xF8E5   ;
Obj_Will_Hit    equ     0xF8F3   ;
Obj_Hit         equ     0xF8FF   ;
Explosion_Snd   equ     0xF92E   ;
Draw_Grid_VL    equ     0xFF9F   ;
                                ;
music1  equ 0xFD0D               ;
music2  equ 0xFD1D               ;
music3  equ 0xFD81               ;
music4  equ 0xFDD3               ;
music5  equ 0xFE38               ;
music6  equ 0xFE76               ;
music7  equ 0xFEC6               ;
music8  equ 0xFEF8               ;
music9  equ 0xFF26               ;
musica  equ 0xFF44               ;
musicb  equ 0xFF62               ;
musicc  equ 0xFF7A               ;
musicd  equ 0xFF8F               ;

