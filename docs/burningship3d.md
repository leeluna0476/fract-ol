# Burningship 3D
- Stereographic projection을 사용해서 평면 위에 있는 버닝쉽을 구면 위에 사영시킨다.
- 현재 박스 화면은 평면이다.
- x, y를 가지고 구면좌표를 구해서 구면으로 만든다.
[Spherical coordinate](spherical_coordinate.md)
- 구면으로 만들었으니 stereographic projection을 한다.
[Stereographic projection](stereographic_projection.md)
- Stereographic projection은 단위구를 기준으로 하므로, xyz로 변환할 때 radius를 1로 설정한다.
- 집합의 특성상 절대값이 2를 넘지 않기 때문에 단위구 위에 얹기 적절하다.
