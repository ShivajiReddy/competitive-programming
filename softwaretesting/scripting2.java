import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class scripting2 {
  public static void main(String[] args) throws Exception{
    
    String cmd = "ls";
    Runtime run = Runtime.getRuntime();
    Process pr = run.exec(cmd);
    pr.waitFor();
    BufferedReader buf = new BufferedReader(new InputStreamReader(pr.getInputStream()));
    String line = "";
    while ((line=buf.readLine())!=null) {
      System.out.println(line);
    }

  }
}