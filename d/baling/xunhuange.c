// baling/xunhuange
// Room in ���� 
// laowuwu 99/04/11
inherit ROOM;

void create()
{
	set("short", "�ٻ�Է");
	set("long", @LONG
�����ǰٻ�Է�����ȵ�һ�˵�ס�������а���һ��ɼľԲ���ͼ���
���ӣ�������һ�׾��µ����˴�����ǽ�Ϲ���һ���޻�����������ŮƮ
�㣬������ӵ��ֱʡ�һ����Ů���������š�
LONG
	);

	set("exits", ([
		"down" : __DIR__"micunyuan",
	]));

	set("objects",([
	 __DIR__"npc/girl":1,
	 ]));
	
	setup();
	replace_program(ROOM);
}

