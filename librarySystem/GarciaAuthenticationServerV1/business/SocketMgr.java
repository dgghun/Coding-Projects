package server.business;

import java.io.*;
import java.net.*;
import common.domain.Login;

/**
 *
 * @author david
 */
public class SocketMgr implements Runnable {

    private Socket clientSocket;
    private final String NAME = "xxxx";
    private final String PASSWORD = "xxxx";
    private boolean authenticated;
    private ObjectOutputStream out;
    private ObjectInputStream in;

    public SocketMgr(Socket clientSocket) {
        this.clientSocket = clientSocket;
        authenticated = false;
    }

    @Override
    public void run() {
        try {
            // Get an input stream and output stream for reading/writing data from/to the client
            out = new ObjectOutputStream(clientSocket.getOutputStream());
            in = new ObjectInputStream(clientSocket.getInputStream());
            Login login = (Login) in.readObject();      // read login object

            // check userName/password
            if (login.getUserName().equals(NAME) && login.getUserPassword().equals(PASSWORD)) {
                authenticated = true;
            } else {
                authenticated = false;
            }
            out.writeObject(authenticated);             // send(write) boolean object
            in.close();
            out.close();
            clientSocket.close();
            Thread.sleep(2000);                        // pause thread to keep running (debugging)
        } catch (Exception e) {
            System.err.println("SocketMgr: " + e);
        }
    }// END of run()

}
