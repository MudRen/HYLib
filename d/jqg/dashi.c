// dashi.c

inherit ROOM;
#include <ansi.h>

void create()
{
      set("short", HIC"����"NOR);
      set("long", @LONG
��ٲ�����һ����ң�ֻ�����������������������һ����������ǰСС
һ������������һ���ֲ�ľ�������������þ߶��ô�ľ��ɡ�
LONG
        );

      set("exits", ([
	  "west" : __DIR__"xiaoshi",
      ]));

      set("objects", ([
               __DIR__"npc/xln" : 1,
      ]));
	
      setup();
}

void init()
{
      add_action("do_open","kai");
      add_action("do_open","open");
}

int do_open(string arg)
{
      object me,ob;
      me=this_player();
      if (me->is_busy() || me->is_fighting())
           return notify_fail("����æ���ģ�\n");
//      if (!me->query_temp("marks/����")) return 0;
      if ( arg=="chu"){
//       if(!objectp(present("gold key", me)))        
//           return notify_fail("��û��Կ�ף���ʲô������\n");
       if(present("da tiehe", environment(me)))
           return notify_fail("���Ѿ��򿪳����ˡ�\n");
       message_vision("$N������Կ�״��˳��š�\n",me);  
       me->delete_temp("marks/����");
       me->start_busy(1);
       me->set_temp("marks/����", 1);
       ob=new(__DIR__"obj/box");
       ob->move(environment(me));
       write("�㷢�ֳ��ڷ��Ÿ������ε������ӡ�\n");
       return 1;
       }
   return notify_fail("��Ҫ��ʲô��\n");
}
