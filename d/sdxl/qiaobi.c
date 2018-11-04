// by dubei

#include <ansi.h>
#include <room.h>

inherit ROOM;

string shitai(object);

void create()
{
    set("short", BLU "�ͱ�"NOR);
    set("long", @LONG
���ͱڱ���һ����������磬��������ͱ��в����Լ��ʮ����
��������һ�������ɼ����Ĵ�ʯ������һ��ƽ̨��ʯ�������̵����֡�
�߽��ͱڣ�����ʯ�ڲ�ľ��������ͺͺ��ʵ�޿�������֮������֪����
���������Ԯ��ȥ����������
LONG
    );

    set("outdoors", "xiangyang");
    set("item_desc", ([
        "shitai" : (: shitai :),
        "zi" : HIW "��  ڣ" NOR,
    ]));

    set("exits", ([
        "south" : __DIR__"donghou",
    ]));

    setup();
}

string shitai(object me)
{

    me->add_temp("temp/kan3", 1);

    if(me->query_temp("temp/kan3")<5)
    {
        return
"�����˰��죬Խ��Խ�������������������ˣ������������ĸߴ�����\n"
"���ض���������������ƾ���书Ӳ����ȥ����ֱ�Ƿ�����˼�ˡ�\n";
    }

    me->set_temp("temp/pa", 1);
    me->delete_temp("temp/kan3");
    return
"����������һ��ͻ���ͱ���ÿ�����߱�����һ����̦����ʮ�Ա�ֱ����\n"
"���ϡ�������һ��������Ծ��̽�ֵ����һ����̦����ȥ��ץ��һ�Ѻ�\n"
"�࣬��Ȼ�Ǹ�СС��Ѩ�������Ƕ�����ܵ��������������䣬�����վã�\n"
"���л��࣬���������̦��\n";

}

void init()
{
        add_action("do_climb", "climb");
//        add_action("do_pa", "pa");
}

int do_climb(string arg)
{
    object me = this_player();
    int dex = me->query("dex");
    int str = me->query("str");

    if((!arg) || (arg != "shitai"))
        return notify_fail("��Ҫ��������ȥ��\n");

    if(me->query_temp("temp/pa")<1)
        return notify_fail("���ĸߴ�����������Ӳ����ȥ����ֱ�Ƿ�����˼�ˡ�\n");

    message_vision(GRN"$N��һ����������ʯ���ϵĶ�Ѩ��������ƽ̨����ȥ��\n", me);

    if( (dex < 27) && (str < 27) && (random(2)) )
    {
        message_vision(HIR"$N����һ�ᣬ�����㷦����ֻ�÷���Ծ�¡�\n"NOR, me);
        return 0;
    }

    if( (dex > 27) && (str < 27) && (random(3)) )
    {
        message_vision(HIY"$N��������ۿ��쵽��ͷ��ͻȻ��һ�ɣ����������������������ǲ�����\n"NOR, me);
	return 0;
    }

    if ( (dex < 27) && (str > 27) && (random(2)) )
    {
        message_vision(HIY"$N��������ۿ��쵽��ͷ��ͻȻ����һ����µµ����ɽ������һ���ˡ�\n", me);
        me->receive_wound("qi", 30, me);
        me->receive_damage("qi", 40, me);
        return 0;
    }

    message_vision(GRN"$N�������ת�۾͵����ͱڵľ�ͷ������һԾ���ѵ���ƽ̨���ء�\n", me);
    me->move(__DIR__"pingtai");
    message("vision", me->name() + "���ͱ�������������\n", environment(me), ({me}) );
    return 1;
}
