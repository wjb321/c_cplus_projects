/*
f(x, y) =(6. 452(x+0. 125y) (cosx-cos2y) (cosx-cos2y)) /(亅(0. 8+(x-4. 2) (x-4. 2) +2(y-7) (y-7))) +3. 226y
求函数最大值  x的区间[ 0, 10), y的区间[0, 10)
x  y都为三位小数则染色体编码为xxxxyyyy
初始染色体   42303407 44670717 41877579
09054353 57997839 11976719
64139420 89513808 52092913
73909290*/
//写得我都快头秃了  上学人
//初代与子代都是10个个体，当子代生成后，上一代则被抛弃，子代则存储在数组中（覆盖）

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <graphics.h>

#define Seed  srand((unsigned)time(0));//随机数种子
#define BIAN  0.15   //变异概率
#define DAISHU 500 //换代次数


int XuanZeShu[10];//储存选择的染色体的下标
double ZuiYouZhi[20] = { 0 };//储存最优值及产生代数
double TureZuiYou[10] = { 0 };//储存所有代数的最优值

//随机数生成
//其中x为选择哪个函数，sum为选择算法中的适应度之和
double Rand(int x, int sum) {
	// rand（）% （b - a + 1）的范围是[0，b - a+1]

	if (x == 1){//用于初始化染色体

		return rand() % 10;//生成0到9的随机数

	}
	else if (x == 0) {//判断是否需要变异(bian除以100)<=0.15即变异

		double bian;
		bian = (rand() % 100);//生成0到100的随机数

		return bian / 100;

	}
	else if (x == 2){//生成选择所需的随机数，既选择哪一条染色体 10次

		return rand() % (sum + 1);

	}
	else if (x == 3){//返回交叉或变异哪一位数字

		return rand() % 8;

	}
	else if (x == 4){//返回变异多少个

		return rand() % 5 + 1;
	}

}

//适应度函数(即所求函数) 返回适应度
double ShiYing(double ranseti[][10], int i){
	double x, y;
	//解码x,y;
	x = ranseti[i][0] + ranseti[i][1] * 0.1 + ranseti[i][2] * 0.01 + ranseti[i][3] * 0.001;
	y = ranseti[i][4] + ranseti[i][5] * 0.1 + ranseti[i][6] * 0.01 + ranseti[i][7] * 0.001;

	double FenZi = 6.452*(x + 0.125*y)*pow((cos(x) - cos(2 * y)), 2);
	double FenMu = sqrt(0.8 + pow((x - 4.2), 2) * 2 * pow((y - 7), 2));

	return (FenZi / FenMu) + 3.266*y;
}


//选择算法，轮盘赌选择:以数轴形式呈现，按适应度分为分成10个区域
void XuanZe(double ranseti[][10]){

	//此处为给染色体在数轴所占区域，为了方便计算省略了小数点
	double sum[10] = { 0 };
	sum[0] = ranseti[0][8];
	for (int i = 1; i<10; i++){
		sum[i] = sum[i - 1] + ranseti[i][8];
	}

	//选择哪个染色体，将其下标储存在XuanZeShu[]数组中
	int NaGe = 10;
	for (int j = 0; j<10; j++){
		int XuanRan = Rand(2, (int)sum[9]);
		//不同区域对应不同的染色体
		if (XuanRan >= 0 && XuanRan<(int)sum[0]){ XuanZeShu[j] = 0; }
		else if (XuanRan >= (int)sum[0] && XuanRan<(int)sum[1]){ XuanZeShu[j] = 1; }
		else if (XuanRan >= (int)sum[1] && XuanRan<(int)sum[2]){ XuanZeShu[j] = 2; }
		else if (XuanRan >= (int)sum[2] && XuanRan<(int)sum[3]){ XuanZeShu[j] = 3; }
		else if (XuanRan >= (int)sum[3] && XuanRan<(int)sum[4]){ XuanZeShu[j] = 4; }
		else if (XuanRan >= (int)sum[4] && XuanRan<(int)sum[5]){ XuanZeShu[j] = 5; }
		else if (XuanRan >= (int)sum[5] && XuanRan<(int)sum[6]){ XuanZeShu[j] = 6; }
		else if (XuanRan >= (int)sum[6] && XuanRan<(int)sum[7]){ XuanZeShu[j] = 7; }
		else if (XuanRan >= (int)sum[7] && XuanRan<(int)sum[8]){ XuanZeShu[j] = 8; }
		else if (XuanRan >= (int)sum[8] && XuanRan <= (int)sum[9]){ XuanZeShu[j] = 9; }

	}

}

