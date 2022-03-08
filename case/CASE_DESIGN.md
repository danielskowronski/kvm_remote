# Case Design

## elements

### plan

4 edges in top half:
- screw
- (top cover)
- distance bolt
- (prototype board)
- distance bolt
- (board-batteries wall)
- nut

4 edges in bottom half:
- nut
- (10 mm high hex slot)
- distance bolt
- (bottom cover)
- screw

2 holes in battery holder:
- nut
- (battery holder)
- screw

### BOM

- M3 screws (x10):
  - 4 for top cover
  - 2 for battery holder
  - 4 for bottom cover
- M3 distance bolt 10 mm (x12):
  - 4 for attaching top cover to prototype board
  - 4 for attaching prototype board to board-batteries wall (screwed to other 4)
  - 4 for attaching bottom cover to case
- M3 nut (x10):
  - 4 for attaching prototype board's distance bolts to board-batteries wall
  - 2 for battery holder
  - 4 for attaching bottom cover's distance bolts to board-batteries wall

## Layout

### from sides

- 02.0 mm removable top 
- 10.0 mm for board components, topmost: microUSB
- 01.5 mm prototype board itself
- 10.0 mm for board pins (min is 5 mm, but standard coupling nut is 10 mm)
- 02.0 mm board-batteries wall with slot for power screw terminals
- 21.0 mm 2x 18650 battery holder
- 02.0 mm safe space
- 02.0 mm removable bottom

total height: 46.5 mm

### from top

board is 70x90 mm, extra space from each side will be 5 mm => 100x80 mm

## Parts

### Top & bottom

generally the same base, but top with 3 additional holes (LED and buttons) and extruded labels

something like https://www.openscad.info/index.php/2020/07/07/the-easiest-project-box/ without screw posts, but with holes instead

```scad
$fn=25;
BOX_W = 80;
BOX_L = 100;
BOX_H = 10;
CORNER_RADIUS = 3; // Radius of corners
WALL_THICKNESS = 2;// Wall Thickness

linear_extrude( BOX_H )
    difference(){
        offset(r=CORNER_RADIUS) 
            square( [BOX_W, BOX_L], center=true );
        
        offset( r= CORNER_RADIUS - WALL_THICKNESS )
            square( [BOX_W-WALL_THICKNESS, BOX_L-WALL_THICKNESS], center=true );
    }

coordinates = [ [0,0],[0,BOX_L],[BOX_W,BOX_L],[BOX_W,0] ];

translate ( [-BOX_W/2, -BOX_L/2] )
    hull()
    for (i = coordinates)
        translate(i) sphere(CORNER_RADIUS);

// TODO: screw holes
```

M3 (3.1 major dia) screw holes' centers positioned:
- 10 mm from shorter edges (wall 2, disatnce to board 5, from board edge 2)
- 9 mm  from  longer edges (wall 2, disatnce to board 5, from board edge 3)

### main body

based on above code two conjoined elements

```
|                 |
|                 |
--  ---------------
||               ||
||               ||
```

top half:    11.5 mm
wall:         2.0 mm
bottom half: 15.0 mm

wall have hole for battery connector positioned:
- from left 2 mm (side thickness) to 28 mm (wall 2, disatnce to board 5, element reaches 21 into board)
- from bottom 2 mm (side thickness) to 23 mm(wall 2, disatnce to board 5, element reaches 16 into board)

bottom half have additional hex spaces for distancing rods positioned so the center of hole will be in the same place as covers' holes:
- hex dia of rod is 4.6 mm

