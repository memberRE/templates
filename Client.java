import java.io.*;
import java.net.Socket;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) {
        try {
            new Client();
        } catch (IOException e) {
            System.out.println("fail to connect to server.");
        }
    }

    public Client() throws IOException {
        Socket socket = new Socket("49.233.212.163", 8080);
        OutputStream outputStream = socket.getOutputStream();
        Scanner scanner = new Scanner(System.in);
        String type = scanner.nextLine();
        outputStream.write(type.getBytes());
        outputStream.flush();
        InputStream inputStream = socket.getInputStream();
        System.out.println("get input");
        byte[] names = new byte[100];
        int len = inputStream.read(names);
        String back = new String(names, 0, len);
        System.out.println(back);
        if (back.equals("NO GPU")) {
            System.out.println("BAD link, no gpu");
        } else {
            ClientThread ct = new ClientThread(socket);
            ct.start();
            byte[] buf = new byte[1024];
            while (true) {
                System.out.println("input file path:");
                String s = scanner.nextLine();
                if (s.equals("STOP")) {
                    outputStream.write(s.getBytes());
                    outputStream.flush();
                    break;
                }
                File file = new File(s);
                if (file.isFile() && file.exists()) {
                    FileInputStream fileIn = new FileInputStream(file);
                    // Get the size
                    int size = fileIn.available();
                    // Get type
                    String[] format = s.split("\\.");
                    String fileType = format[format.length - 1];
                    String head = fileType + ":" + size + ":";
                    buf = head.getBytes();
                    // Give head info
                    outputStream.write(buf);
                    outputStream.flush();
                    while ((size = fileIn.read(buf)) != -1) {
                        outputStream.write(buf, 0, size);
                        //System.out.println(size);
                    }
                    outputStream.flush();
                    System.out.println("Finish upload");
                } else {
                    System.out.println("Not a file");
                }
            }
        }
    }
}

/**
 *   作用：一直接收服务端转发过来的信息
 * */
class ClientThread extends Thread {
    private Socket socket;

    public ClientThread(Socket socket) {
        this.socket = socket;
    }

    public void run() {
        try {
            InputStream inputStream = socket.getInputStream();
            int count = 0;
            while (true) {
                byte[] buf = new byte[1024];
                int len = inputStream.read(buf);
                String head = new String(buf, 0, len);
                System.out.println(head);
                if (head.equals("STOP")) {
                    System.out.println("Stop receive");
                    break;
                }
                String[] formatted = head.split(":");
                String fileName = count + "." + formatted[0];
                File file = new File(fileName);
                FileOutputStream fileOut = new FileOutputStream(file);
                count++;
                int size = Integer.parseInt(formatted[1]);
                /*if (formatted.length >= 3) {
                    len = formatted[2].getBytes().length;
                    size -= len;
                    fileOut.write(formatted[2].getBytes());
                }*/
                int part = -1;
                while ((size > 0) && ((part = inputStream.read(buf)) != -1)) {
                    System.out.println(part + "\t" + size);
                    if (size > part) {
                        fileOut.write(buf, 0, part);
                    } else {
                        fileOut.write(buf,0, size);
                        break;
                    }
                    size -= part;
                }
                fileOut.flush();
                System.out.println("Closing");
                fileOut.close();
                System.out.println("file : " + fileName + " get");
            }
        } catch (IOException e1) {
            e1.printStackTrace();
        }
    }
}
