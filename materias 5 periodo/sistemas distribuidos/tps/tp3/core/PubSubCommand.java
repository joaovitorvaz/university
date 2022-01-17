package core;

import java.util.Set;
import java.util.SortedSet;
import java.util.ArrayList;

public interface PubSubCommand {

    public Message execute(Message m, SortedSet<Message> log, Set<String> subscribers, boolean isPrimary, ArrayList<String> brokers,  String primaryServerAddress, int primaryServerPort, int currentPort);

}
