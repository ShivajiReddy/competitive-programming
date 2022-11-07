import java.util.*;

public class practice {
  public static void main(String[] args) {
    HashMap<Integer, String> hmap = new HashMap<> (10);
    hmap.put(10, "Ten");
    hmap.remove(10);
    hmap.putIfAbsent(10, "TEN");
    hmap.putIfAbsent(20, "TWENTY");
    //hmap.put(30, "Thirty");
    System.out.println(hmap.size() + " " + hmap.isEmpty() + " " 
    	+ hmap.get(100) + " " + hmap.get(20));

    if(hmap.get(100) == null) {
      System.out.println("Nullllll");
    }
      
    System.out.println(hmap.get(30));
    for(String i : hmap.values()) {
    	System.out.println(i);
    }
    
    ArrayList<String> strArray = new ArrayList<> ();
    
    strArray.add("Hello ");
    strArray.add("World");
    
    System.out.println(strArray.get(0).toCharArray()[0]);

    String strString = strArray.get(0);

    char chArray[] = strString.toCharArray();

    int intArray[] = new int[10];

    // Strigs //
    String str1 = "Hello World";
    String str2 = "Hello world";
    //System.out.println(String.valueOf("123"));


    int tempArr[] = new int[]{1, 2, 3, 4};
    
    List arrList = Arrays.asList(tempArr);


    arrList.stream().forEach(i -> {System.out.println(i);});


    int n = 123;

    int res = 0;

    while(n > 0) {
      int digit = n%10;
      res = res*10 + digit;
      n = n/10;
    }

    System.out.println("REVERSEEEE:" + res);


  }
}
