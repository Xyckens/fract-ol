# fract-ol 
Fract-ol project developed by me for 42 in a Ubuntu environment.
In the mandatory part we need to present the Julia and Mandelbrot Fractal Sets. 
![Julia Set Fractal](https://user-images.githubusercontent.com/53185699/212414778-16072951-224e-48be-bcec-8b60590ccc1e.png)
![Mandelbrot Set Fractal](https://user-images.githubusercontent.com/53185699/212414859-cf0b3d61-0881-4420-8696-48cc9569d244.png)
For the bonus we are asked to choose another Set and I chose the Burning Ship (calculated by only using the real part of the Mandelbrot calculations).
![Burning Ship Fractal](https://user-images.githubusercontent.com/53185699/212414692-fa75a51d-b250-4d30-a061-4fde8f8bbdf3.png)

## Features
* Render different fractals: mandelbrot, julia, burning ship
* Change to different color schemes
* The mouse wheel zooms in and out, almost infinitely (within the limits of the computer)
* Move the image with the arrow keys
* Reset to the inicial image/ reset zoom

## Compiling and running
Run `make` then run it with `./fractol [fractal]`. Possible fractals are: `julia`, `mandelbrot`,
`burning`. Cycle color-schemes with `+` and `-` on the right numpad. Zoom in and out with the
mousewheel.
