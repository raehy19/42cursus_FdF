#include <mlx.h>

int	main(void)
{
	void    *mlx;
	void    *mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");// 창을 생성한고 창의 식별자를 반환 받는다.
	mlx_loop(mlx);// 새로 생성한 window가 있는 mlx를 rendering
}
