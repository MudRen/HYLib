// Room: /u/wsl/changan/ca14.c
// This is a room made by Wsl.

inherit ROOM;

void create()
{
	set("short", "�ٲ���");
	set("long", @LONG
һ���ţ���Ϳ������ŵ�ǽ�Ϲ��š��ٲ��á������ֵ��������
���Ա߷���һ����ҩ�õ�¯�ӣ�����ɢ����Ũ����ҩζ���ұ߹���һ
�����ӣ�paizi����
LONG
);
	set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "����ҩƷ��ȫ���������ۡ�
ҩƷ��Ŀ���£�
��ҩ��        ��ʮ������
��������        ��ʮ������
������ҩ�ɶ�����
",
]));
        set("objects", ([
           __DIR__"npc/huoji" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"ca12",
]));

	setup();
	replace_program(ROOM);
}
