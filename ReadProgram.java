import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class ReadProgram{
    public static void main(String[] args) {
      int linenum=1;
        String fileName="JavaProgram.java";

        try {
            FileReader fileReader = new FileReader(fileName);
            BufferedReader bufferedReader = new BufferedReader(fileReader);
            // while((line = bufferedReader.readLine()) != null){
            //     if(line.startsWith("int") || line.startsWith("void") || line.startsWith("char") || line.startsWith("long")){
            //         if(line.contains("(") && line.contains(")") && line.contains("{")){
            //                 System.out.println(line.split(" ")[1].split("\\(")[0]);
            //         }
            //     }
            // }
            while((line=bufferedReader.readLine())&&(line!=null)){

              if(line.endsWith(";")){
                continue;
              }
              else if(line.contains("if")||line.contains("while")||line.contains("for")){
                  if(line.contains("(")&&(line.endsWith(")")||line.endsWith("{")){
                    continue;
                  }
                }
              }
              System.out.println(line);
              linenum++;
            }
            bufferedReader.close();
        } catch (FileNotFoundException e) {
            System.err.println("File not found!");
            e.printStackTrace();
        } catch (IOException e) {
            System.err.println("IOException caught!");
        }
    }
}
