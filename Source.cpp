#include<iostream>
using namespace std;
int main()
{

	cout << "                               ****Cipher text into Plain text****\n\n";
	int a[3][3];
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			cout << "Enter a number for key at the place " << i + 1 << j + 1 << " :";
			cin >> a[i][j];
		}
	}
	cout << endl;
	cout << "Key is:- \n";
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			cout << a[i][j] << "  ";
		}
		cout << endl;
	}
	int determinant;
	determinant = a[0][0] * ((a[1][1] * a[2][2]) - (a[2][1] * a[1][2])) - a[0][1] * (a[1][0] * a[2][2] - a[2][0] * a[1][2]) + a[0][2] * (a[1][0] * a[2][1] - a[2][0] * a[1][1]);
	if (determinant < 0)
	{
		int det1 = (determinant / 26) * 26;
		int det2 = determinant - det1;
		cout <<"\nDeterminent: "<< det2 << endl << endl;
		int dett = 26 + det2;
		determinant = dett;
		cout << "Determinent(mod 26): "<<dett << endl << endl;
	}
	else
	{
		cout << "Determinent: " << determinant << endl;
	}
	int det = 0;
	for (int i = 0;i <= 1000;i++)
	{
		det = determinant*i;
		if (det % 26 == 1)
		{
			determinant = i;
			break;
		}

	}
	cout << "\nThe reciprocal modulo of determinent : " << determinant << endl;




	/////////////////////////////////////////////////////////////////////////////
	/// adjoint of 3x3
	int m[3][3];
	m[0][0] = (a[1][1] * a[2][2]) - (a[1][2] * a[2][1]);
	m[0][1] = (a[1][0] * a[2][2]) - (a[1][2] * a[2][0]);
	m[0][2] = (a[1][0] * a[2][1]) - (a[1][1] * a[2][0]);
	m[1][0] = (a[0][1] * a[2][2]) - (a[0][2] * a[2][1]);
	m[1][1] = (a[0][0] * a[2][2]) - (a[0][2] * a[2][0]);
	m[1][2] = (a[0][0] * a[2][1]) - (a[0][1] * a[2][0]);
	m[2][0] = (a[0][1] * a[1][2]) - (a[0][2] * a[1][1]);
	m[2][1] = (a[0][0] * a[1][2]) - (a[0][2] * a[1][0]);
	m[2][2] = (a[0][0] * a[1][1]) - (a[0][1] * a[1][0]);

	/////////////////////////////////////////////////////////////////////
	cout << endl;
	cout << "Minor is:-" << endl;
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			cout << m[i][j] << "  ";
		}
		cout << endl;
	}

	///////////////////////////////////////////////////////////////////////
	//// cofactor of 3x3
	int c[3][3];
	c[0][0] = m[0][0];
	c[0][1] = -m[0][1];
	c[0][2] = m[0][2];
	c[1][0] = -m[1][0];
	c[1][1] = m[1][1];
	c[1][2] = -m[1][2];
	c[2][0] = m[2][0];
	c[2][1] = -m[2][1];
	c[2][2] = m[2][2];

	/////////////////////////////////////////////////////////////////////////

	cout << endl;
	cout << "cofactor is:-" << endl;
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			cout << c[i][j] << "  ";
		}
		cout << endl;
	}
	/////////////////////////////////////////////////////////////////////////
	///// transpose of cofactors
	int empty[3][3];
	empty[0][1] = c[0][1];
	empty[0][2] = c[0][2];
	empty[1][2] = c[1][2];
	c[0][0] = c[0][0];
	c[0][1] = c[1][0];
	c[0][2] = c[2][0];
	c[1][0] = empty[0][1];
	c[1][1] = c[1][1];
	c[1][2] = c[2][1];
	c[2][0] = empty[0][2];
	c[2][1] = empty[1][2];
	c[2][2] = c[2][2];

	//////////////////////////////////////////////////////////////////
	cout << endl;
	cout << "transpose of a cofactor:-" << endl;
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			cout << c[i][j] << "  ";
		}
		cout << endl;
	}


	/////////////////////////////////////////////////////////////////////////

	cout << endl;
	cout << "Adjoint correspond to class of 26:-" << endl;
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			if (c[i][j] < 0 )
			{
				c[i][j] = c[i][j] % 26;
				if (c[i][j] < 0)
				{
					c[i][j] = c[i][j] + 26;
				}
				//c[i][j] = -(c[i][j]-((c[i][j]/26)*26));
			}
			else if (c[i][j] > 25)
			{
				c[i][j] = c[i][j] % 26;
			}
		}
	}

	//////////////////////////////////////////////////

	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			cout << c[i][j] << "  ";
		}
		cout << endl;
	}

	///////////////////////////////////////////////
