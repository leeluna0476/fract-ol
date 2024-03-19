# Stereographic projection 스테레오 투영법
구 위의 (x, y, z)와 평면 위의 (X, Y)의 사영과 역은 다음 공식으로 주어진다.
(X, Y) = (x / 1 - z, y / 1 - z)
(x, y, z) = (2X / 1 + X^2 + Y^2, 2Y / 1 + X^2 + Y^2, -1 + X^2 + Y^2 / 1 + X^2 + Y^2)

Spherical coordinates (φ, θ):
	- φ the zenith angle, 0 <= φ <= π
		  φ = acos(y / radius)
		 	부호를 고려해야 한다면 atan을 사용하겠지만 구 좌표에서는 일반적으로 범위가 0에서 pi까지라서 acos를 사용하는 것이 더 적절하다.
	- θ the azimuth, 0 <= θ <= 2π
		  θ = acos(x / (radius * sin(φ))
