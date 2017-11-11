; main game
init_game
    ; hiscore
    LDX #player_score
    JSR Clear_Score    

    LDA #100
    LDX #player_score
    JSR Add_Score_a
    ;set player cords.
    LDA #0
    LDB #10
    STA player_x
    STB player_y

    LDA #2
    STA speed

; main loop
main
    ; code for joy stick is based on the docs on playvectrex.com
joystick_input
    JSR Joy_Digital     ; read joy stick
    LDA Vec_Joy_1_X
    BEQ no_x_movement
    BMI left_move
right_move
    LDA player_x
    ADDA speed
    STA player_x
    ;; move right here.
    BRA x_done
left_move
    LDA player_x
    SUBA speed
    STA player_x
    ;; nothing needs to be done.
no_x_movement
    ;; nothing for this has to happen.
x_done
    JSR Read_Btns
    BITA #$01
    BEQ done_buttons
    LDA player_y
    ADDA speed
    STA player_y
    BRA draw
done_buttons
    LDA player_y
    DECA
    ; we should read memory
    CMPA #-40;
    BLT floor
    STA player_y
floor
draw
    ; draw the scene   
    JSR Wait_Recal      ; recalibrate
    JSR Intensity_5F    ; set intensity
    ; display the player score.
    LDU #player_score
    LDA #$7f
    LDB #-$80
    JSR Print_Str_d
    ; we set the scale factor for rendering normal lines
    LDA #$80           ; some scale factor.
    STA VIA_t1_cnt_lo
    LDA player_y
    LDB player_x
    JSR Moveto_d        ; reset the position to the center (0,0)
    ; draw dinosaur
    LDX #dinosaur   
    JSR Draw_VLc

    BRA main

; floor checking function
floor_check
    LDA active_floors
