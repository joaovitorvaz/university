package pub;

import java.util.Set;
import java.util.SortedSet;
import java.util.ArrayList;

import core.Message;
import core.MessageImpl;
import core.PubSubCommand;

public class NotifyCommand implements PubSubCommand {

    @Override
    public Message execute(Message m, SortedSet<Message> log, Set<String> subscribers, boolean isPrimary, ArrayList<String> backupAddrs,  String primaryServerAddress, int primaryServerPort,  int currentPort) {

        Message response = new MessageImpl();

        response.setContent("Message notified: " + m.getContent());

        response.setType("notify_ack");

        if (!log.contains(m)) {
            log.add(m);
        }

        return response;

    }

}