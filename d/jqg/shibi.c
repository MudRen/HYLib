// shibi.c ʯ��
// By River 99.5.25
inherit ROOM;
#include <room.h>
#include <ansi.h>
void create()
{
       set("short","ʯ��");
       set("long",@LONG
��ԼĪ��������ʮ�ɣ������Ṧ׿����һ·����Ϊ�ģ��������붴Ѩ�߰�
��ʱ��ʯ�ڲ����⻬�쳣�����޿�������֮��������������б�������Ǳڻ���
��Ӭ�����ܸ��ڲ��䡣
LONG
);
       set("no_sleep_room", 1);
       set("no_fight", 1);
       setup();
}

void init()
{
       add_action("do_shuai","shuai");
       add_action("do_pa",({"pa", "climb"}));
}

int do_shuai(string arg)
{
       object ob1,me;
       me=this_player();
       if ( !arg || arg !="shugan") return 0;
       if ( me->is_busy() || me->is_fighting())
            return notify_fail("����æ����\n");
       if (me->query_temp("jqg/shuai"))
            return notify_fail("���Ѿ�������ˤ����Ѩ�ˡ�\n");
       if (!ob1=(present("zao shugan",me)))
            return notify_fail("����ʲô����ˤ����\n");
       if (!me->query_temp("jqg/fu") || !ob1->query("jqg/fu"))
            return notify_fail("�������������ˤ��ȥ�к��ã�\n");
       me->start_busy(2);
       destruct(ob1);
       me->set_temp("jqg/shuai", 1);
       message_vision("$N˫��ʹ��ǧ��׹��������̤��ʯ��֮�ϣ�˫���˾���������ˤ����Ѩ��\n",me);
       tell_object(me,"��һ�¾���ʹ��ǡ���ô�����������ʱ���ú���ڶ�Ѩ���ϡ�\n");
       return 1;
}

int do_pa(string arg)
{
       object me,*ob;
       int i;
       me=this_player();
       if ( !arg || (arg != "down" && arg != "up")) return 0;
       if ( me->is_busy() || me->is_fighting())
             return notify_fail("����æ����\n");
       if ( arg =="up"){
       if (!me->query_temp("jqg/shuai"))
             return notify_fail("ʯ�ڹ⻬�쳣���޿�������֮���������Ǳڻ�����Ӭ�����ܸ��ڲ��䡣\n");
       ob = deep_inventory(me);
       i = sizeof(ob);
       while (i--)
       if (ob[i]->is_character())
             return notify_fail("�����ϱ���һ���ˣ��޷���������ȥ��\n");
       message_vision("$N˫��ץ�����������������������ø����ˣ���һ�����Ȼ������Ѩ��\n",me);
       me->delete_temp("jqg");
       me->move(__DIR__"shanlu6");
       tell_room(environment(me), me->name() + "�������"HIW"ʯ��"NOR"����������\n",me);
       return 1;
       }
       if ( arg == "down"){
       if (me->query_temp("jqg/shuai"))
             return notify_fail("���Ѿ������ɶ�ˤ��ȥ�ˣ������������ȥ��\n");
       ob = deep_inventory(me);
       i = sizeof(ob);
       while (i--)
       if (ob[i]->is_character())
             return notify_fail("�����ϱ���һ���ˣ��޷���������ȥ��\n");
       message_vision("$N�쿴�������ƣ�ͷ����Ѩ����������ɳ�������࣬������ʯ��֮�ס�\n",me);
       me->move(__DIR__"shiyao");
       tell_room(environment(me), me->name() + "�������ʯ������������\n",me);
       return 1;
       }
}
