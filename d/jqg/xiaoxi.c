// By River 99.5.20
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"������"NOR);
        set("long", @LONG
Ϫ��һ·���£���������һ�������ն�ľ��أ���������ɽ�������̧ͷ
���죬ֻ��һ�ߡ�ɽ��ˮ�̣���ɫ�������ģ�ֻ�����¼�����Ϣ������͸����
�գ�Ϫ���оſ��ʯӭ����������������һ�㣬��ס��ȥ·��Ϫ��ͣ��һҶС
��(boat)����������ʱ����֮�ۡ�
LONG
        );

        set("exits", ([
                "northup": __DIR__"glt",
        ]));
        set("item_desc",([
          "boat": "һҶС�ۣ�ͣ��Ϫ�ߵ�ɽʯ֮�ϣ�����Ҫ��(tui)��СϪ����ʹ�á�\n",
        ]));
        set("outdoors", "�����");
        setup();
}

void init()
{
        add_action("do_jump",({"tiao", "jump", "yue"}));
        add_action("do_tui", "tui");
}

int do_tui(string arg)
{
        object me=this_player();
        if( me->is_busy() || me->is_fighting())
             return notify_fail("����æ���ģ�\n");
        if( !arg || arg != "boat") 
             return notify_fail("��Ҫ��ʲô��\n");
        if( arg =="boat"){
          if ( me->query_temp("weapon"))
                 return notify_fail("�����ű�����ô�ƶ�С�ۣ�\n");
          message_vision("$N˫��һʹ����������С������Ϫ�С�\n",me);
          me->start_busy(1);
          me->set_temp("jqg/tui", 1);
          return 1;
        }
}

int do_jump(string arg)
{
        object me = this_player();
        if( me->is_busy() || me->is_fighting())
             return notify_fail("����æ���ģ�\n");
        if( !arg ||(arg != "boat" && arg != "zhou")) 
             return notify_fail("��Ҫ����������\n");
        if( arg =="zhou" || arg=="boat"){
          if (! me->query_temp("jqg/tui"))
                return notify_fail("С�ۻ��ڰ��ϣ�������ȥ���к��ã�\n");
          tell_object(me,"�����˿�����������С����������ȥ��\n");
          tell_room(environment(me), me->name() + "������С����������ȥ��\n", ({ me }));
          me->delete_temp("jqg");
          me->move(__DIR__"boat3");
          tell_room(environment(me), me->name() + "���ȵ�վ����С��֮�ϡ�\n", ({ me }));
          tell_object(me,"�������������ȵ�վ����С��֮�ϡ�\n");
          return 1;
        }
}
