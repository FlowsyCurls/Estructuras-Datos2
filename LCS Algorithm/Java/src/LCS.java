//Longest Common Subsequence
public class LCS {
    /* Returns length of LCS for X[0..m-1], Y[0..n-1] */
    int lcs_DP(String s1, String s2){
        char[] a=s1.toCharArray();
        char[] b=s2.toCharArray();
        return lcs_aux(a, b, a.length, b.length);
    }
    int lcs_aux( char[] a, char[] b, int i, int j) {
        if (i == 0 || j == 0)
            return 0;
        if (a[i-1] == b[j-1])
            return 1 + lcs_aux(a, b, i - 1, j - 1);
        else
            return max(lcs_aux(a, b, i, j - 1), lcs_aux(a, b, i - 1, j));
    }

    /* Utility function to get max of 2 integers */
    int max(int a, int b) {
        return (a > b)? a : b;
    }



}