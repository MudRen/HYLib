// Room: /d/xiangyang/caodi3.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
������������Ĳݵء��ɹű���������������İ���ȫ��
���ˣ���Ȼ�ɹű�û�������ţ�����ɱ��Χ˿��������
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);
	set("exits", ([
//		"north"  : __DIR__"southgate2",
		"north"  : "quest/menpaijob/gaibang/guanka",
		"south"  : "/d/wudang/wdroad5",
		"west"   : "/p/guangchang1",
		"southdown"  : "/d/tiezhang/hunanroad1",
		"east"   : "/quest/skills2/wakuang/kuangshan",
	]));
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	object *inv;
	int sizeinv;
        if( dir=="west" && !userp(me) )
                return notify_fail("����ֻ����Ҳ��ܽ�ȥ��\n");
      if( dir=="west" )		
{
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character()&& userp(inv[sizeinv])  )  
     				return notify_fail("�����ȥ�����˿ڣ�\n");
       		
		}
}		
        return ::valid_leave(me, dir);
}