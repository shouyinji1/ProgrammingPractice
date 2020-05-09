/*
2018年蓝桥杯省赛Java B组第三题：复数幂

设i为虚数单位。对于任意正整数n，(2+3i)^n的实部和虚部都是整数。求(2+3i)^123456等于多少？
即(2+3i)的123456次幂，这个数字很大，要求精确表示。
答案写成"实部±虚部i"
的形式，实部和虚部都是整数（不能用科学计数法表示），中间任何地方都不加空格，实部为正时前面不加正号。(2+3i)^2写成:-5+12i，(2+3i)^5的写成:122-597i

注意：需要提交的是一个很庞大的复数，不要填写任何多余内容。
*/


import java.math.BigInteger;

public class Main{
	public static void main(String[] args) {
		BigInteger a = new BigInteger("2");
		BigInteger b = new BigInteger("3");
		BigInteger a1 = new BigInteger("2");
		BigInteger b1 = new BigInteger("3");
		BigInteger temp;
		for(int i = 1; i<123456; i++){
			temp = a.multiply(a1).subtract(b.multiply(b1));
			b = a.multiply(b1).add(b.multiply(a1));
			a = temp;
		}
		if(b.compareTo(BigInteger.valueOf(0))>0){
			System.out.println(a+"+"+b+"i");
		}else{
			System.out.println(a+""+b+"i");
		}
	}
}
