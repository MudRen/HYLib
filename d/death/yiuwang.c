// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
���ﲻ��Ѫ�ȣ�Ҳ���ź���������ķ���ȫ����������Ѻ������������
������֮���޷���̸��һ�ؾ�����ʮ�꣬������������������ˣ���
���������һƬ�ž���Ϊ���£���֮�����������˿־塣��һ���
�������������
LONG
        );
        set("exits", ([
		"up" : __DIR__"diaojin",
		"down" : __DIR__"huokeng",
        ]) );
	set("coor/x",-1020);
	set("coor/y",-70);
	set("coor/z",-120);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 
