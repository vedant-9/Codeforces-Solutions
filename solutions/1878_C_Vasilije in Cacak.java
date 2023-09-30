
// It's Not Over Until I Win
// Believe
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class cp {

    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        String next() {
            while (!st.hasMoreTokens())
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void solve(FastScanner sc) {
        long n = sc.nextLong();
        long k = sc.nextLong();
        long x = sc.nextLong();
        // System.out.println(n + " " + k + " " + x);
        long min_ksum = k * (k + 1) / 2;
        long max_ksum = n * (n + 1) / 2 - (n - k) * (n - k + 1) / 2;
        if (x >= min_ksum && x <= max_ksum)
            System.out.println("YES");
        else
            System.out.println("NO");
    }

    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        int tc = 1;
        tc = sc.nextInt();
        while (tc-- > 0) {
            solve(sc);
        }
    }
}