///////////////// inverse of 3x3
	cout << endl;
	int inverse[3][3];
	for (int i = 0;i<3;i++)
	{
		for (int j =0;j < 3;j++)
		{
			inverse[i][j] = (determinant*c[i][j]);
			/*if (adj[i][j] < 0)
			{
			adj[i][j] = 26 + adj[i][j];
			}*/
		}
	}

	cout << endl;
	///cout << "Det: " << determinant << endl;
	cout << endl;
	cout << "The inverse is:-" << endl;
	for (int i = 0;i<3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			cout << inverse[i][j] << " ";
		}
		cout << endl;
	}

	//////////////////////////////////////////////////
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			if (inverse[i][j] > 25)
			{
				inverse[i][j] = inverse[i][j] % 26;
			}
		}
	}

	cout << endl;
	cout << "Inverse (class of 26):-" << endl;
	for (int i = 0;i<3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			cout << inverse[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	///////////////////////////////////////////////////////////


	int count;
	cout << "Enter the number of alphabets you want to decode: ";
	cin >> count;
	int i = 0;
	char array[100];
	while (i < count)
	{
		cout << "Enter a alphabet: ";
		cin >> array[i];
		i++;
	}
	

	/////////////////////////////////////////////////////////////

	int num[100];
	for (int i = 0; i < count; i++)
	{
		if (array[i] == 'A')
		{
			num[i] = 0;
		}
		else if (array[i] == 'B')
		{
			num[i] = 1;
		}
		else if (array[i] == 'C')
		{
			num[i] = 2;
		}
		else if (array[i] == 'D')
		{
			num[i] = 3;
		}
		else if (array[i] == 'E')
		{
			num[i] = 4;
		}
		else if (array[i] == 'F')
		{
			num[i] = 5;
		}
		else if (array[i] == 'G')
		{
			num[i] = 6;
		}
		else if (array[i] == 'H')
		{
			num[i] = 7;
		}
		else if (array[i] == 'I')
		{
			num[i] = 8;
		}
		else if (array[i] == 'J')
		{
			num[i] = 9;
		}
		else if (array[i] == 'K')
		{
			num[i] = 10;
		}
		else if (array[i] == 'L')
		{
			num[i] = 11;
		}
		else if (array[i] == 'M')
		{
			num[i] = 12;
		}
		else if (array[i] == 'N')
		{
			num[i] = 13;
		}
		else if (array[i] == 'O')
		{
			num[i] = 14;
		}
		else if (array[i] == 'P')
		{
			num[i] = 15;
		}
		else if (array[i] == 'Q')
		{
			num[i] = 16;
		}
		else if (array[i] == 'R')
		{
			num[i] = 17;
		}
		else if (array[i] == 'S')
		{
			num[i] = 18;
		}
		else if (array[i] == 'T')
		{
			num[i] = 19;
		}
		else if (array[i] == 'U')
		{
			num[i] = 20;
		}
		else if (array[i] == 'V')
		{
			num[i] = 21;
		}
		else if (array[i] == 'W')
		{
			num[i] = 22;
		}
		else if (array[i] == 'X')
		{
			num[i] = 23;
		}
		else if (array[i] == 'Y')
		{
			num[i] = 24;
		}
		else if (array[i] == 'Z')
		{
			num[i] = 25;
		}
	}

	/////////////////////////////////////////////////////////////////////
	cout << endl;
	cout << "The plain text is:- ";

	for (int i = 0;i < count;i++)
	{
		int result[3][1];
		int name[3][1];
		name[0][0] = num[i];
		i++;
		name[1][0] = num[i];
		i++;
		name[2][0] = num[i];
		result[0][0] = (inverse[0][0] * name[0][0]) + (inverse[0][1] * name[1][0]) + (inverse[0][2] * name[2][0]);
		result[1][0] = (inverse[1][0] * name[0][0]) + (inverse[1][1] * name[1][0]) + (inverse[1][2] * name[2][0]);
		result[2][0] = (inverse[2][0] * name[0][0]) + (inverse[2][1] * name[1][0]) + (inverse[2][2] * name[2][0]);
		for (int k = 0;k<3;k++)
		{
			int j = 0;
			if (result[k][j] > 25)
			{
				result[k][j] = result[k][j] % 26;
			}
		}
		for (int k = 0;k < 3;k++)
		{
			int j = 0;
			if (result[k][j] == 0)
			{
				cout << "A";
			}
			else if (result[k][j] == 1)
			{
				cout << "B";
			}
			else if (result[k][j] == 2)
			{
				cout << "C";
			}
			else if (result[k][j] == 3)
			{
				cout << "D";
			}
			else if (result[k][j] == 4)
			{
				cout << "E";
			}
			else if (result[k][j] == 5)
			{
				cout << "F";
			}
			else if (result[k][j] == 6)
			{
				cout << "G";
			}
			else if (result[k][j] == 7)
			{
				cout << "H";
			}
			else if (result[k][j] == 8)
			{
				cout << "I";
			}
			else if (result[k][j] == 9)
			{
				cout << "J";
			}
			else if (result[k][j] == 10)
			{
				cout << "K";
			}
			else if (result[k][j] == 11)
			{
				cout << "L";
			}
			else if (result[k][j] == 12)
			{
				cout << "M";
			}
			else if (result[k][j] == 13)
			{
				cout << "N";
			}
			else if (result[k][j] == 14)
			{
				cout << "O";
			}
			else if (result[k][j] == 15)
			{
				cout << "P";
			}
			else if (result[k][j] == 16)
			{
				cout << "Q";
			}
			else if (result[k][j] == 17)
			{
				cout << "R";
			}
			else if (result[k][j] == 18)
			{
				cout << "S";
			}
			else if (result[k][j] == 19)
			{
				cout << "T";
			}
			else if (result[k][j] == 20)
			{
				cout << "U";
			}
			else if (result[k][j] == 21)
			{
				cout << "V";
			}
			else if (result[k][j] == 22)
			{
				cout << "W";
			}
			else if (result[k][j] == 23)
			{
				cout << "X";
			}
			else if (result[k][j] == 24)
			{
				cout << "Y";
			}
			else if (result[k][j] == 25)
			{
				cout << "Z";
			}
		}

	}
	cout << endl;
	system("pause");
	///////////////////////////////////////////////////////////////////////












	return 0;
}