//变异算法
void BianYi(double RanSeTi[][10]){
	for (int i = 0; i<10; i++){//循环每个染色体是否需要变异
		double IsBian = Rand(0, 0);//变异比较值
		int NaWei[7] = { 11 };//变异哪些，以下标表示
		if (IsBian <= BIAN){//不等式成立，则变异   
			NaWei[6] = Rand(4, 0);//最多变异5位   
			for (int j = 0; j <= NaWei[6];){//储存变异的下标
				int SHU = Rand(3, 0);//变异下标
				int flag = 0;//假设都不重复
				for (int k = 0; k <= j; k++){
					if (NaWei[k] == SHU){ flag = 1; break; }//判断
				}
				if (flag == 0){
					int Huan;
				XuanHuan:
					Huan = Rand(1, 0);
					NaWei[j] = SHU;
					if (RanSeTi[i][SHU] != Huan){
						RanSeTi[i][SHU] = Huan;
					}
					else{ goto XuanHuan; }
					j++;
				}//赋值
				if (j == NaWei[6]){ break; }//退出循环
			}

		}

	}



}

//交叉算法  只随机交叉其中一半
//先判断父本和母本是否相等，相等则令其中一个交叉后变异
//然后覆盖
void JiaoCha(double RanSeTiFu[][10], double RanSeTi[][10]){

	int NaWei[5][10] = { -1 };//储存哪位染色体进行交叉替换。
	for (int i = 0; i<5; i++){//循环输入行
		int count = 0;//是否选好一组的交叉位置

		while (1){//由于还要遍历随机数是否重复，则用while

			int flag = 0;//假设都不重复
			int ZHI = Rand(3, 0);//是否重复
			for (int j = 0; j <= count; j++){
				if (ZHI == NaWei[i][j]){//判断
					flag = 1;
					break;
				}
			}
			//赋值 不同的随机数
			if (flag == 0){ NaWei[i][count] = ZHI; count++; }
			if (count == 4){ break; }//为4时，一组选择完毕
		}

	}

	//开始覆盖数组
	for (int i = 1; i <= 5; i++){
		for (int j = 0; j<8; j++){
			if (j == NaWei[i - 1][0] || j == NaWei[i - 1][1] || j == NaWei[i - 1][2] || j == NaWei[i - 1][3]){
				RanSeTi[i * 2 - 2][j] = RanSeTiFu[i * 2 - 1][j];
				RanSeTi[i * 2 - 1][j] = RanSeTiFu[i * 2 - 2][j];
			}
			else{
				RanSeTi[i * 2 - 1][j] = RanSeTiFu[i * 2 - 1][j];
				RanSeTi[i * 2 - 2][j] = RanSeTiFu[i * 2 - 2][j];
			}

		}

	}

}


//比较最优值函数
//并输出每一代最优染色体及其值
void BiJiao(double RanSeTi[][10], int ZiDai){
	ZuiYouZhi[8] = 0;
	//每代最优
	for (int i = 0; i<10; i++){
		if (RanSeTi[i][8]>ZuiYouZhi[8])
		{
			ZuiYouZhi[8] = RanSeTi[i][8];
			ZuiYouZhi[9] = i;
		}
	}
	//全代最优
	for (int i = 0; i<10; i++){
		if (TureZuiYou[8]<RanSeTi[i][8])
		{//更优才赋值
			TureZuiYou[8] = RanSeTi[i][8];
			TureZuiYou[9] = (double)ZiDai;
			//储存解
			for (int j = 0; j<8; j++){
				TureZuiYou[j] = RanSeTi[i][j];
			}
		}

	}


	double x, y;
	int ii = ZuiYouZhi[9];
	//解码x,y;
	x = RanSeTi[ii][0] + RanSeTi[ii][1] * 0.1 + RanSeTi[ii][2] * 0.01 + RanSeTi[ii][3] * 0.001;
	y = RanSeTi[ii][4] + RanSeTi[ii][5] * 0.1 + RanSeTi[ii][6] * 0.01 + RanSeTi[ii][7] * 0.001;

	printf("第%d代最优值为\n", ZiDai);
	printf("x = %.3lf, y = %.3lf\n", x, y);
	printf("最优值%lf\n", ZuiYouZhi[8]);
	printf("\n");


}


