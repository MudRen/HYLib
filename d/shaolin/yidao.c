// Room: /d/shaolin/yidao.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ�
���̣����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡�
��ʱ����������������߷ɳ۶���������һ·���������ϵ���
�������ž�װ���¼��������еĻ���������ŵ�������������Щ
Щϰ��Ľ����ˡ���·��������������������֡��������ݿ쵽
�ˡ�
LONG );
	set("exits", ([
		"south" : "/d/city/beimen",
		"north" : __DIR__"yidao1",
            "east" : "/p/guangchang",
	]));
	set("outdoors", "shaolin");
	set("no_clean_up", 0);
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	object *inv;
	int sizeinv;

        if( dir=="east" && !userp(me) )
                return notify_fail("����ֻ����Ҳ��ܽ�ȥ��\n");
        if( dir=="east")
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