//cool 98.4.18
inherit ROOM;

void create()
{
        set("short", "��ݴ���");
        set("long", @LONG
������һ����լ�ӣ��ſڸ���һ�����ҡ�������ݡ�����������ʯʨ��
��Ӵ��ſ��ƽ�ȥ�����������������������ܷ�æ�����ӣ��ſ�վ������
�������������ϡ�
LONG);
        set("exits", ([
                "north" : __DIR__"dayuan",
                "south" : __DIR__"xiaojs",
        ]));
        set("no_fight",1);
        set("objects", ([
__DIR__"npc/menwei" : 1,
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;
        if (me->query("combat_exp") >=  50000
           && dir =="north")
	     return notify_fail("�������洫����һ����������������ֻ���ɳ��뽭�������֡�\n");
        if (me->query("potential") >=  50000
           && dir =="north")
	     return notify_fail("�������洫����һ����������������ֻ���ɳ��뽭�������֡�\n");

		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("�����ȥ�����˿ڣ�\n");
       		
		}

	return ::valid_leave(me, dir);
        
}
