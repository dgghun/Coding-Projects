package library.services;

import java.io.*;
import java.net.*;
import common.domain.Login;

/**
 *
 * @author david
 */
public class AuthenticationSvcSocketImpl implements IAuthenticationSvc {

    public boolean authenticate(Login login) throws Exception {
        Socket socket = null;
        ObjectInputStream in = null;
        ObjectOutputStream out = null;
        boolean authenticated = false;

        try {
            socket = new Socket(InetAddress.getLocalHost(), 8000);
            in = new ObjectInputStream(socket.getInputStream());
            out = new ObjectOutputStream(socket.getOutputStream());
            out.writeObject(login);
            authenticated = (boolean) in.readObject();
        } catch (Exception e) {
            // log the error
            System.err.println("AuthenticationSvcSocketImpl:" + e);
        } finally {
            try {
                in.close();
                out.close();
                socket.close();
            } catch (Exception e) {
                System.err.println("AuthenticationSvcSocketImpl: " + e);
            }
        }

        return authenticated;
    } // END of authenticate()
}// END of AuthenticationSvcSocketImpl
