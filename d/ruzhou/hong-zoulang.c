//Room: /d/ruzhou/hong-zoulang.c
// by llm 99/06/12

inherit ROOM;

void create()
{
	set("short", "����ׯ����");
   set("long", @LONG
���������Ǻ����۵������������ߵʹ�����������ź����������
���ź��Ĵ���̺���������������ǽ����������棬һ��ϲ���Ҹ�֮
�����ĵ���Ȼ������ǰ����һ�������������
LONG
   );
	set("exits", ([
		"west" : __DIR__"hong-damen",
		"east" : __DIR__"hongniang-zhuang",
   ]) );

   set("objects", ([
   	__DIR__"npc/xiao-hongniang" : 1,
      ]) );
   setup();
	replace_program(ROOM);
}
