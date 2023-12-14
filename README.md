# fract-ol
[1. Arguments](#Arguments)

[2. Buttons](#Buttons)

[3. Keys controls](#Key-controls)

[4. Mouse controls](#Mouse-controls)

---

**Implementation description → **
[Implementation](implementation.md)

---

Copy and paste the script below to your bash.
```bash
git clone https://github.com/leeluna0476/fract-ol.git fract-ol
cd fract-ol
make
./fractol [fractal] [c.real] [c.imag]
```
Options:
- [fractal]: Enter the name of the fractal you want to see.
- [c.real] [c.imag]: Enter a complex number $c$ for julia set. (Only for julia set!)

## Arguments

![](pictures/mandelbrot_red.png)
```
./fractol mandelbrot
```

---

![](pictures/julia_blue.png)
```
./fractol julia
```

![](pictures/julia_-1.25_0.1.png)
```
./fractol julia -1.25 0.1
```

---

![](pictures/burningship_red.png)
```
./fractol burningship
```

---

![](pictures/tricorn_blue.png)
```
./fractol tricorn
```

## Buttons
You can click the buttons listed on the menu.
Try it!

|Button|Function|
|---|---|
|[|Theme RED|
|]|Theme BLUE|
|0|Reset Box|
|1|Mandelbrot set|
|2|Julia set|
|3|Burningship set|
|4|Tricorn set|

---

There are two themes: RED and BLUE.
![](pictures/mandelbrot_blue.png)
![](pictures/julia_-1.25_0.1_red.png)

---

You can call each set JUST by clicking the button.
![](pictures/burningship_red.png)

## Key controls
You can click the same keys with buttons to call each functions.

|Keys|Function|
|---|---|
|[|Theme RED|
|]|Theme BLUE|
|0|Reset Box|
|1|Mandelbrot set|
|2|Julia set|
|3|Burningship set|
|4|Tricorn set|

## Mouse controls
You can control fractals by mouse click.

|Mouse|Function|
|---|---|
|Wheel UP|Zoom in|
|Wheel DOWN|Zoom out|
|Left click|Set the mouse point as the center of the box|
