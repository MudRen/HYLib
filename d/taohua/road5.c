inherit ROOM;
 
void create()
{
        set("short", "����");
        set("long",@LONG
����һ����ɽ�ϵ�һ��Сɽ�������ں�С��������һ�������ȥ������
�������ʲôҲ��������
LONG);
        set("exits", ([
            "east"   : __DIR__"bagua1",
            "west"   : __DIR__"road4",
            "south"   : __DIR__"bagua0",
            "north"   : __DIR__"bagua0",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "taohua");
        setup();
//        replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;
	
	if (dir =="east" ||dir =="south"||dir =="north")
	{
	
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("�����ȥ�����˿ڣ�\n");
       		
		}
		
	}

	return ::valid_leave(me, dir);
}