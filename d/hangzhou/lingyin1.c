//Cracked by Kafei
// ������֮����
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", "�������ڵ�");
    set("long", @LONG
�߽���ֻ����������̻��¶�������շ��������Ĵ�������
��������̬���ϵ�Τ��������������������Ǵ��۱��
LONG);

    set("exits", 
          ([ /* sizeof() == 2 */ 
             "out" : __DIR__"lingyin0", 
             "north": __DIR__"lingyin2",
          ])
       );
	set("cost", 0);
    setup();
   replace_program(ROOM);
}