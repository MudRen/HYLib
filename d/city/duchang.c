// Room: /city/duchang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "����ĳ�");
	set("long", @LONG
�����ǻ���ĳ��Ĵ�Ժ���̻����µ����ݣ���ô�����������Ժ��
������ͨ�����������ͨ����������������������ߺ���������������
ҡͷһЦ����Ҫ��������������������沫������Ҳ�Ǳ�̶����������
�ᣬ����������ǲ����ݡ�
LONG );
	set("item_desc", ([
		"paizi" : "��¥�Ĺ��������ڲ��Խ׶Ρ�\n",
	]));
	set("objects", ([
		CLASS_D("shenlong")+"/pang" : 1,
	]));
	set("exits", ([
//		"west" : __DIR__"daxiao",
		"up"   : __DIR__"duchang2",
		"east" : __DIR__"nandajie1",
		"south": __DIR__"bobingting",
		"west" : __DIR__"zoulang1",
		"north" : __DIR__"shaiziting",	
	]));
	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "west" && this_player()->query("age")<18)
                return notify_fail("Сë���������Ϲ�պ�ʲô?!\n");
        return ::valid_leave(me, dir);
}

