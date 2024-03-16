# FDF---Wireframe-model


### Overview
FDF is a project about representing a landscape as a 3D object in isometric projection in which all surfaces are outlined in lines. The rendered image can be zoomed in and out, rotated and moved in the window.

<br>

<img width="1537" alt="Screen Shot 2024-03-16 at 4 45 45 PM" src="https://github.com/triimar/FtF---Wireframe-model/assets/116010422/87cd99eb-9f66-41fb-8b02-412829011c4f">

<br>

This FtF uses [MLX42](https://github.com/codam-coding-college/MLX42) graphics library version 2.2.1.

<br>

<img width="1538" alt="Screen Shot 2024-03-16 at 4 50 30 PM" src="https://github.com/triimar/FtF---Wireframe-model/assets/116010422/3680091f-24f8-4a17-80a5-e71268d42b1b">

<br>

### Actions 

- `arrow keys` move the object left-right-up-down in the window;
- `mouse wheel` allows to zoom in and out;
- keys `2`, `3`, `4` translate the model to front view, end view and top view correspondingly;
- `1` returns the image to isometric projection view;
- `Q` and `W` keys rotate the object on the x-axis;
- `A` and `S` keys allow rotation on y-axis;
- `Z` and `X` keys rotate the object on z-axis;
- Pressing `ESC` or clicking the `X` on the window closes the window and quits the program.
 
<br>
 
<img width="1538" alt="Screen Shot 2024-03-16 at 4 43 08 PM" src="https://github.com/triimar/FtF---Wireframe-model/assets/116010422/949b6be5-9445-4658-bb7f-305d2f0e2852">

<br>

### Running the Program(s)
The program takes as input an fdf file in which 
- The horizontal position of the character corresponds to the x-axis.
- The vertical position of the character top view corresponds to the y-axis.
- The (integer)value of the character corresponds to z-axis (altitude).

**./fdf \<.ftf_file_for_input\>**

<br>

<img width="1538" alt="Screen Shot 2024-03-16 at 5 01 43 PM" src="https://github.com/triimar/FtF---Wireframe-model/assets/116010422/6a5a8778-8c9a-4acc-8739-5a75f2b3ac5d">
