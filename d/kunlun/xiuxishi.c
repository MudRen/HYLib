// xiuxishi.c
// from wudang. modify later

inherit ROOM;

void create()
{
		  set("short", "��Ϣ��");
		  set("long", @LONG
���Ǽ�������᷿�����Ŵ������ţ����ߺܻ谵��������ż�����ʰ��
���������ľ�������ž�������˯����
LONG
		  );

		set("no_fight", 1);
		set("sleep_room", 1);

		  set("exits", ([
		  "south" : __DIR__"liangong",
		  "southeast" : __DIR__"chufang",
		  ]));

		  setup();
		  replace_program(ROOM);
}


