// /d/wudang/tandi2.c  ˮ̶��

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIB"ˮ̶��"NOR);
        set("long", @LONG
����ˮ̶̶�ף�̶��ϸɳ��ѩ��̶ˮī����ˮ���̹ǣ��ž�һƬ������ֲ���
LONG                           
        );
        set("objects",([        
                 __DIR__"npc/eyu" : 1,
             ]));
        set("outdoors", "�䵱");
        setup();

}
void init()
{
        add_action("do_qian",({"qian","dive"}));
}

int do_qian(string arg)
{       object me;

        me=this_player();
        if ( !arg || (arg != "down" && arg != "up" ))
            return notify_fail("�����������ˮ��������ȥ!\n");

        if (arg =="down") {
           return notify_fail("���뵱������������ѽ!\n");
          }
        else
          {message_vision("$Nһ���ȣ�������ȥ��\n", me);
           me->receive_damage("jing", 50-(int)me->query_skill("dodge", 1)/20);
           me->move(__DIR__"tandi1");
           tell_room(environment(me), me->name() + "��ˮ��ð��������\n", ({ me }));
           return 1;
          }

     return 1;
}
/*void drop_ob(object obj)
{    
     ::drop_ob(obj);
   if objectp(present(obj, environment(me)))
    { message_vision(HIY"$N����̶��һ��ͱ���ɳ�����ˡ�\n"NOR, obj);
      destruct(obj);
     }
}

void get_ob(object obj)
{    
   object me,ob;
   me=this_player();
   ::get_ob(obj);
   me->start_busy(2);
   if objectp(present("eyu", environment(me)))
    {if (random(3)>2)
      message_vision(HIW"��ɳͻȻһ�󷭶���һ���ײе����㱻�����ˡ�\n"NOR);
      ob=new(__DIR__"eyu");
      ob->kill_ob(me);
     }
}
*/
