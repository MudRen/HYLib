inherit ROOM;

void create()
{
	set("short", "��΢��");
	set("long", @LONG
��һ�߽��������ŵ�һ�ɲ���������Ƣ������Ϊ֮һˬ�����Ű���
��һ���ſ��������˿��ˣ����������ͷ�Ӷ���
LONG );
	set("resource/water", 1);
	set("exits", ([
		"southeast" : __DIR__"beishi",
	]));
	set("objects",([
	__DIR__"npc/xiaoer":1,
	]));
	setup();
	replace_program(ROOM);
}

