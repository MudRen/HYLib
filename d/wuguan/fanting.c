#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������������ò͵ĵط������ﲼ�úܼ�, ֻ���ż�������
��������һ������س��š�һ�������ڲ�ͣ��æµ�ţ����������
Ҫʳ���ˮ��
LONG);
        set("exits", ([
                "east" :"/d/wuguan/shilu-4",
        ]));

        set("objects", ([
//           __DIR__"npc/wang" : 1,
           __DIR__"npc/xiaost" : 1,
        ]));       
        set("no_fight", 1);
        setup();
}
int valid_leave(object me, string dir)
{
        int i;
	object *ob;
        ob = deep_inventory(me);
	i = sizeof(ob);
	    
        if ((dir == "east") && present("wang chuzi", environment(me)) ){
           if(present("tea", environment(me)))
              return notify_fail("��������ס������㻹���ȰѲ�������߰ɡ�\n"); 
           while (i--) 
              if (ob[i]->query("food_remaining")) {
                  switch ( random(2) ){
                      case 0: return notify_fail("�����Ӳ����˵�������ס����˵�������ȰѶ������������߰ɡ�\n"); break;
                      case 1: return notify_fail("��������ס�������ʳ���ô���������\n"); break;
                      }
                  }
           }
       return ::valid_leave(me, dir);
}
