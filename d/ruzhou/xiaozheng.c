// Room: /d/ruzhou/xiaozheng.c С��
// llm 99/02

inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
�����Ѿ��������ݵؽ��ˡ�С�򲻴󣬵���λ����ԭ����ԣ���
�������Ŀ��˱�ʹ�������������������ˡ�����ʹ������ı����˿�
���٣�����������ɫ�ҴҵĽ������ˡ�
LONG
	);

	set("exits", ([
		"south" : "/d/nanyang/yidao3",
		"north" : __DIR__"ruzhou",
              "west" : __DIR__"yingbin-lou1",
	]));

	set("objects",([
		__DIR__"npc/xiao-fan" : 1,
	]));

	set("outdoors", "ruzhou");
	setup();
	replace_program(ROOM);
}



