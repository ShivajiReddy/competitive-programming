import java.util.*;
import java.io.File;

public class removeStopWords {

	public static void main(String[] args) {
		// Read the file using whitespace as a delimiter (default)
		// so that the input will be split into words
		//try {
			Scanner file = new Scanner(new File("stop_words_english.txt"));
			
			Set<String> wordSet = new HashSet<>();
			// For each word in the input
			while (file.hasNext()) {
				//add words into Hashset
			    wordSet.add(file.next().trim().toLowerCase());
			}
			
			//string to be searched
			String word = "haven't";
			
			
			if (wordSet.contains(word)) {
				//word is a stopword
			    System.out.println("Yes");
			} else {
				//not a stopword
			    System.out.println("No");
			}
	

		//} 
		//catch(Exception e) {
			//Exception occurred
		//}

		
	}
}