package core;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Set;
import java.util.SortedSet;
import java.util.TreeSet;
import java.util.concurrent.CopyOnWriteArrayList;
import java.util.logging.*;

// The useful socket consumer
public class PubSubConsumer<S extends Socket> extends GenericConsumer<S> {

    private int uniqueLogId;
    private SortedSet<Message> log;
    private Set<String> subscribers;
    private boolean isPrimary;
    
    private ArrayList<String> brokers;
    private String primaryServer;
    private int primaryPort;

    public PubSubConsumer(GenericResource<S> re, boolean isPrimary, ArrayList<String> list, String primaryServer, int primaryPort) {
        super(re);
        this.uniqueLogId = 1;
        this.log = new TreeSet<Message>(new MessageComparator());
        this.subscribers = new TreeSet<String>();
        this.isPrimary   = isPrimary;

        this.brokers       = list;
        this.primaryServer = primaryServer;
        this.primaryPort   = primaryPort;
    }

    @Override
    protected void doSomething(S str) {

        try {
            ObjectInputStream in = new ObjectInputStream(str.getInputStream());
            Message msg = (Message) in.readObject();
            Message response = null;
            
            if (msg.getType().equals("electNewPrimary")){
                String addr = str.getLocalAddress().toString();
                addr = addr.equals("/127.0.0.1") == true ? "localhost" : addr;

                if(msg.getContent().split(":")[0] != addr &&  Integer.parseInt(msg.getContent().split(":")[1]) != str.getLocalPort()){
                    this.primaryServer = msg.getContent().split(":")[0];
                    this.primaryPort =  Integer.parseInt(msg.getContent().split(":")[1]);
                    this.isPrimary = false;
                
                } else{
                    this.primaryServer = msg.getContent().split(":")[0];
                    this.primaryPort = Integer.parseInt(msg.getContent().split(":")[1]);
                    this.isPrimary = true;
                }

                response = new MessageImpl();
                response.setType("syncNewPrimary");
                response.setContent("Successful Election");

            } else if (msg.getType().equals("syncPolling")){
                /**
                 * Ideia: Envia mensagem do tipo: addrInvoker:portInvoker-addressElectionHost:ipElectionHost-randomNum-addrMinRandom:portMinRandom-PositionInList
                 * O host da eleição irá processar as informações do menor número, addr:port e PositionInList e após fim de eleição,
                 * Faz um broadcast para todos que participaram da eleição dizendo quem é o novo primário.
                 * 
                 * Temporário para teste: Chama uma função de eleição que vai sortear um broker da lista de brokers tirando o atual primário
                 * Tentará comunicar o novo primário que é primário (no invoker), e caso consiga, o primário envia uma mensagem de sync de novo primário
                 * para os brokers da lista. Caso não consiga, o invoker chama a função recursivamente de sortear novamente.
                */
                do {
                    Collections.shuffle(this.brokers);
                } while (this.brokers.get(0).equals(this.primaryServer + ":" + this.primaryPort));

                this.primaryServer = this.brokers.get(0).split(":")[0];
                this.primaryPort = Integer.parseInt(this.brokers.get(0).split(":")[1]);

                response = new MessageImpl();
                response.setType("primarySynced");
                response.setContent(this.primaryServer + ":" + this.primaryPort);

            }else if (msg.getType().equals("syncConnection")){
                /**
                 * This message returns the list of brokers on cluster, both up and down.
                 * In case the list is returned by a backup broker, a warning is thrown into the console.
                 * However, the way it is implemented in appl.Broker, the warning can be ignored once the
                 * cluster address:port list is created beforehand.
                */
                response = new MessageImpl();
                response.setType("responseBackupList");
                response.setContent(String.join("-", this.brokers));
                
                if (!this.isPrimary){
                    // Create a Logger
                    Logger logger = Logger.getLogger(PubSubConsumer.class.getName());

                    // Set Logger level
                    logger.setLevel(Level.WARNING);

                    // Call warning method
                    logger.warning("Client connected to a backup - Backup list might not be updated");
                }

            // Pegando o endereço e porta do broker primário e enviando eles como respostas caso o broker seja secundário
            } else if (!isPrimary && !msg.getType().startsWith("sync")) {
                response = new MessageImpl();
                response.setType("backup");
                response.setContent(this.primaryServer + ":" + this.primaryPort); 

            } else { // Else utilizado para o tratamento de ações de sub, unsub, publish e notify em brokers primários
                if (!msg.getType().equals("notify") && !msg.getType().startsWith("sync"))
                    msg.setLogId(uniqueLogId);
               
                response = commands.get(msg.getType()).execute(msg, log, subscribers, isPrimary, this.brokers, this.primaryServer, this.primaryPort, str.getLocalPort());

                if (!msg.getType().equals("notify"))
                    uniqueLogId = msg.getLogId();
            }

            ObjectOutputStream out = new ObjectOutputStream(str.getOutputStream());
            out.writeObject(response);
            out.flush();
            out.close();
            in.close();
            str.close();

        } catch (Exception e) {
            try {
                str.close();
            } catch (IOException e1) {
                e1.printStackTrace();
            }
        }

    }
    
    public String getPrimaryAddress(){
        return this.primaryServer;
    }

    public int getPrimaryPort(){
        return this.primaryPort;
    }

    public Boolean getIsPrimary(){
        return this.isPrimary;
    }

    public ArrayList<String> getBrokersList(){
        return this.brokers;
    }

    public List<Message> getMessages() {
        CopyOnWriteArrayList<Message> logCopy = new CopyOnWriteArrayList<Message>();
        logCopy.addAll(log);

        return logCopy;
    }

}
