// Room: /d/yandang/luoyan2.c

inherit ROOM;

void create()
{
	set("short", "����ɽׯ");
	set("long", @LONG
������ǰ����һ����ΰ��ׯ԰,ӭ�������ȴ���,��ǰ�İ���̨��һ
����Ⱦ,���ߵ�����ʯʨ����һ�˶��,�������һ���Ҷ�,��˵��������
����������.
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/menwei.c" : 2,
]));
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"luoyan3",
  "south" : __DIR__"luoyan1",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "�Ҷ�" : "����ڵװ���,����ɽׯ���ֱ����ݺ�,�罣�����.
",
]));

	setup();
}

int valid_leave(object me,string dir)
{
	string fam;
	object npc;

	fam=(string)me->query("family/family_name");
	npc=present("men wei",this_object());
	if( fam && fam!="�㵴��" && dir=="north" && objectp(npc))
	return notify_fail("ɽׯ��������һ���۵�����ʲô�㣡��\n");
	return ::valid_leave(me,dir);
}

