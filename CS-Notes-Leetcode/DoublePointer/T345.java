
// 2021.04.21
// Leetcode 第345题
// https://leetcode-cn.com/problems/reverse-vowels-of-a-string/description/
package DoublePointer;

public class T345 {
    public static void main(String[] args) {
        T345 solution = new T345();
        System.out.println(solution.reverseVowels("hello"));
    }

    public String reverseVowels(String s) {
        char[] str = s.toCharArray();
        int small = 0;
        int big = str.length - 1;

        while (small < big) {
            while (small < str.length && str[small] != 'a' && str[small] != 'e' && str[small] != 'i'
                    && str[small] != 'o' && str[small] != 'u' && str[small] != 'A' && str[small] != 'E'
                    && str[small] != 'I' && str[small] != 'O' && str[small] != 'U') {
                small++;
            }
            while (big >= 0 && str[big] != 'a' && str[big] != 'e' && str[big] != 'i' && str[big] != 'o'
                    && str[big] != 'u' && str[big] != 'A' && str[big] != 'E' && str[big] != 'I' && str[big] != 'O'
                    && str[big] != 'U') {
                big--;
            }
            if (small < big) {
                char temp = str[small];
                str[small] = str[big];
                str[big] = temp;
                small++;
                big--;
            }
        }
        return new String(str);
    }
}
