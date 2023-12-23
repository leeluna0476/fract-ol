#include <mlx.h>
#include <math.h>
#include <string.h>

#define WIDTH 	1920
#define HEIGHT 	1080
# define WHITE	0x00FFFFFF
# define RED	0x00FF0000
# define BLUE	0x000000FF
# define BLACK	0x00000000

typedef struct s_data {
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_complex {
	double	real;
	double	imag;
}			t_complex;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	c_abs(t_complex z)
{
	return (sqrt(z.real * z.real + z.imag * z.imag));
}

void	next(t_complex *z, t_complex c)
{
	double	r;
	double	i;

	r = z->real;
	i = z->imag;
	z->real = r * r - i * i + c.real;
	z->imag = 2 * r * i + c.imag;
}

void	mandelbrot(t_data *img)
{
	t_complex	z;
	t_complex	c;
	int			r;
	int			g;
	int			b;

	for (int j = 0; j < HEIGHT; j++)
	{
		for (int i = 0; i < WIDTH; i++)
		{
			z.real = 0;
			z.imag = 0;
			c.real = (((double)(i - (WIDTH >> 1))) - 200) / 500;
			c.imag = ((double)(j - (HEIGHT >> 1))) / 500;
			for (int k = 0; k < 1000; k++)
				next(&z, c);

			if (z.real >= 0 && z.imag >= 0)
			{
				r = 0;
				g = 0;
				b = 100 * (2 * atan(z.real / z.imag) / M_PI);
			}
			else if (z.real < 0 && z.imag >= 0)
			{
				r = 100 * (2 * fabs(atan(z.real / z.imag)) / M_PI);
				g = 0;
				b = 0;
			}
			else if (z.real < 0 && z.imag < 0)
			{
				r = 100;
				g = 100 * (2 * fabs(atan(z.imag / z.real)) / M_PI);
				b = 100 * (2 * fabs(atan(z.imag / z.real)) / M_PI);
			}
			else
			{
				r = 100 * (2 * fabs(atan(z.imag / z.real)) / M_PI);
				g = 100 * (2 * fabs(atan(z.imag / z.real)) / M_PI);
				b = 100;
			}

			// 색상 범위를 0에서 255로 제한
			my_mlx_pixel_put(img, i, j, (r << 16) | (g << 8) | b);
		}
	}
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img, 0, 0);
}

int	main(void)
{
	t_data	img;

	bzero(&img, sizeof(t_data));
	img.mlx_ptr = mlx_init();
	img.win_ptr = mlx_new_window(img.mlx_ptr, WIDTH, HEIGHT, "fractol");
	img.img = mlx_new_image(img.mlx_ptr, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
			&img.line_length, &img.endian);
	mandelbrot(&img);
	mlx_loop(img.mlx_ptr);
}
