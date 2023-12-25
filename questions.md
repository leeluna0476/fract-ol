# 설명 노트
## MiniLibX
- [ ] What is MLX?
  - MLX는 프랑스의 스태프 ol씨가 만든 그래픽 라이브러리다.
## Fractal
- [ ] What is a fractal?
  - 프랙탈은 일부 작은 조각이 전체와 비슷한 형태를 가지는 기하학적 구조를 말한다. 이러한 특징을 자기유사성이라고 하는데, 자기유사성을 가지는 구조를 프랙탈 구조라고 한다.
  - 브누아 망델브로(Benoît B. Mandelbrot)가 처음 사용한 단어이다. 어원은 조각났다는 뜻의 라틴어 fractus이다.
- [ ] What is a complex number? (feat. complex plane)
  - 복소수는 $z = a + bi$ 꼴의 수이다. $a$, $b$는 실수, $i$는 허수 단위이다. $i^2$는 $-1$을 만족시킨다.
  - $a$는 실수부, $b$는 허수부라고 한다.
  - 복소평면은 복소수를 기하학적으로 표현하기 위해 개발된 좌표평면이다.
  - 서로 직교하는 실수축과 허수축으로 이루어져 있으며, 실수부가 실수축에, 허수부가 허수축에 대응된 형태의 데카르트 좌표로 볼 수 있다.
  - 켤레 복소수는 복소수의 허수부에 덧셈 역원(opposite number)을 취하여 얻는 복소수이다.
- [ ] What are Mandelbrot, Julia, Burningship, Tricorn sets?
  - 수식 정리하기.
  - $z = a + bi$
  - Mandelbrot: $z_{n+1} = z_n ^2 + c$
    - 망델브로 집합은 브누아 망델브로가 고안한 프랙탈의 일종이다.
	- 위 점화식으로 정의된 수열을 발산하게 만드는 상수 $c$의 집합이다.
	- $z$의 절대값이 2를 넘어가면 발산하며, 이 때의 c는 집합에 속해있지 않는다. (2를 경계값이라고 부른다.)
	- 집합에 속해있는 경우, 무한히 계산을 해도 연산이 끝나지 않을 것이기 때문에 적절한 선에서 연산을 끝내야 한다. (max iteration)
	- 위와 같이 수열이 발산하지 않고 수렴할 때 c는 집합에 속해있다.
  - Julia: $z_{n+1} = z_n ^2 + c$
    - 위 점화식으로 정의된 수열을 발산하게 만드는 $z$의 집합이다.
	- 망델브로 집합과 다르게, 가까운 두 점이 서로 다른 양상을 보이는 초기 조건의 민감성을 가진다.
	- 망델브로 집합은 임의의 복소수 $c$에 대해 동일한 반복 규칙을 적용하지만, 줄리아 집합은 $z$의 초기값에 따라 전체적인 형상이 달라진다.
  - Burningship: $z_{n+1} = (|Re(z_n)| + |Im(z_n)|i)^2 + c$
    - 위 점화식으로 정의된 수열을 발산하게 만드는 $c$의 집합이다.
	- 망델브로 집합과 다른 점은, 복소수를 제곱하기 전에 실수부와 허수부를 절대값으로 설정한다.
  - Tricorn: $z_{n+1} = \bar{z}_n ^2 + c$
    - 위 점화식으로 정의된 수열을 발산하게 만드는 $c$의 집합이다.
	- 망델브로 집합과 다른 점은, 복소수 $z$의 켤레 복소수를 취하여 연산한다.

## UI
- [ ] Screen
- [ ] Button
- [ ] Key
- [ ] Mouse
  - Wheels, left click

## 3D Fractal
- [ ] 3D Mandelbrot (feat. **rotation matrix**, bifurcation diagram of logistic map)
- [ ] 3D Julia
- [ ] 3D Burningship (feat. **stereographic projection**, spherical coordinate, linear interpolation)
