package server.business;

import java.net.*;
import java.util.*;

/**
 *
 * @author david
 */
public class ConnectionMgr {

    ServerSocket server = null;
    Socket socket = null;
    SocketMgr socketMgr;
    Thread thread;
    int maxThreads = 5;                             
    List<Thread> threadList = new ArrayList<>();

    
    /**
     * Prints the status of threads created (debugging)
     * @param threadList 
     */
    public void checkThreads(List<Thread> threadList) {

        System.out.println(" THREAD CHECK:");
        for (Thread t : threadList) {
            if (t.isAlive()) {
                System.out.println("\t*" + t.getName() + " is running.");
            } else {
                System.out.println("\t*" + t.getName() + " is no longer running.");
            }
        }
        System.out.println("\f");

    }

    public void listen() {
        try {
            server = new ServerSocket(8000, 100);
            while (maxThreads > 0) {
                socket = server.accept();           // accept next connection request
                socketMgr = new SocketMgr(socket);
                thread = new Thread(socketMgr);
                thread.start();
                maxThreads--;
                threadList.add(thread);
                checkThreads(threadList);
            }

        } catch (Exception e) {
            System.err.println("ConnectionMgr catch: " + e);
        } finally {
            try {
                thread.join();                  // wait for threads to finish
                checkThreads(threadList);
                server.close();
            } catch (Exception e) {
                System.err.println("ConnectionMgr finally: " + e);
            }
        }

    }// END of listen()

    
    
    /**
     * Run server
     *
     * @param args
     */
    public static void main(String[] args) {
        ConnectionMgr connectionMgr = new ConnectionMgr();
        connectionMgr.listen();
    }

}
