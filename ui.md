# UI
## Init Screen
|No.|File|Function|
|---|---|---|
|1|**ui_init_screen.c**|```void	my_mlx_pixel_put(t_data *data, int x, int y, int color);```|
|2||```void	init_screen(t_data *img);```|
|3||```void	init_axis(t_data *img);```|
|4||```void	init_box(t_data *img);```|
|5||```void	clear_box(t_data *img);```|

가장 첫번째 단계는 스크린을 초기화하는 것이다.
본 스크린의 구역은 메뉴바와 배경, 그리고 프랙탈이 송출될 박스 화면으로 나뉜다.

1. Menu
2. Background
3. Box

파싱 단계에서 아무런 오류 없이 프로그램이 정상적으로 시작할 때, 세 구역을 모두 기본값으로 초기화를 해준다.

```void	my_mlx_pixel_put(t_data *data, int x, int y, int color);```을 사용하여 이미지에 지정된 색깔을 일일히 찍어준다.

## Menu
|No.|File|Function|
|---|---|---|
|1|**ui_menu.c**|```bool	check_menu(int a, int b);```|
|2||```void	write_header(t_data *img, int *line, int *gap);```|
|3||```void	write_2ds(t_data *img, int *line, int *gap);```|
|4||```void	write_3ds(t_data *img, int *line, int *gap);```|
|5||```void	write_menu(t_data *img);```|
|6|**ui_menu_utils.c**|```bool	check_menu(int a, int b);```|
|7||```bool	check_write(t_data *img);```|

메뉴에 메뉴들을 한 줄씩 적어준다.
mlx 내장 함수인 ```int	mlx_string_put (void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);```를 사용했다.

문자열을 적는 것은 이미지에 포함되지 않기 때문에 이미지를 렌더링한 이후에 적어줘야 한다.
메뉴를 띄워야 하는 타이밍이 여러 군데 있는데, 한마디로 정리하자면 이미지가 새로 렌더링이 될 때마다 다시 메뉴를 띄워야 한다. (예: 마우스 호버링, 유의미한 마우스/키보드 클릭 등)

마우스 호버링의 경우 실시간으로 마우스 좌표를 받아오면서 이미지를 계속 띄워준다. 마우스가 특정 픽셀 안에 들어올 경우 색상을 바꿔서 이미지를 다시 띄워주는 방식으로 구현하였다.
마우스/키보드 클릭은 ```bool	check_write(t_data *img);```로 write를 해야 하는 경우인지 판별을 해주었다.

## Button
|No.|File|Function|
|---|---|---|
|1|**ui_button.c**|```void	make_button(t_data *img, t_xy start, t_xy button_wh, int color);```|
|2||```void	_button(t_data *img, int start_x, int start_y);```|
|3||```void	make_all_false(t_data *img);```|
|4||```void	turn_on_button(t_data *img, int button);```|
|5|**ui_button_execute.c**|```void	call_set(t_data *img);```|
|6||```void	call_set_3d(t_data *img);```|
|7||```void	choose_set(t_data *img);```|
|8||```int	terminate_program(void);```|
|9||```void	execute_button(t_data *img, int button, void (*f)(t_data *));```|
|10|**ui_key.c**|```void	key_fractals(t_data *img, int key);```|
|11||```void	key_offset(t_data *img, int key);```|
|12||```int	key_press(int key, void *param);```|
|13||```void	hook(t_data *img);```|
|14|**ui_key_utils.c**|```void	control_fractals(int key, t_data *img);```|
|15||```void	control_3ds(int key, t_data *img);```|
|16||```void	control_directions(int key, t_data *img);```|
|17||```void	control_theme(int key, t_data *img);```|
|18||```void	control_key(int key, t_data *img);```|
|19|**ui_mouse.c**|```void	init_zoom_center(t_data *img);```|
|20||```void	send_click_to_key(t_data *img, int y);```|
|21||```void	wheel(int button, t_data *img);```|
|22||```int	mouse_move(int x, int y, void *param);```|
|23||```int	mouse_press(int button, int x, int y, void *param);```|
|24|**ui_key.c**|```void	key_fractals(t_data *img, int key);```|
|25||```void	key_offset(t_data *img, int key);```|
|26||```int	key_press(int key, void *param);```|
|27||```void	hook(t_data *img);```|
|28|**ui_key_utils.c**|```void	control_fractals(int key, t_data *img);```|
|29||```void	control_3ds(int key, t_data *img);```|
|30||```void	control_directions(int key, t_data *img);```|
|31||```void	control_theme(int key, t_data *img);```|
|32||```void	control_key(int key, t_data *img);```|
|33|**ui_mouse.c**|```void	init_zoom_center(t_data *img);```|
|34||```void	send_click_to_key(t_data *img, int y);```|
|35||```void	wheel(int button, t_data *img);```|
|36||```int	mouse_move(int x, int y, void *param);```|
|37||```int	mouse_press(int button, int x, int y, void *param);```|
|38|**ui_theme.c**|```void	init_theme(t_data *img);```|
|39||```void	key_theme(t_data *img, int key);```|

