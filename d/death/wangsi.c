// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
ԶԶ��ȥ�����Թ�����죬������Ķ���������ԩ�꣬������������ս
������ʬ���������񣬼�����ɢ��������Թ�������𽥾ۼ���һ��
�־���Ϊ���������Ҳ�����̷���ֻ�ǹ��������������У����к�����
���˼�ڿ�ˮ½�������������꣬���в���ԩ����԰�Ϣ����ϧ����ս
���������������е�ԩ�꾹ȻԽ��Խ�ࡣ���������ǣ�����ƽ�����ˡ�
LONG
        );
        set("exits", ([
		"south" : __DIR__"pingan",
        ]) );
        set("objects", ([
                __DIR__"npc/ghost" : 5,
        ]) );
	set("coor/x",-1020);
	set("coor/y",-70);
	set("coor/z",-290);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 
