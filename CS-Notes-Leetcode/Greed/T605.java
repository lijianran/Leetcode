
// 2021.05.10
// Leetcode 第605题
// https://leetcode-cn.com/problems/can-place-flowers/description/
package Greed;

public class T605 {
    public static void main(String[] args) {
        int[] flowerbed = { 1, 0, 0, 0, 1 };

        T605 solution = new T605();
        System.out.println(solution.canPlaceFlowers(flowerbed, 1));
        System.out.println(solution.canPlaceFlowers(flowerbed, 2));
    }

    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int length = flowerbed.length;
        if (length == 0) {
            return false;
        }
        int count = 0;
        for (int i = 0; i < length; i++) {
            if (flowerbed[i] != 1) {
                if (i - 1 >= 0 && flowerbed[i - 1] == 1) {
                    continue;
                }
                if (i + 1 < length && flowerbed[i + 1] == 1) {
                    continue;
                }
                count += 1;
                // 种花
                flowerbed[i] = 1;
            }
        }
        if (count >= n) {
            return true;
        }
        return false;
    }
}
