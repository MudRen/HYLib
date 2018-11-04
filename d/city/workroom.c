// Room: /d/city/workroom.c
//����lywin4/29

#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "��ǮС��");
  set ("long", @LONG
����һ��������Ǯ��С���ӣ�������Ǯ����Ļ���zhaoqian�ɡ�
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"guangchang",
]));
  set("outdoors", "city");

  setup();
}

void init()
{
        add_action("do_zhaoqian", "zhaoqian");
}


int do_zhaoqian()
{
        object me,ob;
        me = this_player();

        if(me->is_busy())
             return notify_fail("��Ҫ̫�ļ�����ǮҲ�������ɣ�\n");

        if(me->query("qi")<10)
             return notify_fail("�㻹������Ϣһ�°ɣ���Ǯ�����ף��ۻ��˲��á���\n");
             me->start_busy(3);
        message_vision("$N��ͷ����Ǯ......\n", me);
        message_vision("$NĪ��������ҵ�Ǯ�ˡ�\n", me);
                me->receive_damage("qi", 10);
                ob=new("/clone/money/silver");
                ob->set_amount(5+random(10));
                ob->move(me); 
                    return 1;
}
