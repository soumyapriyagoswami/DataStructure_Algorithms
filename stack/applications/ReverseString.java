import java.util.Stack;

public class ReverseString {
    public static String reverse(String str) {
        Stack<Character> stack = new Stack<>();
        for (char c : str.toCharArray()) {
            stack.push(c);
        }

        StringBuilder reversedStr = new StringBuilder();
        while (!stack.isEmpty()) {
            reversedStr.append(stack.pop());
        }

        return reversedStr.toString();
    }

    public static void main(String[] args) {
        String str = "Hello, World!";
        String reversed = reverse(str);
        System.out.println("Reversed string: " + reversed);
    }
}
