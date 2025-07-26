# Fractol

## Description

Fractol is a graphic project which with the help of an external library (minilibx) renders and manipulate a Mandelbrot and Julia set, it manages image and window creation and destruction as well as mouse and keyboard input to control the fractal's zoom and position.

1. [Project Description](#Description)
2. [Install and usage](#Install-and-usage)
3. [Minilibx and graph enviroment](#Minilibx)
4. [Math Theory behind it](#Fractals)
5. [Program functionality Summary](#How-it-works)

## Install and usage

* To install, clone repository:
```
git clone https://github.com/marcosto29/fract-ol.git
```
* To run program, run the following command:
```
make
```
* To execute the program, run the following command:
```diff
./fractol (either Mandelbrot or Julia)
# The program handles input error showing a message on how to fix it
```

## Minilibx

Minilibx is an abstraction layer for the X11 library. It offers various functions which not only facilitate the creation and use of screens, windows, and images, but also the event management and maks subscriptions.

It works the same way as X11: it connects to the graphics server by opening a display and creates windows and images. It makes the management of both mouse and keyboard events easier and allows you to listen them automatically, handling mask subscriptions. The image and window creation render and destruction works exactly the same way.

Basically with the help of Minilibx, a decent render can be made without deep knowladge of X-Window providing simple functions that handle a group of complex functionalities behind them. 

## Fractals

## How it Works
