// Room: /d/japan/zoulang.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����������һ����������,�����ȵ�һ��������,��һ����һ��СС
�Ļ�԰,֧�������ȵ����Ӷ��Ǿ޴��ԭľ,û�о����κε�װ��,ȴʹ��
����ʮ��ׯ��.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"liusheng",
  "southeast" : __DIR__"zoulang",
  "northdown" : __DIR__"xuanguan",
]));

	setup();
	replace_program(ROOM);
}
