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
    
    write("L1 is ");
    write_list(L1);
    
    write("L1 without the second element is");
    write_list(drop_at(L1, 1));
    
    write("merge_sort(L1) is");
    write_list(merge_sort(L1));
    
    writeln("L1 length is " + length(L1));
    
    writeln("L1 last element is " + last(L1));
    
    writeln("Are there any duplicated elements in L1? " + duplicated(L1));

    write("L2 is ");
    write_list(L2);
    
    writeln("Appending L2 to L1 is");
    write_list(append(L1, L2));
    
    writeln("L1 reversed (with acc) is");
    write_list(reverse_acc(L1));
    
    writeln("L1 max is " + list_max(L1));
    
    writeln("L1 max is " + list_max(L1));

    writeln("L1 sum is " + sum(L1));
    
    writeln("Is 2 element from L1? " + elem(L1, 2));
    
    writeln("L1 without the second element is");
    write_list(drop_at(L1, 1));
    
    writeln("Does L1 has contiguos elems? " + contiguos(L1));
    
    writeln("L1 without the last element is");
    write_list(init(L1));
    
    writeln("Does L1 is a palindrome? " + palindrome(L1));
    
    writeln("Are L1 and L2 equal? " + equal_list(L1, L2));
    
    writeln("Is L1 ordered? " + ordered(L1));
    
    writeln("Ordered insert 4 into L1 is");
    write_list(ordered_insert(L1, 4));
    
    writeln("The third element of the list is " + nth(L1, 2));
    
    writeln("Change last for the first of L1 is");
    write_list(change_first_last(L1));
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
  
  static List drop_at(List xs, int i) {
    if (i == 0)
      return tail(xs);
    return list(head(xs), drop_at(tail(xs), i - 1));
  }
  
  static List drop(List xs, int i) {
    if (i == 0)
      return xs;
    return drop(tail(xs), i - 1);
  }
  
  static List take(List xs, int i) {
    if (i == 0)
      return null;
    return list(head(xs), take(tail(xs), i - 1));
  }
  
  static List merge(List xs, List ys) {
  	if (empty(xs))
  		return ys;
  	if (empty(ys))
  		return xs;
  	if (head(xs) <= head(ys))
  		return list(head(xs), merge(tail(xs), ys));
  	else
  		return list(head(ys), merge(xs, tail(ys)));
  }
  
  static List merge_sort2(List xs, int n) {
    if (n == 1)
      return xs;
    double half_double = n / 2;
    int half = (int) half_double;
    
    return merge(merge_sort2(take(xs, half), half),
				         merge_sort2(drop(xs, half), n - half));
  }
  
  static List merge_sort(List xs) {
    return merge_sort2(xs, length(xs));
  }
  
  static int last(List xs) {
    if (empty(tail(xs)))
      return head(xs);
    return last(tail(xs));
  }
  
  static boolean elem(List xs, int x) {
  	if (empty(xs))
  		return false;
  	if (head(xs) == x)
  		return true;
  	return elem(tail(xs), x);
  }
  
  static boolean duplicated(List xs) {
    if (empty(xs))
      return false;
    if (elem(tail(xs), head(xs)))
      return true;
    return duplicated(tail(xs));
  }
  
  static List append(List xs, List ys) {
    if (empty(xs))
      return ys;
    return list(head(xs), append(tail(xs), ys));
  }
  
  static List reverse_acc2(List xs, List acc) {
    if (empty(xs))
      return acc;
    return reverse_acc2(tail(xs),
                        append(list(head(xs), null), acc));
  }
  
  static int list_max2(List xs, int curr) {
    if (empty(xs))
      return curr;
    return list_max2(tail(xs), Math.max(head(xs), curr));
  }
  
  static int list_max(List xs) {
    return list_max2(tail(xs), head(xs));
  }
  
  static List reverse_acc(List xs) {
    return reverse_acc2(xs, null);
  }
  
  static boolean contiguos(List xs) {
    if (empty(xs) || empty(tail(xs)))
  		return false;
  	if (head(xs) == head(tail(xs)))
  		return true;
  	return contiguos(tail(xs));
  }
  
  static List init(List xs) {
    if (empty(tail(xs)))
  		return null;
  	
  	return list(head(xs), init(tail(xs)));
  }
  
  static boolean palindrome(List xs) {
    if (empty(xs) || empty(tail(xs)))
		  return true;
  	if (head(xs) != last(xs))
  		return false;
  	return palindrome(init(tail(xs)));
  }
  
  static boolean equal_list(List xs, List ys) {
    if (empty(xs) && empty(ys))
		  return true;
  	if (empty(xs) || empty(ys))
  		return false;
  	if (head(xs) != head(ys))
  		return false;
  	return equal_list(tail(xs), tail(ys));
  }
  
  static boolean ordered(List xs) {
    if (empty(xs) || empty(tail(xs)))
  		return true;
  	if (head(xs) > head(tail(xs)))
  		return false;
  	return ordered(tail(xs));
  }
  
  static List ordered_insert(List xs, int x) {
    if (empty(xs))
  		return list(x, null);
  	if (head(xs) > x)
  		return list(x, xs);
  	return list(head(xs), ordered_insert(tail(xs), x));
  }
  
  static int nth(List xs, int i) {
    if (i == 0)
  		return head(xs);
  	return nth(tail(xs), i - 1);
  }
  
  static List change_first_last(List xs, int first) {
    if (empty(xs))
      return list(first, null);
    return list(head(xs), change_first_last(tail(xs), first));
  }
  
  static List change_first_last(List xs) {
    return change_first_last(tail(xs), head(xs));
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
