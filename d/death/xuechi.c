// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "Ѫ����");
        set("long", @LONG
�����Ѻ�Ķ��ǡ���Ƥ¶�ǣ��۱۶ϽҲֻΪı�ƺ���������������
ǧ�ꡱ�Ķ�ͽ�����϶�մ�������˵�Ѫ����������Ѫ��Ѫ��������˽�
����Ѫ��֮�У�ÿ������Ѫ��Ѭ��֮�࣬���Լ�ҹ��ʹ���ѵ���
LONG
        );
        set("exits", ([
		"up" : __DIR__"daoshan",
		"down" : __DIR__"abi",
        ]) );
	set("coor/x",-1020);
	set("coor/y",-70);
	set("coor/z",-260);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 
