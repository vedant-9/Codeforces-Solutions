
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
        int n = sc.nextInt();
        ArrayList<ArrayList<Integer>> a = new ArrayList<ArrayList<Integer>>();
        for (int i = 0; i < n; i++) {
            int k = sc.nextInt();
            ArrayList<Integer> t = new ArrayList<>();
            while (k-- > 0) {
                t.add(sc.nextInt());
            }
            a.add(t);
        }
        Set<Integer> main_st = new HashSet<Integer>();
        for (int i = 0; i < n; i++) {
            for (Integer x : a.get(i)) {
                main_st.add(x);
            }
        }
        // System.out.println(main_st);
        int max_size = 0;
        for (int c = 1; c <= 50; c++) {
            Set<Integer> st = new HashSet<Integer>();
            for (int i = 0; i < n; i++) {
                if (!a.get(i).contains(c)) {
                    for (Integer x : a.get(i)) {
                        st.add(x);
                    }
                }
            }
            if (st.size() != main_st.size()) {
                max_size = Math.max(max_size, (int) st.size());
            }
        }
        System.out.println(max_size);
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
