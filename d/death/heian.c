// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�ڰ���");
        set("long", @LONG
������޹�������������ͽ�������������ʮ����߸�����û��һ��
�־�Ⱥڰ��������˴����ĸе������ˣ�����ͨ������ķ��˺��٣�
һ�����������ȥ�ɺ��ѣ�����Ҳ����������Ը�����һ����ʡ��
���ᡣ���±��ǵ�ɽ���ˡ�
LONG
        );
        set("exits", ([
		"up" : __DIR__"youguo",
		"down" : __DIR__"daoshan",
        ]) );
	set("coor/x",-1020);
	set("coor/y",-70);
	set("coor/z",-240);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 
