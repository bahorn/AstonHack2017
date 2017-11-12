; Called when we start a new game.
init_game
    ; setup everything
    LDA #0
    STA count
    LDA #0
    STA player_x
    LDA #-$60
    STA player_y
    LDA #0
    STA bullet_active
    STA bullet_x
    STA bullet_y
    ; set up some enemies on the stack
    JSR Random_3 ; stores a random value in Register A, which is where we want it.
    LDB #$75
    STA enemy_x
    STB enemy_y
    LDA #1
    STA speed
    ; clear score
    LDX #player_score
    JSR Clear_Score  

;; the main game loop.
main
    ;; check status
    LDB #00
    CMPB bullet_active
    BEQ no_bullet
    LDB #$75
    CMPB bullet_y
    BGT in_frame
    LDA #0
    STA  bullet_active
    BRA no_bullet
in_frame
    LDA bullet_y
    ADDA #10
    STA bullet_y
no_bullet
    ; now update enemy position
    LDA enemy_y
    SUBA speed
    STA enemy_y
    LDB #-$7A
    CMPB enemy_y
    BGT bottom
    BRA collisions
bottom
    JSR Random_3
    STA enemy_x
    LDB #$75
    STB enemy_y
    jmp game_over
; this is actually not correct, but works in *most* cases.
collisions
    LDA bullet_active
    CMPA #00
    BEQ input
    LDA enemy_x
    ADDA #10
    SUBA bullet_x
    ;; drop sign bit
    LSLA
    LSRA
    CMPA #20
    BGT input
    LDA enemy_y
    SUBA bullet_y
    LSLA
    LSRA
    CMPA #12
    BGT input
bad
    LDA #100
    LDX #player_score
    JSR Add_Score_a
    LDA #0
    STA bullet_active
    LDA #-$7f
    STA bullet_y
    JSR Random_3
    STA enemy_x
    LDB #$75
    STB enemy_y

input
    ;; read input
    ; we care about left/right movement.
    JSR Joy_Digital
    LDA Vec_Joy_1_X
    BEQ no_movement
    BMI left_movement

right_movement
    LDA player_x
    ADDA #2
    STA player_x
    BRA movement_done

left_movement
    LDA player_x
    SUBA #2
    STA player_x
    BRA movement_done

no_movement
    ; do nothing
movement_done
    ;
    ; used to check if we are firing a bullet.
    JSR Read_Btns
    ; check if we are firing.
    BITA    #$01
    BEQ no_button
    ; preform creating on object here.
    LDA #01
    CMPA bullet_active
    BEQ no_button
    LDA player_x
    ADDA #5
    STA bullet_x
    LDA player_y
    STA bullet_y
    LDA #1
    STA bullet_active 

no_button
    ;; display everything.
    ; set up the displaying.
    JSR Wait_Recal
    LDA #10
    STA VIA_t1_cnt_lo
    JSR Intensity_5F
    ; Draw score first
    LDU #player_score
    LDA #$7f
    LDB #-$80
    JSR Print_Str_d
    ; Draw the player
    ; first, move to the pointer to player_x, player_y   
    ; display the enemies
    LDA player_y
    LDB player_x
    JSR Moveto_d
    ; now do the actual drawing
    LDX #player_sprite
    JSR Draw_VLc
    ; now lets cycle through the list of enemies on the screen and display them.
    ; draw our bullet if we have one.
    LDB #00
    CMPB bullet_active
    BEQ done
    JSR Reset0Int
    LDA bullet_y
    LDB bullet_x
    JSR Moveto_d
    LDX #bullet_sprite
    JSR Draw_VLc
done
    JSR Reset0Int
    LDA enemy_y
    LDB enemy_x
    JSR Moveto_d
    LDX #raptor_sprite
    JSR Draw_VLc
    JMP main ; loop until the game ends.

; subroutine used to fix the pen so we can render more objects.
; use like a normal Moveto_d.
; not sure if this is actually a good way of displaying stuff,
; but it works and I'm at a hackathon.
resetpen
    JSR Reset0Int
    JSR Moveto_d
    RTS

