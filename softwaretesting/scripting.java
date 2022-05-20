import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class scripting {
  public static void main(String[] args) {
    Process p;
    try {
      List < String > cmdList = new ArrayList < String > ();
      // adding command and args to the list
      cmdList.add("bash");
      cmdList.add("/Users/shivaji/Desktop/testscript.sh");
      cmdList.add("shivaji");
      ProcessBuilder pb = new ProcessBuilder(cmdList);
      p = pb.start();

      p.waitFor();
      BufferedReader reader = new BufferedReader(new InputStreamReader(
        p.getInputStream()));
      String line;
      while ((line = reader.readLine()) != null) {
        System.out.println(line);
      }
    } catch (IOException e) {
      // TODO Auto-generated catch block
      e.printStackTrace();
    } catch (InterruptedException e) {
      // TODO Auto-generated catch block
      e.printStackTrace();
    }

  }
}