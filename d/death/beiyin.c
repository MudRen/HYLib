// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "����ɽ");
        set("long", @LONG
�زص���ų�������Ȼ����̹ǣ�ԭ�����˱���ɽ������ɽ��
�ظ����ն�ĵط�����ɽ��Ұ���ǹ»�Ұ���ζ఼͹��ɽ���վ���
�������룬����®�ң��㲻�ɵ�Ӳ��ͷƤ��ǰ�ߡ�
LONG
        );
        set("exits", ([
		"northdown" : __DIR__"dizang",
		"southdown" : __DIR__"shandao",
        ]) );
	set("coor/x",-1020);
	set("coor/y",-50);
	set("coor/z",-90);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 
