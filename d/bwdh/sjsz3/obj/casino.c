//Cracked by Kafei
// casino tool for casino in sjsz
// Apache 10/98

inherit ITEM;

void create() {
    set_name("��̨", ({ "casino table" }));
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "���Ŷ�̨�ǿ��ƶĳ��ģ�\nCommands:\n  casino east n\n  casino west n \n
  casino bet \n  casino pay \n  casino stop \n");
        set("material", "steel");
        set("weight", 5000);
        set("value", 10000000);
        set("no_get", 1);
    }
    setup();
}

void init() {
    add_action("casino_cmds", "casino");
}

int casino_cmds(string arg) {
    object me = this_player();
    object room;
    string cmd, temp;
    int args, ratio, round;
    

    if (!wizardp(me))
        return 0;
    if (!arg)
        return notify_fail("ָ����󣡣��޲�����\n");

    args = sscanf(arg, "%s %d", cmd, ratio);
    if (args != 2)
        args = sscanf(arg, "%s", cmd);
    room =  find_object("/d/bwdh/sjsz/gamble_room");
    if (!objectp(room)) {
        room = load_object("/d/bwdh/sjsz/gamble_room");
        if (!objectp(room))
            return notify_fail("�Ҳ����ĳ���\n");
    }

    if (args == 1) {
        switch (cmd) {
        case "bet" :  if ( room->query("status") == 1)
                          return notify_fail("�ĳ��������ڽ���ѹע��\n");
                      else {
                          round = room->query("round");
                          round++;
                          room->set("round", round);
                          temp = "��" + chinese_number(round) + "��";
                          room->set("status", 1);
                          message_vision("$N��һ������" + temp + "�����ģ���\n", me);
                          return 1;
                      }
                      break;
        case "pay" :  if ( room->query("status") == -1)
                          return notify_fail("�������أ�\n");
                      else {
                          room->set("status", -1);
                          message_vision("$N��ɥ�������������ˣ���Ҫ���ˡ���\n", me);
                          return 1;
                      }
                      break;
        case "stop":  if (room->query("status") == 0)
                          return notify_fail("�ĳ��Ѿ���������\n");
                      else {
                          room->set("status", 0);
                          message_vision("$N�ر��˶ĳ���\n", me);
                          return 1;
                      }
                      break;
        default : return notify_fail("ָ����󣡣���������\n");
                  break;
        }
    }

    if (args == 2) {
         if (room->query("status") != 0)
             return notify_fail("���ȹرնĳ���\n");
         if (ratio > 0)
             temp = chinese_number(ratio) + "��һ";
         else if (ratio < 0)
             temp = "һ��" + chinese_number(-ratio);

         switch (cmd) {
         case "east" : if (ratio != 0) {
                           room->set("east", ratio);
                           message_vision("$N�趨��������Ϊ" + temp +"��\n", me);
                           return 1;
                       }
                       else {
                           room->set("win", "east");
                           message_vision("$N�ж�����ʤ��\n", me);
                           return 1;
                       }
                       return 1;
         case "west" : if (ratio != 0) {
                           room->set("west", ratio);
                           message_vision("$N�趨��������Ϊ" + temp +"��\n", me);
                           return 1;
                       }
                       else {
                           room->set("win", "east");
                           message_vision("$N�ж�����ʤ��\n", me);
                           return 1;
                       }
                       return 1;
         default : return notify_fail("ָ����󣡣�˫������\n");
                   break;
         }
    }  

    return notify_fail("ָ�����\n");
}
