class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int[][] paths = new int[text1.length()+1][text2.length()+1];
        for (int i = 1; i < text1.length()+1; i++) {
            for (int j = 1; j < text2.length()+1; j++) {
                if (text1.charAt(i-1) == text2.charAt(j-1)) {
                    paths[i][j] = paths[i-1][j-1] + 1;
                }
                else {
                    paths[i][j] = Math.max(paths[i-1][j], paths[i][j-1]);
                }
            }
        }
        return paths[text1.length()][text2.length()];
    }
}
