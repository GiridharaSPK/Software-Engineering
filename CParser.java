import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class CParser {
    public static void main(String[] args) {

        System.out.println("Enter the name of the C file in folder SE to fetch the functions in them: ");
        Scanner sc = new Scanner(System.in);
        String fileName= sc.nextLine();

        //Change location of file here
        // String fileName = "/home/giridhar_cs/Desktop/SE/C1E23.c";

        String line;
        System.out.println("The functions in the C file are:");
        try {
            FileReader fileReader = new FileReader(fileName);
            BufferedReader bufferedReader = new BufferedReader(fileReader);
            while((line = bufferedReader.readLine()) != null){
                if(line.startsWith("int") || line.startsWith("void") || line.startsWith("char") || line.startsWith("long")){
                    if(line.contains("(") && line.contains(")") && line.contains("{")){
                            System.out.println(line.split(" ")[1].split("\\(")[0]);
                    }
                }
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
