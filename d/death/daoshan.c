// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��ɽ��");
        set("long", @LONG
һƬ������ƽ�أ����ϵ������������ļ⵶����ţ�;����ӳ���£���
�еĺ����Ե�ɭ���ޱȣ���Ŀ���ģ����˴��ų�������ͷ�ߵ���ͷ��һ
���߲���ʮ��֮һ�͵�����ȥ�������ɴ��һ�㣬��ʱ�����������
������������������߹����ո�һ�գ��긴һ�ꡣ�������±������һ
���˹�Ѻ�ĵط��ˣ�������������֮ͽ��
LONG
        );
        set("exits", ([
		"up" : __DIR__"heian",
		"down" : __DIR__"xuechi",
        ]) );
	set("coor/x",-1020);
	set("coor/y",-70);
	set("coor/z",-250);
	set("coor/x",-1020);
	set("coor/y",-70);
	set("coor/z",-250);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 
