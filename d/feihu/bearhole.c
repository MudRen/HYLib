// �ܶ�
// by steel 
#include "ansi.h"
inherit ROOM;

void create()
{
	set("short", "�ܶ�");
	set("long", @LONG
        ���߽���һ��ɽ��,���������ů�Ͷ��ˡ�������һ��ŨŨ����
ζ����̧ͷһ����һͷ˶���ޱȵİ����������������㡣    
LONG
	);
	
	set("exits", ([
                "northeast" :__DIR__"hole10", 
               ]));
        set("objects",([
               __DIR__"npc/bear":1,
             ]) );   
	setup();
        replace_program(ROOM);
}

