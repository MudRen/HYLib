// Room: /d/feitian/daochang.c
inherit ROOM;

void create()
{
  set ("short", "��Ż�����");
  set ("long", @LONG
���������Ż������ĵ����ˣ�������ʦ���������ﴫ���似��
�����ǽ�Ϲ���һ��������(ce zi)��������ĵ��Ӷ���Ҫ��
����������������ʽ����.
LONG);
set("valid_startroom", "1");
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"houting",
  "west" : __DIR__"bingqishi",
  "south" : __DIR__"zoulang",
  "east" : __DIR__"xiangfang",
]));
  set("objects", ([ /* sizeof() == 2 */
//  __DIR__"obj/liumingce" : 1,
  __DIR__"npc/axun" : 1,
                "quest/menpai/feitian/shi" : 1,
                "d/biwu/champion_feitian" : 1,
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "che zi" : "���Ƿ����������������ӵ������ᡣ(read)
",
]));
  setup();
//  replace_program(ROOM);
	"/clone/board/feitian_b"->foo();
}
