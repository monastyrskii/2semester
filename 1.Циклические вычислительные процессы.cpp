#include <iostream>
using namespace std;

int main()
{
	double a, b, dx, x0, x1, i, c, f;
	cout << "  a="; cin >> a;
	cout << "  b="; cin >> b;
	cout << "  c="; cin >> c;
	cout << "  x0="; cin >> x0;
	cout << "  x1="; cin >> x1;
	cout << "  dx="; cin >> dx;
	cout << endl << " X    F " << endl;

	int ac = a; int bc = b; int cc = c;
	
	for (i = x0; i <= x1; i += dx)
	{
		if ((c < 0) && (a != 0))
		{
			f = -a * i*i;
		}
		if ((c > 0) && (a == 0))
		{
			f = (a - i) / (c * i);
		}
		else
		{
			f = i / c;
		}
		if ((ac ^ bc) && !(ac || cc) != 0)
			cout << " " << i << "    " << f << endl;
		else cout << " " << i << "    " << int (f) << endl;
	}
	system("pause");
	return (0);
}
