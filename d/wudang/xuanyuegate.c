//Room: xuanyuegate.c ������
//Date: Sep 22 1997

inherit ROOM;
#include <ansi.h>

void create()
{
      set("short","������");
      set("long",@LONG
�����ǰ��һ����ľ��ï�ĸ�ɽ������ɽ������������Լ�ɼ���һ��ʯ
����ɽ�����죬���ż�������͡�һ������������¥ʽ��ʯ����ɽ��������
�����С������������ĸ����֣�ԭ������������������䵱ɽ���䵱ɽһ��
̫��ɽ��Ϊ��ʮ������֮һ���ж�ʮ�߷塢��ʮ���ҡ���ʮ�Ľ�����̨����
������̶�������š��������һ���أ�����������ɭ�ޣ����ղ��죬������
����
LONG);
      set("objects", ([
           CLASS_D("wudang") +"/zhike": 1,
           CLASS_D("wudang") +"/daotong": 2,
      ]));
      set("outdoors", "wudang");
      set("exits",([ /* sizeof() == 1 */
          "east"     : __DIR__"slxl3",
          "southup"  : __DIR__"shijie1",
      ]));
//      set("no_clean_up", 0);
      setup();
}

void init()
{
        add_action("do_quit","quit");
        add_action("do_quit","halt");
        add_action("do_quit","learn"); 
        add_action("do_quit","xue");
        add_action("do_quit","respirate");
        add_action("do_quit","tuna"); 
        add_action("do_quit","persuade");
        add_action("do_quit","practice");
        add_action("do_quit","lian"); 
        add_action("do_quit","study");
        add_action("do_quit","du");
        add_action("do_quit","teach");
        add_action("do_quit","jiao");
        add_action("do_quit","study");
        add_action("do_quit","yandu");        
        add_action("do_quit","exercise");
        add_action("do_quit","dazuo");
}
int valid_leave(object me, string dir)
{
        if (me->is_fighting()) 
        return notify_fail("���������������!\n");
        if (me->is_busy()) 
        return notify_fail("������������!\n");

        if (me->query_temp("in_guard") &&
                objectp(present("zhike daozhang", environment(me))))
           return notify_fail("֪�͵�����ס��˵��ֵ��ʱ��δ������������ְ�ء�\n");

        me->delete_temp("in_guard"); 
        me->delete("guardwd");
        remove_call_out("clone_meng");

        return ::valid_leave(me, dir);
}

int do_quit(string arg)
{
        write(this_player()->query("name")+"�����ĵ��ػ���\n");
        return 1;
}
