// Room: /jyguan/zahuopu.c
// YZC 1995/12/04 , Shark 10/08/1998 edit

inherit ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
	����һ��СС���ӻ��̣�����С�������һ�أ�����һЩ�ճ���Ʒ������
�������������һֻ�����ϣ��к��Ź������ˡ���˵˽������Ҳ��һЩ���صĶ�����
̯������һ������(zhaopai)��
LONG
	);

	set("item_desc", ([
		"zhaopai": "���� \"list\" �г������\"buy\" ���ϰ幺�\n",
	]));
	set("exits", ([
		"east" : __DIR__"townroad",
	]));
	set("objects", ([
		__DIR__"npc/maimaiti": 1,
	]));

	setup();
	replace_program(ROOM);
}

