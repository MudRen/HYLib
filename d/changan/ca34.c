// Room: /d/changan/ca34.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
    ������ǳ����ǵ�����֣�������ֽ����ڴˡ�һ��Ρ��ߴ��
��¥������ǰ��������Щ���ơ�ÿ���峿�����������������ŵ�
���������򳤰��ǵĴ��С�·�ڳ�ˮ�����������˳����ϡ�
LONG
);
	set("no_clean_up", 0);
	set("outdoors", 1);
	set("exits", ([ /* sizeof() == 4 */
  "south" : "/d/city4/kedian",
  "north" : __DIR__"ca13",
  "east" : "/d/city4/center",
  "west" : "/d/city4/westgate",
//  "northwest" : __DIR__"ta1",
]));

	setup();
	replace_program(ROOM);
}
