import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;
import java.util.TreeSet;

public class Main {
    static class GloPoint {
        public char name;
        public HashSet<Character> equVar = new HashSet<>(30);
        public HashSet<Character> equGolPoint = new HashSet<>(30);
        public HashSet<String> equVarFiled = new HashSet<>(30);
        public HashSet<Character>[] fiedlEqu = new HashSet[30];

        public GloPoint(char name) {
            this.name = name;
            for (int i = 0; i < 26; i++) {
                fiedlEqu[i] = new HashSet<>();
            }
        }
    }

    static class Variabl {

        public char name;
        public HashSet<Character> equVarFiled = new HashSet<>(30);

        public Variabl(char name) {
            this.name = name;
        }
    }

    static HashSet<String> vztd = new HashSet<>(30);
    static HashSet<Character> inStk = new HashSet<>(30);
    static GloPoint[] points = new GloPoint[30];
    static Variabl[] variabls = new Variabl[30];
    static HashMap<Character, Integer> isEmpty = new HashMap<>(30);

    public static void dfs(char u) {
        HashSet<Character> tem = new HashSet<>();
        tem.addAll(points[u - 'A'].equGolPoint);
        for (String string : points[u - 'A'].equVarFiled) {
            char lef = string.charAt(0);
            char rit = string.charAt(2);
            if (inStk.contains(lef)) {
                for (Character character : points[lef - 'A'].equVar) {
                    tem.addAll(variabls[character - 'a'].equVarFiled);
                }
            } else {
                inStk.add(lef);
                dfs(lef);
                for (Character character : points[lef - 'A'].equVar) {
                    tem.addAll(variabls[character - 'a'].equVarFiled);
                }
            }
            /*if (isEmpty.getOrDefault(lef,0) > 0) {
                tem.addAll(points[lef - 'A'].fiedlEqu[rit - 'a']);
            }*/
        }
        for (Character character : tem) {
            if (inStk.contains(character)) {
                points[u - 'A'].equVar.addAll(points[character - 'A'].equVar);
                continue;
            }
            inStk.add(character);
            dfs(character);
            points[u - 'A'].equVar.addAll(points[character - 'A'].equVar);
        }
        for (int i = 0; i < 26; i++) {
            if (points[u - 'A'].fiedlEqu[i].size() != 0) {
                HashSet<Character> temm = points[u - 'A'].fiedlEqu[i];
                for (Character character : temm) {
                    if (!inStk.contains(character)) {
                        inStk.add(character);
                        dfs(character);
                    }
                    for (Character var : points[u - 'A'].equVar) {
                        variabls[var - 'a'].equVarFiled.addAll(points[character - 'A'].equVar);
                    }
                }
            }
        }
    }

    /*public static int dfs2(char u) {
        if (isEmpty.containsKey(u)) {
            return isEmpty.get(u);
        }
        if (points[u - 'A'].equVar.size() != 0) {
            isEmpty.put(u, 1);
            return 1;
        } else {
            HashSet<Character> tem = new HashSet<>();
            tem.addAll(points[u - 'A'].equGolPoint);
            for (String string : points[u - 'A'].equVarFiled) {
                char lef = string.charAt(0);
                char rit = string.charAt(2);
                tem.addAll(points[lef - 'A'].fiedlEqu[rit - 'a']);
            }
            for (Character character : tem) {
                if (inStk.contains(character)) {
                    continue;
                }
                inStk.add(character);
                int ans = dfs2(character);
                if (ans > 0) {
                    isEmpty.put(u, 1);
                    break;
                }
            }
            if (!isEmpty.containsKey(u)) {
                isEmpty.put(u, 0);
            }
            return isEmpty.get(u);
        }
    }*/

    public static void main(String[] args) {
        int n;
        for (int i = 0; i < 28; i++) {
            points[i] = new GloPoint((char) ('A' + i));
            variabls[i] = new Variabl((char) ('a' + i));
        }

        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        String tem;
        scanner.nextLine();
        for (int i = 1; i <= n; i++) {
            tem = scanner.nextLine();
            String[] equ = tem.split(" = ");
            if (equ[0].length() == 1 && equ[1].length() == 1) {
                char lef = equ[0].charAt(0);
                char rit = equ[1].charAt(0);
                if (rit >= 'a') {
                    points[lef - 'A'].equVar.add(rit);
                } else {
                    points[lef - 'A'].equGolPoint.add(rit);
                }
            } else if (equ[0].length() == 3) {
                //String[] lefto = equ[0].split(".");
                char lefGlo = equ[0].charAt(0);
                char lefVar = equ[0].charAt(2);
                char rit = equ[1].charAt(0);
                points[lefGlo - 'A'].fiedlEqu[lefVar - 'a'].add(rit);
            } else {
                char lef = equ[0].charAt(0);
                points[lef - 'A'].equVarFiled.add(equ[1]);
            }
        }
        /*for (int i = 0; i < 26; i++) {
            inStk.clear();
            dfs2((char) ('A' + i));
        }*/
        for (int i = 0; i < 26; i++) {
            inStk.clear();
            char character = (char) ('A' + i);
            //if (!vztd.contains(Character.toString(character))) {
            //    inStk.add(character);
            //    dfs(character);
            //}
            dfs(character);
            System.out.print(character + ": ");
            TreeSet<Character> temm = new TreeSet<>(points[i].equVar);
            for (Character ch : temm) {
                System.out.print(ch);
            }
            System.out.print('\n');
        }
    }
}
