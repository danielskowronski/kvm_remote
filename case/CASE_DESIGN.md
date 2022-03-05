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
- 00.2 mm prototype board itself
- 10.0 mm for board pins (min is 5 mm, but standard coupling nut is 10 mm)
- 02.0 mm board-batteries wall with slot for power screw terminals
- 21.0 mm 2x 18650 battery holder
- 02.0 mm safe space
- 02.0 mm removable bottom

total height: 47 mm

### from top

board is 70x90 mm, extra space from each side will be 5 mm => 100x80 mm
