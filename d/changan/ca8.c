// Room: /d/changan/ca8.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����߽������͸е������������ڣ����ܵ�ǽ�Ϲ�����������
�ֶ����Ѿ���õ��������������˵���ذ�׵���м���Ÿ���ʢ��
��¯��һ���������ڻ�¯���������ô��š�
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"ca7",
]));
	set("objects", ([ /* sizeof() == 1 */
  "/d/city/npc/smith" : 1,
]));

	setup();
	replace_program(ROOM);
}
