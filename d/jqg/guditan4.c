// guditan4.c

inherit ROOM;
#include <ansi.h>
void create()
{
     set("short", HIC"�ȵ�ˮ̶"NOR);
     set("long", @LONG
���������������ڵ�����ˮ̶�ײ���ˮ̶���ܲ������Ķ�������������
��ͷ�����Ϸ�(zuoshang)��Լ͸�Ź�����ˮ�к������ˣ�����̹Ǳ���ʹ���
�����󵶹�һ������ʹ���˴��������ɶ�������ǸϿ��뿪�ɡ�
LONG
        );
     set("item_desc", ([
        "zuoshang": HIC"�㶨�����ƣ��������ƺ���һ��б�ϵ�ˮ����\n"NOR,
     ]));
     set("outdoors", "�����");    
     setup();
 
}

void init()
{
       object me;
       me=this_player();
       add_action("do_qian","qian");
//       if ((int)me->query("jing", 1) < 0||(int)me->query("qi", 1) < 0){
//         me->set_temp("last_damage_from","��ˮ̶�б���");
//         me->unconcious();
//         me->die();
//         return;
//        }       
}

int do_qian(string arg)
{
	object me;
       	me=this_player();
       	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
       	if ( !arg || (arg != "zuoshang" && arg != "up") )
       		return notify_fail("��Ҫ������Ǳ��\n");
       	if (arg =="zuoshang"){
           if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 40) 
		return notify_fail("�����ӳ��أ��þ�ȫ��Ҳ�޷���������ȥ��\n");
          message_vision(YEL"$N��������һ�ţ������Ϸ���ȥ��\n"NOR, me);
          me->receive_damage("jing", 200);
	  me->receive_damage("qi", 200);
       	  me->move(__DIR__"tongdao");
          me->start_busy(1);
       	  tell_room(environment(me), me->name() + "��б�·���Ǳ��������\n", ({ me }));
          message_vision (HIB"$Nֻ����ͷ���εģ�������ڱ����ˮ�У���ס�Ĳ�����\n"NOR,me);
          return 1;
       	  }
       	else {
          if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 40) 
	    return notify_fail("�����ӳ��أ��þ�ȫ��Ҳ�޷�Ǳ������!\n");
          message_vision(YEL"$N��������һ�ţ������渡ȥ��\n"NOR, me);
          me->receive_damage("jing", 200);
          me->receive_damage("qi", 200);
          me->move(__DIR__"guditan3");
          me->start_busy(1);
          tell_room(environment(me), me->name() + "������Ǳ��������\n", ({ me }));
          message_vision (HIB"$Nֻ����ͷ���εģ�������ڱ����ˮ�У���ס�Ĳ�����\n"NOR,me);
          return 1;
	  } 
     return 1;
}
 