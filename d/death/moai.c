// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ĥ����");
        set("long", @LONG
һ���������ǵ�Ѫ��ζ����ֻ��ĥ�̲�ͣ��ת���ţ���ĥ�ĳ෢����
����ͷ�󺹣���ʱ�����š������ǡ�Ƥ��������Ĩ����������������
���������������ﻨ�԰����ˡ����˷�����֮�أ��˷�����������ĥ
�̣�եΪ�⽴��Ȼ�����ɺ����������裬ƴ���������������κ��
�����̡����������׵����Ҳ������������
LONG
        );
        set("exits", ([
		"up" : __DIR__"bopi",
		"down" : __DIR__"zhuidao",
        ]) );
	set("coor/x",-1020);
	set("coor/y",-70);
	set("coor/z",-170);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 
