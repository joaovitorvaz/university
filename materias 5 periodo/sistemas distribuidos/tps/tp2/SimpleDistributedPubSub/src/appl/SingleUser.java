package appl;

import java.io.Console;
import java.io.IOException;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;
import java.util.Random;
import java.util.Scanner;
import java.lang.Runtime;

import core.Message;

public class SingleUser {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new SingleUser();
	}
	
	public SingleUser(){
		Scanner reader = new Scanner(System.in);  // Reading from System.in

		System.out.print("Enter the User name: ");
		String userName = reader.next();

		// System.out.print("Enter the Broker address: ");
		// String brokerAdd = reader.next();
		
		// System.out.print("Enter the Broker port number: ");
		// int brokerPort = reader.nextInt();
		
		// System.out.print("Enter the User address: ");
		// String userAdd = reader.next();
		
		System.out.print("Enter the User port number: ");
		int userPort = reader.nextInt();

		System.out.println("");
		
		try {
			Thread.sleep(3000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		PubSubClient user = new PubSubClient("localhost", userPort);
		
		user.subscribe("localhost", 8080);
		
		startTP2(user, userName, 8080, "localhost");
	}
	
	private void startTP2 (PubSubClient user, String userName, int brokerPort, String brokerAdd){
		System.out.println("User " + userName + " entered the system!\n");
		Thread sendOneMsg;

		for (int i = 0; i < 10; i++) {
			String selected = "X";
			boolean proceed = false;

			sendOneMsg = new ThreadWrapper(user, userName + ":access:" + selected, brokerAdd, brokerPort);
			sendOneMsg.start();
			
			try{
				sendOneMsg.join();			
			}catch (Exception e){
				e.printStackTrace();
			}

			while(!proceed) {
				List<Message> logUser = user.getLogMessages();	
				proceed = getAcquiresReleasesAndUser(logUser, selected, userName);

				try {
					Thread.sleep(500);
					System.out.println(".");
				} catch (InterruptedException e1) {
					e1.printStackTrace();
				}
			}

			sendOneMsg = new ThreadWrapper(user, userName + ":acquire:" + selected, brokerAdd, brokerPort);
			sendOneMsg.start();
			
			try{
				sendOneMsg.join();			
			}catch (Exception e){
				e.printStackTrace();
			}
			
			System.out.println("The resource " + selected + " is available for you.");
			try {
				int wait = getRandomInteger(1000, 5000);
				Thread.sleep(wait);
				System.out.println("The resource " + selected + " was used for " + wait / 1000 + " seconds.");
			} catch (InterruptedException e1) {
				e1.printStackTrace();
			}

			System.out.println("User Release resource!");
			sendOneMsg = new ThreadWrapper(user, userName + ":release:" + selected, brokerAdd, brokerPort);

			sendOneMsg.start();
			
			try{
				sendOneMsg.join();			
			} catch (Exception e){
				e.printStackTrace();
			}
			
			try {
				int wait = getRandomInteger(1000, 5000);
				System.out.println("Wait " + wait / 1000 + " seconds.");
				Thread.sleep(wait);
			} catch (InterruptedException e1) {
				e1.printStackTrace();
			}
		}
						
		user.unsubscribe(brokerAdd, brokerPort);
		
		user.stopPubSubClient();
		
	}

	private boolean getAcquiresReleasesAndUser(List<Message> logUser, String var, String userName) {
		Iterator<Message> it = logUser.iterator();
		int countAcquires = 0, countRelease = 0;
		while(it.hasNext()) {
			Message aux = it.next();
			String msg = aux.getContent();
			if(msg.contains("acquire:" + var))
				countAcquires++;

			if(msg.contains("release:" + var))
				countRelease++;
		}

		if(countRelease == countAcquires) {
			Iterator<Message> isNow = logUser.iterator();
			while(isNow.hasNext() && countRelease >= 0) {
				Message aux = isNow.next();
				String msg = aux.getContent();

				if(msg.contains("access:" + var)) {
					if(msg.contains(userName) && countRelease == 0)
						return true;

					else
						countRelease--;
				}
			}
		}

		return false;
	}

	public int getRandomInteger(int minimum, int maximum){ 
        return ((int) (Math.random()*(maximum - minimum))) + minimum; 
    }
	
	class ThreadWrapper extends Thread{
		PubSubClient c;
		String msg;
		String host;
		int port;
		
		public ThreadWrapper(PubSubClient c, String msg, String host, int port){
			this.c = c;
			this.msg = msg;
			this.host = host;
			this.port = port;
		}
		public void run(){
			c.publish(msg, host, port);
		}
	}

}
