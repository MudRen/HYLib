// /d/taiyuan/xiyuan.c
// Room in ̫ԭ
// rich 99/05/05
inherit ROOM;
void create()	
{
	set("short", "Ϸ԰");
	set("long", @LONG
Ϸ԰���̨�����ڳ�Ϸ������ᣲ����������ˣ�̨�¼��������ԣ�
���Ų��ٹ����е������㵸���е���Ʒ�裬�кá�
LONG
	);
set("outdoors", "taiyuan");
set("exits", ([
                "out" : __DIR__"chaguan", 
	]));
set("objects",([
  __DIR__"npc/xiyou":1,
  ]));
       setup();
	replace_program(ROOM);
}	
