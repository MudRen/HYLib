// /d/wudang/shuitan.c  ˮ̶

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIB"ˮ̶"NOR);
        set("long", @LONG
����һ����ˮ̶��̶ˮ�峺��ˮ���̹ǣ�������ʲô������ҧ��Ľ�ֺ��
���ǸϿ����ϰ��ɡ�
LONG                           
        );
	set("outdoors", "�䵱");
        set("objects",([        
               __DIR__"obj/lxshi":1,
        ]));
        setup();

}
void init()
{
        add_action("do_pa","pa");
        add_action("do_qian",({"qian","dive"}));
}


int do_pa(string arg)
{       object me;
        me=this_player();
        if ( !arg || arg != "up" )
            return notify_fail("���ù���ʽ��ˮ��������ȥ!\n");
        if (present("lianxin shi", me))
            return notify_fail("�㸺��̫�أ��޷����ϰ�!\n");

         message_vision("$N����ʪ͸���������Ƶ������˰���\n", me);
         me->move(__DIR__"shibapan");
     return 1;
}

int do_qian(string arg)
{       object me,tmp;
        object *ob;
        int i;
        me=this_player();
        if ( !arg || (arg != "down"))
            return notify_fail("�����������ˮ��������ȥ!\n");

        if (arg =="down") {
           if (! present("lianxin shi", me))
              return notify_fail("�����������������޷���Ǳ!\n");
          message_vision("$Nһ�����ԣ�Ǳ����ȥ��\n", me);
          me->receive_damage("jing", 60-(int)me->query_skill("dodge", 1)/20);
          me->move(__DIR__"tandi1");
//          me->apply_condition("diving",1);
          tell_room(environment(me), me->name() + "������Ǳ��������\n", ({ me }));
          return 1;
          }

     return 1;
}
/*void drop_ob(object obj)
{    drop_ob(obj);
  if objectp(present(obj, environment(me)))
    { message_vision(HIY"$N������̶�׳�ȥ��\n"NOR, obj);
      destruct(obj);
    }
}
*/
