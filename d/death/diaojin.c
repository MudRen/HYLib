// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�����ǵ����ĵ�һ�㣬������ʮ�˲㣬ÿ�����Ѻͬһ���˷�����ʵ��
��Ѻ���ַ��ˡ����һ�������Ѻ���ǡ��ż����ȣ��������գ�������
ǰ����ǧ��ҵ������ͨ����������������������й�Ѻ�Ľ�����������
֮�ˣ�������֮�࣬���Ѫ�ȣ�����������˷�����������������Ѳ��
�����±�����������
LONG
        );
        set("exits", ([
		"up" : __DIR__"diyu",
		"down" : __DIR__"yiuwang",
        ]) );
	set("coor/x",-1020);
	set("coor/y",-70);
	set("coor/z",-110);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 
