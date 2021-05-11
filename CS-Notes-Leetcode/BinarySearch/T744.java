
// 2021.05.11
// Leetcode 第744题
// https://leetcode-cn.com/problems/find-smallest-letter-greater-than-target/description/
package BinarySearch;

public class T744 {
    public static void main(String[] args) {
        T744 solution = new T744();
        char[] letters = {'c', 'f', 'j'};
        System.out.println(solution.nextGreatestLetter(letters, 'j'));
    }

    public char nextGreatestLetter(char[] letters, char target) {
        int l = 0;
        int h = letters.length - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (letters[m] <= target) {
                l = m + 1;
            } else {
                // h = m;
                h = m - 1;
            }
        }

        if (l >= letters.length){
            return letters[0];
        }
        return letters[l];
    }
}
