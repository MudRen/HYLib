// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
һ�������������������������˹�ȥ����֮�У���������������
�ش���ÿ��һ�Σ���������ɽ�̿��Ȼ�󱻹��佽����ˮ��ָ�
ԭ���������������Ͻ�����㲻�ɵ��ĵ���٣�����������ǰδ��
����ʲô��ҵ���ɴ�������ۺ������
LONG
        );
        set("exits", ([
		"up" : __DIR__"yiuwang",
		"down" : __DIR__"yandu",
        ]) );
	set("coor/x",-1020);
	set("coor/y",-70);
	set("coor/z",-130);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 