본 프로그램은 마우스/키보드 훅으로 사용자에게 입력을 받는다.
mlx 내장 함수인 ```void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param);```을 사용해서 마우스/키보드의 입력을 감지한다.
그에 따라서 알맞는 처리를 해주는 함수 몇가지를 직접 구현했다.

- Mouse hook
  - Wheel
    - Wheel up, Wheel down, Wheel click
  - Left click
- Keyboard hook

### Mouse
|Event|Input range|Target|Function|
|---|---|---|---|
|**Left click**|메뉴바 버튼|모든 프랙탈|버튼 조작|
||박스|2D 프랙탈|프랙탈을 화면 중앙으로 평행이동|
||박스|3D 줄리아|줄리아를 잘라서 단층을 보여줌|
|**Wheel up, down**|박스|2D 프랙탈|프랙탈 확대 및 축소|
|**Wheel click**|박스|모든 프랙탈|색상 테마를 제외한 모든 설정값 초기화|

**Mouse move**

가장 우선적으로 받는 입력은 **mouse_move**이다.
마우스의 움직임을 실시간으로 감지하면서 마우스 커서가 버튼의 범위 안에 올라올 때마다 CHARCOAL 색상으로 버튼을 칠해주며 **호버링** 효과를 주었다.

**Mouse click**

프로그램을 조작하는 데 주로 쓰이는 입력은 **마우스 좌클릭**이다.
버튼의 범위에서 클릭이 들어오면 해당하는 프랙탈 또는 테마(문자열로 적혀있다)를 실행하고, 박스의 범위에서 클릭이 들어오면 현재 어떤 프랙탈이 켜져 있는지 탐색해서 해당하는 기능을 수행한다.

프랙탈을 실행할 때는 ```boolean``` 배열에 버튼의 상태 정보를 담아서 상태가 ```true```인 프랙탈만 호출하도록 구현하였다.
2D 프랙탈의 경우, 좌클릭으로 클릭한 부분을 박스의 중앙으로 이동을 시킬 수 있다.
3D 줄리아의 경우, 좌클릭으로 클릭한 부분의 단층을 잘라서 볼 수 있다.
같은 좌클릭이지만 어떤 프랙탈이 ```true```인지에 따라 다르게 작동하는 것이다.

**마우스 휠**은 2D 프랙탈을 조작하는 데 쓰인다. 휠을 위로 밀면 확대, 아래로 당기면 축소이다.
프랙탈은 작은 부분이 큰 부분과 유사한 형태를 가지는 구조이므로 확대를 함으로써 그것을 관찰할 수 있다.
마우스 커서가 위치한 부분을 박스의 중앙과의 거리 * 확대할 비율만큼 이동을 시키고 나서 프랙탈을 확대를 시킨다. 그 후 다시 원래 위치로 되돌려놓는 방식으로 마우스 커서를 기준으로 확대하는 움직임을 구현하였다.

휠을 클릭하면 색상 테마를 제외한 모든 설정값들을 초기화한다. 확대, 평행이동, 단층 높이 등을 기본값으로 돌려놓는다. 처음에 버튼을 켰을 때의 상태로 돌아가는 걸 볼 수 있다.

### Key
|Event|Function|
|---|---|
|[|Theme RED|
|]|Theme BLUE|
|0|Clear box|
|1|Mandelbrot|
|2|Julia|
|3|Burningship|
|4|Tricorn|
|5|Bifurcation diagram of logistic map|
|7|3D Julia|

키보드 입력으로도 간편하게 각 기능들을 호출할 수 있다.
위 차트에 있는 키들은 각 버튼들과도 상응한다.
마우스로 버튼을 클릭할 때도 키보드로 입력을 할 때와 동일한 버튼을 제어하고 동일한 함수를 호출하여 동일하게 작동하도록 구현하였다.

```void	key_fractals(t_data *img, int key);```로 어떤 버튼을 켜고 끌지 제어한다.

또한 ```void execute_button(t_data *img, int button, void (*f)(t_data *));```는 함수 포인터를 매개변수로 받아서 초기에 실행해야 하는 기능들을 실행한다.

모든 초기 설정이 완료되면 비로소 해당하는 프랙탈 함수를 호출해서 보여준다.
