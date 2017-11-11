; init code
init
    ; set up joystick
    LDA #1
    STA Vec_Joy_Mux_1_X 
    LDA #3
    STA Vec_Joy_Mux_1_Y
    LDA #0
    STA Vec_Joy_Mux_2_X
    STA Vec_Joy_Mux_2_Y
    ; set up the high score table
    LDX #player_score
    JSR Clear_Score  
    LDX #high_score
    JSR Clear_Score
 
    JMP title_screen
