#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"����֮ʧ��԰"NOR);
	set("long", HIW @LONG
 ������磬Ʈ��������,����,�ذ����ɷ����Ļƽ����̳ɣ����ܵ�ǽ��
���컨���������������ıڻ��;��µ�ʯ�񡣿���������ˮ��ɢ��������
�Ĺ�â���޿�����Ʈ���ڿ��е�����ʹ��һ��������á�
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong69",
		"west" : __DIR__"dong71",
                	]));
         set("objects", ([
              __DIR__"npc/boss16": 1,
             __DIR__"npc/boss25": 1,
__DIR__"npc/lev1": 3,
__DIR__"npc/lev9": 3,
"/clone/box/gboxm" : random(3),
                ]));
	set("no_clean_up", 0);set("magicroom",1);set("outdoors","migong");set("magicset",1);
	setup();
//	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;
	
    if (me->is_fighting()) 
        return notify_fail("���������������!\n");

    if(me->is_busy())
        return notify_fail("��������æ��\n");

	if (1)
	{

		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("��������˿ڣ�\n");
       		
		}
		
	}

	return ::valid_leave(me, dir);
}