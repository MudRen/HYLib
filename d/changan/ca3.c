// Room: /u/wsl/changan/ca3.c
// This is a room made by wsl.

inherit ROOM;

void create()
{
	set("short", "�Ƶ��¥");
	set("long", @LONG
�ϵ��͵�Ķ�¥���㲻��������һ˿���⣬�붫�᷿�ɣ����᷿
�Ѿ�����ס�ˡ���˵���и�����һֱס���ǵġ�
LONG
);
        set("exits", ([
  "west" : __DIR__"ca5",
  "down" : __DIR__"ca2",
  "east" : __DIR__"ca4",
]));

	setup();
	replace_program(ROOM);
}
