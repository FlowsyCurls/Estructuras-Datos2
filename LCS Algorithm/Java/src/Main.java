
public class Main {

    public static void main(String[] args)
    {
        LCS lcs = new LCS();
        String s1 = "HOLAAAQ";
        String s2 = "GXTXAYB";

        System.out.println("Length of LCS_DP is" + " " +
                lcs.lcs_DP(s1,s2) );
    }
}
