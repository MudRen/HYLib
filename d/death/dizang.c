// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�زص�");
        set("long", @LONG
����ظ�֮�У���Ȼ��һ���ɹ���ʵ���������ţ�������ڤ����
�ز��������޹����ഫ�ز�ԭΪ�������ӣ������õ��ھŻ������乫
����˽�����������ֻأ����������������������Ա���α����������
���Ѿ�֮�����������˴����ɵز��������ã������������ޱߴȺ���
���������
LONG
        );
        set("exits", ([
		"southup" : __DIR__"beiyin",
        ]) );
       set("objects", ([
                __DIR__"npc/pusa" : 1,
        ]) );

	set("coor/x",-1020);
	set("coor/y",-40);
	set("coor/z",-100);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 