//主函数
int main(){
	double RanSeTi[10][10], RanSeTiFu[10][10];
	Seed//宏
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j<8; j++) {

			//初始化初代染色体
			RanSeTi[i][j] = (int)Rand(1, 0);

		}
		//储存适应度
		RanSeTi[i][8] = ShiYing(RanSeTi, i);
	}

	//初始最优值
	BiJiao(RanSeTi, 0);


	//循环迭代
	for (int ZiDai = 1; ZiDai <= DAISHU; ZiDai++){
		//选择操作
		XuanZe(RanSeTi);

		//将选择出的染色体存储，为下一步交叉做准备
		for (int i = 0; i<10; i++){
			for (int j = 0; j<8; j++){
				RanSeTiFu[i][j] = RanSeTi[XuanZeShu[i]][j];
			}
		}

		//交叉操作
		JiaoCha(&RanSeTiFu[0], &RanSeTi[0]);

		//变异操作
		BianYi(RanSeTi);

		//储存适应度
		for (int Shi = 0; Shi<10; Shi++){
			RanSeTi[Shi][8] = ShiYing(RanSeTi, Shi);
		}

		//比较输出该代最优值
		BiJiao(RanSeTi, ZiDai);

	}

	//最优解
	double tx, ty;
	//解码tx,ty;
	tx = TureZuiYou[0] + TureZuiYou[1] * 0.1 + TureZuiYou[2] * 0.01 + TureZuiYou[3] * 0.001;
	ty = TureZuiYou[4] + TureZuiYou[5] * 0.1 + TureZuiYou[6] * 0.01 + TureZuiYou[7] * 0.001;
	printf("最终最优值为\n");
	printf("x = %.3lf, y = %.3lf\n", tx, ty);
	printf("最优值%lf\n", TureZuiYou[8]);
	printf("产生于第%.0lf代\n", TureZuiYou[9]);
	printf("\n");




	return 0;
}

//int main()
//{
//	float a = 456.78926;
//	int b = 0;
//	float c = 0;
//    int temp = 0;
//	int d = 0;
//	// C = A – B * (A / B).
//	temp = (int)((a - (int)a)*10000);
//	printf("b = %d\n", int(a)); 
//	printf("c= %d\n",(temp)/100);
//	d = (temp) / 100;
//	printf("d= %d\n", (temp ) % 100);
//	//printf("d1= %d\n", temp -100 *(temp / 100)); 
//	printf("d1= %d\n", temp - 100 * d);
//	return 0;
//}
//float intermediate = 0;
//float Decelerate = 50.0;
//#define Radian  0.523
//#define Radius  0.045
//#define PI 3.14159
//#include <math.h>
//
//float vol0 = 90.0;
//float tempval = 0.0;
//float vol1 = 85.3;
//int main(void)
//{
//	intermediate = Decelerate * Radian * Radius;
//	tempval = ((vol0 + sqrt(vol0 * vol0 - 4 * intermediate)) / 2.0);
//	if (vol1 + 3 < ((vol0 + sqrt(vol0 * vol0 - 4 * intermediate)) / 2.0) && vol1 < vol0 - 3)
//	{
//		                  printf("vol1  is %f \r\n", vol1 );
//		                  printf("vol0 is %f \r\n", vol0);
//		                  printf("cal is %f \r\n", (vol0 + sqrt(vol0 * vol0 - 4* intermediate))/ 2.0 );
//		MES4_DATA0 = 1;
//
//		printf("block\n");
//		 printf("ECU_IDs it is blocked %#x\r\n", ECU_IDs);
//	}
//	printf("tempval %.5f\n", tempval);
//	printf("differ %.5f\n", vol0 - tempval);
//}