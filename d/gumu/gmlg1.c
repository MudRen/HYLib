// Room: /u/xdd/gumu/gmlg1.c
// by shang and xdd  97/6
// Modify By River 98/08/29
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
       set("short", HIC"ʯ��"NOR);
       set("long", @LONG
����һ���ܱյ�ʯ�ң����е��ŵƻ�ʯ����С������һ����ת���˴���
��Ĺ�������������书�����޵����ơ���������ֻ��ȸ��
LONG        );

       set("exits", ([
            "north" : __DIR__"liangong",
            "south" : __DIR__"gmlg2",
       ]));

//       create_door("north", "ʯ��", "south", DOOR_CLOSED);
       
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
          if ( (int)me->query_skill("dodge", 1) > 51 )
            return notify_fail("�㲻���������˷�ʱ�侫���ˡ�\n");
          if ( (int)me->query("jing") < 20 )
            return notify_fail("��̫����, ����Ϣһ�¡�\n");
//          if ( me->query("potential") > me->query("max_pot"))   
//             me->set("potential", me->query("max_pot"));   
          i = me->query_skill("dodge", 1) / 5;
          me->receive_damage("jing", 5 + random(10));
          me->receive_damage("jing", 5 + random(10));
          if ( random(i) > 2 ) {
                 write("�������������۵���ͷ�󺹣���˵׽��������ëҲ������һ����\n");
                 }
          else {
                 write("���۵���ͷ�󺹣����ץ������ȸ��\n");
                 me->improve_skill("dodge", (int)(me->query_int()/2) +
                            (int)(me->query_int()/2) );
                 if(me->query("combat_exp") < 100000){
                 me->add("potential", random(2));
//               me->add("combat_exp", random(5));
                 return 1;
                 }
               }
          return 1;
          }
        return notify_fail("��Ҫ׽ʲô��\n");
}

