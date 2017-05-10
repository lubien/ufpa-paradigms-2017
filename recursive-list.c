#include <stdio.h>
#include <stdlib.h>

int max(int x, int y) {
	if (x > y)
		return x;
	return y;
}

typedef struct List {
	int head;
	struct List * tail;
} List;

List * list(int x, List * xs) {
 	List * head = malloc(sizeof(List));
 	head->head = x;
 	head->tail = xs;
	return head;
}

int head(List * xs) {
    return xs->head;
}

List * tail(List * xs) {
    return xs->tail;
}

int empty(List * xs) {
	return xs == NULL;
}

int length_tail(List * xs, int count) {
	if (empty(xs))
		return count;
	
	return length_tail(tail(xs), count + 1);
}

int length(List * xs) {
	return length_tail(xs, 0);
}

int sum_tail(List * xs, int count) {
	if (empty(xs))
		return count;
	return sum_tail(tail(xs), count + head(xs));
}

int sum(List * xs) {
	return sum_tail(xs, 0);
}

int last(List * xs) {
	if (empty(tail(xs)))
		return head(xs);
	
	return last(tail(xs));
}

List * init(List * xs) {
	if (empty(tail(xs)))
		return NULL;
	
	return list(head(xs), init(tail(xs)));
}

int elem(int x, List * xs) {
	if (empty(xs))
		return 0;
	if (head(xs) == x)
		return 1;
	return elem(x, tail(xs));
}

int duplicated(List * xs) {
	if (empty(xs))
		return 0;
	if (elem(head(xs), tail(xs)))
		return 1;
	return duplicated(tail(xs));
}

List * reverse(List * xs) {
	if (empty(xs))
		return NULL;
	return list(last(xs), reverse(init(xs)));
}

List * append(List * xs, List * ys) {
	if (empty(xs))
		return ys;
	return list(head(xs), append(tail(xs), ys));
}

List * reverse_acc_tail(List * xs, List * acc) {
	if (empty(xs))
		return acc;
	return reverse_acc_tail(
		tail(xs),
		append(list(head(xs), NULL), acc)
	);
}

List * reverse_acc(List * xs) {
	return reverse_acc_tail(xs, NULL);
}

int max_list_tail(List * xs, int current) {
	if (empty(xs))
		return current;
	return max_list_tail(tail(xs), max(current, head(xs)));
}

int max_list(List * xs) {
	return max_list_tail(xs, 0);
}

int nth(int i, List * xs) {
	if (i == 0)
		return head(xs);
	return nth(i - 1, tail(xs));
}

int drop_index(int i, List * xs) {
	if (i == 0)
		return tail(xs);
	return list(head(xs), drop_index(i - 1, tail(xs)));
}

int contiguos(List * xs) {
	if (empty(xs) || empty(tail(xs)))
		return 0;
	if (head(xs) == head(tail(xs)))
		return 1;
	return contiguos(tail(xs));
}

int palindrome(List * xs) {
	if (empty(xs) || empty(tail(xs)))
		return 1;
	if (head(xs) != last(xs))
		return 0;
	return palindrome(init(tail(xs)));
}

int equal_list(List * xs, List * ys) {
	if (empty(xs) && empty(ys))
		return 1;
	if (empty(xs) || empty(ys))
		return 0;
	if (head(xs) != head(ys))
		return 0;
	return equal_list(tail(xs), tail(ys));
}

void write(char str[]) {
	printf("%s", str);
}

void writeLn(char str[]) {
	write(str);
	printf("\n");
}

void write_list(List * xs) {
    if (empty(xs))
        printf("\n");
    else {
        printf("%d ", head(xs));
        write_list(tail(xs));
    }
}

int main() {
	List * L1 = list(1, list(2, list(3, NULL)));
    List * L2 = list(5, list(6, list(7, NULL)));
    
	write("L1 is ");write_list(L1);
    write("L1 length is ");printf("%d\n", length(L1));
    write("L1 sum is ");printf("%d\n", sum(L1));
    write("L1 last element is ");printf("%d\n", last(L1));
    write("Are there duplicated elements is L1? ");printf("%d\n", duplicated(L1));
    write("L1 reversed WITHOUT accumulator is ");write_list(reverse_acc(L1));
    write("L2 is ");write_list(L2);
	write("Appending L2 to L1 is ");write_list(append(L1,L2));
    write("L1 reversed WITH accumulator is ");write_list(reverse_acc(L1));
    write("The higher element of L1 is ");printf("%d\n", max_list(L1));
    write("The second element of L1 is ");printf("%d\n", nth(1, L1));
    write("L1 without the 2nd element is ");write_list(drop_index(1, L1));
    write("Are there any contiguos elements is L1? ");printf("%d\n", contiguos(L1));
    write("L1 without the last element is ");write_list(init(L1));

	L1 = list(1, list(2, list(1, NULL)));
	L2 = list(1,list(5, list(6, list(7, NULL))));
    write("Is L1 a palindrome? ");printf("%d\n", palindrome(L1));
    write("Is L2 a palindrome? ");printf("%d\n", palindrome(L2));
    write("Are L1 and L1 equal? ");printf("%d\n", equal_list(L1, L1));
    write("Are L1 and L2 equal? ");printf("%d\n", equal_list(L1, L2));
	List * L4 = list(4,list(6,list(3,list(4,list(2,list(6,list(4,NULL)))))));
//	write("Removendo os duplicados de L4: ");
//	write_list(remDupl(L4));write("A lista L1 está ordenada ? "+isOrd(L1));nl();
//	write("Inserindo 4 na lista L2: ");write_list(insOrd(4,L1));nl();
//	write("O 3 elemento da lista L1 é: "+enesimo(3,L1));nl();
//	Lista L1 = list(1, list(2, list(11, null)));
//	write("Merge de L1 e L2");wlist(merge(L1,L2));nl();
//	Lista L4 = list(4,list(6,list(3,list(4,list(2,list(6,list(4,null)))))));
//	write("Merge sort de L4: ");write_list(mergeSort(L4));
}
