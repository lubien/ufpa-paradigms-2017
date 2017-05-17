class List {
  public int head;
  public List tail;
  
  public List(int h, List t) {
    head = h;
    tail = t;
  } 
}

public class Main {
  public static void main(String[] args) {
    List L1 = list(1, list(2, list(3, null)));
    List L2 = list(5, list(6, list(7, null)));
    write("L1 is ");write_list(L1);
    writeln("L1 length is " + length(L1));
    writeln("L1 sum is " + sum(L1));
  }
  
  static List list(int head, List tail) {
    return new List(head, tail);
  }
  
  static int head(List xs) {
    return xs.head;
  }
  
  static List tail(List xs) {
    return xs.tail;
  }
  
  static boolean empty(List xs) {
    return xs == null;
  }
  
  static int length(List xs) {
    if (empty(xs)) return 0;
    return 1 + length(tail(xs));
  }
  
  static int sum(List xs) {
    if (empty(xs))
      return 0;
    return head(xs) + sum(tail(xs));
  }
  
  static void write_list(List xs) {
    if (empty(xs))
      write("\n");
    else {
      write(" " +head(xs) + " ");
      write_list(tail(xs));
    }
  }

  static void write(String str) {
    System.out.print(str);
  }
  
  static void writeln(String str) {
    write(str);
    write("\n");
  }
}
