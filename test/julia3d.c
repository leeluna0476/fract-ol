#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <mlx.h>
#include <stdlib.h>
#include <string.h>

# define WIDTH 			1920
# define HEIGHT 		1080

# define WHITE			0x00FFFFFF
# define BLACK			0x00000000
# define RED			0x00FF0000

# define PI				3.141592653589793

typedef struct s_complex {
	double	real;
	double	imag;
}			t_complex;

typedef struct s_matrix {
	double mat[3][3];
}		t_matrix;

typedef struct s_vec3d {
	double vec[3];
}		t_vec3d;

typedef struct s_julia3d {
	int	x;
	int	y;
	int	z;
	int	color;
}		t_julia3d;

typedef struct s_data {
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			horz;
	int			vert;
	t_julia3d	*julia3d_dots;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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

double	c_abs(t_complex z)
{
	return (sqrt(z.real * z.real + z.imag * z.imag));
}

bool	all_diverge(t_complex c)
{
	t_complex	z;
	int			i;
	int			j;
	int			k;

	j = -1;
	while (++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
		{
			z.real = (double)(i - WIDTH / 2) / 300;
			z.imag = (double)(j - HEIGHT / 2) / 300;
			k = -1;
			while (c_abs(z) < 2 && ++k < 400)
				next(&z, c);
			if (c_abs(z) < 2)
				return (false);
		}
	}
	return (true);
}

void	julia(t_data *img, t_complex c, int color)
{
	t_complex	z;
	int			i;
	int			j;
	int			k;

	j = -1;
	while (++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
		{
			z.real = (double)(i - WIDTH / 2) / 300;
			z.imag = (double)(j - HEIGHT / 2) / 300;
			k = -1;
			while (c_abs(z) < 2 && ++k < 400)
				next(&z, c);
			if (c_abs(z) < 2)
				my_mlx_pixel_put(img, i, j, color);
		}
	}
}

int	get_total_slices(t_complex c, double slice)
{
	int		slice_num;
	slice_num = 0;
	while (all_diverge(c) == false)
	{
		c.real += slice;
		slice_num++;
	}
	return (slice_num);
}

void	init_matrix(t_matrix *matrix)
{
	int	i;
	int	j;

	j = 0;
	while (j < 3)
	{
		i = 0;
		while (i < 3)
		{
			matrix->mat[i][j] = 0;
			i++;
		}
		matrix->mat[j][j] = 1;
		j++;
	}
}

t_matrix	matrix_multiply(t_matrix mat1, t_matrix mat2)
{
	t_matrix	mat3;
	int	i;
	int	j;
	int	k;

	memset(&mat3, 0, sizeof(t_matrix));
	j = 0;
	while (j < 3)
	{
		i = 0;
		while (i < 3)
		{
			k = 0;
			while (k < 3)
			{
				mat3.mat[i][j] += mat1.mat[j][i] * mat2.mat[j][k];
				k++;
			}
			i++;
		}
		j++;
	}
	return (mat3);
}

void	matrix_point_multiply(t_matrix mat, t_data *img, int u)
{
	double vec[3];

	vec[0] = img->julia3d_dots[u].x;
	vec[1] = img->julia3d_dots[u].y;
	vec[2] = img->julia3d_dots[u].z;

	double _rx = 0;
	double _ry = 0;
	double _rz = 0;

	int i = 0;
	while (i < 3)
	{
		_rx += mat.mat[0][i] * vec[i];
		_ry += mat.mat[1][i] * vec[i];
		_rz += mat.mat[2][i] * vec[i];
		i++;
	}
	(&(img->julia3d_dots[u]))->x = _rx;
	(&(img->julia3d_dots[u]))->y = _ry;
	(&(img->julia3d_dots[u]))->z = _rz;
}

void	julia3d(t_data *img)
{
	t_complex	c;
	t_complex	z;
	double		slice;
	int			slice_num;
	int			total_dots;
	int			i;
	int			j;
	int			k;
	int			z_value;

	c.real = -0.7269;
	c.imag = 0.1889;
	slice = 0.01;
	slice_num = get_total_slices(c, slice);
	int dots_per_slice = WIDTH * HEIGHT;
	total_dots = dots_per_slice * slice_num;
	img->julia3d_dots = malloc(total_dots * sizeof(t_julia3d));
	z_value = 0;
	int box_std_x = WIDTH / 2;
	int box_std_y = HEIGHT / 2;

	while (all_diverge(c) == false)
	{
		j = 0;
		while (j < HEIGHT)
		{
			i = 0;
			while (i < WIDTH)
			{
				z.real = (double)(i - box_std_x) / 300;
				z.imag = (double)(j - box_std_y) / 300;

				k = 0;
				while (k < 10)
				{
					next(&z, c);
					if (c_abs(z) >= 2)
						break ;
					k++;
				}

				if (c_abs(z) < 2)
				{
					(&(img->julia3d_dots[i + j * WIDTH + z_value * dots_per_slice]))->x = i - box_std_x;
					(&(img->julia3d_dots[i + j * WIDTH + z_value * dots_per_slice]))->y = j - box_std_y;;
					(&(img->julia3d_dots[i + j * WIDTH + z_value * dots_per_slice]))->z = z_value;
					(&(img->julia3d_dots[i + j * WIDTH + z_value * dots_per_slice]))->color = WHITE - z_value * 1000;
				}
				i++;
			}
			j++;
		}
		c.real += slice;
		z_value++;
	}

	t_vec3d angle;
	angle.vec[0] = PI * img->horz / 180;
	angle.vec[1] = PI * img->vert / 180;
	angle.vec[2] = 0;


	t_matrix matx;
	init_matrix(&matx);

	matx.mat[1][1] = cos(angle.vec[0]);
	matx.mat[1][2] = -sin(angle.vec[0]);
	matx.mat[2][1] = sin(angle.vec[0]);
	matx.mat[2][2] = cos(angle.vec[0]);

	t_matrix maty;
	init_matrix(&maty);
	maty.mat[0][0] = cos(angle.vec[1]);
	maty.mat[0][2] = sin(angle.vec[1]);
	maty.mat[2][0] = -sin(angle.vec[1]);
	maty.mat[2][2] = cos(angle.vec[1]);

	t_matrix matz;
	init_matrix(&matz);
	matz.mat[0][0] = cos(angle.vec[2]);
	matz.mat[0][1] = -sin(angle.vec[2]);
	matz.mat[1][0] = sin(angle.vec[2]);
	matz.mat[1][1] = cos(angle.vec[2]);

	t_matrix _mat = matrix_multiply(matx, maty);
	t_matrix rotation_mat = matrix_multiply(_mat, matz);

	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			printf("%f ", rotation_mat.mat[i][j]);
		}
		printf("\n");
	}
	
	int	u = 0;
	while (u < total_dots)
	{
		if (img->julia3d_dots[u].color != 0)
		{
			matrix_point_multiply(rotation_mat, img, u);
			my_mlx_pixel_put(img, img->julia3d_dots[u].x + box_std_x, img->julia3d_dots[u].y + box_std_y, img->julia3d_dots[u].color);
		}
		u++;
	}

	free(img->julia3d_dots);
}

int	main(void)
{
	t_data		img;

	img.mlx_ptr = mlx_init();
	img.win_ptr = mlx_new_window(img.mlx_ptr, WIDTH, HEIGHT, "Hello 42 Seoul");
	img.img = mlx_new_image(img.mlx_ptr, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
			&img.line_length, &img.endian);
	julia3d(&img);
	mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.img, 0, 0);
	mlx_loop(img.mlx_ptr);
	return (0);
}
