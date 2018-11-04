// Room: /u/xdd/gumu/gmlg4.c
// by shang and xdd  97/6
// Modify By River 98/08/30
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
     set("short", HIC"ʯ��"NOR);
     set("long", @LONG
��ʯ�ұ�֮��ǰ׽��ȸ��ʯ�ҳ�����Լ����һ��������������ֻ��ȸ���ڡ�
�ط���������࣬��׽��ȸ��ȻԶΪ���ѡ�ʯ���ܱգ�ǽ����ֻ����յ�����
ʯ�ҵƻ�ͨ����
LONG
        );

     set("exits", ([
         "north" : __DIR__"gmlg3",          
         "south" : __DIR__"gmlg5",          
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
          int i;
          if (!living(me)) return 0;
          if (!(fam = me->query("family")) || fam["family_name"] != "��Ĺ��")
           return notify_fail("�㲻�ǹ�Ĺ���ˣ�����������Ĺ�书��\n");
          if ( arg == "maque") {
          if ((int)me->query_skill("dodge",1 ) < 50)
            return notify_fail("���Ṧ��̫�ͣ�׽��ס��ô����ȸ�ġ�\n");
          if ( (int)me->query_skill("dodge", 1) > 101 )
            return notify_fail("�㲻���������˷�ʱ�侫���ˡ�\n");  
          if ( (int)me->query("jing") < 30 )
            return notify_fail("��̫����, ����Ϣһ�¡�\n");
//          if ( me->query("potential") > me->query("max_pot"))   
//             me->set("potential", me->query("max_pot"));   
          i = me->query_skill("dodge", 1) / 10;
          me->receive_damage("jing", 10 + random(15));
          me->receive_damage("jing", 10 + random(15));
          if ( random(i) > 2 ) {
                 write("�������������۵���ͷ�󺹣���˵׽��������ëҲ������һ����\n");
                 }
          else {
                 write("���۵���ͷ�󺹣����ץ������ȸ��\n");
                 me->improve_skill("dodge", (int)(me->query_int()/2) + (int)(me->query_int()/2) );
                 if (me->query("combat_exp") < 100000) {
                 me->add("potential", random(2));
//               me->add("combat_exp", random(5));
                 return 1;
                 }
               }
          return 1;
          }
       return notify_fail("��Ҫ׽ʲô��\n");       
}

