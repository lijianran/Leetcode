
// 2021.05.13
// Leetcode 第127题
// https://leetcode-cn.com/problems/word-ladder/
package Search;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class T127 {
    public static void main(String[] args) {
    }

    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        wordList.add(beginWord);
        int N = wordList.size();
        int start = N - 1;
        int end = 0;

        while (end < N && !wordList.get(end).equals(endWord)) {
            end++;
        }
        if (end == N) {
            return 0;
        }

        List<Integer>[] graphic = buildGraphic(wordList);

        return getShortestPath(graphic, start, end);
    }

    @SuppressWarnings("unchecked")
    private List<Integer>[] buildGraphic(List<String> wordList) {
        int N = wordList.size();
        List<Integer>[] graphic = new List[N];

        for (int i = 0; i < N; i++) {
            graphic[i] = new ArrayList<>();
            for (int j = 0; j < N; j++) {
                if (isConnect(wordList.get(i), wordList.get(j))) {
                    graphic[i].add(j);
                }
            }
        }

        return graphic;
    }

    private boolean isConnect(String s1, String s2) {
        int diff = 0;
        for (int i = 0; i < s1.length() && diff <= 1; i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                diff++;
            }
        }

        return diff == 1;
    }

    private int getShortestPath(List<Integer>[] graphic, int start, int end) {
        Queue<Integer> queue = new LinkedList<>();
        boolean[] marked = new boolean[graphic.length];
        queue.add(start);
        marked[start] = true;
        int path = 1;

        while (!queue.isEmpty()) {
            int size = queue.size();
            path++;

            while (size-- > 0) {
                int cur = queue.poll();
                for (int next : graphic[cur]) {
                    if (next == end) {
                        return path;
                    }
                    if (marked[next]) {
                        continue;
                    }

                    marked[next] = true;
                    queue.add(next);
                }
            }

        }

        return 0;
    }

}
