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
    	// ���ҵ���ǰ�еľ���ֵ������һ��
        int t = r;
        for (int i = r; i < n; i++)
            if (fabs(a[i][c]) > fabs(a[t][c]))
                t = i;
		// �����ǰ��ȫ��0����ɨ����һ����
        if (fabs(a[t][c]) < eps) continue;
		
		// ���������ֵ������һ�л�����ǰ�棨��ʵ�������ǰ�沢����ָ��һ�У�����ָ��Ԫ��ʱ����ݵ���һ�У�
        for (int i = c; i < n + 1; i++) swap(a[t][i], a[r][i]);
        // ����һ�еĵ�һ��ϵ������Ԫ�����1������ϵ����Ӧ������Ԫ�ľ�ֵ
        for (int i = n; i >= c; i--) a[r][i] /= a[r][c];
        // ������������б任���ѵ�ǰ������
        for (int i = r + 1; i < n; i++)
            if (fabs(a[i][c]) > eps)
                for (int j = n; j >= c; j--)
                    a[i][j] -= a[r][j] * a[i][c];

        r++;
    }
	// ���r < n����˵�����ı�׼�εķ��̸�����С��n�ģ��ǲ���Ψһ��
    if (r < n) {
    	// ������ϵ��ȫ��0�ķ����еĳ�����������һ����0�����޽�
        for (int i = r; i < n; i++)
            if (fabs(a[i][n]) > eps)
                return 2;
        // �����������
        return 1;
    }
	
	// ���r = n���򷽳���Ψһ�⣬��������ϵ������Ϊ��λ����ʵ����ֻ��
	// Ҫ�ѳ����һ�¾����ˣ�ϵ������Ҫ��ı䣬��Ϊ��ʱ���ֻ��Ҫ��������
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
	
	// �����Ψһ�⣬�Ͱѳ����������
    if (t == 0) {
        for (int i = 0; i < n; i++) printf("%.2lf\n", a[i][n]);
    } else if (t == 1) puts("Infinite group solutions");
    else puts("No solution");

    return 0;
}
