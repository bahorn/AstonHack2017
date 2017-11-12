dinosaur_scale EQU 10
; goose!
player_sprite
    FCB 3
    FCB 0,1*dinosaur_scale
    FCB 1*dinosaur_scale,0
    FCB 0,-1*dinosaur_scale
    FCB -1*dinosaur_scale,0


bullet_scale EQU 2
bullet_sprite
    FCB 3
    FCB 0,1*bullet_scale
    FCB 1*bullet_scale,0
    FCB 0,-1*bullet_scale
    FCB -1*bullet_scale,0

raptor_scale EQU 4
raptor_sprite
    FCB 10
    FCB 0,0
    FCB -1*raptor_scale,1*raptor_scale
    FCB 1*raptor_scale,1*raptor_scale
    FCB raptor_scale,0
    FCB 0,raptor_scale
    FCB raptor_scale,0
    FCB 3*raptor_scale,-2*raptor_scale
    FCB -3*raptor_scale,-2*raptor_scale
    FCB -1*raptor_scale,0
    FCB 0,raptor_scale
    FCB -1*raptor_scale,0
    
