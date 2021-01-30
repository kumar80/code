import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class PrimesInSubtree {

  private static final Scanner scanner = new Scanner(System.in);

  static List<Integer> primeQuery(
      int n, List<Integer> u, List<Integer> v, List<Integer> values, List<Integer> queries) {
    List<Integer> result = new ArrayList<>();
    // Build the tree
    Map<Integer, Set<Integer>> tree = new HashMap<>();
    for (int i = 0; i < u.size(); i++) {
      Set<Integer> set = tree.getOrDefault(u.get(i), new HashSet<Integer>());
      set.add(v.get(i));
      tree.put(u.get(i), set);
    }
    int[] numPrimes = new int[n];
    Arrays.fill(numPrimes, -1);
    // Start query
    for (int q : queries) {
      result.add(totalPrimes(tree, q, values, numPrimes));
    }
    return result;
  }

  static int totalPrimes(
      Map<Integer, Set<Integer>> tree, int root, List<Integer> values, int[] numPrimes) {
    if (numPrimes[root - 1] != -1) {
      return numPrimes[root - 1];
    }
    int total = isPrime(values.get(root - 1)) ? 1 : 0;
    if (tree.getOrDefault(root, new HashSet<>()).isEmpty()) {
      return total;
    }
    for (int child : tree.get(root)) {
      if (numPrimes[child - 1] != -1) {
        total += numPrimes[child - 1];
      } else {
        int n = totalPrimes(tree, child, values, numPrimes);
        numPrimes[child - 1] = n;
        total += n;
      }
    }
    return total;
  }

  static boolean isPrime(int num) {
    if (num <= 3) {
      return true;
    } else if (num % 2 == 0) {
      return false;
    } else {
      for (int i = 2; i < Math.sqrt(num); i++) {
        if (num % i == 0) {
          return false;
        }
      }
      return true;
    }
  }

  public static void main(String[] args) throws IOException {
    while (scanner.hasNext()) {
      int n = Integer.valueOf(scanner.nextLine());
      // Starts
      int num = Integer.valueOf(scanner.nextLine());
      List<Integer> u = new ArrayList<>();
      for (int i = 0; i < num; i++) {
        u.add(Integer.valueOf(scanner.nextLine()));
      }
      // Ends
      num = Integer.valueOf(scanner.nextLine());
      List<Integer> v = new ArrayList<>();
      for (int i = 0; i < num; i++) {
        v.add(Integer.valueOf(scanner.nextLine()));
      }
      // Values
      num = Integer.valueOf(scanner.nextLine());
      List<Integer> values = new ArrayList<>();
      for (int i = 0; i < num; i++) {
        values.add(Integer.valueOf(scanner.nextLine()));
      }
      // Queries
      num = Integer.valueOf(scanner.nextLine());
      List<Integer> queries = new ArrayList<>();
      for (int i = 0; i < num; i++) {
        queries.add(Integer.valueOf(scanner.nextLine()));
      }
      System.out.println(primeQuery(n, u, v, values, queries).toString());
    }
  }
}