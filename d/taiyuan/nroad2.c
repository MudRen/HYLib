// /d/taiyuan/nroad2.c
// Room in ̫ԭ
// modify by yang

#include <room.h>
inherit ROOM;
void create()	
{
	set("short", "��ٵ�");
	set("long", @LONG
������һ����������Ĵ�ٵ��ϡ��������������������ӵġ�����
�ġ����Ŵ󳵵���������������ǳ����֡���ʱ����������������
�߷ɳ۶���������һ·��������·��������������������֡�����ȥ��
��Զ������һƬ���ԭ�ˡ�
LONG
        );
set("outdoors", "taiyuan");
set("valid_startroom", 1);
set("exits", ([
                "southeast":__DIR__"nroad1", 
                "north":__DIR__"nroad3", 
                
	]));
       setup();
 	replace_program(ROOM);
}
