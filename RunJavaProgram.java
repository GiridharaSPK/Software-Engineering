import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.IOException;

public class RunJavaProgram{

    private static final String INPUTFILENAME = "JavaProgram.java";
    private static final String OUTPUTFILENAME = "output.java";

        public static void main(String[] args) {

            File file = new File(OUTPUTFILENAME);
            BufferedReader br = null;
            FileReader fr = null;
            BufferedWriter bw = null;
            FileWriter fw = null;

            try {

                if (!file.exists()) {
                    file.createNewFile();
                }

                fr = new FileReader(INPUTFILENAME);
                br = new BufferedReader(fr);
                fw = new FileWriter(file.getAbsoluteFile(), true);
                bw = new BufferedWriter(fw);

                String sCurrentLine="";
//check all errors
                checkEndCharecter(sCurrentLine);

            } catch (IOException e) {
                e.printStackTrace();
            } finally {
                try {
                    if (br != null)
                        br.close();
                        bw.close();
                    if (fr != null)
                        fr.close();
                        fw.close();
                } catch (IOException ex) {
                    ex.printStackTrace();
                }
            }
        }
public static void checkEndCharecter(String sCurrentLine){

  fr = new FileReader(INPUTFILENAME);
  br = new BufferedReader(fr);
  fw = new FileWriter(file.getAbsoluteFile(), true);
  bw = new BufferedWriter(fw);
  
  while ((sCurrentLine = br.readLine()) != null) {
      if(sCurrentLine.lastIndexOf(";") == sCurrentLine.length()-1 || sCurrentLine.lastIndexOf("{") == sCurrentLine.length()-1 || sCurrentLine.lastIndexOf("}") == sCurrentLine.length()-1){
      }else if(sCurrentLine.charAt(0) == '/'){
          if( sCurrentLine.charAt(1) == '/'){
              System.out.println( sCurrentLine +"\t Comment");
          }else{
              System.out.println(sCurrentLine +"\t Unknown Error");
          }
      }else{
          System.out.println(sCurrentLine +"\tERROR: EndCharecter is not declared.");
      }
      // System.out.println(sCurrentLine);
  }
}

}
