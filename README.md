# Fractol

## Description

Fractol is a graphic project which with the help of an external library (minilibx) renders and manipulate a Mandelbrot and Julia set, it manages image and window creation and destruction as well as mouse and keyboard input to control the fractal's zoom and position.

1. [Project Description](#Description)
2. [Install and usage](#Install-and-usage)
    * [Controls](#Controls)
3. [Minilibx and graph enviroment](#Minilibx)
4. [Math Theory behind it](#Fractals)
    * [Mandelbrot](#Mandelbrot)
    * [Julia](#Julia)
6. [Program functionality Summary](#How-it-works)

## Install and usage

* To install, clone repository:
```
git clone https://github.com/marcosto29/fract-ol.git
```
* To compile program, run the following command:
```diff
make
# Some packages might be needed
# If required --> sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```
* To execute the program, run the following command:
```diff
./fractol (either Mandelbrot or Julia)
# The program handles input error showing a message on how to fix it
```
### Controls

| Input | Output |
:------|------:
**Left** arrow | Move fractal to the **left**|
**Right** arrow | Move fractal to the **right**|
**Up** arrow | Move fractal **up**|
**Down** arrow | Move fractal **down**|
Scroll **Up** | Zoom **In** |
Scroll **Down** | Zoom **Out** |
**Esc** Button | **Close** window |

## Minilibx

Minilibx is an abstraction layer for the X11 library. It offers various functions which not only facilitate the creation and use of screens, windows, and images, but also the event management and maks subscriptions.

It works the same way as X11: it connects to the graphics server by opening a display and creates windows and images. It makes the management of both mouse and keyboard events easier and allows you to listen them automatically, handling mask subscriptions. The image and window creation render and destruction works exactly the same way.

Basically with the help of Minilibx, a decent render can be made without deep knowladge of X-Window providing simple functions that handle a group of complex functionalities behind them. 

## Fractals

The main goal of this project is to render a fractal on screen, but what is exactly a fractal.

A fractal is a geometric structure whose pattern repeats itself at different scales, almost as if it were an infinite loop.

This can be seen when zooming in and out a fractal, it doesnt matter how deep is zoomed the fractal will hold the same or similar shapesthroughout the process.

Another common feature is the fact that a fractal has its own dimension, some cannot be represented with existing numbers, recurring to imaginary ones, other are more complex than 1 dimension but less than 2.

An interesting fact, fractals can be found in nature, such as snowflakes or even trees.

<p align = "center">
   <img width = "300" src = "https://github.com/marcosto29/fract-ol/blob/main/Images/Snowflake.jpeg" "Fractal Example">
</p>

### Mandelbrot

The Mandelbrot set can be represented with the help of the following formula:

$`z_{0} = 0`$

$`z_{n + 1} = z_{n}^2 + c`$

Any number applied to this formula that does not diverge is considered part of the set.

If c = 1, the result succsession is 0, 1, 2, 5, 26, etc. Diverge, therefore 1 is not part of the Mandelbrot set.

If c = -1, the result succsession is 0, -1, 0, -1, 0, etc. It does not diverge, therefore -1 is part of the Mandelbrot set.

The Mandelbrot set, however, is represented on the complex plane, with the help of i ($`\sqrt{-1}`$), any set of numbers represented on this plane is complex with an existing and imaginary number, one example would be **c = (-1, 0.1i)**.

It is known that every point whose distance to the origin is greater than 2 ($`x^2 + y^2 \gt 4`$) does not belong to the Mandelbrot set.

<p align = "center">
   <img width = "300" src = "https://github.com/marcosto29/fract-ol/blob/main/Images/Mandelbrot.png" "Mandelbrot">
</p>

### Julia

The Julia set is similar to the Mandelbrot set, the formula used to check a number is a little bit different:

$`z_{0} = z`$

$`z_{n + 1} = z_{n}^2 + c`$

Just like in Mandelbrot the way to check if a number is part of the set is to observe if it diverges, in this case, however, **c** is gonna be a constant number decide by the user, while **z** instead of starting at 0 will start at the respective coordinate.

The rest of the procedure is made the same way, checking if the distance to the origin is greater than 2.

<p align = "center">
   <img width = "300" src = "https://github.com/marcosto29/fract-ol/blob/main/Images/Julia.png" "Julia">
</p>

## How it Works

As explained above, the minilibx works the same way as the X11, therefore, after parsing the input and cheking that everything is ready, the first thing that needs to be done is to open the display that will allow the communication between the program and the graph server.

The minilibx makes all this process easier by just calling the mlx_init function which opens the display and returns a void pointer that will contain the information needed to communicate and render images.

After opening the display the creation of windows is just as easy, calling the function mlx_new_window passing display reference, and some configuration parameters such as the width the heigth and the name will built it and return it as a void pointer. On my approach I wanted to hook the events needed to close the window and listen to keyboard inputs right after creating it, to make it more intuitive.

To hook an event, the mlx_hook function is called with: the window to be hooked, the input that will trigger, the mask needed to listen to it, the function called, and the display reference.

The infinite loop that listen to inputs on the minilibx is easily handle by the mlx_loop function.

Finally, since painting on the window (which can be done) is a worst approaching, the next thing needed is an image, to create it, just like with the window by calling mlx_new_image with the display reference and the width and heigth will return a canvas as a void pointer ready to be painted.

### Image painting

After closing the window, some important functions to be called to make it clean are: mlx_loop_end, mlx_destroy_image, mlx_clear_window, mlx_destroy_window, mlx_destroy_display, all of them with their respective reference.
