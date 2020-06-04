public class Main {

    public static void main(String[] args) {
        Algorithms alg = new Algorithms();
        int a = alg.sequentialSearch(33);
        int b = alg.binarySearch(33);
        int c = alg.interpolationSearch(33);

        if (a==b && b==c)
            System.out.println("Element is found at index: " + a);
        else System.out.println("Element is not found!");


    }
}


