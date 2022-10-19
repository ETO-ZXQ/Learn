//https://blog.csdn.net/qq_46105170/article/details/113967176?spm=1001.2101.3001.6650.8&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EOPENSEARCH%7ERate-8.pc_relevant_default&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EOPENSEARCH%7ERate-8.pc_relevant_default&utm_relevant_index=11https://blog.csdn.net/qq_46105170/article/details/113967176?spm=1001.2101.3001.6650.8&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EOPENSEARCH%7ERate-8.pc_relevant_default&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EOPENSEARCH%7ERate-8.pc_relevant_default&utm_relevant_index=11
#include <iostream>
#include <cmath>

using namespace std;

const int N = 110;
const double eps = 1e-6;

int n;
double a[N][N];

int gauss() 
{
    int c, r;
    for (c = 0, r = 0; c < n; c++) 
	{
    	// 先找到当前列的绝对值最大的那一行
        int t = r;
        for (int i = r; i < n; i++)
            if (fabs(a[i][c]) > fabs(a[t][c]))
                t = i;
		// 如果当前列全是0，那扫描下一个列
        if (fabs(a[t][c]) < eps) continue;
		
		// 将这个绝对值最大的那一行换到最前面（其实这里的最前面并不是指第一行，而是指消元的时候阶梯的下一行）
        for (int i = c; i < n + 1; i++) swap(a[t][i], a[r][i]);
        // 把这一行的第一个系数（主元）变成1，其余系数相应除以主元的旧值
        for (int i = n; i >= c; i--) a[r][i] /= a[r][c];
        // 做第三类初等行变换，把当前列消掉
        for (int i = r + 1; i < n; i++)
            if (fabs(a[i][c]) > eps)
                for (int j = n; j >= c; j--)
                    a[i][j] -= a[r][j] * a[i][c];

        r++;
    }
	// 如果r < n，那说明最后的标准形的方程个数是小于n的，那不是唯一解
    if (r < n) {
    	// 检查左边系数全是0的方程中的常数项，如果发现一个非0，则无解
        for (int i = r; i < n; i++)
            if (fabs(a[i][n]) > eps)
                return 2;
        // 否则是无穷解
        return 1;
    }
	
	// 如果r = n，则方程有唯一解，将方程组系数矩阵化为单位阵，其实这里只需
	// 要把常数项化一下就行了，系数不需要真的变，因为这时候解只需要看常数项
    for (int i = n - 2; i >= 0; i--)
        for (int j = i + 1; j < n; j++)
            a[i][n] -= a[j][n] * a[i][j];

    return 0;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n + 1; j++)
            cin >> a[i][j];

    int t = gauss();
	
	// 如果有唯一解，就把常数项输出来
    if (t == 0) {
        for (int i = 0; i < n; i++) printf("%.2lf\n", a[i][n]);
    } else if (t == 1) puts("Infinite group solutions");
    else puts("No solution");

    return 0;
}
