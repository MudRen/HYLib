// gmlg5.c By River 98/08/30
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
     set("short", HIC"ʯ��"NOR);
     set("long", @LONG
��ʯ�ұ�֮��ǰ׽��ȸ��ʯ�ҳ�����Լ����һ�����������ж�ֻ��ȸ���ڡ�
�ط���������࣬��׽��ȸ��ȻԶΪ���ѡ�ʯ���ܱգ�ǽ����ֻ����յ�����
ʯ�ҵƻ�ͨ����
LONG
        );

     set("exits", ([        
         "north" : __DIR__"gmlg4",
     ]));

     setup();
}

void init()
{
     add_action("do_zhuo", "zhuo");
}

int do_zhuo(string arg)
{
          mapping fam;
          object me = this_player();          
          if (!living(me)) return 0;
          if (!(fam = me->query("family")) || fam["family_name"] != "��Ĺ��")
           return notify_fail("�㲻�ǹ�Ĺ���ˣ�����������Ĺ�书��\n");
          if ( arg == "maque") {
          if ( me->query("gender")=="Ů��")
            return notify_fail("��ĹŮ���ӿ���ȥ������Ůȭ����\n");
          if ((int)me->query_skill("dodge",1 ) < 20)
            return notify_fail("���Ṧ��̫�ͣ�׽��ס��ô����ȸ�ġ�\n");
          if ((int)me->query_skill("strike", 1) < 20)
            return notify_fail("��Ļ����Ʒ���������죬����ץ��ס��ȸ��\n");
          if ((int)me->query_skill("tianluo-diwang", 1) > 10)
            return notify_fail("���Ѿ�ѧ�����޵������ˣ��Լ��úô�Ħ�ɡ�\n");
          if ( (int)me->query("jing") < 30 )
            return notify_fail("��̫����, ����Ϣһ�¡�\n");
          write("��˫����ߵ����Ǳ��ģ���ȸ������������ǰ����֮�ڡ�\n");         
          me->receive_damage("jing", 5);
          me->receive_damage("jing",15);
          me->improve_skill("tianluo-diwang", 2);
          return 1;
          }
   return notify_fail("��Ҫ׽ʲô��\n");       
}
