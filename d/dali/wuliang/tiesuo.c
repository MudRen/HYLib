// Room: tiesuo.c
// By River 98/12
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�����Ź��������������������£�����ľ�壬�Թ����ߣ�����������Ϊ��
�֡�һ̤���ţ����������㼴�϶����е����ģ������εø���������һƳ�ۼ䣬
������ˮ����������������ĭ��������ڰ�ӽŵ׷ɹ���ֻҪһ��ʧ�㣬��
�뽭ˮ�������õ�ˮ��Ҳ�ѻ����� 
LONG
        );
        set("exits", ([
            "north" : __DIR__"hslin",
            "south" : __DIR__"jiangan",
        ]));       
        set("outdoors", "����");
        setup(); 
}

void init()
{
        object me=this_player();
        if ( me->query_skill("dodge", 1) < random(50)){
        me->start_busy(2);
        me->set_temp("last_damage_from", "׹�뽭����");
        message_vision(HIR"$N����һ�����ȣ��ѳֲ�ס��ˤ��������ڵ����׽��ڡ�\n"NOR,me);
        me->unconcious();
        }       
}
