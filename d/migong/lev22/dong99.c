#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"�ⰵ֮���"NOR);
	set("long", HIW @LONG
 ������磬Ʈ��������,����,�ذ����ɷ����Ļƽ����̳ɣ����ܵ�ǽ��
���컨���������������ıڻ��;��µ�ʯ�񡣿���������ˮ��ɢ��������
�Ĺ�â���޿�����Ʈ���ڿ��е�����ʹ��һ��������á�
LONG NOR);
	set("exits", ([
		"down" : __DIR__"dong98",
		"up" : __DIR__"dong100",
                	]));
set("no_npc",1);
       set("objects", ([
              __DIR__"npc/bossz1" : 1,
             __DIR__"npc/bossz2": 1,
            "/d/migong/lev14/npc/boss" : 2,
            "/d/migong/lev15/npc/boss" : 2,
            	            	            	            	
"/clone/box/gboxm" : 2,
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
