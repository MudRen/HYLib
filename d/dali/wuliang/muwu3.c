// cool 980725
// Modify By River 98/12
//COOL@SJ,9908
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "ʯ����");
        set("long", @LONG
������ʯ�����ˣ����������ģ�ʲôҲ������������ⶼ���ſڵ�һ��
����ʯ��ס�ˣ�ֻ��͸������ʯ����͸���������⣬�������������ӡ�
LONG
        );

        set("item_desc", ([
              "yan" : "һ�����ʯ�����������ƿ�!��\n",
        ]));
        setup();
}

void init()
{   
       object room,ob;
       ob=this_player();
       if( ! ( room = find_object(__DIR__"muwu3")))
         room = load_object(__DIR__"muwu3");
       if(!present("duan yu", room))
       if (interactive(ob)
        && !present("qingnian nanzi", room)
        && ob->query_temp("duanyu/find2")){
         new(__DIR__"npc/dy")->move(room);
         }
       if (userp(ob)) {
	  remove_call_out("close");
          call_out("close", 2, this_object());
          }
	  add_action("do_tui", "tui");
          add_action("do_tui", "push");
}

int do_tui(string arg)
{
       int i;
        i = this_player()->query("neili");
       if( !arg || arg!="yan" ) 
         return notify_fail("��Ҫ��ʲô��\n");
        message_vision("$Nվ���ź󣬰�˫�Ʒ������ϣ����������һ������˫��һ���������һ����������\n", this_player());
       if ( i >=800 ){
        message_vision("$Nֻ��һ����죬��ʯ�������ƿ��ˣ�\n", this_player());
        set("exits/out", __DIR__"muwu2");
        this_player()->add("neili",-800);
        remove_call_out("close");
        call_out("close", 5, this_object());
        }
       else {
        message_vision("$Nȴ����ʯ��˿����������$N��������������\n", this_player());
        this_player()->set("neili",0);
        }
    return 1;
}

void close(object room)
{
      message("vision","��ʯ�����ƶ�����ʯ���ٴη�ס�ˡ�\n", room);
      room->delete("exits/out");
}
