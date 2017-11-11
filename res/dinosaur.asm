dinosaur_scale EQU 10
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
